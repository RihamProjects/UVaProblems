#include <bits/stdc++.h>
using namespace std;
#define oo 10000000000000000
typedef long long    ll;
const int N = 303;
ll n;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE
    int TC;
    scanf("%d", &TC);
    while(TC--){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a == gcd(a, b) && b == lcm(a, b))
            printf("%d %d\n", a, b);
        else printf("-1\n");
    }
    return 0;
}
