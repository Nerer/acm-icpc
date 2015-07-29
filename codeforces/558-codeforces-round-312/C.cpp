#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int MAXN = 200000;
const int inf = (1 << 30);
int n, a[MAXN], inq[MAXN], opt[MAXN], ok[MAXN];
int main() {
	scanf("%d", &n);
	int lmt = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		lmt = max(lmt, a[i]);
	}
	
	//cout << "ok" <<endl;
	for (int i = 1; i <= n; i++) {
		queue<pair<int, int> > Q;
		Q.push(make_pair(a[i], 0));
		inq[a[i]] = i;
		while (!Q.empty()) {
			pair<int, int> t = Q.front();
			opt[t.first] += t.second;
			ok[t.first] ++;
			//cout << t.first << " " << t.second << endl; 
			Q.pop();
			if (inq[t.first >> 1] != i) Q.push(make_pair(t.first >> 1, t.second + 1)), inq[t.first >> 1] = i;
			if ((t.first << 1) <= lmt) 
				if (inq[t.first << 1] != i) 
					Q.push(make_pair(t.first << 1, t.second + 1)), inq[t.first << 1] = i;
		}
	}
	int ans = inf;
	for (int  i = 1; i <= lmt; i++) if (ok[i] == n) ans = min(ans, opt[i]);
	cout << ans << endl;
	return 0;
}
