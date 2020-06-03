#include <iostream>
using namespace std;


class Student
{
    private:
        int score_point;

    public:
        //getter 
        void setPoint(int sP)
        {
            score_point = sP;
        }
        //setter
        void getPoint()
        {
            return score_point;
        }
}

int main()
{
    Student student;
    student.setPoint(100);
    cout<<student.getPoint();
    return 0;
}
