#include <bits/stdc++.h>
using namespace std;

#define OO 1000000000000000007
#define oo 1000000007
typedef long long    ll;
typedef unsigned long long    ull;
typedef long double    ld;

const int N = 15;
int k, x[N], Cur = 0; vector<vector<int>>ans;
int NumberOfOnes(string s){
    int cnt = 0;
    for(auto i : s) if(i == '1') cnt++;
    return cnt;
}

void Push(string s){
    vector<int>temp;
    for(int i=0;i<s.size();i++)
        if(s[i] - '0') temp.push_back(x[i]);
    ans.push_back(temp);
}
void Solve(string s){
    if(s.size() == k){
        if(NumberOfOnes(s) == 6)
            Push(s);
        return;
    }
    Solve(s + '1'); Solve(s + '0');
}

ostream& operator<<(ostream& out, vector<int> an){
    for(int i=0;i<an.size() - 1;i++)
        out << an[i] << " ";
    out << an.back() << endl;
    return out;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    scanf("%d", &k);
    while(k){
        Cur = 0;
        for(int i=0;i<k;i++)scanf("%d", x + i);
        Solve("");
        for(int i = 0;i<ans.size();i++) cout << ans[i];
        scanf("%d", &k);
        if(k)  {
            puts("");
            for(int i = 0;i<ans.size();i++) ans[i].clear();
            ans.clear();
        }
    }
	return 0;
}
