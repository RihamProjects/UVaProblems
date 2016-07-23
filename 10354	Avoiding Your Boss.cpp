#include <bits/stdc++.h>
using namespace std;

#define oo 		(int)1e9
#define ll 		long long
#define ld 		long double
#define F 		first
#define S 		second

const int N = 105;
int P, R, BH, OF, YH, M;
int dist[N][N];
bool Mark[N];
void FloydWarshall() {
	for (int k = 1; k <= P; k++)
		for (int i = 1; i <= P; i++)
			for (int j = 1; j <= P; j++)
				dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
}
vector<pair<int, int>> adj[N];
int Dijkestra(int s, int e) {
	priority_queue<pair<int, int>> pq;
	vector<int> distance(P + 3, oo);
	pq.push( { 0, s });
	distance[s] = 0;
	if(Mark[s]) return oo;
	while (!pq.empty()) {
		int node = pq.top().S, cost = pq.top().F;
		pq.pop();
		if (cost > distance[node])
			continue;
		for (int i = 0; i < (int) adj[node].size(); i++) {
			int ch = adj[node][i].F, d = adj[node][i].S;
			if (!Mark[ch]) {
				if (distance[ch] > distance[node] + d) {
					distance[ch] = distance[node] + d;
					pq.push( { distance[ch], ch });
				}
			}
		}
	}
	return distance[e];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
	while (scanf("%d%d%d%d%d%d", &P, &R, &BH, &OF, &YH, &M) == 6) {
		memset(Mark, 0, sizeof Mark);
		for (int i = 1; i <= P; i++)
			for (int j = 1; j <= P; j++) {
				if (i == j) {
					dist[i][j] = 0;
					continue;
				}
				dist[i][j] = oo;
			}
		for (int i = 0; i < R; i++) {
			int p1, p2, d;
			scanf("%d%d%d", &p1, &p2, &d);
			dist[p1][p2] = dist[p2][p1] = d;
			adj[p1].push_back({ p2, d });
			adj[p2].push_back({ p1, d });
		}

		if (YH == BH || YH == OF || M == BH || OF == M) {
			printf("MISSION IMPOSSIBLE.\n");
			for (int i = 0; i <= P; i++)
				adj[i].clear();
			continue;
		}
		FloydWarshall();
		int ShortestPath = dist[BH][OF];
		for (int i = 1; i <= P; i++)
			if (ShortestPath == dist[BH][i] + dist[i][OF]) {
				Mark[i] = 1;
			}

		int ans = Dijkestra(YH, M);
		if (ans >= oo)
			printf("MISSION IMPOSSIBLE.\n");
		else
			printf("%d\n", ans);
		for (int i = 0; i <= P; i++)
			adj[i].clear();
	}
	return 0;
}
