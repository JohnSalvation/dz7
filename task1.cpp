#include <iostream>
#include <memory>

using namespace std;

class Date {
private:
    int m_day, m_month, m_year;
public:
    Date(int d = 1, int m = 1, int y = 2020) : m_day(d), m_month(m), m_year(y) {}
    void setDay(int day) {m_day = day;}
    void setMonth(int month) {m_month = month;}
    void setYear(int year) {m_year = year;}
    int getDay() {return m_day;}
    friend ostream& operator << (ostream &out, const Date &date);
};

ostream& operator << (ostream &out, const Date &date) {
    out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
    return out;
}

void isNull(unique_ptr<Date> &d) {
    if(d)
        cout << "Not null" << endl;
    else
        cout << "Null" << endl;
}

int main() {
    unique_ptr<Date> today (new Date);
    unique_ptr<Date> date;
    today->setDay(4);
    today->setMonth(6);
    today->setYear(2020);
    cout << *today;
    isNull(today);
    isNull(date);
    date = move(today);
    cout << *date;
    isNull(today);
    isNull(date);
return 0;
}


