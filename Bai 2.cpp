#include <iostream>
#include <cstdlib>
using namespace std;

class PhanSo {
private:
    int tu, mau;

public:
    // Ham tao khong doi
    PhanSo() {
        tu = 0;
        mau = 1;
    }

    // Ham tao co doi
    PhanSo(int tu, int mau) {
        this->tu = tu;
        this->mau = mau;
    }

    // Ham huy
    ~PhanSo() {}

    // Nap chong nhap/xuat la ham ban
    friend istream& operator>>(istream &in, PhanSo &p);
    friend ostream& operator<<(ostream &on, PhanSo p);

    void rutgon();
    int UCLN(int a, int b);

    // Nap chong toan tu cong, tru, nhan, chia
    PhanSo operator+(PhanSo b);
    PhanSo operator-(PhanSo b);
    PhanSo operator*(PhanSo b);
    PhanSo operator/(PhanSo b);
};

int PhanSo::UCLN(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void PhanSo::rutgon() {
    int uc = UCLN(tu, mau);
    if (uc != 0) {
        tu /= uc;
        mau /= uc;
    }
    if (mau < 0) {
        mau = -mau;
        tu = -tu;
    }
}

istream& operator>>(istream &in, PhanSo &p) {
    cout << "Nhap tu: "; in >> p.tu;
    do {
        cout << "Nhap mau: "; in >> p.mau;
    } while (p.mau == 0);
    return in;
}

ostream& operator<<(ostream &on, PhanSo p) {
    on << p.tu << "/" << p.mau << endl;
    return on;
}

PhanSo PhanSo::operator+(PhanSo b) {
    PhanSo kq;
    kq.tu = tu * b.mau + mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    return kq;
}

PhanSo PhanSo::operator-(PhanSo b) {
    PhanSo kq;
    kq.tu = tu * b.mau - mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    return kq;
}

PhanSo PhanSo::operator*(PhanSo b) {
    PhanSo kq;
    kq.tu = tu * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    return kq;
}

PhanSo PhanSo::operator/(PhanSo b) {
    PhanSo kq;
    kq.tu = tu * b.mau;
    kq.mau = mau * b.tu;
    kq.rutgon();
    return kq;
}

int main() {
    PhanSo a, b;
    cin >> a;
    cin >> b;

    cout << "PS a: " << endl;
    cout << a;
    cout << "PS b: " << endl;
    cout << b;

    PhanSo c;

    cout << endl << "Tong hai phan so: " << endl;
    c = a + b;
    cout << c;

    cout << "Hieu hai phan so: " << endl;
    c = a - b;
    cout << c;

    cout << "Tich hai phan so: " << endl;
    c = a * b;
    cout << c;

    cout << "Thuong hai phan so: " << endl;
    c = a / b;
    cout << c;

    return 0;
}
