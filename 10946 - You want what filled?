#include <bits/stdc++.h>
using namespace std;

#define OO 1000000000000000007
#define oo 1000000007
typedef long long    ll;
typedef unsigned long long    ull;
typedef long double    ld;

const int N = 53;
int di[] = {1, 0, -1, 0}, dj[] = {0, 1, 0, -1}, n, m, Cur = 0; char CurChar;
bool visited[N][N];
char s[N][N];

bool valid(int i, int j){
    return (i>=0 && j>=0 && i<n && j<m && CurChar == s[i][j]);
}

void dfs(int I, int J){
    Cur++;
    visited[I][J] = 1;
    for(int i=0;i<4;i++){
        int childi = I+di[i], childj = J+dj[i];
        if(!visited[childi][childj] && valid(childi, childj))
            dfs(childi, childj);
    }
}

ostream& operator <<(ostream& out, pair<int, char>a){
    out << a.second << " " << a.first << endl;
    return out;
}
bool comp(pair<int, char>a, pair<int, char>b){
    if(a.first == b.first)
        return a.second > b.second;
    return a.first < b.first;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
int cnt = 0;
while(scanf("%d%d", &n, &m) == 2, n && m){
    printf("Problem %d:\n", ++cnt);
    vector<pair<int, char> >ans;
    memset(visited, 0, sizeof visited);
    for(int i=0;i<n;i++) scanf("%s", s + i);
    for(int i = 0;i<n;i++) for(int j=0;j<m;j++){
        if(!visited[i][j] && s[i][j] != '.'){
            Cur = 0;CurChar = s[i][j];
            dfs(i, j);
            ans.push_back({Cur, s[i][j]});
        }
    }
    sort(ans.begin(), ans.end(), comp);
    while(!ans.empty()){ cout << ans.back(); ans.pop_back(); }
}
	return 0;
}
