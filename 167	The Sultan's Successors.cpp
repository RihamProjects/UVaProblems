#include <bits/stdc++.h>
using namespace std;

/**-----------------------------------**---------------------------------**/
typedef     long long           ll;
typedef     long double         Ld;
#define     sz(v)               ((int)((v).size()))
#define     all(v)              (v.begin()),(v.end())
#define     pb(a)               push_back(a)
#define     r(n)              scanf("%d",&n)
#define     rL(n)              scanf("%I64d",&n)
#define     p(n)            printf("%d\n",n)
#define     pL(n)            printf("%I64d\n",n)
#define     set(v,d)            memset(v, d, sizeof(v))
#define     loop(i,n)           for(int i=0; i < n; i++)
#define     rvlop(k,n)         for(int k=n-1; k>0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  100300  ///infinity

/**------------------------------------**--------------------------------**/
ll Ipow(ll base, ll exp)
{
    ll result = 1;
    while (exp)
    {
        if (exp & 1){
            result *= base%oo;
            result%=oo;
        }
        exp >>= 1;
        base *= base%oo;
        base%=oo;
    }

    return result%oo;
}
ll l,t,m,s[100005];
bool Ok(ll s[],ll mid){
    if(mid>=m+l)
        return (s[mid]+s[mid-m] <= t);
    return (t >= s[mid]);
}

bool rw[30],ld[15],rd[15];
int board[8][8],Max=-oo,sum=0;
void Backtrack(int c,int sum){
    if(c==8){
        Max=max(Max,sum);
        return;
    }
    loop(r,8){
        if(!rw[r]&&!ld[r-c+7]&&!rd[r+c]){
            rw[r]=ld[r-c+7]=rd[r+c]=true;
            Backtrack(c+1,sum+board[r][c]);
            rw[r]=ld[r-c+7]=rd[r+c]=false;
        }
    }
}

int main(){
    int k,x;
    r(k);
    while(k--){
        loop(i,8)loop(j,8){
            r(x);
            board[i][j]=x;
        }
        set(rw,0);
        set(ld,0);
        set(rd,0);
        Backtrack(0,0);
        cout<<setw(5)<<setiosflags(ios::right)<<Max<<endl;
        Max=-oo;
    }



  return 0;
}
