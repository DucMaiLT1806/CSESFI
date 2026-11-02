#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string ho_ten  ;
    int sp , n , sumbill = 0 , sum_ab_2m =0;
    double dg ,voucher  = 0 , tongDT = 0 ;
    cout << fixed << setprecision(0);

    do {
        cout<<"============ QUAN LY HOA DON ============ \n" ;
        cout<<"1. Lap hoa don\n"
            <<"2. Thong ke doanh thu\n"
            <<"0. Thoat \n" ;
        cout<<"Chon chuc nang: \n" ;
        cin >>n ;

        switch (n) {
        case 1:{
            cout<<"Nhap ten khach hang: \n" ;
            cin.ignore();
            getline(cin, ho_ten) ;
            cout<<"Nhap so luong san pham: \n" ;
            cin>>sp ;
            cout<<"Nhap don gia (VND) : \n" ;
            cin>>dg ;
            if (dg*sp >= 3000000) {
                voucher = 0.10;
            } else if (dg*sp >= 1000000) {
                voucher = 0.05;
            } else voucher = 0.0;

            double tien_giam = voucher*sp*dg ;
            tongDT += sp *dg - tien_giam  ;

            cout<<"\n============ HOA DON THANH TOAN ============\n"
                <<"Khach hang: "<<ho_ten <<endl
                <<"Tong tien khach hang: " <<sp*dg <<endl
                <<"Giam gia: "<<voucher *100 <<endl ;
            cout<<"Tien giam: " <<tien_giam << " VND " <<endl
                <<"Can thanh toan: "<<dg*sp - tien_giam  <<" VND " <<endl;
            int pttt ;
            cout<<"Chon phuong thuc thanh toan: \n" ;
            cout<<"1. Tien mat\n"
                <<"2. Chuyen khoan \n"
                <<"3. The \n" ;
            cout<<"Lua chon: " ;cin >>pttt ;
            sumbill ++ ;
            if (dg*sp - tien_giam >= 2000000) sum_ab_2m ++ ;

            switch(pttt) {
                case 1: cout<<"Phuong thuc: Tien mat \n" ; break ;
                case 2: cout<<"Phuong thuc: Chuyen khoan \n" ; break ;
                case 3: cout<<"Phuong thuc: The \n" ;break ;
                default: break ;
                }
            break ;
            }
        case 2: {
                cout<<"Tong doanh thu : " <<tongDT <<" VND " <<endl ;
            if (sumbill>0) {
                cout<<"Doanh thu trung binh: "<<tongDT/sumbill <<" VND " <<endl ;
            }else cout<<"Doanh thu trung binh: 0 VND" ;
            cout<<"So hoa don tu 2.000.000 VND: " <<sum_ab_2m <<endl ;
        break;
            }

        default:
            cout<<"Khong co dich vu nao danh cho ban: " ;
            break ;
        }

    }while (n!=0) ;


    return 0;
}
