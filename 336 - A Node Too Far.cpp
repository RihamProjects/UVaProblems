#include <bits/stdc++.h>
using namespace std;
#define oo 100000000000000007
typedef long long    ll;
const int N = 2000;
vector<ll>d;
map<ll, vector<ll> >adj;


ll BFS(ll s, int TTL){
    queue<ll>q;
    q.push(s);
    d[s] = 0;
    ll cnt = 0;

    while(!q.empty()){
        ll u = q.front();
        if(d[u] <= TTL)
            cnt++;
        q.pop();
        if(!adj[u].size()) cnt--;
        for(int i=0;i<adj[u].size();i++){
            ll v = adj[u][i];
            if(d[v] == -1){
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int NC; ll cnt = 0, mx = -oo;
    unordered_set<ll>st;
    while(scanf("%d", &NC) == 1, NC){
        for(int i=0;i<NC;i++){
            ll f, t;
            scanf("%lld%lld", &f, &t);
            adj[f].push_back(t);
            adj[t].push_back(f);
            st.insert(f);
            st.insert(t);
            mx = max(mx, f);
            mx = max(mx, t);
        }
        ll s, TTL;
        while(scanf("%lld%lld", &s, &TTL) == 2, s){
            d = vector<ll>(mx + 5, -1);
            printf("Case %lld: %lld nodes not reachable from node %lld with TTL = %lld.\n", ++cnt, st.size() - BFS(s, TTL), s, TTL);
        }

        for(int i=0;i <= mx + 2;i++)
            adj[i].clear();
        st.clear();
    }
    return 0;
}
