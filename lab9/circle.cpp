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


class Circle{


    friend ostream & operator<<( ostream &output, Circle &C ){
        output << "Point 1: " << C.p1 << " Point 2: " << C.p2 << endl;
        output <<"Radius: " << C.radius() << endl;
        output <<"Diameter: " << C.diameter() << endl;
        output <<"Area: " << C.area() << endl;
        output <<"Circumference: " << C.circumference()<< endl;
        return output;
    }

    friend istream & operator>>( istream &input, Circle &C ){
        input >> C.p1 >> C.p2;
        return input;
    }


public:


    Circle(){
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);

    }

    Circle(Point in_p1, Point in_p2){
        p1.setX(in_p1.getX());
        p1.setY(in_p1.getY());
        p2.setX(in_p2.getX());
        p2.setY(in_p2.getY());
    }

    void setP1(Point in_p){
        p1.setX(in_p.getX());
        p1.setY(in_p.getY());
    }
    void setP2(Point in_p){
        p2.setX(in_p.getX());
        p2.setY(in_p.getY());
    }
    Point getP1(){
        return p1;
    }

    Point getP2(){
        return p2;
    }

    bool isCircle(){
        if (p1==p2){
            return false;
        }
        return true;
    }
    double radius(){
        return sqrt(pow(p1.getX()-p2.getX(),2)+pow(p1.getY()-p2.getY(),2));
    }

    double diameter(){
        return 2*radius();
    }

    double area(){
        return radius()*radius()*M_PI;
    }

    double circumference(){
        return diameter()*M_PI;
    }

    bool operator == (Circle c1){
        if (((c1.getP1()) == p2) && (c1.getP2()==p2) &&(abs(c1.radius()-radius())<=0.0001) && c1.isCircle() && isCircle()){
            return true;
        }
        return false;
    }



private:
    Point p1;
    Point p2;
};

int main()
{
    Point p(0,0);
    Point p2(5,6);

    Circle c1 (p,p2);
    Circle c2 (p,p2);

    if (c1 == c2){
        cout <<"Overload works";
    }


    return 0;
}
