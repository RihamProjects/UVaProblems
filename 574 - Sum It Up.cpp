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
    #define     p(n)                printf("%d\n",n)
    #define     pL(n)               printf("%I64d ",n)
    #define     Set(v,d)            memset(v, d, sizeof(v))
    #define     loop(i,n)           for(int i=0; i < n; i++)
    #define     rvlop(k,n)          for(int k=n-1; k>=0; k--)
    #define     loopb(i,n,begin)    for(int i=begin; i < n; i++)
    #define     lop(i,v)            for(int i=0; i < sz(v); i++)
    #define     oo                  15  ///infinity

    /********************************-Declarations-*******************************/
    //bitset<oo>prime;
    int t,n,CHECK=0,arr[oo];
    vector<string>save;
    vector<int>sol;
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    void Backtrack(string s,int sum,int indx){
        if(indx==n){
            if(sum==t){
                string tmp,ss;
                CHECK=1;
                lop(i,s)
                    if(s[i]=='1')sol.pb(arr[i]);
                lop(i,sol){
                    stringstream sa; sa<<sol[i];sa>>tmp;
                    ss+=tmp;
                    if(i!=sz(sol)-1)
                        ss+='+';
                }
                lop(i,save)
                    if(save[i]==ss){
                        sol.clear();
                        return;
                    }
                save.pb(ss);
                cout<<ss<<endl;sol.clear();
            }
            return;
        }
        Backtrack(s+'1',sum+arr[indx],indx+1);
        Backtrack(s+'0',sum,indx+1);
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
#ifndef ONLINE_JUDGE
//    freopen("Output.txt","w",stdout);
#endif
    r(t),r(n);
    while(t&&n){
        loop(i,n)r(arr[i]);
        printf("Sums of %d:\n",t);
        Backtrack("",0,0);
        if(!CHECK)
            puts("NONE");
        CHECK=0;
        r(t),r(n);
    }

      return 0;
    }
