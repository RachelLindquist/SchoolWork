#include <iostream>

using namespace std;

#include <iostream>
#include<fstream>
#include <sstream>
#include <vector>
#include <cctype>
#include <string>
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
        if (((c1.getP1()) == p1) && (c1.getP2()==p2) && (c1.getP3() == p3) && isTri() && c1.isTri()){
            return true;
        }
        return false;
    }


private:
    Point p1;
    Point p2;
    Point p3;
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
    ifstream shapes;
    shapes.open("shapes.txt");

    ofstream shapeInfo;
    shapeInfo.open("shapes-info.txt");
    if (shapes.is_open()){
        while(!shapes.eof()){
            stringstream ss;
            vector <double> points;
            string temp;
            getline (shapes,temp);
            ss << temp;


            cout << temp << endl;
            while (!ss.eof()){
                double t;
                ss >> t;
                points.push_back(t);
            }
            cout << points.size() << endl;
            if (points.size() == 6){
                //triangle
                shapeInfo << "Sufficient coordinates input." << endl;
                Point p1(points.at(0),points.at(1));
                Point p2(points.at(2),points.at(3));
                Point p3(points.at(4),points.at(5));
                Triangle tri (p1,p2,p3);
                if (tri.isTri()){
                    shapeInfo <<"The object is a Triangle." << endl;
                    shapeInfo <<"Area of the Triangle: " << tri.area() << " sq. units" << endl;
                    shapeInfo << "Perimeter of the triangle " << tri.perimeter() << " units" << endl;
                    if (tri.equilateral()){
                        shapeInfo << "The triangle is an equilateral triangle" << endl << endl;

                    } else{
                        shapeInfo <<"The triangle is not an equilateral triangle" << endl << endl;
                    }
                } else {
                    shapeInfo << "The object is not a Triangle." << endl << endl;
                }
            } else if (points.size() == 8){
                //quad
                shapeInfo << "Sufficient coordinates input." << endl;
                Point p1(points.at(0),points.at(1));
                Point p2(points.at(2),points.at(3));
                Point p3(points.at(4),points.at(5));
                Point p4(points.at(6),points.at(7));
                Quadrilateral quad (p1,p2,p3,p4);
                if (quad.isQuad()){
                    shapeInfo <<"The object is a Quadrilateral." << endl;
                    shapeInfo <<"Area of the Quadrilateral: " << quad.area() << " sq.units" << endl << endl;
                } else {
                    shapeInfo << "The object is not a Quadrilateral." << endl << endl;
                }
            } else if (points.size() == 4){
                //circle
                shapeInfo << "Sufficient coordinates input." << endl;
                Point p1(points.at(0),points.at(1));
                Point p2(points.at(2),points.at(3));
                Circle cir(p1,p2);
                if (cir.isCircle()){
                    shapeInfo << "The object is a Circle" << endl;
                    shapeInfo <<"Radius of the Circle: " << cir.radius() << " unit"<< endl;
                    shapeInfo <<"Diameter of the Circle: " << cir.diameter() << " units" << endl;
                    shapeInfo <<"Area of the Circle: " << cir.area() << " units" << endl;
                    shapeInfo << "Circumference of the Circle:" << cir.circumference() << " units" << endl<< endl;
                } else {
                    shapeInfo << "The object is not a Circle." << endl << endl;
                }

            } else {
                shapeInfo << "Sufficient coordinates NOT input. " << endl << endl;
            }
            if (shapes.eof()){
                break;
            }
        }

    }
    shapes.close();
    shapeInfo.close();

    return 0;

}
