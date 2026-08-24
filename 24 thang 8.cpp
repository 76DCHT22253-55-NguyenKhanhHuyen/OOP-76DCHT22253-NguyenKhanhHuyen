#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class NhanVien {
private:
    string manv;
    string tennv;
    float luongcb;
    float heso;

public:
    // Constructor khong doi
    NhanVien() {
        manv = "";
        tennv = "";
        luongcb = 0;
        heso = 0;
    }

    // Constructor co doi
    NhanVien(string ma, string ten, float luong, float hs) {
        manv = ma;
        tennv = ten;
        luongcb = luong;
        heso = hs;
    }

    void xuat() {
        cout << left
             << setw(15) << manv
             << setw(20) << tennv
             << setw(15) << luongcb
             << setw(10) << heso
             << endl;
    }
};

int main() {
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    vector<NhanVien> ds;

    // Nhap n nhan vien
    for (int i = 0; i < n; i++) {
        string ma, ten;
        float luong, hs;

        cout << "\n=== NHAP NHAN VIEN THU " << i + 1 << " ===" << endl;

        cout << "Nhap ma nhan vien: ";
        cin >> ma;

        cout << "Nhap ten nhan vien: ";
        cin >> ten;

        cout << "Nhap luong co ban: ";
        cin >> luong;

        cout << "Nhap he so: ";
        cin >> hs;

        // Su dung constructor co doi
        NhanVien nv(ma, ten, luong, hs);

        // Dua nhan vien vao vector
        ds.push_back(nv);
    }

    // Xuat theo cot
    cout << "\n================ DANH SACH NHAN VIEN ================\n";

    cout << left
         << setw(15) << "Ma NV"
         << setw(20) << "Ten NV"
         << setw(15) << "Luong CB"
         << setw(10) << "He so"
         << endl;

    cout << "------------------------------------------------------\n";

    for (int i = 0; i < ds.size(); i++) {
        ds[i].xuat();
    }
    return 0;
}
