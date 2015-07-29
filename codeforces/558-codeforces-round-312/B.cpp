#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1000000 + 10;
const int N = 200000;

int a[N], start[MAXN], finish[MAXN], sum[MAXN];
int n;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	memset(start, 0, sizeof start);
	memset(finish, 0, sizeof finish);
	memset(sum, 0, sizeof sum); 
	int maxn = 0;
	for (int i = 1; i <= n; i++) {
		if (!start[a[i]]) start[a[i]] = i;
		++sum[a[i]];
		if (sum[a[i]] > maxn) maxn = sum[a[i]];
		finish[a[i]] = i;
	}
	
	int ans = MAXN, ansl = 1, ansr = n;
	for (int i = 1; i <= n; i++) {
		if (sum[a[i]] < maxn) continue;
		if (finish[a[i]] - start[a[i]] < ans) {
			ans = finish[a[i]] - start[a[i]];
			ansl = start[a[i]];
			ansr = finish[a[i]];
		}
	}
	cout << ansl << " " << ansr <<endl;
	return 0;
}
	
