#include <bits/stdc++.h>
#define oo 1000000007
#define ll long long
using namespace std;
const int N = 23;
int cnt=0, cost[N][N];
int n, m;
int Dijkestra(int s, int e){
    priority_queue<pair<int, int>>pq;
    vector<int>dist(n+5, oo);
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int node = pq.top().second, Cost = pq.top().first;
        pq.pop();
        if(Cost>dist[node]) continue;
        for(int i=1;i<=n;i++){
            if(cost[node][i] != oo){
                if(dist[node]+cost[node][i]<dist[i]){
                    dist[i]=dist[node]+cost[node][i];
                    pq.push({dist[i], i});
                }
            }
        }
    }
    return dist[e];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(scanf("%d%d", &n, &m) == 2 && !(!n && !m)){
        for(int i=0;i<=n;i++)for(int j=0;j<=n;j++) cost[i][j] = oo;
        char s[21][11];
        for(int i=0;i<n;scanf("%s", s+i++));
        for(int i=0;i<m;i++){
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            cost[f][t] = min(cost[f][t], c);
            cost[t][f] = cost[f][t];
        }
        int ans = 0, ANS = 0, Min = oo;
        for(int i=1;i<=n;i++){
            ans = 0;
            for(int j=1;j<=n;j++)
                ans += Dijkestra(j, i);
            if(Min > ans) ANS = i, Min = ans;
        }
        printf("Case #%d : %s\n", ++cnt, s[ANS-1]);
    }
	return 0;
}
