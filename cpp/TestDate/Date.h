#ifndef DATE_H
#define DATE_H


class Date
{
    public:
        Date();
        Date(int y, int m, int d);
        virtual ~Date();
        Date(const Date& other);
        void setYear(int y);
        void setMonth(int m);
        void setDay(int d);
        int getYear();
        int getMonth();
        int getDay();
        bool isLeapYear(int y);
        void nextDay();
        void print();
    protected:
    private:
        int year;
        int month;
        int day;
        bool isYearValid(int y);
        bool isMonthValid(int m);
        bool isDayValid(int d);
};

#endif // DATE_H
