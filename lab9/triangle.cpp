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


class Triangle{


    friend ostream & operator<<( ostream &output, Triangle &C ){
        output << "Point 1: " << C.p1 << " Point 2: " << C.p2 << " Point 3: " << C.p3 << endl;
        output <<"Area " << C.area() << endl;
        output <<"Perimeter " << C.perimeter() << endl;
        output <<"Equilateral: " << C.equilateral() << endl;
        return output;
    }

    friend istream & operator>>( istream &input, Triangle &C ){
        input >> C.p1 >> C.p2 >> C.p3;
        return input;
    }


public:


    Triangle(){
        p1.setX(0);
        p1.setY(0);
        p2.setX(0);
        p2.setY(0);
        p3.setY(0);
        p3.setX(0);

    }

    Triangle(Point in_p1, Point in_p2, Point in_p3){
        p1.setX(in_p1.getX());
        p1.setY(in_p1.getY());
        p2.setX(in_p2.getX());
        p2.setY(in_p2.getY());
        p3.setX(in_p3.getX());
        p3.setY(in_p3.getY());
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
    Point getP1(){
        return p1;
    }

    Point getP2(){
        return p2;
    }

    Point getP3(){
        return p3;
    }
    bool isTri(){
        if (abs(p1.getX()*(p2.getY()-p3.getY()) + p2.getX()*(p3.getY()-p1.getY()) + p3.getX() * (p1.getY()-p2.getY())) <= 0.001){
            return false;
        }
        if ((abs(p1.getX() - p2.getX()) <= 0.001) && (abs(p1.getX() - p3.getX()) <= 0.001)){
            return false;
        }
        if ((abs(p1.getY() - p2.getY()) <= 0.001) && (abs(p1.getY() - p3.getY()) <= 0.001)){
            return false;
        }
        return true;
    }

    double area(){
        double p = perimeter()/2;
        double s1 = sqrt(pow((p1.getX() - p2.getX()),2)+pow((p1.getY() - p2.getY()),2));
        double s2 = sqrt(pow((p1.getX() - p3.getX()),2) + pow((p1.getY() - p3.getY()),2));
        double s3 = sqrt(pow((p2.getX() - p3.getX()),2)+ pow((p2.getY() - p3.getY()),2));
        return sqrt(p*(p-s1)*(p-s2)*(p-s3));
    }
    double perimeter(){
        double s1 = sqrt(pow((p1.getX() - p2.getX()),2)+pow((p1.getY() - p2.getY()),2));
        double s2 = sqrt(pow((p1.getX() - p3.getX()),2) + pow((p1.getY() - p3.getY()),2));
        double s3 = sqrt(pow((p2.getX() - p3.getX()),2)+ pow((p2.getY() - p3.getY()),2));
        return s1+s2+s3;
    }
    bool equilateral(){
        double s1 = sqrt(pow((p1.getX() - p2.getX()),2)+pow((p1.getY() - p2.getY()),2));
        double s2 = sqrt(pow((p1.getX() - p3.getX()),2) + pow((p1.getY() - p3.getY()),2));
        double s3 = sqrt(pow((p2.getX() - p3.getX()),2)+ pow((p2.getY() - p3.getY()),2));
        if (abs(s1-s2) <= 0.0001 && abs(s1-s3) <=0.001){
            return true;
        }
        return false;
    }

    bool operator == (Triangle c1){
        if (((c1.getP1()) == p1) && (c1.getP2()==p2) && (c1.getP3() == p3) &&isTri() && c1.isTri()){
            return true;
        } else {
            return false;
        }
    }



private:
    Point p1;
    Point p2;
    Point p3;
};


int main()
{
    // testing
    Point p (0,3);
    Point p2(4,5);
    Point p3 (6,7);

    Triangle t1(p,p2,p3);
    Triangle t2(p,p2,p3);
    if (t1 == t2){
        cout << "Operator == works" << endl;
    } else {
        cout <<"fail" << endl;
    }

    return 0;
}
