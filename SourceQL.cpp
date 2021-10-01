#include "List_CTKH.cpp"
// #include "newsPaper.h"
// #include "Book.h"

int main()
{
    List_CTKH<CTr_KH*> x;
    bool Danhap = false;
    int key;
    string id;
    int p;
    cout << "   CHUONG TRINH QUAN LI CONG TRINH KHOA HOC PHAN LOAI THEO SACH - BAO" << endl
         << "       Sinh vien thuc hien: Le Hoang Ngoc Han - MSSV: 102190161" << endl
         << "-------------------------------------------------------------------------" << endl;
    while(true)
    {
        cout << "              CHON SO TUONG UNG VOI CHUC NANG TRONG MENU SAU:" << endl
             << "               1) THEM SACH / BAI BAO"                         << endl
             << "               2) CHINH SUA SACH / BAI BAO"                    << endl
             << "               3) XOA SACH / BAI BAO"                          << endl
             << "               4) HIEN THI DANH SACH CTKH"                     << endl
             << "               5) TIM KIEM SACH / BAI BAO THEO MA CTKH"        << endl
             << "               6) SAP XEP CTKH THEO NAM XUAT BAN"              << endl
             << "               7) THOAT CHUONG TRINH"                          << endl
             << "           Nhap 1, 2, 3, 4, 5, 6 hoac 7 de chon chuc nang"        << endl;
        cin >> key;
        switch (key)
        {
            int chon;
            case 1: //done
                cin >> x;
                Danhap = true;
                system("pause");
                break;
            case 2: //done
                cout << "Nhap ma cong trinh khoa hoc muon sua: ";
                cin >> id;
                x.listUpdateID(id);
                Danhap = true;
                system("pause");
                break;
            case 3:
                cout << "Nhap ma cong trinh khoa hoc muon xoa: ";
                cin >> id;
                x.listRemoveID(id);
                //cout << x;
                Danhap = true;
                system("pause");
                break;
            case 4: // done
                cout << x;
                Danhap = true;
                system("pause");
                break;
            case 5: // done
                cout << "Nhap ma cong trinh khoa hoc muon tim: ";
                cin >> id;
                x.listSearch(id);
                Danhap = true;
                system("pause");
                break;
            case 6: // done
                cout << "Ban muon sap xep (1) Tang dan / (2) Giam dan: ";
                cin >> p;
                if (p==1) x.listArrange(inc);
                if (p==2) x.listArrange(dec);
                else if (p !=1 || p != 2) cout << "Khong ton tai chuc nang nay!";
                Danhap = true;
                system("pause");
                break;
            case 7: // done
                exit(0);
            default: //done
                cout << "Khong co chuc nang nay!";
                Danhap = true;
                system("pause");
                break;
        }
    }
    system("pause");
    return 0;
}