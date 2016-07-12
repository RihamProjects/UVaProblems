#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 21;
vector<int>adj[N];
int BFS(int s, int d){
    queue<int>q; vector<int>dist(N, oo);
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int parent = q.front(); q.pop();
        for(int i=0;i<adj[parent].size();i++){
            int child = adj[parent][i];
            if(dist[child] == oo){
                dist[child] = dist[parent] + 1;
                if(child == d)
                    return dist[child];
                q.push(child);
            }
        }
    }
    return 0;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int x, y, N, source, dest, cnt = 0;
    while(scanf("%d", &x) == 1){
        printf("Test Set #%d\n", ++cnt);
        for(int i=1;i<20;i++){
            while(x--){
                scanf("%d", &y);
                adj[i].push_back(y); adj[y].push_back(i);
            }
            scanf("%d", &x);
        }
        for(int i=0;i<x;i++){
            scanf("%d%d", &source, &dest);
            printf("%2d to %2d:%2d\n", source, dest, BFS(source, dest));
        }
        for(int i=1;i<=20;i++) adj[i].clear();
        printf("\n");
    }
    return 0;
}
