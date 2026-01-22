#include <iostream>
#include <vector>
using namespace std;

void VD2() {
    int n = 6;
    int res = -1;
    vector<int> dp, a = { 8, 3, 5, 6, 8, 3 };
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (a[j] < a[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    cout << res;
}

//W = 6 n = 4
//w 2 1 4 3 
//v 3 3 4 2

int main()
{
    int n, W;
    //cin >> n;

    return 0;
}