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
bitset<oo>prime;
int n;
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
    while(r(n)==1){
        if(n<8){
            puts("Impossible.");
            continue;
        }
        if(n&1){
            printf("2 3 ");
            n-=5;
        }
        else{
            printf("2 2 ");
            n-=4;
        }

        int j;
        loop(i,n){
            if(prime[i]){
                j=n-i;
                if(prime[j]){
                    printf("%d %d\n",i,j); break;
                }
            }
        }
    }


  return 0;
}
