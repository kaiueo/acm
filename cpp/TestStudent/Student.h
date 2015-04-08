#ifndef STUDENT_H
#define STUDENT_H
#include "Date.h"


class Student
{
    public:
        Student(const char* const n, const Date &b);
        Student(const char* const n, int y, int m, int d);
        virtual ~Student();
        Student(const Student& other);
        void setName(const char* const n);
        const char *getName() const;
        const Date getBirthDate();
        static const int getCount();
        void print() const;
    protected:
    private:
        const Date birthDate;
        static int count;
        char *name;
};

#endif // STUDENT_H
