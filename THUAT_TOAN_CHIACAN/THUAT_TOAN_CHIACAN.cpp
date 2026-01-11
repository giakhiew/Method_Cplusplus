#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cn = floor(sqrt(n));
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> block_sum(cn + 1, 0);
	for (int i = 0; i < cn; i++) {
		int l = cn * i, r = (i + 1) * cn - 1;
		r = min(r, n);
		while (l <= r) block_sum[i] += a[l++];
	}
	for (auto item : block_sum) cout << item << ' ';
	return 0;
}