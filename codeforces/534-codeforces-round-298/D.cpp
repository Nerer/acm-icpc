#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <ctime>
#include <climits>
using namespace std;
const int MAXN = 300010;
int step[MAXN], flg = 0, n;
int vis[MAXN] ,counter = 0;
int begin[MAXN], finish[MAXN];
pair<int, int> b[MAXN];
int a[MAXN];

int start;

void dfs(int x, int dep) {
	step[dep] = x;
	if (dep == n) {
		flg = 1;
		return;
	}
	if (begin[a[x] + 1])
	for (int i = begin[a[x] + 1]; i <= finish[a[x] + 1]; i++) {
		if (!vis[b[i].second]) {
			vis[b[i].second] = 1;
			begin[a[x] + 1] = i + 1;
			dfs(b[i].second, dep + 1);
			return;
		}
	}
	
	for (int j = 1; j * 3 <= a[x] + 1; j++) {
		if (begin[a[x] + 1 - j * 3])
		for (int i = begin[a[x] + 1 - j * 3]; i <= finish[a[x] + 1 - j * 3]; i++) {
			if (!vis[b[i].second]) {
			vis[b[i].second] = 1;
			begin[a[x] + 1 - j * 3] = i + 1;
			dfs(b[i].second, dep + 1);
			return;
		}
	}
	}
}

int main() {
start = clock();

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) b[i] = make_pair(a[i], i);

	sort(b + 1, b + n + 1);
	
	for (int i = 1; i <= n; i++) {
		if (!begin[b[i].first]) begin[b[i].first] =i;
		if (b[i].first != b[i + 1].first || i == n) finish[b[i].first] = i;
	}		
	
	
	int source = -1;
	
	for (int i = 1; i <= n; i++)
		if (a[i] == 0) {
			source = i;
			break;
		}
	
	if (source > 0) {
		vis[source] = 1;
		dfs(source, 1);
	}
	
	if (flg) {
		puts("Possible");
		for (int i = 1; i < n; i++) printf("%d ",step[i]);
		printf("%d\n", step[n]);
	}
	else puts("Impossible");
	
	return 0;
}
