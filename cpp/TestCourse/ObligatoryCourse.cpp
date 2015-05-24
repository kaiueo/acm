#include "ObligatoryCourse.h"

ObligatoryCourse::ObligatoryCourse(const string &n, int ch) : Course(n, ch)
{
    setMark(0);
}

ObligatoryCourse::~ObligatoryCourse()
{
    //dtor
}

ObligatoryCourse& ObligatoryCourse::setMark(int m)
{
    if(m>=0&&m<=100)
    {
        mark = m;
    }
    else{
        mark = 0;
    }
}

int ObligatoryCourse::getScore() const
{
    return mark;
}

ostream& operator<<(ostream &output, const ObligatoryCourse&c)
{
    output<<"CourseName:"<<c.Course::getName()<<"\tCreditHour:"<<c.Course::getCreditHour();
    return output;
}







