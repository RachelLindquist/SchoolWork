#include <iostream>

using namespace std;

class Cube {
public:
    Cube(){
        setL(0);
    }

    Cube(double length){
        setL(length);
    }

    double getL(){
        return l;
    }

    void setL(double length){
        l = length;
    }

    void display(){
        cout <<"Cube Parameters: " << endl;
        cout <<"Length: " << getL() << endl;
        cout <<"Volume: " << getV() << endl;
        cout << "Surface Area: " << getSA() << endl << endl;
    }

private:
    double getV(){
        return l*l*l;
    }
    double getSA(){
        return 6 * l *l;
    }
    double l;

};

int main()
{
    Cube c1;
    c1.display();

    Cube c2(5);
    c2.display();

    c2.setL(3);
    c2.display();



    return 0;
}
