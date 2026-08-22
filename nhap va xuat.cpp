#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

void nhap(NhanVien nv[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nNhap nhan vien " << i + 1 << ":\n";

        cout << "Ma NV: ";
        cin >> nv[i].maNV;

        cin.ignore();
        cout << "Ten NV: ";
        getline(cin, nv[i].tenNV);

        cout << "Luong co ban: ";
        cin >> nv[i].luongCoBan;

        cout << "He so: ";
        cin >> nv[i].heSo;
    }
}

void xuat(NhanVien nv[], int n) {
    cout << "\n===== DANH SACH NHAN VIEN =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nNhan vien " << i + 1 << ":\n";
        cout << "Ma NV: " << nv[i].maNV << endl;
        cout << "Ten NV: " << nv[i].tenNV << endl;
        cout << "Luong co ban: " << nv[i].luongCoBan << endl;
        cout << "He so: " << nv[i].heSo << endl;
    }
}

int main() {
    int n;

    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    NhanVien nv[n];

    nhap(nv, n);
    xuat(nv, n);

    return 0;
}
