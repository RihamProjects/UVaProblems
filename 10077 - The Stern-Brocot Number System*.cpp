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
void BinarySearch(int qe,int qd){
    int Le=0,Ld=1,He=1,Hd=0;
    while(Le*Hd<Ld*He){
        int Me=(Le+He),Md=(Ld+Hd);

        if(Me*qd<qe*Md){
            Le=Me,Ld=Md;
            cout<<'R';
        }
        else if(Me*qd>qe*Md){
            He=Me,Hd=Md;
            cout<<'L';
        }
        else
            return;
    }
}

int main(){
    int qe,qd;
    while(1){
    scn(qe),scn(qd);
    if(qe==1&&qd==1)return 0;
    BinarySearch(qe,qd);
    puts("");
    }
  return 0;
}
