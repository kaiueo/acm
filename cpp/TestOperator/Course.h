#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
using namespace std;
class Course
{
    friend ostream& operator<<(ostream &out, const Course &c);
    public:
        Course();
        virtual ~Course();
        Course(const string n, const int h);
        Course(const Course& other);
        Course &setName(const string n);
        string getName() const;
        Course &setCreditHour(int h);
        int getCreditHour() const;
    protected:
    private:
        string name;
        int creditHour;
};

#endif // COURSE_H
