#include <iostream>
#include <string>
using namespace std;

// Lop Nguoi
class Nguoi {
protected:
    string hoten;
    int namsinh;

public:
    void nhap() {
        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);

        cout << "Nhap nam sinh: ";
        cin >> namsinh;
    }

    void xuat() {
        cout << "Ho ten: " << hoten << endl;
        cout << "Nam sinh: " << namsinh << endl;
    }
};

// Lop SinhVien ke thua lop Nguoi
class SinhVien : public Nguoi {
private:
    string masv;
    float dtb;

public:
    void nhap() {
        Nguoi::nhap();

        cout << "Nhap ma sinh vien: ";
        cin >> masv;

        cout << "Nhap diem trung binh: ";
        cin >> dtb;
    }

    void xuat() {
        Nguoi::xuat();

        cout << "Ma sinh vien: " << masv << endl;
        cout << "Diem trung binh: " << dtb << endl;
    }

    string getMaSV() {
        return masv;
    }

    string getHoTen() {
        return hoten;
    }
};

int main() {
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    // Nhap danh sach sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n===== NHAP SINH VIEN " << i + 1 << " =====" << endl;
        ds[i].nhap();
    }

    // Xuat danh sach sinh vien
    cout << "\n\n===== DANH SACH SINH VIEN =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien " << i + 1 << " ---" << endl;
        ds[i].xuat();
    }

    // Nhap thong tin tim kiem
    string timkiem;

    cout << "\n\nNhap ma sinh vien hoac ho ten can tim: ";
    cin.ignore();
    getline(cin, timkiem);

    bool timthay = false;

    // Tim kiem
    for (int i = 0; i < n; i++) {
        if (ds[i].getMaSV() == timkiem ||
            ds[i].getHoTen() == timkiem) {

            cout << "\n===== SINH VIEN TIM THAY =====" << endl;
            ds[i].xuat();

            timthay = true;
        }
    }

    if (timthay == false) {
        cout << "\nKhong tim thay sinh vien!" << endl;
    }

    return 0;
}
