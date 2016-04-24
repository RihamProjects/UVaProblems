#include <bits/stdc++.h>
using namespace std;

#define OO 1000000000000000007
#define oo 1000000007
typedef long long    ll;

const int N = 2000;
map<string, int>d;
map<string, vector<string> >adj;


void BFS(string source, string dest){
    queue<string>q;
    q.push(source);
    d[source] = 0;

    while(!q.empty()){
        string u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            string v = adj[u][i];
            if(d.count(v) == 0){
                d[v] = d[u] + 1;
                if(v == dest) return;
                q.push(v);
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    int TC, cnt = 0;
    scanf("%d", &TC);
    puts("SHIPPING ROUTES OUTPUT");
    while(TC--){
        printf("\nDATA SET  %d\n\n", ++cnt);
        int V, E, P;
        scanf("%d%d%d", &V, &E, &P);
        for(int i=0;i<V;i++) {
            string s;
            cin >> s;
        }

        for(int i=0;i<E;i++) {
            string f, t;
            cin >> f >> t;
            adj[f].push_back(t);
            adj[t].push_back(f);
        }

        for(int i=0;i<P;i++) {
            int cost; string f, t;
            cin >> cost >> f >> t;
            d.clear();
            BFS(f, t);
            if(d.count(t) > 0)
                printf("$%d\n", d[t]*100*cost);
            else puts("NO SHIPMENT POSSIBLE");
        }
        adj.clear();
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}
