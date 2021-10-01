#pragma once
#include "CTr_KH.h"

class newsPaper : virtual public CTr_KH
{
        string ctr_Name;
        int num_Author;
        CTr_KH* ctkh;
    public:
        newsPaper(string, int, string, int, bool);
        newsPaper(string = " ", int = 0, CTr_KH* = nullptr);
        virtual ~newsPaper();
        void Show();
        void Update();
        void Add();
        friend ostream& operator<<(ostream&, const newsPaper&);
        friend istream& operator>>(istream&, newsPaper&);
};