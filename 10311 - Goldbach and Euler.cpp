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
#define     rvlop(k,n)         for(int k=n-1; k>=0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  100000010  ///infinity
/**------------------------------------**------------------------------------**/
/*int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return a * (b / gcd(a, b)); }
int Ipow(int base,int exp)
    {int result = 1;
    while(exp)
    {if(exp & 1)result*=base;
        exp>>=1;base*=base;}
    return result;}*/
/********************************-Declarations-*******************************/
bitset<oo+1>prime;
int N;
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
    while(r(N)==1){
        int save1,save2;bool found=false;
        if(N<=2){
            printf("%d is not the sum of two primes!\n",N);
        }
        else if(N&1){
            if(prime[N-2])
                printf("%d is the sum of %d and %d.\n",N,min(2,N-2),max(2,N-2));
            else
                printf("%d is not the sum of two primes!\n",N);
        }
        else{
            rvlop(i,N/2)
                if(prime[i]){
                    if(i!=N-i&&prime[N-i]){
                        save1=i;
                        save2=N-i;
                        found=true;
                        break;
                    }
                }
            if(found)
                printf("%d is the sum of %d and %d.\n",N,save1,save2);
            else
                printf("%d is not the sum of two primes!\n",N);

        }

    }

  return 0;
}
