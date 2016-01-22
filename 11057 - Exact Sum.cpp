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

int main(){
    while(cin>>N){
        int A[N],ans=oo,value;
        loop(i,N)scn(A[i]);
        sort(A,A+N);
        scn(Q);
        loop(i,N-1){
            if(Q-A[i]<A[N-1]&&Q-A[i]>=A[i]){
                bool found=binary_search(&A[i+1],&A[i+1]+N-i-1,Q-A[i]);
                if(found){
                    int diff=abs(Q-2*A[i]);
                    if(ans>diff){
                        value=A[i];
                        ans=diff;
                    }
                }
            }
            else if(Q-A[i]==A[N-1]){
                int diff=abs(Q-2*A[i]);
                if(ans>diff){
                    value=A[i];
                    ans=diff;
                }
            }
          //  printf("Oh!I am in an infinite loop\n\n");
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",value,Q-value);
    }
  return 0;
}
