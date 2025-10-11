#include <iostream>
#include <algorithm>
using namespace std;

int arr[101];
bool done = false;

void init(int n) {
    for (int i = 1; i <= n; i++) arr[i] = i;
}

void print(int n) {
    for (int i = 1; i <= n; i++) cout << arr[i];
    cout << endl;
}

void sinh_chuoi_nhi_phan(int n) {
    int i = n;

    while (i >= 1 && arr[i] == 1) i--;

    if (i == 0) {
        done = true;
        return;
    }

    arr[i] = 1;

    for (int k = i + 1; k <= n; k++) arr[k] = 0;   
}

void sinh_to_hop_chap_k_cua_n(int k, int n) {
    int i = k;
    while (i >= 1 && arr[i] == n - k + i) i--;

    if (i == 0) {
        done = true;
        return;
    }

    arr[i] = arr[i] + 1;

    for (int tam = i + 1; tam <= k; tam++) arr[tam] = arr[tam - 1] + 1;
}

void sinh_hoan_vi_cua_n(int n) {
    int i = n - 1; int j = n;
    while (i >= 1 && arr[i] > arr[i + 1]) i--;

    if (i == 0) {
        done = true;
        return;
    }

    while (j >= 0 && arr[j] < arr[i]) j--;
    swap(arr[i], arr[j]);

    int l = i + 1, r = n;
    while (l < r) {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

int main()
{
    int n; cin >> n;
    init(n);
    while (not done) {
        print(n);
        sinh_hoan_vi_cua_n(n);
    }
    return 0;
}
