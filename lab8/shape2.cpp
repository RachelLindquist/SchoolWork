#include <iostream>
#include <cmath>

using namespace std;

class Torus{
public:


    Torus(double r =0, double R =0){
        bigR = R;
        smallR = r;
    }
    double getBR(){
        return bigR;
    }

    double getSR(){
        return smallR;
    }

    void setBR(double R){
        bigR = R;
    }

    void setSR(double r){
        smallR = r;
    }

    void display(){
        cout <<"Torus Parameters: " << endl;
        cout <<"R: " << getBR() << endl;
        cout <<"r: " << getSR() << endl;
        cout <<"Volume :" << getV() << endl;
        cout <<"Surface Area: " << getSA() << endl << endl;
    }
private:
    double bigR;
    double smallR;

    double getV(){
        return 2* M_PI*M_PI*bigR*smallR*smallR;
    }

    double getSA(){
        return 4*M_PI*M_PI*bigR*smallR;
    }



};

int main()
{
    Torus t1;
    t1.display();

    Torus t2(3,7);
    t2.display();

    t2.setBR(10);
    t2.display();

    return 0;
}
