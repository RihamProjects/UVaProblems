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
#define     p(n)            printf("%d\n",n)
#define     pL(n)            printf("%I64d ",n)
#define     Set(v,d)            memset(v, d, sizeof(v))
#define     loop(i,n)           for(int i=0; i < n; i++)
#define     rvlop(k,n)         for(int k=n-1; k>0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  100000  ///infinity
/**------------------------------------**------------------------------------**/
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int Ipow(int base,int exp)
    {int result = 1;
    while(exp)
    {if(exp & 1)result*=base;
        exp>>=1;base*=base;}
    return result;}
/********************************-Declarations-*******************************/
bitset<1000010>prime;vi primes;
int N;


/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    void _Sieve(ll Upperbound){
         prime.set(); prime[0]=prime[1]=0;
        for(ll i=2;i<=Upperbound;i++)
            if(prime[i]){
                for(ll j=i*i;j<=Upperbound;j+=i)
                    prime[j]=0;
                primes.pb(int(i));
            }
    }

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

int main(){
//    freopen("Output.txt","w",stdout);
    _Sieve(oo);
    scanf("%d",&N);
    while(N){
        int cnt=0,i=0;
        while(primes[i]<=N/2&&i<sz(primes)){
            if(prime[N-primes[i]])cnt++;
            i++;
        }
        p(cnt);
        scanf("%d",&N);
    }


  return 0;
}
