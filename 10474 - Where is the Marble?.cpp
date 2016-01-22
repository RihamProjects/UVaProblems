#include <bits/stdc++.h>
using namespace std;

/**-----------------------------------**---------------------------------**/
typedef     long long           ll;
typedef     long double         ld;
#define     sz(v)               ((int)((v).size()))
#define     all(v)              (v.begin()),(v.end())
#define     pb(a)               push_back(a)
#define     scn(n)              scanf("%d",&n)
#define     print(n)            printf("%d ",n)
#define     set(v,d)            memset(v, d, sizeof(v))
#define     loop(i,n)           for(int i=0; i < n; i++)
#define     rvlop(k,n)         for(int k=n-1; k>=0; k--)
#define     loopb(i,n,begin)     for(int i=begin; i < n; i++)
#define     lop(i,v)            for(int i=0; i < sz(v); i++)
#define     oo                  (ll)(1e8) ///infinity
/**------------------------------------**--------------------------------**/
int N,Q;

int BinarySearch(int A[],int q){
    int L=0,H=N-1;
    while(L<H){
        int mid=(H+L)/2;
        if(A[mid]<q)
            L=mid+1;
        else if(A[mid]>=q)
            H=mid;
    }
    if(A[L]==q)return L+1;
    return -1;
}

int main(){
    int cnt=0;

    while(1){
        scn(N),scn(Q);
        int A[N];

        if(N==0&&Q==0)return 0;

        loop(i,N)scn(A[i]);

        sort(A,A+N);
        printf("CASE# %d:\n",++cnt);

        loop(i,Q){
            int x,q;
            scn(q);
            x=BinarySearch(A,q);

            if(x!=-1)printf("%d found at %d\n",q,x);
            else printf("%d not found\n",q);

        }
    }

  return 0;
}
