#include <bits/stdc++.h>
using namespace std;

typedef    unsigned long long         ull;
typedef    long long                   ll;
typedef    long double                 ld;
#define    Set(v,d)                     memset(v, d, sizeof(v))
#define    oo                           1000000007   //infinity
#define    F                            first
#define    S                            second
#define    pb                           push_back
#define    sz(x)                        (int)(x.size())
#define    all(x)                       (x.begin()), (x.end())
#define    rall(x)                      (x.rbegin()), (x.rend())

struct edge{
    int from, to, weight;
    edge(int from, int to, int weight): from(from), to(to), weight(weight){}

    bool operator < (const edge& e) const{
        return weight > e.weight;
    }

};

const int MAX = 20005;
int n, m, s, t;
vector<edge>adj[MAX];

int Dijkstra(int s, int t){
    priority_queue<edge> pq;
    vector<int>dist(n, oo);

    pq.push(edge(-1, s, 0));
    dist[s] = 0;
    while(!pq.empty()){
        edge Edge = pq.top(); pq.pop();
        if(Edge.weight > dist[Edge.to]) continue;
        for(int i=0;i<sz(adj[Edge.to]);i++){
            edge NextEdge = adj[Edge.to][i];
            if(dist[NextEdge.to] > dist[NextEdge.from] + NextEdge.weight){
                dist[NextEdge.to] = NextEdge.weight = dist[NextEdge.from] + NextEdge.weight;
                pq.push(NextEdge);
            }
        }
    }
    return dist[t];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int TC, cnt = 0;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d%d%d", &n, &m, &s, &t);
        for(int i=0;i<m;i++){
            int from, to, weight;
            scanf("%d%d%d", &from, &to, &weight);
            adj[from].pb(edge(from, to, weight));
            adj[to].pb(edge(to, from, weight));
        }
        int ans = Dijkstra(s, t);
        if(ans == oo)
            printf("Case #%d: unreachable\n", ++cnt);
        else
            printf("Case #%d: %d\n", ++cnt, ans);
        for(int i=0;i<n;i++)
            adj[i].clear();
    }
	return 0;
}
