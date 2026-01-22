#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n = 5, m = 3;
    vector<int> a = { 8, 1, 2, 9, 4 };
    sort(a.begin(), a.end());
    int l = 0, r = n - 1, res = 0;
    //1 2 4 8 9
    m = (l + r) / 2;
    while (l <= r) {

    }
    cout << res;
    return 0;
}