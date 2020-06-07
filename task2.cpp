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
    friend Date laterDate (Date &d1, Date &d2);
    friend void exchange (Date &d1, Date &d2);
};

ostream& operator << (ostream &out, const Date &date) {
    out << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
    return out;
}

Date laterDate(Date &d1, Date &d2) {
    int first = d1.m_day + d1.m_month * 31 + d1.m_year * 365;
    int second = d2.m_day + d2.m_month * 31 + d2.m_year * 365;
    if (first > second)
        return d1;
    else
        return d2;
}
void exchange(Date& d1, Date& d2) {
    Date temp;
    temp = move(d1);
    d1 = move(d2);
    d2 = move(temp);
}

int main() {
    unique_ptr<Date> date1 (new Date);
    unique_ptr<Date> date2 (new Date);
    date1->setDay(4);
    date1->setMonth(6);
    date1->setYear(2020);
    date2->setDay(10);
    date2->setMonth(6);
    date2->setYear(2020);
    cout << "Date1: "  << *date1;
    cout << "Date2: " << *date2;
    cout << "Later date is Date2: " << laterDate(*date1, *date2);
    exchange(*date1, *date2);
    cout << "Date1: " << *date1;
    cout << "Date2: " << *date2;

    return 0;
}

