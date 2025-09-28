#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef string bignum_str;
typedef vector<int> vi;

void input(bignum_str &number) {
    cin >> number;
}

void output(bignum_str number) {
    cout << number;
}

void input(vi &v) {
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        v.push_back(str[i] - '0');
    }
}

void output(vi v) {
    for (int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
}

void equal_length(bignum_str& a, bignum_str& b) { //can bang size
    while (a.size() < b.size()) {
        a = '0' + a;
    }
    while (b.size() < a.size()) {
        b = '0' + b;
    }
}

int compare(bignum_str a, bignum_str b) {//so sanh
    equal_length(a, b);
        if (a < b ) return -1;
        if (a > b) return 1;
        return 0;
}

void add_zero(vi& a, int sz) {
    reverse(a.begin(), a.end());
    while (a.size()<sz) a.push_back(0);
    reverse(a.begin(), a.end());
}

void change(vi& a, vi& b) {
    int sz = max(a.size(), b.size());
    add_zero(a, sz);
    add_zero(b, sz);
}

int compare(vi a, vi b) {
    change(a, b);
    if (a < b) return -1;
    if (a > b) return 1;
    return 0;
}

vi Int_Vector(int n) {
    vi v1;
    while (n != 0) {
        v1.push_back(n % 10);
        n /= 10;
    }
    reverse(v1.begin(), v1.end());
    return v1;
}

bignum_str add(bignum_str a, bignum_str b) { //cong 2 chuoi string
    equal_length(a, b);

    int carry = 0;
    bignum_str res="";
    for (int i = a.size()-1; i >= 0; --i) {
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        carry = d/10;
        res = (char)(d % 10 + '0') + res;
    }

    if (carry != 0) {
        res = '1' + res;
    }

    return res;
}

vi add(vi v1, vi v2) { //cong 2 vector
    change(v1, v2);
    vi res;
    int carry = 0;
    for (int i = v1.size() - 1; i >= 0; --i) {
        int x = v1[i] + v2[i] + carry;
        carry = x / 10;
        res.push_back(x % 10);
    }
    if (carry != 0) {
        res.push_back(1);
        
    }
    reverse(res.begin(), res.end());
    return res;
}

void del0(bignum_str& str) {
    while (str.size() >= 2 && str.front() == '0') {
            str.erase(str.begin());
    }
}

void del0(vi& v1) {
    reverse(v1.begin(), v1.end());
    while (v1.size() >= 2 && v1.back() == 0) {
        v1.pop_back();
    }
    reverse(v1.begin(), v1.end());
}

bignum_str tru(bignum_str str1, bignum_str str2) {
    equal_length(str1, str2);
    bool checkminus = false;
    int check = compare(str1, str2);
    if (check < 0) {
        swap(str1, str2);
        checkminus = true;
    }

    bignum_str res;
    int carry = 0;
    for (int i = str1.size() - 1; i >= 0; --i) {
        
        if (str1[i] < str2[i]) {
            int d = 10 + (str1[i] - '0') - (str2[i] - '0') - carry;
            carry = 1;
            res = (char)(d % 10 + '0') + res;
        }

        else {
            int d = (str1[i] - '0') - (str2[i] - '0') - carry;
            carry = 0;
            res = (char)(d % 10 + '0') + res;
        }
    }
    del0(res);
    if (checkminus != 0) res = '-' + res;
    return res;
}

vi tru(vi v1, vi v2) {
    change(v1, v2);
    bool checkminus = false;
    int check = compare(v1, v2);
    if (check < 0) {
        checkminus = true;
        swap(v1, v2);
    }
    int carry = 0;
    vi res;
    for (int i = v1.size() - 1; i >= 0; --i) {
        int d = v1[i] - v2[i] - carry;
        if (d < 0) {
            d += 10;
            carry = 1;
        }
        else carry = 0;
        res.push_back(d);
    }
    del0(res);
    //check minus
    reverse(res.begin(), res.end());
    return res;
}


void Fibonacci(int n) {
    bignum_str f0 = "0";
    bignum_str f1 = "1";
    bignum_str fn = "";
    for (int i = 2; i <= n; i++) {
        fn = add(f0, f1);
        f0 = f1;
        f1 = fn;
    }
    cout<<fn;
}

bignum_str product1(bignum_str a, long long b) {
    string res;
    int carry = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
        int d = (a[i] - '0') * b + carry;
        carry = d / 10;
        res += (char)(d % 10 + '0');
    }
    if (carry > 0) {
        while (carry != 0) {
            res += (char)(carry % 10 + '0');
            carry /= 10;
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

vi product2(vi a, vi b) {
    vi res;
    vi c(a.size() + b.size() + 1);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            int tam = a[i] * b[j];
            c[i + j] += tam % 10;
            c[i + j + 1] += tam / 10;
        }
    }
    for (int i = 0; i < c.size()-1; i++) {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
    }
    reverse(c.begin(), c.end());
    del0(c);
    return c;
}
//
vi TinhHoanVi(int n) {
    vi res = { 1 };
    vi a;
    for (int i = 2; i <= n; i++) {
        a = Int_Vector(i);
        res = product2(res, a);
    }
    return res;
}

vi chia(vi v1, long long b) {
    long long cur = 0;
    vi res;
    for (int d : v1) { //giong for auto item 
        cur = cur * 10 + d;
        res.push_back(cur / b);
        cur %= b;
    }
    del0(res);
    return res;
}

long long chiadu(vi v1, long long b) {
    long long cur = 0;
    vi res;
    for (int d : v1) {
        cur = (cur * 10 + d) % b;
    }
    return cur;
}

int main()
{
    bignum_str a,b;
    vi v1,v2;
    input(v1);
    /*input(v1);
    input(v2);
    */
   /* input(v1);
    input(v2);
    vi check = add(v1,v2);
    output(check);*/
    vi v = chia(v1,67);
    output(v);
        return 0;
}