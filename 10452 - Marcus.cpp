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
    #define     oo                  30  ///infinity

    /********************************-Declarations-*******************************/
    //bitset<oo>prime;
    int n,m,T,stI,stJ;
    char x,arr[10][10];
    string word="@IEHOVA#";
    /**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
    bool valid(int r,int c){return (r>=0&&c>=0&&r<n&&c<m);}

    void Backtrack(string s,int r,int c,int indx){
        if(indx==7){
            lop(i,s){
                if(s[i]=='f')(i==sz(s)-1)? printf("forth") : printf("forth ");
                else if(s[i]=='r')(i==sz(s)-1)? printf("right") : printf("right ");
                else (i==sz(s)-1)? printf("left") : printf("left ");
            }
            return;
        }
        if(valid(r-1,c)&&arr[r-1][c]==word[indx+1])
            Backtrack(s+'f',r-1,c,indx+1);
        else if(valid(r,c+1)&&arr[r][c+1]==word[indx+1])
            Backtrack(s+'r',r,c+1,indx+1);
        else if(valid(r,c-1))
            Backtrack(s+'l',r,c-1,indx+1);
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
    r(T);
    while(T--){
        r(n),r(m);
        loop(i,n)
            cin>>arr[i];
        loop(i,m)
            if(arr[n-1][i]=='@'){stJ=i;break;}
        Backtrack("",n-1,stJ,0);
        puts("");
    }

      return 0;
    }
