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

vi adj[340]; bool visited[340];

void dfs(int n){
    visited[n] = 1;
    for(int i=0;i<sz(adj[n]);i++)
        if(!visited[adj[n][i]])
            dfs(adj[n][i]);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int TC; char maxChar;
    scanf("%d", &TC);
    cin.ignore();
    while(TC--){
//        cin.ignore();
        int cnt = 0;
        for(int i=0;i<340;i++)
            adj[i].clear();
        Set(visited, 0);
        cin>>maxChar;
        cin.ignore();
        while(1){
            string s;
            getline(cin, s);
            if(!sz(s)) break;
            adj[s[0]-'A'].pb(s[1]-'A');
            adj[s[1]-'A'].pb(s[0]-'A');
        }
//        for(int i=0;i<=maxChar-'A';i++) for(int j=0;j<sz(adj[i]);j++) cout<<i<<" "<<adj[i][j]<<endl;
        for(int i=0;i<=maxChar-'A';i++)
            if(!visited[i]){ dfs(i); cnt++; }
        cout<<cnt<<endl;
        if(TC) puts("");
    }
    return 0;
}

