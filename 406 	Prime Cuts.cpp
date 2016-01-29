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
#define     p(n)            printf("%d",n)
#define     pL(n)            printf("%I64d ",n)
#define     Set(v,d)            memset(v, d, sizeof(v))
#define     loop(i,n)           for(int i=0; i < n; i++)
#define     rvlop(k,n)         for(int k=n-1; k>0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  1000000  ///infinity
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
bitset<10000010>prime;
vi primes;int N,C;
/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    void _Sieve(int Upperbound){
         prime.set(); prime[0]=0,prime[1]=1;
        primes.pb(1);
        for(int i=2;i<=Upperbound;i++)
            if(prime[i]){
                for(int j=i*i;j<=Upperbound;j+=i)
                    prime[j]=0;
                primes.pb(int(i));
            }
    }

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

int main(){
 //   freopen("Output.txt","w",stdout);
    while(scanf("%d %d",&N,&C)!=EOF){
        _Sieve(N);
        int z=sz(primes)&1 ? C*2-1 : C*2,b=(sz(primes)-z)/2;
        if(sz(primes)<z){
            z=sz(primes);
            b=0;
        }

        printf("%d %d: ",N,C);
        loopb(i,z+b,b){printf("%d",primes[i]);if(i<z+b-1)printf(" ");}

        printf("\n\n");
        primes.clear();
    }


  return 0;
}
