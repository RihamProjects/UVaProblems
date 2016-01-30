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
#define     oo                  1000010  ///infinity
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
int T,L,U;
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
    r(T);
    while(T--){
        r(L),r(U);
        int save,Once=1,Max=-oo,sol,cnt=0;map<int,int>a;
        loopb(i,U+1,L){
            if(prime[i]){
                if(Once){save=i,Once=0;}
                else{
                    a[i-save]++;
                    if(Max<a[i-save]){
                        Max=a[i-save];
                        sol=i-save;
                    }
                    save=i;
                    cnt++;
                }
            }
        }
        if(!cnt){
            puts("No jumping champion");
            continue;
        }
        cnt=0;
        map<int,int>::iterator it=a.begin();
        for(;it!=a.end();it++)
            if(it->second==Max)
                cnt++;
        if(cnt>=2){
            puts("No jumping champion");
            continue;
        }
        printf("The jumping champion is %d\n",sol);
    }


  return 0;
}
