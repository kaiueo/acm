#ifndef OBLIGATORYCOURSE_H
#define OBLIGATORYCOURSE_H

#include "Course.h"


class ObligatoryCourse : public Course
{
    friend ostream& operator<<(ostream &, const ObligatoryCourse&);
    public:
        ObligatoryCourse(const string &n, int ch);
        virtual ~ObligatoryCourse();
        ObligatoryCourse& setMark(int m);
        int getScore() const;
    protected:
    private:
        int mark;
};

#endif // OBLIGATORYCOURSE_H
