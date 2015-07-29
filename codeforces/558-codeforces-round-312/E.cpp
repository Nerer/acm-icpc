#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>

#define lc (x << 1)
#define rc ((lc) + 1)

using namespace std;

const int MAXN = 222222;

int n, m;

int tag[26][MAXN * 4], T[26][MAXN * 4];

void update(int id, int x ,int range) {
	if (tag[id][x] > -1) {
		T[id][x] = tag[id][x] * range;
		if (range > 1) {
			tag[id][lc] = tag[id][x];
			tag[id][rc] = tag[id][x];
		}
		tag[id][x] = -1;
	}
}

void seg_clear(int id, int x, int l, int r, int ql, int qr) {
	update(id, x, r - l + 1);
	if (ql <= l && qr >= r) {
		tag[id][x] = 0;
		update(id, x, r - l + 1);	
		return;
	}
	else {
		int mid = (l + r) >> 1;
		if (ql <= mid) seg_clear(id, lc, l, mid, ql, qr);
		if (qr > mid) seg_clear(id, rc, mid + 1, r, ql, qr);
		if (r > l) {
			update(id, lc, mid - l + 1);
			update(id, rc, r - mid);
			T[id][x] = T[id][lc] + T[id][rc];
		}
	}	
}

int	 seg_calc(int id, int x, int l, int r, int ql, int qr) {
	update(id, x, r - l + 1);
	if (ql <= l && qr >= r) {
		return T[id][x];
	}
	else {
		int mid = (l + r) >> 1, ret = 0;
		if (ql <= mid) ret += seg_calc(id, lc, l, mid, ql, qr);
		if (qr > mid) ret += seg_calc(id, rc, mid + 1, r, ql, qr);
		if (r > l) {
			update(id, lc, mid - l + 1);
			update(id, rc, r - mid);
			T[id][x] = T[id][lc] + T[id][rc];
		}
		return ret;
	}

}

void seg_add(int id, int x, int l, int r, int ql, int qr) {
	update(id, x, r - l + 1);

	if (ql <= l && qr >= r) {
		tag[id][x] = 1;
		update(id, x, r - l + 1);
	}
	else {
		int mid = (l + r) >> 1;
		if (ql <= mid) seg_add(id, lc, l, mid, ql, qr);
		if (qr > mid) seg_add(id, rc, mid + 1, r, ql, qr);
		if (r > l) {
			update(id, lc, mid - l + 1);
			update(id, rc, r - mid);
			T[id][x] = T[id][lc] + T[id][rc];
		}
	}
} 

char ans[MAXN];
int main() {
	scanf("%d%d", &n, &m);
	char str[MAXN];
	
	scanf("%s",str + 1);
	
	memset(tag, -1, sizeof tag);
	for (int i = 1; i <= n; i++)
		seg_add(str[i] - 'a', 1, 1, n, i, i);
	
	for (int i = 1; i <= m; i++) {
		int ql, qr, flg;
		scanf("%d%d%d", &ql, &qr, &flg);
		if (flg == 1) {
			int now = ql;
			for (int ch = 0; ch <= 25; ch++) {
				int range = seg_calc(ch, 1, 1, n, ql, qr);
				if (range) {
					seg_clear(ch, 1, 1, n, ql, qr);
					seg_add(ch, 1, 1, n, now, now + range - 1);
					now += range;
				}
			}
		}
		else {
			int now = ql;
			for (int ch = 25; ch >= 0; ch--) {
				int range = seg_calc(ch, 1, 1, n, ql, qr);
				if (range) {
					seg_clear(ch, 1, 1, n, ql, qr);
					seg_add(ch, 1, 1, n, now, now + range -1);
					now += range;					
				}
			}
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= 25; j++)
			if (seg_calc(j, 1, 1, n, i, i)) {
				ans[i] = j + 'a';
				break;
			}
	
	
	for (int i = 1; i <= n; i++) putchar(ans[i]);
	puts("");
	
	return 0;
}
