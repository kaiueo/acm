#include "Course.h"

Course::Course()
{
    name = "";
    creditHour = 0;
}

Course::~Course()
{
    //dtor
}

Course::Course(const Course& other)
{
    setName(other.getName());
    setCreditHour(other.getCreditHour());
}

Course::Course(const string n, const int h)
{
    setName(n);
    setCreditHour(h);
}


Course &Course::setName(const string n)
{
    name = n;
    return (*this);
}
string Course::getName() const{
    return name;
}
Course &Course::setCreditHour(const int h){
    creditHour = h;
    return (*this);
}
int Course::getCreditHour() const{
    return creditHour;
}

ostream& operator<<(ostream &out, const Course &c){
    out<<"课程名："<<c.getName()<<" 学分："<<c.getCreditHour()<<endl;
    return out;
}
