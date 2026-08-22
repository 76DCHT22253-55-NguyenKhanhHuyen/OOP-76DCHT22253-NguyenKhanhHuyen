#include <iostream>
#include <string>
using namespace std;

class NhanVien {
private:
    string manv;
    string tennv;
    float luongcb;
    float heso;

public:
    void nhap() {
        cout << "Nhap ma nhan vien: ";
        cin >> manv;

        cout << "Nhap ten nhan vien: ";
        cin >> tennv;

        cout << "Nhap luong co ban: ";
        cin >> luongcb;

        cout << "Nhap he so: ";
        cin >> heso;
    }

    void xuat() {
        cout << "Ma nhan vien: " << manv << endl;
        cout << "Ten nhan vien: " << tennv << endl;
        cout << "Luong co ban: " << luongcb << endl;
        cout << "He so: " << heso << endl;
    }
};

int main() {
    // Tao mang 10 doi tuong NhanVien
    NhanVien dsnv[10];

    // Nhap thong tin cho 10 nhan vien
    for (int i = 0; i < 10; i++) {
        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        dsnv[i].nhap();
    }

    // Xuat thong tin 10 nhan vien
    for (int i = 0; i < 10; i++) {
        cout << "\n=== THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        dsnv[i].xuat();
    }

    return 0;
}
