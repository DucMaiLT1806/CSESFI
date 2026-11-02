
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int luaChon, luaChonTT, soLuong, giamGia, dem = 0, dem2T = 0;
    string hoTen, thanhToan;
    double donGia, tienGiam, tongTien, tongDoanhThu = 0;
    do
    {
        cout << "==============QUAN LY HOA DON===============\n";
        cout << "1. Lap hoa don\n";
        cout << "2. Thong ke doanh thu\n";
        cout << "0. Thoat\n";
        cout << "Nhap lua chon: ";
        cin >> luaChon;
        cin.ignore();

        switch (luaChon)
        {
            case 0:
                cout << "Chao tam biet!\n";
                break;
            case 1:
                do // Cau a
                {
                    cout << "Nhap ho ten khach hang: ";
                    getline(cin, hoTen);
                    cout << "Nhap so luong san pham: ";
                    cin >> soLuong;
                    cout << "Nhap don gia (VND): ";
                    cin >> donGia;
                    if (soLuong <= 0 || donGia <= 0)
                        cout << "Du lieu khong hop le\n";
                } while (soLuong <= 0 || donGia <= 0);

                // Cau b
                tongTien = donGia * soLuong;
                if (tongTien < 1000000)
                    giamGia = 0;
                else if (tongTien < 3000000)
                    giamGia = 5;
                else
                    giamGia = 10;
                tienGiam = giamGia / 100.0 * tongTien;

                // Cau c
                do
                {
                    cout << "Chon phuong thuc thanh toan:\n";
                    cout << "1. Tien mat\n";
                    cout << "2. Chuyen khoan\n";
                    cout << "3. The\n";
                    cout << "Nhap lua chon: ";
                    cin >> luaChonTT;

                    switch (luaChonTT)
                    {
                        case 1: thanhToan = "Tien mat"; break;
                        case 2: thanhToan = "Chuyen khoan"; break;
                        case 3: thanhToan = "The"; break;
                        default: cout << "Lua chon khong hop le\n";
                    }
                } while (luaChonTT < 1 || luaChonTT > 3);

                cout << "========== HOA DON THANH TOAN ==========\n";
                cout << "Khach hang: " << hoTen << endl;
                cout << "Tong tien hang: " << fixed << setprecision(2) << tongTien << endl;
                cout << "Giam gia: " << giamGia << "%\n";
                cout << "Tien giam: " << tienGiam << endl;
                cout << "Can thanh toan: " << fixed << tongTien - tienGiam << endl;

                tongDoanhThu += (tongTien - tienGiam);
                dem++;
                if (tongTien - tienGiam >= 2000000)
                    dem2T++;
                break;
            case 2: // d
                if (dem == 0)
                    cout << "Chua nhap hoa don\n";
                else
                {
                    cout << "Tong doanh thu: " << tongDoanhThu << endl;
                    cout << "Doanh thu trung binh: " << tongDoanhThu / dem << endl;
                    cout << "So hoa don tu 2000000VND tro len: " << dem2T << endl;
                }
                break;
            default:
                cout << "Lua chon khong hop le\n";
        }
    } while (luaChon != 0);

    return 0;
}
