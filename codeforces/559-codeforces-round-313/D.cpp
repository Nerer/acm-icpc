#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef unsigned long long LL;
const int MAXL = 300000;
const LL M = (LL)1e9 + 7; 
using namespace std;

char s1[MAXL], s2[MAXL];
bool check(int l1, int r1, int l2, int r2){
	//cout<<l1<<" "<<r1;
	//system("pause");
	int f = 1	;
	for (int i = 1; i <= r1 - l1 + 1; i++)
		if (s1[i + l1 -1] != s2[l2 + i- 1]) {
			f = 0;
			break;
		}
	if (f) return 1;
	if ((r1 - l1 + 1) & 1) return 0;
	return check(l1, (r1 + l1) >> 1, l2, (r2 + l2) >> 1) && check((r1 + l1 + 1) >> 1, r1, (r2 + l2 + 1) >> 1, r2) ||
		   check(l1, (r1 + l1) >> 1, (r2 + l2 + 1) >> 1, r2) && check((r1 + l1 + 1)>> 1, r1, l2, (r2 + l2) >> 1);
}
int main() {
	scanf("%s%s",s1+1,s2+1);
	
	int len = strlen(s1 + 1);
	int l=len;
	bool flg = check(1,len,1,len);
	
	if (!flg) puts("NO");
	else puts("YES");
	return 0;
}

