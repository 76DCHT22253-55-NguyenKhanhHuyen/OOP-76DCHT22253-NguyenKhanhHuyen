#include <iostream>
using namespace std;

class SoPhuc {
private:
    float phanThuc;
    float phanAo;

public:
    // Câu 1: Hàm tao không doi
    SoPhuc() {
        phanThuc = 0;
        phanAo = 0;
    }

    // Hàm tao có doi
    SoPhuc(float thuc, float ao) {
        phanThuc = thuc;
        phanAo = ao;
    }

    // Hàm huy
    ~SoPhuc() {
    }

    // Câu 2: Toán tu >> nhap so phuc
    friend istream& operator>>(istream& is, SoPhuc& sp) {
        cout << "Nhap phan thuc: ";
        is >> sp.phanThuc;

        cout << "Nhap phan ao: ";
        is >> sp.phanAo;

        return is;
    }

    // Toán tu << xuat so phuc
    friend ostream& operator<<(ostream& os, const SoPhuc& sp) {
        os << sp.phanThuc;

        if (sp.phanAo >= 0)
            os << "+" << sp.phanAo << "i";
        else
            os << sp.phanAo << "i";

        return os;
    }

    // Câu 3: Toán tu +
    SoPhuc operator+(const SoPhuc& sp) {
        return SoPhuc(
            phanThuc + sp.phanThuc,
            phanAo + sp.phanAo
        );
    }

    // Toán tu -
    SoPhuc operator-(const SoPhuc& sp) {
        return SoPhuc(
            phanThuc - sp.phanThuc,
            phanAo - sp.phanAo
        );
    }

    // Toán tu *
    SoPhuc operator*(const SoPhuc& sp) {
        return SoPhuc(
            phanThuc * sp.phanThuc - phanAo * sp.phanAo,
            phanThuc * sp.phanAo + phanAo * sp.phanThuc
        );
    }

    // Toán tu /
    SoPhuc operator/(const SoPhuc& sp) {
        float mau = sp.phanThuc * sp.phanThuc
                  + sp.phanAo * sp.phanAo;

        return SoPhuc(
            (phanThuc * sp.phanThuc + phanAo * sp.phanAo) / mau,
            (phanAo * sp.phanThuc - phanThuc * sp.phanAo) / mau
        );
    }
};

int main() {
    SoPhuc sp1, sp2;

    // Nhap 2 so phuc
    cout << "=== NHAP SO PHUC 1 ===" << endl;
    cin >> sp1;

    cout << "\n=== NHAP SO PHUC 2 ===" << endl;
    cin >> sp2;

    // Xuat 2 so phuc
    cout << "\nSo phuc 1: " << sp1 << endl;
    cout << "So phuc 2: " << sp2 << endl;

    // Cong
    cout << "\nTong: " << sp1 + sp2 << endl;

    // Tru
    cout << "Hieu: " << sp1 - sp2 << endl;

    // Nhân
    cout << "Tich: " << sp1 * sp2 << endl;

    // Chia
    cout << "Thuong: " << sp1 / sp2 << endl;

    return 0;
}
