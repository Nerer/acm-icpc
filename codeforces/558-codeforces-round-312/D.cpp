#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>

using namespace std;

int h, q;
long long getleft(int nowh, long long x) {
	return x << (h - nowh);
}

long long getright(int nowh, long long x) {
	long long ret = x;
	for (int i = 1; i <= h - nowh; i++)
		ret = (ret << 1) + 1;
	return ret;		
}

int main() {
	scanf("%d%d", &h, &q);
	long long maxr = (1LL << h) - 1;
	long long maxl = 1LL << h - 1;
	vector<pair<long long, long long> > seg;
	for (int i = 1; i <= q; i++) {
		int nowh, flg;
		long long l, r;
		//scanf("%d%lld%lld%d", &nowh, &l, &r, &flg);
		cin >> nowh >> l >> r >> flg;
		long long downl = getleft(nowh, l);
		long long downr = getright(nowh, r);
		if (flg == 0) seg.push_back(make_pair(downl, downr));
		else {
			maxr = min(downr, maxr);
			maxl = max(downl, maxl);
		}
	}
	
	//cout << maxl << " " << maxr <<endl;
	sort(seg.begin(), seg.end());
	//cout << seg[0].first << " " << seg[0].second << endl;
	for (int i = 0; i < (int)seg.size(); i++)
		if (seg[i].first <= maxl && seg[i].second >= maxl) maxl = seg[i].second + 1;
	//cout << maxl << " " << maxr << endl;
	
	for (int i = (int) seg.size() - 1; i >= 0; i--)
		if (seg[i].second >= maxr && seg[i].first <= maxr) maxr = seg[i].first - 1;
	
	if (maxl == maxr) cout << maxl << endl;
	if (maxl > maxr) cout << "Game cheated!" << endl;
	if (maxl < maxr) cout << "Data not sufficient!" << endl;
	return 0; 
}
