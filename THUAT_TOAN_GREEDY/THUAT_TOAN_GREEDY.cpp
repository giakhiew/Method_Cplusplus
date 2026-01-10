#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, X;
vector<int> d(n);

struct Job {
	int deadline, profit;
};

void Bai1() {
	vector<int> d(n);
	for (int i = 0; i < n; i++) cin >> d[i];
	int res = 0, i = 0;
	sort(d.begin(), d.end(), greater<int>());
	while (X > 0) {
		if (X / d[i] > 0) {
			int sumtmp = X / d[i];
			res += sumtmp;
			X -= sumtmp * d[i];
			i++;
		}
		else {
			i++;
		}
	}
	cout << res;
}

void Bai2() {
	vector<pair<int, int>> vp(n);
	int start, end;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		vp[i] = { start, end };
	}

	sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second < b.second;
		});

	int res = 1, i = 0;
	for (int j = 1; j < n; j++) {
		if (vp[i++].second < vp[j].first) res++;
	}
	cout << res;
}

int main()
{
	cin >> n >> m;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	return 0;
}