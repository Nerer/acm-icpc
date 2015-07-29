#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1000;
int n;

struct Tree{
	int pos, val;
}po[MAXN], po2[MAXN];


bool cmp(Tree p1, Tree p2){
	return p1.pos < p2.pos;
}
int go(int start, int d) {
	int now = start;
	int ret = 0;
	while (now >= 1 && now <= n) {
		now += d;
		if (po[now].val > 0) ret += po[now].val, po[now].val = 0, d = -d;
	}
	return ret;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d %d", &po[i].pos, &po[i].val);
	++n;
	po[n].pos = 0;
	po[n].val = 0;
	sort(po + 1, po + n + 1, cmp);	
	for (int i = 1; i <= n; i++) po2[i] = po[i];
	int mark = 0;
	for (int i = 1; i <= n; i++)
		if (po[i].pos == 0) {
			mark = i;
			break;
		}
	int ans = 0;
	ans = go(mark, 1);
	for (int i = 1; i <= n; i++) po[i] = po2[i];
	ans = max(ans, go(mark, -1));
	cout << ans << endl;

	return 0;
}


