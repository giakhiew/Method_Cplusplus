#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Query {
    int l, r, id;
};

int a[100005];
int freq[100005];
int ans[100005];
int distinct = 0;
int block;

void add(int x) {
    distinct += freq[x];
    freq[x]++;
}

void remove_(int x) {
    freq[x]--;
    distinct -= freq[x];
}

bool cmp(Query A, Query B) {
    if (A.l / block != B.l / block)
        return A.l < B.l;
    return A.r < B.r;
}

int main()
{
	//dem so lan xuat hien cua x trong doan
        int n, q, x;    
        cin >> n >> q >> x;
        for (int i = 1; i <= n; i++) cin >> a[i];

        vector<Query> queries(q);
        for (int i = 0; i < q; i++) {
            cin >> queries[i].l >> queries[i].r;
            queries[i].id = i;
        }

        block = sqrt(n);
        sort(queries.begin(), queries.end(), cmp);

        int curL = 1, curR = 0;

        for (auto& item : queries) {
            while (curL > item.l) add(a[--curL]);
            while (curR < item.r) add(a[++curR]);
            while (curL < item.l) remove_(a[curL++]);
            while (curR > item.r) remove_(a[curR--]);

            ans[item.id] = distinct;
        }

        for (int i = 0; i < q; i++) cout << ans[i] << '\n';
	return 0;
}