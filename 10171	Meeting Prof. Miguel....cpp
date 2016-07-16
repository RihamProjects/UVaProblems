#include <bits/stdc++.h>
using namespace std;
#define oo 1000000007
#define ll long long
#define ld long double
const int N = 30;
int n;
vector<pair<int, int>>Yadj[N], Madj[N];
int MDijkestra(int s, int e){
    priority_queue<pair<int, int>>pq;
    vector<int>d(30, oo);
    pq.push({0, s});
    d[s]=0;
    while(!pq.empty()){
        int Cur = pq.top().second, dist = pq.top().first;
        pq.pop();
        if(dist > d[Cur]) continue;
        for(int i=0;i<Madj[Cur].size();i++){
            int ch = Madj[Cur][i].first, Cost = Madj[Cur][i].second;
            if(d[Cur] + Cost < d[ch]){
                d[ch] = d[Cur] + Cost;
                pq.push({d[ch], ch});
            }
        }
    }
    return d[e];
}int YDijkestra(int s, int e){
    priority_queue<pair<int, int>>pq;
    vector<int>d(30, oo);
    pq.push({0, s});
    d[s]=0;
    while(!pq.empty()){
        int Cur = pq.top().second, dist = pq.top().first;
        pq.pop();
        if(dist > d[Cur]) continue;
        for(int i=0;i<Yadj[Cur].size();i++){
            int ch = Yadj[Cur][i].first, Cost = Yadj[Cur][i].second;
            if(d[Cur] + Cost < d[ch]){
                d[ch] = d[Cur] + Cost;
                pq.push({d[ch], ch});
            }
        }
    }
    return d[e];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    while(scanf("%d", &n), n){
        unordered_set<int>x;
        for(int i=0;i<n;i++){
            char y, u, a, b;int c;
            scanf(" %c %c %c %c %d", &y, &u, &a, &b, &c);
            x.insert(int(a-'A'));
            x.insert(int(b-'A'));
            if(y == 'Y'){
                if(u == 'U')
                    Yadj[int(a-'A')].push_back({int(b-'A'), c});
                else{
                    Yadj[int(a-'A')].push_back({int(b-'A'), c});
                    Yadj[int(b-'A')].push_back({int(a-'A'), c});
                }
            }else{
                if(u == 'U')
                    Madj[int(a-'A')].push_back({int(b-'A'), c});
                else{
                    Madj[int(a-'A')].push_back({int(b-'A'), c});
                    Madj[int(b-'A')].push_back({int(a-'A'), c});
                }
            }
        }
        char s, e;
        scanf(" %c %c", &s, &e);
        int start = int(s-'A'), End = int(e - 'A');
        x.insert(start), x.insert(End);
        set<pair<int, char>>st;
        for(auto i = x.begin(); i != x.end(); i++){
            int M=MDijkestra(End, *i),Y=YDijkestra(start, *i);
            st.insert({M+Y, char(*i + 'A')});
        }

        for(auto i = x.begin(); i != x.end(); i++){
            Madj[*i].clear(), Yadj[*i].clear();
        }
        auto i = st.begin();
        if(i->first == oo)
            printf("You will never meet.\n");
        else{
            printf("%d", i->first);
            int Mn = i->first;
            while(Mn == i->first)
                printf(" %c", i->second),i++;
            puts("");
        }
    }
	return 0;
}
