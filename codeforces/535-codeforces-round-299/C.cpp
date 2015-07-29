#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int A, B, n;

bool check(int l, int tim, int m, int now) {
	long long sum = 0;
	if (tim < (long long)A + (long long)(now - 1) * B) return 0;
	sum = (long long) tim * min(now - l + 1, m);
	long long tmp;
	tmp = (long long) (2 * A + (long long)(l - 1) * B + (long long)(now - 1) * 	B) * (long long)(now - l + 1) / 2;
	if (sum < tmp) return 0;
	return 1;
}

int main() {
	cin >> A >> B >> n;
	for (int i = 1; i <= n; i++) {
		int l, t, m;
		scanf("%d%d%d", &l, &t, &m);
		int down = l, up = l + 10000000;
		while (down < up) {
			//cout << down << " " << up << endl;
			int mid = (up + down) >> 1;
			if (check(l, t, m ,mid)) down = mid + 1;
			else up = mid;
		}
		if (down == l) puts("-1");
		else printf("%d\n", down - 1);
	}
}

