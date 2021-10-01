#pragma once
#include "newsPaper.h"

class Book : virtual public CTr_KH
{
    string book_Type;
    CTr_KH* ctkh;
    public:
        Book(string = " ", CTr_KH* = nullptr);
        Book(string, string, int, bool);
        virtual ~Book();
        void Show();
        void Update();
        void Add();
        friend ostream& operator<<(ostream&, const Book&);
        friend istream& operator>>(istream&, Book&);
};