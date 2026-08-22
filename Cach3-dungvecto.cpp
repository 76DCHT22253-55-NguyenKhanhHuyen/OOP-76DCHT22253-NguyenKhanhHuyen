#include <iostream>
#include <string>
#include <vector>
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
    // Tao vector chua cac doi tuong NhanVien
    vector<NhanVien> ds;

    // Nhap thong tin cho 10 nhan vien
    for (int i = 0; i < 10; i++) {
        NhanVien nv;

        cout << "\n=== NHAP THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        nv.nhap();

        // Them nhan vien vao vector
        ds.push_back(nv);
    }

    // Xuat thong tin 10 nhan vien
    for (int i = 0; i < ds.size(); i++) {
        cout << "\n=== THONG TIN NHAN VIEN THU "
             << i + 1 << " ===" << endl;

        ds[i].xuat();
    }

    return 0;
}
