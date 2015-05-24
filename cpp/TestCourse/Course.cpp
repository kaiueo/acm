#include "Course.h"

Course::Course(const string &n, int ch)
{
    name=n;
    creditHour=ch;
}

Course::~Course()
{
    //dtor
}
ostream& operator<<(ostream &output, const Course&c)
{
    output<<"CourseName:"<<c.name<<"\tCreditHour:"<<c.creditHour<<"\tScore: "<<c.getScore();
    return output;
}
