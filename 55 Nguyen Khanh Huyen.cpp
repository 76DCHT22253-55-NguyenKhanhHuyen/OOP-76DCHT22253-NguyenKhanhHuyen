#include <iostream>
#include <string>
using namespace std;

// Khai báo lop
class NhanVien
{
private:
    string manv;
    string hoten;
    string ngaysinh;
    string diachi;

public:
    // Phuong thuc nhap
    void nhap()
    {
        cout << "Nhap ma nhan vien: ";
        getline(cin, manv);

        cout << "Nhap ho ten: ";
        getline(cin, hoten);

        cout << "Nhap ngay sinh: ";
        getline(cin, ngaysinh);

        cout << "Nhap dia chi: ";
        getline(cin, diachi);
    }

    // Phuong thuc xuat
    void xuat()
    {
        cout << "Ma nhan vien: " << manv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Ngay sinh: " << ngaysinh << endl;
        cout << "Dia chi: " << diachi << endl;
    }
};

// Khai báo hàm main()
int main()
{
    // Khai báo 1 doi tuong là Minh thuc lop NhanVien
    NhanVien Minh;

    // Nhap thông tin cho Minh
    Minh.nhap();

    // Xuat thông tin c?a Minh
    Minh.xuat();

    return 0;
}
