#pragma once
#include "newsPaper.h"
#include "Book.h"

template<class T>

class List_CTKH
{
        string per_Name;
        int num_CTKH;
        T* list; // T là newsPaper* hoặc Book*
    public:
        List_CTKH(string, int);                     // Hàm dựng tham số
        List_CTKH();                                // Hàm dựng mặc định
        ~List_CTKH();                               // Hàm hủy
        void listAdd(const T&);                     // Thêm vào cuối ds
        int ListIndexOf(const T&);                  // Lấy vị trí của đối tượng truyền vào
        void listUpdate(T&);                        // Chỉnh sửa đối tượng kiểu T
        void listUpdateID(string&);                 // Chỉnh sửa theo mã CTKH
        void listRemove(const T&);                  // Xóa đối tượng kiểu T 
        void listRemoveAt(const int&);              // Xóa đối tượng theo thứ tự trong DS
        void listRemoveID(string);                  // Xóa đối tượng theo mã CTKH
        void listShow();                            // In ra danh sách CTKH (kể cả sách và báo)
        int listSearch(string);                     // Tìm kiếm CTKH theo mã CTKH
        void listArrange(bool(*compare)(T&, T&));   // Sắp xếp theo năm XB
        template <class Y>                          // Đa năng hóa
        friend ostream& operator<<(ostream&, const List_CTKH<Y>&);
        template <class Y>
        friend istream& operator>>(istream&, List_CTKH<Y>&);
        T& operator[](const int&);
        const T& operator=(const T&);
};

// Các chức năng: 
// Đa năng hóa toán tử nhập, xuất, truy cập [], gán =
// Chức năng quản lí: thêm, sửa, xóa, hiển thị, tìm kiếm, sắp xếp
// Sử dụng: con trỏ hàm, template, exception, object relationship;