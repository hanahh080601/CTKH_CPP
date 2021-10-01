#include "newsPaper.h"
#include <iostream>
using namespace std;

newsPaper::newsPaper(string h, int a, CTr_KH* c)
    :ctkh(c), ctr_Name(h), num_Author(a)
{
    // this -> ctr_Name = h;
    // this -> num_Author = a;
}

newsPaper::newsPaper(string name, int num, string id, int year, bool kv)
{
    this -> ctr_Name = name;
    this -> num_Author = num;
    this -> ctr_ID = id;
    this -> pubYear = year;
    this -> pubArea = kv;
}

newsPaper::~newsPaper()
{
}
void newsPaper::Show()
{
    string a;
    if (this -> pubArea)     a = "Quoc te";
    else a = "Trong nuoc";
    cout << "Ten cong trinh khoa hoc: " << this -> ctr_Name << endl;
    cout << "Ma cong trinh khoa hoc: " << this -> ctr_ID << endl;
    cout << "Nam xuat ban: " << this -> pubYear << endl;;
    cout << "Khu vuc xuat ban: " << a << endl;
    cout << "So luong tac gia: "<< this->num_Author << endl << endl;
}

ostream& operator<<(ostream& o, const newsPaper& np)
{
    o << "Ma cong trinh khoa hoc: " << np.ctr_ID << endl;
    o << "Ten cong trinh khoa hoc: " << np.ctr_Name << endl;
    o << "Nam xuat ban: " << np.pubYear << endl;
    o << "Khu vuc xuat ban: " << np.pubArea << endl;
    o << "So luong tac gia: " << np.num_Author << endl << endl; 
    return o;
}

void newsPaper::Update()
{
    int k;
    cout<< "Nhap muc muon sua:"         << endl
        << "1) Ma cong trinh "          << endl
        << "2) Ten cong trinh khoa hoc" << endl
        << "3) Nam xuat ban"            << endl
        << "4) Khu vuc xuat ban"        << endl
        << "5) So luong tac gia"        <<endl
        << "Nhap 1, 2, 3, 4 hoac 5 de thuc hien sua: ";
    cin >> k;
    switch (k)
    {
    case 1:
        cout << "Nhap ma cong trinh moi: ";
        cin >> this -> ctr_ID;
        break;
    case 2:
        cout << "Nhap ten cong trinh khoa hoc moi: ";
        cin.ignore();
        getline(cin, this->ctr_Name);
        break;
    case 3:
        this->checkYear();
        break;
    case 4:
        this->checkArea();
        break;
    case 5:
        cout << "Nhap so luong tac gia moi: ";
        cin >> this -> num_Author;
        break;
    default:
        cout << "Khong ton tai muc can sua!";
        break;
    }
}

void newsPaper::Add()
{
    cout << "Nhap ma cong trinh: ";
    cin >> this -> ctr_ID;
    cout << "Nhap ten cong trinh khoa hoc moi: ";
    cin.ignore();
    getline(cin, this->ctr_Name);
    this->checkYear();
    this->checkArea();
    cout << "Nhap so luong tac gia moi: ";
    cin >> this -> num_Author;
}

istream& operator>>(istream& i, newsPaper& np)
{
    //bool s;
    cout << "Nhap Bai Bao" << endl;
    cout << "Nhap ten bai bao khoa hoc:";
    i.ignore();
    getline(i, np.ctr_Name);
    cout << "Nhap so luong tac gia cua bai bao:";
    i >> np.num_Author;
    cout << "Nhap ma cong trinh khoa hoc: ";
    i >> np.ctr_ID;
    np.checkArea();
    np.checkYear();
    return i;
}
