#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 103;
vector<pair<int, int>>adj[N];
int n, cur = 1, x, sum = 0;
void Dijkestra(pair<int, int> source){
    vector<int>dist(n+1, oo);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    dist[source.second] = 0;
    pq.push(source);
    while(!pq.empty()){
        int u = pq.top().second, d = pq.top().first;
        pq.pop();
        if(d > dist[u]) continue;
        for(int i = 0; i<adj[u].size(); i++){
            int child_n = adj[u][i].first, child_c = adj[u][i].second;
            if(dist[u] + child_c < dist[child_n]){
                dist[child_n] = dist[u] + child_c;
                pq.push({dist[child_n], child_n});
            }
        }
    }
    for(int i=1;i<=n;i++) sum = max(sum, dist[i]);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(scanf("%d", &n) == 1){
        sum = 0, cur = 1;
        for(int i=2;i<=n;i++){
            int cnt = cur++, f = 1;
            while(cnt--){
                string s;
                cin >> s;
                if(s != "x"){
                    stringstream ss;
                    ss << s;
                    ss >> x;
                }else {f++; continue;}
                adj[i].push_back({f, x}); adj[f++].push_back({i, x});
            }
        }
        Dijkestra({0, 1});
        printf("%d\n", sum);
        for(int i=1;i<=n;i++) adj[i].clear();
    }
    return 0;
}
