#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

int giai_thua(int n) {
    if (n == 1) return 1;
    return giai_thua(n-1) * n;
}

int luy_thua(int a, int b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    int tam1 = luy_thua(a, b / 2);
    if (b % 2 == 0) return tam1 * tam1;
    else return tam1 * tam1 * a;
}

int Fibonacci(int n) {
    int F0 = 0, F1 = 1;
    if (n == 2 || n == 1) return 1;
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int tong_chu_so(int n) {
    if (n == 0) return 0;
    return tong_chu_so(n / 10) + n % 10;
}

string dao_chuoi(string s) {
    int size = s.size(); 
	if (size == 0) return "";
    return s[size - 1] + dao_chuoi(s.substr(0, size - 1)) ;
}

int GCD(int a, int b) {
    int du = a % b;
    if (du == 0) return a/b;
    return GCD(b, a % b);
}

int LCM(int a, int b) {
    int check = GCD(abs(a),abs(b)), tu = abs(a*b);
    return tu / check;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[high], arr[i + 1]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low >= high) return;
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
}

int find_min(vector<int> arr, int l, int r) {
    if (l >= r) return arr[l];
    int m = (l + r) / 2.0;
    int minl = find_min(arr, l, m - 1);
    int minr = find_min(arr, m + 1, r);
    return min(minl, minr );
}

int tong_mang(vector<int> arr, int l, int r) {
    //Cach 1: 
    /*
    if (r == l) return arr[r];
    return tong_mang(arr, l, r - 1) + arr[r];
    */
    //Cach 2:
    if (l >= r) return arr[l];
    int m = (l + r) / 2.0;
    int suml = tong_mang(arr, l, m);
    int sumr = tong_mang(arr, m + 1, r);
    return suml + sumr;
}

int dem_phan_tu_bang_x(vector<int> arr, int l, int r, int x) {
    if (r == l) return 0;
    if (arr[r] == x) return dem_phan_tu_bang_x(arr, l, r - 1, x) + 1;
    else return dem_phan_tu_bang_x(arr, l, r - 1, x);
}

void binary_search_first_last(vector<int> arr, int l, int r, int x) {
    if (l > r) return;
    int m = floor(l + r) / 2.0;
    int first = -1, last = -1;

    if (arr[m] == x) {
        int taml = m, tamr = m;
        while (arr[taml] == x) {
            first = taml;
            taml--;
        }
        while (arr[tamr] == x) {
            last = tamr;
            tamr++;
        }
        cout << first << " " << last;
    }

    else if (arr[m] < x) return binary_search_first_last(arr, m + 1, r, x);
    else return binary_search_first_last(arr, l, m - 1, x);
}

int main()
{
    /*auto check = dao_chuoi("hell");
    cout << check;*/
    vector<int> arr = {1,2,2,2,3};
    int indexlast = arr.size() - 1;
    /*auto check = dem_phan_tu_bang_x(arr,0,indexlast,2);
    cout << check;*/
    binary_search_first_last(arr, 0, indexlast, 2);
    return 0;
}