#include <iostream>
#include <string>
using namespace std;

// Lop MonHoc
class MonHoc {
protected:
    string tenmh;
    float diemCC;
    float diemKT;
    float diemDT;

public:
    // Ham nhap
    void nhap() {
        cout << "Nhap ten mon hoc: ";
        cin.ignore();
        getline(cin, tenmh);

        cout << "Nhap diem chuyen can: ";
        cin >> diemCC;

        cout << "Nhap diem kiem tra: ";
        cin >> diemKT;

        cout << "Nhap diem thi: ";
        cin >> diemDT;
    }

    // Ham tinh diem hoc phan
    float tinhDiemHocPhan() {
        // CC 10%, KT 30%, DT 60%
        return diemCC * 0.1 + diemKT * 0.3 + diemDT * 0.6;
    }

    // Ham xuat
    void xuat() {
        cout << "Ten mon hoc: " << tenmh << endl;
        cout << "Diem chuyen can: " << diemCC << endl;
        cout << "Diem kiem tra: " << diemKT << endl;
        cout << "Diem thi: " << diemDT << endl;
        cout << "Diem hoc phan: " << tinhDiemHocPhan() << endl;
    }
};


// Lop SinhVien ke thua lop MonHoc
class SinhVien : public MonHoc {
private:
    string hoten;
    string lop;
    string masv;

public:
    // Ham nhap
    void nhap() {
        cout << "Nhap ma sinh vien: ";
        cin >> masv;

        cout << "Nhap ho ten: ";
        cin.ignore();
        getline(cin, hoten);

        cout << "Nhap lop: ";
        getline(cin, lop);

        // Goi ham nhap cua lop cha
        MonHoc::nhap();
    }

    // Ham xuat
    void xuat() {
        cout << "Ma sinh vien: " << masv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Lop: " << lop << endl;

        // Goi ham xuat cua lop cha
        MonHoc::xuat();
    }

    // Kiem tra sinh vien bi cam thi
    bool biCamThi() {
        return diemCC < 5 || diemKT == 0;
    }
};


int main() {
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    // Nhap danh sach sinh vien
    for (int i = 0; i < n; i++) {
        cout << "\n===== NHAP SINH VIEN THU " << i + 1 << " =====" << endl;
        ds[i].nhap();
    }

    // Xuat sinh vien bi cam thi
    cout << "\n\n===== DANH SACH SINH VIEN BI CAM THI =====" << endl;

    bool co = false;

    for (int i = 0; i < n; i++) {
        if (ds[i].biCamThi()) {
            cout << "\n--- Sinh vien thu " << i + 1 << " ---" << endl;
            ds[i].xuat();
            co = true;
        }
    }

    if (!co) {
        cout << "Khong co sinh vien nao bi cam thi." << endl;
    }

    return 0;
}
