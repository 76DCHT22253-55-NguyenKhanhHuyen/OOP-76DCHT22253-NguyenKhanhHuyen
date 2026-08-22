#include <iostream>
#include <string>
using namespace std;

struct NhanVien {
    string maNV;
    string tenNV;
    float luongCoBan;
    float heSo;
};

int main() {
    int n;
    cout << "Nhap so luong nhan vien: ";
    cin >> n;

    NhanVien nv[n];

    return 0;
}
