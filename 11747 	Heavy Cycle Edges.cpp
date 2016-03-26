#include <bits/stdc++.h>
using namespace std;

typedef    unsigned long long           ull;
typedef    long long                          ll;
typedef    long double                      ld;
#define    Set(v,d)                           memset(v, d, sizeof(v))
#define    oo                                     10000000000000007   //infinity
#define    F                                      first
#define    S                                      second
#define    pb                                    push_back
#define    sz(x)                                (int)(x.size())
#define    all(x)                               (x.begin()), (x.end())
#define    rall(x)                             (x.rbegin()), (x.rend())
typedef     vector<int>                     vi;


struct UnionFind{
    vi parent;
    UnionFind(int n){
        parent = vi(n);
        for(int i=0;i<n;i++) parent[i] = i;
    }
    int findSet(int x){
        if(x == parent[x]) return x;
        return parent[x] = findSet(parent[x]);
    }
    void link(int x, int y){
        x = findSet(x), y = findSet(y);
        parent[x] = y;
    }
};

struct edge{
    int f, t, w;
    edge(int f, int t, int w) : f(f), t(t), w(w) {}
    bool operator <(const edge& e) const{
         return w > e.w;
    }
};

const int MAX = 200005;
int n, m;
vector<edge> adjList;
vi ans;

void MST(){
    UnionFind u(n);
    priority_queue<edge>q;
    for(int i=0;i<sz(adjList);i++)
        q.push(adjList[i]);
    while(!q.empty()){
        edge e = q.top(); q.pop();
        if(u.findSet(e.f) != u.findSet(e.t)){
            u.link(e.f, e.t);
        }
        else ans.pb(e.w);
    }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    while(n){
        adjList.clear();
        ans.clear();
        for(int i=0;i<m;i++){
            int f, t, w;
            scanf("%d%d%d", &f, &t, &w);
            adjList.pb(edge(f, t, w));
        }
       MST();
       if(!sz(ans)){
                puts("forest");
       }
       else{
            for(int i=0;i<sz(ans) - 1;i++)
                printf("%d ", ans[i]);
            printf("%d\n", ans[sz(ans)-1]);
       }
        scanf("%d%d", &n, &m);
    }
    return 0;
}

