#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
int a1, a2, a3, b1, b2 ,b3;
bool check() {
	if (a2 + a3 <= a1 && max(b2, b3) <= b1) return 1;
	if (a2 + b3 <= a1 && max(a3, b2) <= b1) return 1;
	if (b2 + b3 <= a1 && max(a2, a3) <= b1) return 1;
	if (b2 + a3 <= a1 && max(a2, b3) <= b1) return 1;
	swap(a1,b1);
	if (a2 + a3 <= a1 && max(b2, b3) <= b1) return 1;
	if (a2 + b3 <= a1 && max(a3, b2) <= b1) return 1;
	if (b2 + b3 <= a1 && max(a2, a3) <= b1) return 1;
	if (b2 + a3 <= a1 && max(a2, b3) <= b1) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &a1, &b1);
	scanf("%d%d", &a2, &b2);
	scanf("%d%d", &a3, &b3);
	if (check()) puts("YES");
	else puts("NO");
	return 0;
}
