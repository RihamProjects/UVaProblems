#include <bits/stdc++.h>
using namespace std;
#define oo 10000000000000000
typedef long long    ll;
const int N = 303;
ll n;
 
 
int main() {
//    #ifndef ONLINE_JUDGE
//        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
//    #endif // ONLINE_JUDGE
    int TC;
    scanf("%d", &TC);
    while(TC--){
        scanf("%lld", &n);
        ll ans = n/2;
        printf("%lld\n", ans);
    }
    return 0;
}
