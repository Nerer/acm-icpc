#include <iostream> 
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#define X first
#define Y second
const int MAXN = 3000;
const int N = 300000;
const int MO = (int)1e9 + 7;
typedef long long LL;

using namespace std;

pair<int,int> po[MAXN];
int n, m, k;
LL dp[N], rev[N], factorial[N];
LL mypow(LL x, LL p){
	if (p == 1) return x;
	else
	{
		LL tmp = mypow(x, p >> 1);
		if (p & 1) return (tmp * tmp) % MO * x %MO;
		else return (tmp * tmp % MO);
	}
}
LL calc(int x, int y) {
	int up = x + y ;
	int down = x;
	LL ret = factorial[up] * rev[down] %MO * rev[up - down] % MO;
	return ret;

}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d%d", &po[i].X, &po[i].Y);	
	
	//cout << n << " " << m << endl;
	factorial[0] = 1;
	for (int i = 1; i <= n+m; i++)
		factorial[i] = factorial[i-1] * i % MO;
	rev[0] = 1;
	for (int i = 1; i <= max(n,m); i++)
		rev[i] = mypow(factorial[i],MO-2) % MO;
	
	sort(po + 1, po + k + 1);
	for (int i = 1; i <= n; i++) dp[i] = 0;
	po[k + 1].X = n;po[k + 1].Y = m;
	dp[1] = calc(po[1].X - 1, po[1].Y - 1);
	for (int i = 2; i <= k + 1; i++)
	{
		dp[i] = calc(po[i].X - 1, po[i].Y - 1);
		for (int j = 1; j < i; j++) 
			if (po[j].X <= po[i].X && po[j].Y <= po[i].Y) {
				dp[i] -= dp[j] * calc(po[i].X - po[j].X, po[i].Y - po[j].Y) % MO;
				if (dp[i] < 0) dp[i] = dp[i] + MO;
				if (dp[i] > MO) dp[i] -= MO;
			}
	}
	
	cout << dp[k + 1] << endl;
	return 0;
}
