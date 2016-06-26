#define _CRT_SECURE_NO_WARNINGS
//#include "AllClasses.h"
#include <bits/stdc++.h>
using namespace std;

#define OO 1000000000000000007
#define oo 1000000007
typedef long long    ll;
typedef unsigned long long    ull;
typedef long double    ld;

const int N = 15;
string in;
struct Comp {
	bool operator()  (string a, string b) {
		for (int i = 0; i<a.size(); i++)for (int j = 0; j<b.size(); j++) {
			if (a[i] == b[i]) continue;
			if (tolower(a[i]) == tolower(b[i])) {
				return (b[i] == tolower(b[i])) ? 1 : 0;
			}
			else return (tolower(a[i]) <= tolower(b[i]));
		}
	}
};

set<string, Comp>st;
void Solve(string s) {
	sort(s.begin(), s.end());
	do {
		st.insert(s);
	} while (next_permutation(s.begin(), s.end()));
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
	int k;
	scanf("%d", &k);
	for (int i = 0; i<k; i++) {
		cin >> in;
		Solve(in);
		for (auto i = st.begin(); i != st.end(); i++) cout << *i << endl;
		st.clear();
	}
	return 0;
}

