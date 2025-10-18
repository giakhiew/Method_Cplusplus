#include <iostream>
#include <vector>

using namespace std;

int arr[101], arrh[101], arrw[101], used[101], solution[101];
bool dcx[101], dcn[101], columnarr[101], rowarr[101];
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
//dg cheo nguoc = i - j + n, dg cheo xuoi = i + j - 1; cot = arr
void printRowColumn() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (solution[i] == j) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void NQuanHau(int row) {
    for (int col = 1; col <= n; col++) {
        int d2 = row - col + n, d1 = row + col - 1;

        if (dcx[d1] == false && dcn[d2] == false && columnarr[col] == false) {

            dcx[d1] = true;
            dcn[d2] = true;
            columnarr[col] = true;
            solution[row] = col;

            if (row < n) NQuanHau(row + 1);
            else printRowColumn();
            

            dcx[d1] = false;
            dcn[d2] = false;
            columnarr[col] = false;
        }
    }
}
void initArrH() {
    for (int i = 1; i <= n; i++) {
        cin >> arrh[i];
    }
}

//void initArrW(int n) {
//    for (int i = 1; i < n; i++) {
//        for (int j = i; j < n - i; j++) {
//            cin >> arrw[j];
//        }
//    }
//}

int ans = 0, sum1 = 0, sum2 = 0;

void doiDau(int pos) {
    if (pos == n) {
        ans = min(sum1, sum2);
    }
    
}

int main() {
    initArrH();
    doiDau(1);
    cout << ans;
    return 0;
}