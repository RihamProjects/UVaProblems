#include<bits/stdc++.h>
using namespace std;

#define oo (int)1e5
#define F first
#define S second

const int N = 101;
vector<int> divisors(int n) { //length
	vector<int> a;
	for (int i = 1; i * i <= n; i++) {
		if (!(n % i)) {
			a.push_back(i);
			if (i != n / i)
				a.push_back(n / i);
		}
	}
	return a;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // ONLINE_JUDGE
	string s;
	while (cin >> s) {
		if (s == ".")
			break;
		vector<int> ans = divisors((int) s.size());
		sort(ans.begin(), ans.end());
		for (int i = 0; i < (int) ans.size(); i++) {
			int Cur = ans[i];
			string temp1, temp2;
			for (int q = 0; q < Cur; q++) {
				temp1 += s[q];
			}
			bool found = 1;
			for (int j = Cur; j < (int) s.size();) {
				temp2 = "";
				for (int q = 0; q < Cur; q++) {
					temp2 += s[j++];
				}
				if (temp1 != temp2) {
					found = 0;
					break;
				}
			}
			if (found) {
				cout << (int) s.size() / ans[i] << endl;
				break;
			}
		}
	}
	return 0;
}
