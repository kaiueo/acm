#ifndef ELECTIVECOURSE_H
#define ELECTIVECOURSE_H

#include "Course.h"


class ElectiveCourse : public Course
{
    friend ostream& operator<<(ostream &, const ElectiveCourse&);
    public:
        ElectiveCourse(const string &n, int ch);
        virtual ~ElectiveCourse();

        ElectiveCourse& setGrade(char g);
        int getScore() const;
    protected:
    private:
        char grade;
};

#endif // ELECTIVECOURSE_H
