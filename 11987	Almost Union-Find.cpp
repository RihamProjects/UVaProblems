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
    vi parent, cnt, sum;
    UnionFind(int n){
        parent = vi(2*n + 3, 0); cnt = sum = vi(2*n + 3, 0);
        for(int i=1;i<=n;i++) parent[i] = i + n;
        for(int i=n+1;i<=2*n;i++) parent[i] = i,  sum[i] = i - n, cnt[i] = 1;
    }
    int findSet(int p){
        if(parent[p] == p) return p;
        return parent[p] = findSet(parent[p]);
    }
    void Union(int p, int q){
        q = findSet(q), p = findSet(p);
        if(q == p) return;
        parent[p] = q;
        cnt[q] += cnt[p];
        cnt[p] = cnt[q];
        sum[p] += sum[q];
        sum[q] = sum[p];
    }
    void Move(int p, int q){
        q = findSet(q); int Pp = findSet(p);
        if(Pp == q) return;
        parent[p] = q;
        cnt[q]++; cnt[Pp]--;
        sum[q] += p; sum[Pp] -= p;
    }
    void NumSum(int p){
        p = findSet(p);
        cout << cnt[p] << " " << sum[p] << endl;
    }
};
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n, m;
    while(cin>>n>>m){
        UnionFind u(n);
        for(int i=0;i<m;i++){
            int o, f, t;
            scanf("%d", &o);
            if(o == 1){
                scanf("%d%d", &f, &t);
                u.Union(f, t);
            }
            else if(o == 2){
                scanf("%d%d", &f, &t);
                u.Move(f, t);
            }
            else{
                scanf("%d", &f);
                u.NumSum(f);
            }
        }
    }
    return 0;
}

