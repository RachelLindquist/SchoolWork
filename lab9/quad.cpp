#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cmath>

using namespace std;

class Point {

    // cout implementation for Point class
    friend ostream & operator<<( ostream &output, const Point &P ){
        output << "x: " << P.x << " y: " << P.y;
        return output;
    }

    // cin implementation for Point class
    friend istream & operator>>( istream &input, Point &P ){
        input >> P.x >> P.y;
        return input;
    }

public:
    Point(){
        x = 0;
        y = 0;
    }

    Point(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }


    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    void setPoint(double in_x, double in_y){
        x = in_x;
        y = in_y;
    }
    void setY(double in_y){
        y = in_y;
    }

    void setX(double in_x){
        x = in_x;
    }

    bool operator==(Point &rhs) {
        return (abs(rhs.x - x) <=0.0001 && abs(rhs.y - y) <= 0.0001);
    }



private:
    double x,y;
};


class Quadrilateral{


    friend ostream & operator<<( ostream &output, Quadrilateral &C ){
        output << "Point 1: " << C.p1 << " Point 2: " << C.p2 << " Point 3: " << C.p3 << " Point 4: " << C.p4 << endl;
        output <<"Area " << C.area() << endl;

        return output;
    }

    friend istream & operator>>( istream &input, Quadrilateral &C ){
        input >> C.p1 >> C.p2 >> C.p3 >> C.p4;
        return input;
    }
public:


    Quadrilateral(){
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
        p3.setY(0);
        p3.setX(0);
        p4.setX(0);
        p4.setY(0);

    }

    Quadrilateral(Point in_p1, Point in_p2, Point in_p3, Point in_p4){
        p1.setX(in_p1.getX());
        p1.setY(in_p1.getY());
        p2.setX(in_p2.getX());
        p2.setY(in_p2.getY());
        p3.setX(in_p3.getX());
        p3.setY(in_p3.getY());
        p4.setX(in_p4.getX());
        p4.setY(in_p4.getY());
    }

    void setP1(Point in_p){
        p1.setX(in_p.getX());
        p1.setY(in_p.getY());
    }
    void setP2(Point in_p){
        p2.setX(in_p.getX());
        p2.setY(in_p.getY());
    }
    void setP3(Point in_p){
        p3.setX(in_p.getX());
        p3.setY(in_p.getY());
    }

    void setP4(Point in_p){
        p4.setX(in_p.getX());
        p4.setY(in_p.getY());

    }
    Point getP1(){
        return p1;
    }

    Point getP2(){
        return p2;
    }

    Point getP3(){
        return p3;
    }
    Point getP4(){
        return p4;
    }
    bool isQuad(){
        if (abs(p1.getX()*(p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY()) + p3.getX() * (p1.getY()-p2.getY())) <= 0.001){
            return false;
        }
        if (abs(p2.getX()*(p3.getY()-p4.getY()) + p3.getX()*(p4.getY()-p2.getY()) + p4.getX() * (p2.getY()-p3.getY())) <= 0.001){
            return false;
        }
        if (abs(p1.getX()*(p3.getY()-p4.getY()) + p3.getX()*(p4.getY()-p1.getY()) + p4.getX() * (p3.getY()-p1.getY())) <= 0.001){
            return false;
        }
        if (abs(p1.getX()*(p2.getY()-p4.getY()) + p2.getX()*(p4.getY()-p1.getY()) + p4.getX() * (p1.getY()-p2.getY())) <= 0.001){

        }
        return true;
    }

    double area(){
        return abs(p1.getX()*p2.getY() + p2.getX() * p3.getY() + p3.getX() * p4.getY() + p4.getX() * p1.getY() - p2.getX() * p1.getY() - p3.getX() * p2.getY() - p4.getX() *p3.getY() - p1.getX() * p4.getY())/2;

    }




private:
    Point p1;
    Point p2;
    Point p3;
    Point p4;
};

int main()
{

    return 0;
}

