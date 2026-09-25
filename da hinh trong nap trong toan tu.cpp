#include <iostream>
using namespace std;

class PhanSo {
private:
    int tu;
    int mau;

public:
    PhanSo(int tu = 0, int mau = 1) {
        this->tu = tu;
        this->mau = mau;
    }

    // Nap chong toán tu +
    PhanSo operator+(PhanSo ps) {
        PhanSo kq;
        kq.tu = tu * ps.mau + ps.tu * mau;
        kq.mau = mau * ps.mau;
        return kq;
    }

    void xuat() {
        cout << tu << "/" << mau;
    }
};

int main() {
    PhanSo ps1(1, 2);
    PhanSo ps2(1, 3);

    PhanSo ps3 = ps1 + ps2;

    cout << "Ket qua: ";
    ps3.xuat();

    return 0;
}
