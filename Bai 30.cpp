#include <iostream>
#include <cmath>
using namespace std;

// ================= CÂU 1 =================
class SP1 {
protected:
    float phanThuc;
    float phanAo;

public:
    // Hàm tao không doi
    SP1() {
        phanThuc = 0;
        phanAo = 0;
    }

    // Hàm tao có doi
    SP1(float thuc, float ao) {
        phanThuc = thuc;
        phanAo = ao;
    }

    // Nhap so phuc
    void nhap() {
        cout << "Nhap phan thuc: ";
        cin >> phanThuc;

        cout << "Nhap phan ao: ";
        cin >> phanAo;
    }

    // In so phuc
    void xuat() {
        cout << phanThuc;

        if (phanAo >= 0)
            cout << " + " << phanAo << "i";
        else
            cout << " - " << -phanAo << "i";
    }

    // Tính module
    float module() const {
        return sqrt(phanThuc * phanThuc +
                    phanAo * phanAo);
    }
};


// ================= CÂU 2 =================
class SP2 : public SP1 {
public:
    // Toán tu = (gán)
    SP2& operator=(const SP2& sp) {
        phanThuc = sp.phanThuc;
        phanAo = sp.phanAo;

        return *this;
    }

    // Toán tu > : so sánh theo module
    bool operator>(const SP2& sp) const{
        return module() > sp.module();
    }
};


// ================= CÂU 3 =================
int main() {
    SP2 ds[10];
    int n;

    cout << "Nhap so luong so phuc (toi da 10): ";
    cin >> n;

    // Kiem tra so luong
    if (n < 1 || n > 10) {
        cout << "So luong khong hop le!";
        return 0;
    }

    // Nhap danh sách
    cout << "\n===== NHAP DANH SACH SO PHUC =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nSo phuc thu " << i + 1 << ":\n";
        ds[i].nhap();
    }

    // Sap xep giam dan theo module
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {

            if (!(ds[i] > ds[j])) {
                SP2 temp;

                temp = ds[i];
                ds[i] = ds[j];
                ds[j] = temp;
            }
        }
    }

    // Xuat danh sáah sau khi sap xep
    cout << "\n===== DANH SACH SAU KHI SAP XEP =====\n";

    for (int i = 0; i < n; i++) {
        cout << "\nSo phuc thu " << i + 1 << ": ";
        ds[i].xuat();

        cout << "    Module = " << ds[i].module();
    }

    return 0;
}
