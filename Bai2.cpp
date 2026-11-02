//MSSV: 2651090015
//Ho va ten : Mai Minh Duc

#include <iostream>
#include <string>

using namespace std;

int main() {
    int kwh, n ,soHo;
    string F_code;

    do {
        cout << "\n========== QUAN LY TIEN DIEN ==========\n";
        cout << "1. Tinh tien dien mot ho\n"
             << "2. Thong ke nhieu ho \n"
             << "0. Thoat \n";
        cout << "Chon chuc nang: ";
        cin >> n;

        switch (n) {
            case 1: {
                cout << "\nNhap ma ho gia dinh: ";
                cin.ignore();
                getline(cin, F_code);

                do {
                    cout << "Nhap so dien tieu thu (kWh): ";
                    cin >> kwh;
                    if (kwh < 0) cout << "Khong hop le | nhap lai!\n";
                } while (kwh < 0);

                int tmp = kwh;
                int b1 = 0, b2 = 0, b3 = 0, b4 = 0;
                if (tmp > 200) { b4 = tmp - 200; tmp = 200; }
                if (tmp > 100) { b3 = tmp - 100; tmp = 100; }
                if (tmp > 50)  { b2 = tmp - 50;  tmp = 50; }
                if (tmp >= 0)  { b1 = tmp; }

                long long tien = b1 * 1800 + b2 * 2000 + b3 * 2500 + b4 * 3000;

                cout << "\n========== HOA DON TIEN DIEN ==========\n"
                     << "Ma ho: " << F_code << endl
                     << "Dien tieu thu: " << kwh << " kWh\n";
                if (b1 > 0 || kwh == 0) cout << "Tien bac 1: " << b1 << " x 1800 = " << b1 * 1800 << " VND\n";
                if (b2 > 0) cout << "Tien bac 2: " << b2 << " x 2000 = " << b2 * 2000 << " VND\n";
                if (b3 > 0) cout << "Tien bac 3: " << b3 << " x 2500 = " << b3 * 2500 << " VND\n";
                if (b4 > 0) cout << "Tien bac 4: " << b4 << " x 3000 = " << b4 * 3000 << " VND\n";
                cout << "Tong tien dien: " << tien << " VND\n";
                cout << "Muc tieu thu: ";
                if (kwh < 100) cout << "Thap\n";
                else if (kwh <= 200) cout << "Trung binh\n";
                else cout << "Cao\n";
                break;
            }
//---------------------------------------------------------------------------------
            case 2: {
                do {
                    cout << "\nNhap so ho gia dinh: ";
                    cin >> soHo;
                } while (soHo <= 0);

                long long sum_all = 0;
                int maxKwh = -1;
                string maHoMax = "";
                int demThap = 0, demTB = 0, demCao = 0;

                for (int i = 1; i <= soHo; i++) {
                    cout << "\n--- Ho thu " << i << " ---\n";
                    cout << "Nhap ma ho gia dinh: ";
                    cin.ignore();
                    getline(cin, F_code);

                    do {
                        cout << "Nhap so dien tieu thu (kWh): ";
                        cin >> kwh;
                        if (kwh < 0) cout << "Khong hop le | nhap lai!\n";
                    } while (kwh < 0);

                    long long tien = 0;
                    int tmp = kwh;
                    if (tmp > 200) { tien += (tmp - 200) * 3000; tmp = 200; }
                    if (tmp > 100) { tien += (tmp - 100) * 2500; tmp = 100; }
                    if (tmp > 50)  { tien += (tmp - 50) * 2000;  tmp = 50; }
                    if (tmp > 0)   { tien += tmp * 1800; }

                    sum_all += tien;

                    if (kwh > maxKwh) {
                        maxKwh = kwh;
                        maHoMax = F_code;
                    }
                    if (kwh < 100) demThap++;
                    else if (kwh <= 200) demTB++;
                    else demCao++ ;
                }

                cout << "\n========== KET QUA THONG KE ==========\n";
                cout << "Tong tien dien: " << sum_all << " VND\n";
                cout << "Tien dien trung binh: " << sum_all / soHo << " VND\n";
                cout << "Ho tieu thu cao nhat: " << maHoMax << " (" << maxKwh << " kWh)\n";
                cout << "So ho muc Thap: " << demThap << "\n";
                cout << "So ho muc Trung binh: " << demTB << "\n";
                cout << "So ho muc Cao: " << demCao << "\n" ;
                break;
            }
            case 0: break ;
            default: cout << "Chon sai! Vui long chon lai.\n" ; break;
        }

    } while (n != 0);

    return 0;
}
