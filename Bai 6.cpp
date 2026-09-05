#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[5];

public:
    // Nhap thong tin sinh vien
    void nhap() {
        cin.ignore();
        
        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 5; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Xuat thong tin sinh vien
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;

        for (int i = 0; i < 5; i++) {
            cout << "Diem mon " << i + 1 << ": " << diem[i] << endl;
        }

        cout << "Diem trung binh: " << tinhDiemTB() << endl;
    }

    // Tinh diem trung binh
    float tinhDiemTB() {
        float tong = 0;

        for (int i = 0; i < 5; i++) {
            tong += diem[i];
        }

        return tong / 5;
    }

    // Kiem tra va in mon thi lai
    void thiLai() {
        bool coThiLai = false;

        for (int i = 0; i < 5; i++) {
            if (diem[i] < 5) {
                if (!coThiLai) {
                    cout << "Sinh vien: " << hoTen << endl;
                    cout << "Cac mon phai thi lai:" << endl;
                    coThiLai = true;
                }

                cout << "Mon " << i + 1
                     << " - Diem: " << diem[i] << endl;
            }
        }
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

    // Xuat danh sach
    cout << "\n\n===== DANH SACH SINH VIEN =====" << endl;

    for (int i = 0; i < n; i++) {
        cout << "\n--- Sinh vien " << i + 1 << " ---" << endl;
        ds[i].xuat();
    }

    // In sinh vien phai thi lai
    cout << "\n\n===== SINH VIEN PHAI THI LAI =====" << endl;

    for (int i = 0; i < n; i++) {
        ds[i].thiLai();
    }

    return 0;
}
