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
bool rw[30],ld[15],rd[15];
int row[8],Min=oo;

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*Functions*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/
void Backtrack(int c,int sum){
    if(c==8){
        Min=min(Min,sum);
        return;
    }
    loop(r,8){
        if(!rw[r]&&!ld[r-c+7]&&!rd[r+c]){
            rw[r]=ld[r-c+7]=rd[r+c]=true;
            int x=(r!=row[c]);
            Backtrack(c+1,sum+x);
            rw[r]=ld[r-c+7]=rd[r+c]=false;
        }
    }
}

/**-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-**/

int main(){
//    freopen("Output.txt","w",stdout);
    int cnt=0;
while(scanf("%d %d %d %d %d %d %d %d",
            &row[0],&row[1],&row[2],&row[3],&row[4],&row[5],&row[6],&row[7]) != EOF){
        loop(i,8)row[i]--;

        Backtrack(0,0);
        printf("Case %d: %d\n",++cnt,Min);
        Min=oo;
        Set(rw,0),Set(ld,0),Set(rd,0);
    }


  return 0;
}
