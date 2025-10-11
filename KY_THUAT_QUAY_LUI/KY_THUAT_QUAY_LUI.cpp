#include <iostream>
#include <vector>

using namespace std;

int arr[101], used[101];
int n = 3;
int k;

void print(int n) {
    for (int i = 1; i <= n; i++) {
        cout << arr[i];
    }
    cout << endl;
}

void inChuoiNhiPhan(int pos) {
    if (pos == n + 1) {
        print(n);
        return;
    }

    arr[pos] = 0;
    inChuoiNhiPhan(pos + 1);
    arr[pos] = 1;
    inChuoiNhiPhan(pos + 1);
}

void inToHopChapKCuaN(int pos, int start) {
    if (pos == k + 1) {
        print(k);
        return;
    }

    for (int i = start; i <= n - (k - pos); i++) {
        arr[pos] = i;
        inToHopChapKCuaN(pos + 1, i + 1);
    }
}

void inHoanVi(int pos) {
    if (pos == n + 1) {
        print(n);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (used[i] == false) {
            used[i] = true;
            arr[pos] = i;
            inHoanVi(pos + 1);
            used[i] = false;
        }
    }
}
int main()
{
    inHoanVi(1);
    return 0;
}