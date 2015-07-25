#include <iostream>
#include <cstdio>
#include <algorithm>

const int MAXN = 2000;

using namespace std;

int n, a[MAXN];
 
int main(){
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	sort(a + 1, a + n + 1);
	if (a[1] == 1) puts("-1");
	else puts("1");
	
	return 0;
}

