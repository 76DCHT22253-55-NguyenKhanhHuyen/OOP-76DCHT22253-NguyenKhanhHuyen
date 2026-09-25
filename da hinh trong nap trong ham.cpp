#include <iostream>
using namespace std;

class TinhToan {
public:
    // Tinh tong 2 so nguyen
    int tinhTong(int a, int b) {
        return a + b;
    }

    // Tinh tong 3 so nguyen
    int tinhTong(int a, int b, int c) {
        return a + b + c;
    }

    // Tinh tong 2 so thuc
    float tinhTong(float a, float b) {
        return a + b;
    }
};

int main() {
    TinhToan t;

    cout << "Tong 2 so nguyen: "
         << t.tinhTong(2, 3) << endl;

    cout << "Tong 3 so nguyen: "
         << t.tinhTong(2, 3, 4) << endl;

    cout << "Tong 2 so thuc: "
         << t.tinhTong(2.5f, 3.5f) << endl;

    return 0;
}
