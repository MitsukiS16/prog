#include <iostream>
using namespace std;

bool isLeapYear(int y){
    if(y % 100 == 0 && y % 400 != 0)
        return false;
    
    if(y % 4 == 0){
        return true;
    }
    
    return false;
}

int getDaysInMonth(int m, bool leapyear){
    if(m == 2) return (leapyear) ? 29 : 28;
    return (m == 4 || m == 6 || m == 9 || m == 11) ? 30 : 31;
}

void advance(int delta, int &d, int &m, int &y){
    int d_temp = d;
    int m_temp = m;
    int y_temp = y;

    while(delta > 0){

        bool leapYear = isLeapYear(y_temp);
        int daysInMonth = getDaysInMonth(m_temp, leapYear);
        bool fitsInMonth = d_temp + delta <= daysInMonth;
        int offs = (fitsInMonth) ? delta : daysInMonth - d_temp;

        d_temp += offs;
        delta -= offs;

        if(!fitsInMonth){
            d_temp = d_temp % daysInMonth;
            m_temp += 1;

            if(m_temp > 12){
                y_temp += 1;
                m_temp = 1;
            }
        }
    }
    d = d_temp;
    m = m_temp;
    y = y_temp;
}
