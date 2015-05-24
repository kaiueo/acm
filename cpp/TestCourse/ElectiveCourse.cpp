#include "ElectiveCourse.h"
#include "Course.h"

ElectiveCourse::ElectiveCourse(const string &n, int ch) : Course(n, ch)
{
    setGrade('E');
}

ElectiveCourse::~ElectiveCourse()
{
    //dtor
}


ElectiveCourse & ElectiveCourse::setGrade(char g)
{
    if(g>='A'&&g<='E')
    {
        grade = g;
    }else{
        grade = 'E';
    }
}

int ElectiveCourse::getScore() const
{
    switch(grade)
    {
    case 'A':
        return 95;
        break;
    case 'B':
        return 85;
        break;
    case 'C':
        return 75;
        break;
    case 'D':
        return 65;
        break;
    case 'E':
        return 55;
        break;
    }
}

ostream& operator<<(ostream &output, const ElectiveCourse&c)
{
    output<<"CourseName:"<<c.Course::getName()<<"\tCreditHour:"<<c.Course::getCreditHour();
    return output;
}







