#include <iostream>
#include <string>
using namespace std;

class SinhVien {
private:
    string hoTen;
    int namSinh;
    float diem[4];

public:
    // Nhap thong tin
    void nhap() {
        cin.ignore();

        cout << "Nhap ho ten: ";
        getline(cin, hoTen);

        cout << "Nhap nam sinh: ";
        cin >> namSinh;

        for (int i = 0; i < 4; i++) {
            cout << "Nhap diem mon " << i + 1 << ": ";
            cin >> diem[i];
        }
    }

    // Xuat thong tin
    void xuat() {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Nam sinh: " << namSinh << endl;

        for (int i = 0; i < 4; i++) {
            cout << "Diem mon " << i + 1 << ": " << diem[i] << endl;
        }

        cout << "Diem trung binh: " << tinhDiemTB() << endl;
    }

    // Tinh diem trung binh
    float tinhDiemTB() {
        float tong = 0;

        for (int i = 0; i < 4; i++) {
            tong += diem[i];
        }

        return tong / 4;
    }

    // Kiem tra dieu kien tot nghiep
    bool totNghiep() {
        // Kiem tra diem trung binh
        if (tinhDiemTB() < 7) {
            return false;
        }

        // Kiem tra co mon nao duoi 5 khong
        for (int i = 0; i < 4; i++) {
            if (diem[i] < 5) {
                return false;
            }
        }

        return true;
    }
};

int main() {
    int n;

    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    SinhVien ds[100];

    // Nhap danh sach
    for (int i = 0; i < n; i++) {
        cout << "\n===== NHAP SINH VIEN " << i + 1 << " =====" << endl;
        ds[i].nhap();
    }

    // In sinh vien du dieu kien tot nghiep
    cout << "\n\n===== SINH VIEN DU DIEU KIEN TOT NGHIEP =====" << endl;

    bool co = false;

    for (int i = 0; i < n; i++) {
        if (ds[i].totNghiep()) {
            cout << "\n--- Sinh vien " << i + 1 << " ---" << endl;
            ds[i].xuat();
            co = true;
        }
    }

    if (!co) {
        cout << "Khong co sinh vien nao du dieu kien tot nghiep!" << endl;
    }

    return 0;
}
