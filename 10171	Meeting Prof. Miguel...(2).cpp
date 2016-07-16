#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 27;
int Madj[N][N], Yadj[N][N];
int Build(int n){
    char m, u, a, b; int c;
    while(n--){
        scanf(" %c %c %c %c %d", &m, &u, &a, &b, &c);
        if(m == 'M'){
            if(u == 'U')
                Madj[a-'A'][b-'A'] = c;
            else
                Madj[a-'A'][b-'A'] = Madj[b-'A'][a-'A'] = c;
        } else{
            if(u == 'U')
                Yadj[a-'A'][b-'A'] = c;
            else
                Yadj[a-'A'][b-'A'] = Yadj[b-'A'][a-'A'] = c;
        }
    }
}
void FloydWarshall(int adj[][N]){
    for(int k=0;k<26;k++)
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                adj[i][j] = min(adj[i][k] + adj[k][j], adj[i][j]);
}
void Relax(set<pair<int, int>>&st, int s, int e){
    Yadj[s][s] = 0, Madj[e][e] = 0;
    for(int i=0;i<26;i++)
        st.insert({Yadj[s][i] + Madj[e][i], i});
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    int n;
    set<pair<int, int>>st;
    while(scanf("%d", &n), n){
        for(int i=0;i<26;i++)for(int j=0;j<26;j++) Madj[i][j] = Yadj[i][j] = oo;
        Build(n);
        FloydWarshall(Madj);
        FloydWarshall(Yadj);
        char s, e;
        scanf(" %c %c", &s, &e);
        Relax(st, int(s-'A'), int(e-'A'));
        auto i = st.begin();
        if(i->first >= oo)
            printf("You will never meet.\n");
        else{
            int Mn = i->first;
            printf("%d", Mn);
            while(i->first == Mn)
                printf(" %c", i->second+'A'), i++;
            printf("\n");
        }
        st.clear();
    }
	return 0;
}
