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

map<char, int> mp;
map<char, vector<char> > adj;
set<char> st;
vector<char> nextAwake;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int N, M;
    while(cin>>N>>M){
        string s; int ans = 0;
        bool Never = 0;
        cin>>s;
        for(int i=0;i<3;i++) mp[s[i]] = 1;
        if(!M && sz(s) != N){ Never = 1; goto there; }
        for(int i=0;i<M;i++){
            char f, t;
            cin>>f>>t;
            adj[f].pb(t);
            adj[t].pb(f);
            st.insert(f), st.insert(t);
        }
        for(int j=0;j<N;j++){

            for(auto i = st.begin(); i != st.end(); i++){
                int cnt = 0;
                if(mp[*i]) continue;
                for(int k=0;k<sz(adj[*i]);k++){
                    if(mp[adj[*i][k]])
                        cnt++;
                    if(cnt == 3){
                        nextAwake.pb(*i); break;
                    }
                }
            }

            if(sz(nextAwake)) ans++;

            for(int i=0;i<sz(nextAwake);i++) mp[nextAwake[i]] = 1;
            nextAwake.clear();
        }
        for(auto i = st.begin(); i != st.end(); i++){
                adj[*i].clear();
                if(!mp[*i]){
                    Never = 1;
                }
        }
        st.clear(); adj.clear(); mp.clear();
there:
        if(!Never)
            printf("WAKE UP IN, %d, YEARS\n", ans);
        else{
            puts("THIS BRAIN NEVER WAKES UP");
        }
    }
    return 0;
}

