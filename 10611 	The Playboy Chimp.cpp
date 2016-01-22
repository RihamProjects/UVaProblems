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
    scn(N);
    ll A[N],q;
    loop(i,N)cin>>A[i];
    scn(Q);
    loop(i,Q){
        cin>>q;
        int low=(lower_bound(A,A+N,q)-A)-1;
        int high=upper_bound(A,A+N,q)-A;
        if(low!=-1&&high!=N)
            cout<<A[low]<<" "<<A[high]<<endl;
        else if(low!=-1)
            cout<<A[low]<<" X\n";
        else if(high!=N)
            cout<<"X "<<A[high]<<endl;
        else
            cout<<"X X\n";
    }
  return 0;
}
