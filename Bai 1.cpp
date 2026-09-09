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
 
    void nhap();
    void xuat();
    void rutgon();
    void cong(PhanSo b);
    void tru(PhanSo b);
    void nhan(PhanSo b);
    void chia(PhanSo b);
 
    int UCLN(int a, int b);
};
 
// Uoc chung lon nhat, dung de rut gon phan so
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
 
void PhanSo::nhap() {
    cout << "Nhap tu: "; cin >> tu;
    do {
        cout << "Nhap mau: "; cin >> mau;
    } while (mau == 0);
}
 
void PhanSo::xuat() {
    cout << tu << "/" << mau << endl;
}
 
void PhanSo::rutgon() {
    int uc = UCLN(tu, mau);
    if (uc != 0) {
        tu /= uc;
        mau /= uc;
    }
    if (mau < 0) {          // dua dau am ve tu so cho chuan
        mau = -mau;
        tu = -tu;
    }
}
 
void PhanSo::cong(PhanSo b) {
    // a/b + c/d = (a*d + b*c) / (b*d)
    PhanSo kq;
    kq.tu = tu * b.mau + mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    cout << "Ket qua cong: ";
    kq.xuat();
}
 
void PhanSo::tru(PhanSo b) {
    // a/b - c/d = (a*d - b*c) / (b*d)
    PhanSo kq;
    kq.tu = tu * b.mau - mau * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    cout << "Ket qua tru: ";
    kq.xuat();
}
 
void PhanSo::nhan(PhanSo b) {
    // a/b * c/d = (a*c) / (b*d)
    PhanSo kq;
    kq.tu = tu * b.tu;
    kq.mau = mau * b.mau;
    kq.rutgon();
    cout << "Ket qua nhan: ";
    kq.xuat();
}
 
void PhanSo::chia(PhanSo b) {
    // a/b : c/d = (a*d) / (b*c)
    if (b.tu == 0) {
        cout << "Khong the chia cho phan so co tu so bang 0!" << endl;
        return;
    }
    PhanSo kq;
    kq.tu = tu * b.mau;
    kq.mau = mau * b.tu;
    kq.rutgon();
    cout << "Ket qua chia: ";
    kq.xuat();
}
 
int main() {
    PhanSo a(2, 3), b(1, 3);
 
    cout << "Phan so a: ";
    a.xuat();
 
    cout << "Nhap phan so b:" << endl;
    b.nhap();
 
    cout << endl << "Thuc hien cac phep toan giua a va b:" << endl;
    a.cong(b);
    a.tru(b);
    a.nhan(b);
    a.chia(b);
 
    return 0;
}
