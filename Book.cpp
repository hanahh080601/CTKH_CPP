#include "Book.h"

Book::Book(string h, CTr_KH* ctkh)
    :ctkh(ctkh), book_Type(h)
{
    // this -> book_Type = h;
}

Book::Book(string type, string id, int year, bool kv)
{
    this -> book_Type = type;
    this -> ctr_ID = id;
    this -> pubYear = year;
    this -> pubArea = kv;
}

Book::~Book()
{
}

void Book::Show()
{
    string a;
    if (this -> pubArea)    a = "Quoc te";
    else a = "Trong nuoc";
    cout << "Ten loai sach: " << this->book_Type << endl;
    cout << "Ma cong trinh khoa hoc: " << this->ctr_ID << endl;
    cout << "Nam xuat ban: " << this->pubYear << endl;
    cout << "Khu vuc xuat ban: " << a << endl << endl;
}

void Book::Update()
{
    int k;
    cout<< "Nhap muc muon sua:" << endl
        << "1) Ma cong trinh "  << endl
        << "2) Nam xuat ban"    << endl
        << "3) Khu vuc xuat ban"<< endl
        << "4) The loai sach"   << endl
        << "Nhap 1, 2, 3 hoac 4 de thuc hien sua: ";
    cin >> k;
    switch (k)
    {
    case 1:
        cout << "Nhap ma cong trinh moi: ";
        cin >> this -> ctr_ID;
        break;
    case 2:
        cout << "Nhap nam xuat ban moi: ";
        cin >> this -> pubYear;
        break;
    case 3:
        cout << "Nhap khu vuc xuat ban moi: true(quoc te) / false(trong nuoc): ";
        cin >> this -> pubArea;
        break;
    case 4:
        cout << "Nhap the loai sach moi: ";
        cin.ignore();
        getline(cin, this -> book_Type);
        break;
    default:
        cout << "Khong ton tai muc can sua!";
        break;
    }
}

void Book::Add()
{
    cout << "Nhap ten loai sach: ";
    cin.ignore();
    getline(cin, this -> book_Type);
    cout << "Nhap ma cong trinh khoa hoc: ";
    cin >> this -> ctr_ID;
    this -> checkYear();
    this -> checkArea();   
}

ostream& operator<<(ostream& o, const Book& b)
{
    o << "Ten loai sach: " << b.book_Type << endl;
    o << "Ma cong trinh khoa hoc: " << b.ctr_ID << endl;
    o << "Nam xuat ban: " << b.pubYear << endl;
    o << "Khu vuc xuat ban: " << b.pubArea << endl;
    return o;
}

istream& operator>>(istream& i, Book& b)
{
    cout << "Nhap ten loai sach: " << endl;
    i.ignore();
    getline(i, b.book_Type);
    cout << "Nhap ma cong trinh khoa hoc: " << endl;
    i >> b.ctr_ID;
    b.checkYear();
    b.checkArea();
    return i;
}


