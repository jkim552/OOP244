#include <iostream>
using namespace std;
class Seminar

{

    int time;

public:

    Seminar()        //Function 1

    {

        time = 30;

        cout << "Seminar starts now on " << endl;

    }



    void lecture()        //Function 2

    {

        cout << "Lectures in the seminar" << endl;

    }



    Seminar(int duration)        //Function 3

    {

        time = duration;

        cout << "Seminar starts now on " << time << " minutes" << endl;

    }



    ~Seminar()        //Function 4

    {

        cout << "Thanks " << endl;

    }

};

int main() {
    Seminar s2(20);
    Seminar s1;
    return 0;
}