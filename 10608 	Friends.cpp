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

const int MAX = 500005;

struct UnionFind{
    vi parent, cnt;
    int components;
    UnionFind(int n){
        parent = cnt = vi(n + 1);
        components = n;
        for(int i=0;i<=n;i++) parent[i] = i, cnt[i] = 1;
    }
    int find_set(int x){
        if(x == parent[x]) return x;
        return parent[x] = find_set(parent[x]);
    }
    /*
1 2
2 1
3 1
    */
    void link(int x, int y){
        x = find_set(x), y = find_set(y);
       if(x == y) return;
        parent[y] = x;
        cnt[x]+=cnt[y];
        cnt[y] = cnt[x];
    }
};


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
    int n, m, TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%d%d", &n, &m);
        UnionFind u(n);
        for(int i=0;i<m;i++){
            int from, to;
            scanf("%d%d", &from, &to);
            u.link(from, to);
        }
        vi cnt = u.cnt;
        cout<<( *max_element(all(cnt))==1? 0 : *max_element(all(cnt)) )<<endl;
    }
    return 0;
}

