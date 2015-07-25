#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int a[10];
int sqr(int x) {
	return x * x;
}
int main() {
	for (int i = 1; i <= 6; ++i) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	ans += sqr(a[1] + a[2] + a[3]) - sqr(a[1]) - sqr(a[3]) - sqr(a[5]);	
	
	cout<<ans<<endl;
		
	return 0;
}
