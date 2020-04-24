#ifndef _STUDENT_H
#define _STUDENT_H

#include <string>

struct Student{
    string name;
    int score;

    bool operator<(const Student &otherStudent){
        return score < otherStudent.score;
    }

    friend ostream& operator<<(ostream &os, const Student &student){
        os<<"Student: " << student.name << Student.score << std::endl;
        return os;
    }
}

#endif 