#include "CTr_KH.h"
#include <iostream>
#include <string>
using namespace std;

CTr_KH::CTr_KH()
{
}

CTr_KH::CTr_KH(string c, int n, bool b)
    :ctr_ID(c), pubYear(n), pubArea(b)
{
    // this -> ctr_ID = c;
    // this -> pubYear = n;
    // this -> pubArea = b;
}

CTr_KH::~CTr_KH()
{
}

int CTr_KH::getYear()
{
    return this -> pubYear;
}

string CTr_KH::getID()
{
    return this -> ctr_ID;
}

void CTr_KH::Show()
{
    string a;
    if (this -> pubArea)    a = "Quoc te";
    else a = "Trong nuoc";
    cout << "Ma cong trinh: "<< this->ctr_ID << endl;
    cout << "Nam xuat ban: " << this->pubYear << endl;
    cout << "Khu vuc xuat ban: " << a << endl;
}

int CTr_KH::operator=(CTr_KH& i)
{
    return (this->ctr_ID == i.ctr_ID);
}

void CTr_KH::checkYear()
{
    bool check;
    do
    {
        check = true;
        cout << "Nhap nam xuat ban cong trinh: ";
        try
        {
            cin >> this->pubYear;
            if (pubYear < 1900 || pubYear > 2020)     throw string("Nhap lai nam xuat ban tu 1900 den nay (2020): ");
        }
        catch(string& e)
        {
            cout << e << endl;
            check = false;
        }
        
    } while (check==false);  
}

void CTr_KH::checkArea()
{
    bool check;
    do
    {
        check = true;
        cout << "Nhap khu vuc xuat ban: 1(quoc te) / 0(trong nuoc): ";
        try
        {
            cin >> this->pubArea;
            if(this->pubArea != 1 && this->pubArea != 0) throw string("Nhap lai 1 hoac 0: ");
        }
        catch(string& e)
        {
            cout << e << endl;
            check  = false;
        }
    } while (check == false);  
}

void CTr_KH::Update()
{
    int k;
    cout<< "Nhap muc muon sua:" << endl
        << "1) Ma cong trinh "  << endl
        << "2) Nam xuat ban"    << endl
        << "3) Khu vuc xuat ban"<< endl
        << "Nhap 1, 2 hoac 3 de thuc hien sua: ";
    cin >> k;
    switch (k)
    {
    case 1:
        cout << "Nhap ma cong trinh moi: ";
        cin >> this -> ctr_ID;
        break;
    case 2:
        this->checkYear();
        break;
    case 3:
        this->checkArea();
        break;
    default:
        cout << "Khong ton tai muc can sua!";
        break;
    }
}

ostream& operator<<(ostream& o, const CTr_KH& ct)
{
    string a;
    if (ct.pubArea) a = "Quoc te";
    else a = "Trong nuoc";
    o << "Ma cong trinh: " << ct.ctr_ID << endl;
    o << "Nam xuat ban: " << ct.pubYear << endl;
    o << "Khu vuc xuat ban: " << a << endl << endl;
    return o;
}

istream& operator>>(istream& i, CTr_KH& ct)
{
    cout << "Nhap ma cong trinh: " << endl;
    i >> ct.ctr_ID;
    ct.checkYear();
    ct.checkArea();
    return i;   
}

void CTr_KH::Add()
{
    cout << "Nhap ma cong trinh: " << endl;
    cin >> this -> ctr_ID;
    this -> checkYear();
    this -> checkArea();
}

