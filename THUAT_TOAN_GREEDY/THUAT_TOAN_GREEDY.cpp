#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n, m, X;

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
	cin >> n;
	vector<pair<int, int>> vp(n);
	map<int, int> a;
	int res = 0;
	for (int i = 0; i < n; i++) {
		int dl, pf;
		cin >> dl >> pf;
		vp[i] = {dl, pf};
	}
	sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second > b.second;
		});
	for (int i = 0; i < n; i++) {
		if (a[vp[i].first] == 0) {
			a[vp[i].first] = vp[i].second;
		}
		else {
			int k = vp[i].first;
			while (k > 1) {
				if (a[k - 1] == 0) {
					a[k - 1] = vp[i].second;
					break;
				}
				else k--;
			}
		}
	}

	for (auto item : a) res += item.second;
	cout << res;
	return 0;
}