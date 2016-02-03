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
    #define     r(n)                scanf("%d",&n)
    #define     rL(n)               scanf("%I64d",&n)
    #define     p(n)                printf("%d ",n)
    #define     pL(n)               printf("%I64d ",n)
    #define     Set(v,d)            memset(v, d, sizeof(v))
    #define     loop(i,n)           for(int i=0; i < n; i++)
    #define     rvlop(k,n)          for(int k=n-1; k>=0; k--)
    #define     loopb(i,n,begin)    for(int i=begin; i < n; i++)
    #define     lop(i,v)            for(int i=0; i < sz(v); i++)
    #define     oo                  33  ///infinity

    /********************************-Declarations-*******************************/
    //bitset<oo+1>prime;
    int primes[]={2,3,5,7,11,13,17,19,23,29,31,37,41,47},ans[20]={1};
    bitset<20>visit;
    int n,cnt=0;
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    bool isPrime(int a){
        for(int i=0;i<14;i++)
            if(primes[i]==a)return true;
        return false;
    }
    void Backtrack(int indx){
        if(indx==n){
            if(!isPrime(1+ans[n-1]))return;
            loop(i,n-1)p(ans[i]);
            printf("%d",ans[n-1]);
            puts("");
            return;
        }
        for(int i=2;i<=n;i++){
            if(!visit[i])
                if(isPrime(i+ans[indx-1])){
                    visit[i]=1;
                    ans[indx]=i;
                    Backtrack(indx+1);
                    visit[i]=0;
                }
        }
    }

    int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
    int lcm(int a, int b) { return a * (b / gcd(a, b)); }
    ll Ipow(int base,int exp)
        {ll result = 1;
        while(exp)
        {if(exp & 1)result*=base;
            exp>>=1;base*=base;}
        return result;}

    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

    int main(){
//    freopen("Output.txt","w",stdout);
    while(r(n)==1){
        if(cnt)
            puts("");
        printf("Case %d:\n",++cnt);
        Backtrack(1);
    }
    return 0;
    }
