#include <bits/stdc++.h>
using namespace std;

/**------------------------------------**------------------------------------**/
typedef     long long           ll;
typedef     long double         Ld;
#define     sz(v)               ((int)((v).size()))
#define     all(v)              (v.begin()),(v.end())
#define     vi                  vector<int>
#define     vs                  vector<string>
#define     vll                 vector<ll>
#define     pb(a)               push_back(a)
#define     r(n)              scanf("%d",&n)
#define     rL(n)              scanf("%I64d",&n)
#define     p(n)            printf("%d ",n)
#define     pL(n)            printf("%I64d ",n)
#define     Set(v,d)            memset(v, d, sizeof(v))
#define     loop(i,n)           for(int i=0; i < n; i++)
#define     rvlop(k,n)         for(int k=n-1; k>0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  20000010  ///infinity
/********************************-Declarations-*******************************/
bitset<oo>prime;vector<pair<int,int> >p;
int S;
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    void _Sieve(ll Upperbound){
        prime.set(); prime[0]=prime[1]=0;
        for(ll i=4;i<=Upperbound;i+=2)prime[i]=0;
        for(ll i=3;i*i<=Upperbound;i+=2)
            if(prime[i]){
                for(ll j=i*i;j<=Upperbound;j+=i)
                    prime[j]=0;
            }
    }

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

int main(){
//    freopen("Output.txt","w",stdout);
    _Sieve(oo);
    loop(i,oo-1)
        if(prime[i]&&prime[i+2])
            p.pb(make_pair(i,i+2));

    while(r(S)==1){
        printf("(%d, %d)\n",p[S-1].first,p[S-1].second);
    }


  return 0;
}
