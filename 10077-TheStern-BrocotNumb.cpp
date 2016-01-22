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
vector<int>L;
void Stern_Brocot_tree(int qe,int qd){
    L.pb(qe/qd);
    int z=(qe%qd);
    if(!z)return;
    Stern_Brocot_tree(qd,z);
}


int main(){
    int qe,qd;
    while(1){
    scn(qe),scn(qd);
    if(qe==1&&qd==1)return 0;
    Stern_Brocot_tree(qe,qd);
    bool exit=true;
    lop(i,L){
        if(i==sz(L)-1){
            loop(j,L[i]-1){
                if(exit) cout<<'R';
                else cout<<'L';
            }
            break;
        }
        loop(j,L[i]){
            if(exit) cout<<'R';
            else cout<<'L';
        }
        exit=!exit;
    }
    L.clear();
    puts("");
    }
  return 0;
}
