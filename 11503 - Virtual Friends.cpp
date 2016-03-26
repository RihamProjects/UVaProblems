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
struct edge;
    vector<edge> adj;
    set<string> s;
    struct UnionFind{
        map<string, string> parent;
        map<string, int> cnt;
        UnionFind(int n){
            for(auto i = s.begin(); i!=s.end(); i++) parent[*i] = *i, cnt[*i] = 1;
        }
        string findSet(string x){
            if(x == parent[x]) return x;
            return parent[x] = findSet(parent[x]);
        }
        void Link(string x, string y){
            if(findSet(x) == findSet(y)) return;
            x = findSet(x), y = findSet(y);
            parent[x] = y;
            cnt[x] += cnt[y];
            cnt[y] = cnt[x];
        }
    };

    struct edge{
        string f, t;
        edge(string f, string t) : f(f), t(t){}
    };
    int n;
    void ST(){
        UnionFind u(n);
        queue<edge>q;
        for(int i=0;i<sz(adj);i++) q.push(adj[i]);
        while(!q.empty()){
            edge e = q.front(); q.pop();
            u.Link(e.f, e.t);
            cout<<u.cnt[u.findSet(e.f)]<<endl;
        }
    }

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int TC;
    scanf("%d", &TC);
    while(TC--){
        adj.clear();
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            string f, t;
            cin>>f>>t;
            s.insert(f), s.insert(t);
            adj.pb(edge(f, t));
        }
        ST();
    }
    return 0;
}

