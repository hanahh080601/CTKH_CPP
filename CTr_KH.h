#include <string>
#include <iostream>
using namespace std;

class CTr_KH
{
    protected:
        string ctr_ID;
        int pubYear;
        bool pubArea;
    public:
        CTr_KH(string, int, bool);
        CTr_KH();
        virtual ~CTr_KH();
        virtual void Show();
        virtual void Update();
        virtual void Add();
        friend ostream& operator<<(ostream&, const CTr_KH&);
        friend istream& operator>>(istream&, CTr_KH&);
        int operator=(CTr_KH&);
        int getYear();
        string getID();
        void checkYear();
        void checkArea();
};

