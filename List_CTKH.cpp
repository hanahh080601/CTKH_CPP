#include "List_CTKH.h"
#include <iostream>
using namespace std;

template <class T>
List_CTKH<T>::List_CTKH()                                           // Hàm dựng mặc định (done)
    :per_Name(" "), num_CTKH(0), list(nullptr)
{
}

template <class T>
List_CTKH<T>::List_CTKH(string c, int n)                            // Hàm dựng tham số (done)
{
    this -> per_Name = c;
    this -> num_CTKH = n;
}

template <class T>
List_CTKH<T>::~List_CTKH()                                          // Hàm hủy (done)
{
    delete[] this -> list;
}

template <class T>
void List_CTKH<T>::listAdd(const T& t)                              // Hàm thêm vào cuối danh sách (done)
{
    if (this -> num_CTKH <= 0)
    {
        this -> list = new T[this -> num_CTKH + 1];
        this -> list[this -> num_CTKH] = t;
    }
    else
    {
        T* temp = new T[this->num_CTKH + 1];
        for(int i = 0; i < this->num_CTKH; ++i)
        {
            *(temp + i) = *(this -> list + i);
        }
        delete[] this -> list;
        this -> list = new T[this -> num_CTKH + 1];
        for(int i = 0; i < this ->num_CTKH; ++i)
        {
            *(this -> list + i) = *(temp + i);
        }
        this -> list[this -> num_CTKH] = t;
    }
    this -> num_CTKH ++;
}

template <class T>
void List_CTKH<T>::listRemoveAt(const int& id)                      // Hàm xóa đối tượng tại vị trí id trong DS (done)
{
    T *temp = new T[this -> num_CTKH];
    for(int i = 0; i < this -> num_CTKH; ++i)
    {
        *(temp + i) = *(this -> list + i);
    }
    delete[] this -> list;
    this -> list = new T[this -> num_CTKH - 1];
    for(int i = 0; i < this -> num_CTKH; ++i)
    {
        if (i == id) 
        {
            for(int k = id; k < this -> num_CTKH; ++k)
            {
                *(this -> list + k) = *(temp + k + 1);
            }
            break;
        }
        else *(this -> list + i) = *(temp + i);
    }
    this -> num_CTKH--;
}

template <class T>
void List_CTKH<T>::listRemoveID(string del)                             // Hàm xóa theo mã CTKH (done)
{
    int t = this->listSearch(del);
    this->listRemoveAt(t);
    cout << "Danh sach cong trinh khoa hoc sau khi xoa: " << endl << endl;
    this->listShow();
}

template <class T>
void List_CTKH<T>::listShow()                                           // Hàm in danh sách (done)
{
    for(int i=0;i<this->num_CTKH;++i)
    {
        this->list[i]->Show();
    }
}

template <class T>
int List_CTKH<T>::ListIndexOf(const T& t)                           // Hàm trả về vị trí của dối tượng T trong danh sách (done)
{
    for(int i=0;i<this->num_CTKH;++i)
    {
        if(this->list[i] == t) return i;
    }
    return -1;
}

template <class T>
void List_CTKH<T>::listUpdate(T& t)                                     // Hàm sửa đối tượng t (done)
{
    if (ListIndexOf(t) != -1)
    {
        for(int i=0;i<this->num_CTKH;++i)
        {
            if (this->list[i] == t)
            this->list[i]->Update();
        }
    }
    else cout << "Khong tim thay!";
}

template <class T>
void List_CTKH<T>::listUpdateID(string& s)                              // Hàm sửa theo mã CTKH (done)
{
    if(this->listSearch(s) != -1)
    {
        this->list[this->listSearch(s)]->Update();
    }
    else cout << "Khong tim thay!";
}

template <class T>
T& List_CTKH<T>::operator[](const int& k)                               // Đa năng hóa toán tử truy cập (done)
{
    T t;
    return (k >= 0 && k < this->num_CTKH) ? *(this -> list + k) : t;
}

template <class T>
int List_CTKH<T>::listSearch(string id)                                 // Hàm tìm kiếm theo mã CTKH (done)
{
    int i;
    for(i = 0; i < this->num_CTKH; ++i)
    {
        if (this->list[i]->getID() == id)  
        {
            cout << "Cong trinh ban tim kiem:" << endl << endl;
            this->list[i]->Show();
            break;
        }  
    }
    if (i==num_CTKH) return -1;
    else return i;
}

template <class T>
bool inc(T& a, T& b)
{
    return (a->getYear() > b->getYear()) ? 1 : 0;
}

template <class T>
bool dec(T*& a, T*& b)
{
    return ((*a).getYear() < (*b).getYear()) ? 1 : 0;
}

template <class T>
void List_CTKH<T>::listArrange(bool(cmp)(T& a, T& b))                          // Hàm sắp xếp sd con trỏ hàm (done)
{
    for(int i = 0; i < this -> num_CTKH - 1; ++i)
    {
        for(int j = i + 1; j < this->num_CTKH; ++j)
        {
            if(cmp(*(this -> list + i), *(this -> list + j)))
            {
                T temp = *(this -> list + i);
                *(this -> list + i) = *(this -> list + j);
                *(this -> list + j) = temp;
            }
        }
    }
    this->listShow();
}

template<class Y>
ostream& operator<<(ostream& o, const List_CTKH<Y>& db)                           // Đa năng hóa tt xuất (done)
{
    o << "Danh sach tat ca cong trinh khoa hoc" << endl << endl;
    for(int i = 0; i < db.num_CTKH; ++i)
    {
        db.list[i]->Show();
    }
    return o;
}

template<class Y>
istream& operator>>(istream& i, List_CTKH<Y>& db)                                   // Đa năng hóa tt nhập (done)
{
    int n;
    cout << "Nhap ten ca nhan: ";
    i.ignore();
    getline(i, db.per_Name);
    cout << "Nhap so luong sach hoac bao muon nhap: ";
    cin >> n;
    for(int j = 0; j < n; j++)
    {
        int type;
        cout << "Ban muon nhap (1)-Sach / (2)-Bao: ";
        cin >> type;
        if (type == 1)
        {
            Y bao = new newsPaper;
            bao -> Add();
            db.listAdd(bao);
        }
        if (type == 2)
        {
            Y sach = new Book;
            sach-> Add();
            db.listAdd(sach);
        }
    }
    cout << "Nhap thanh cong!" << endl;
    return i;
}





