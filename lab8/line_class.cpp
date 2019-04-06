// Add your information here

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include<cmath>


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

    Point(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
    // Add your functions here

    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void setPoint(int in_x, int in_y){
        x = in_x;
        y = in_y;
    }
    void setY(int in_y){
        y = in_y;
    }

    void setX(int in_x){
        x = in_x;
    }


private:
    int x,y;
};

class Line {
    // implement cout for Line classes objects
    friend ostream & operator<<( ostream &output, const Line &L ){
        output << "Point 1: " << L.P1 << endl << "Point 2: " << L.P2;
        return output;
    }

    // implement cin for Line classes objects
    friend istream & operator>>( istream &input, Line &L ){
        input >> L.P1 >> L.P2;
        return input;
    }

public:
    // Add your functions/methods here //
    Line(){
        P1.setPoint(0,0);
        P2.setPoint(0,0);
    }
    Line(int x1, int y1, int x2, int y2){
        P1.setPoint(x1,y1);
        P2.setPoint(x2,y2);
    }
    void setLine(Point one, Point two){
        P1.setX(one.getX());
        P1.setY(one.getY());
        P2.setX(two.getX());
        P2.setY(two.getY());
    }

    void setFirstPoint(Point one){
        P1.setX(one.getX());
        P1.setY(one.getY());
    }

    void setSecondPoint(Point two){
        P2.setX(two.getX());
        P2.setY(two.getY());
    }

    Point getFirstPoint(){
        return P1;
    }

    Point getSecondPoint(){
        return P2;
    }
    double getSlope(){
        return ((P1.getY()-P2.getY())/(P1.getX()-P2.getX()));
    }
    double getLength(){
        int x = P1.getX()-P2.getX();
        int y = P1.getY()-P2.getY();
        return sqrt((x*x)+(y*y));
    }

    double getYIntercept(){
        return P1.getY() - getSlope()*P1.getX();
    }

    bool vertical(){
        if (P1.getX() == P2.getX()){
            return true;
        }
        return false;
    }

    bool horizontal(){
        if (P1.getY() == P2.getY()){
            return true;
        }
        return false;
    }

    bool parallel(Line secondLine){
        if (getSlope() == secondLine.getSlope()){
            return true;
        }
        return false;
    }

    void Print(){
        cout <<"Point 1: " << P1 << endl;
        cout <<"Point 2: " << P2 << endl;
        cout <<"Slope: " << getSlope() << endl;
        cout <<"Length: " << getLength() << endl;
        cout <<"Y-intercept: (0," << getYIntercept()<< ")" << endl;
        cout <<"Vertical: " << vertical() << endl;
        cout <<"Horizontal: " << horizontal() << endl;

    }

private:
    Point P1, P2;
};

int main(){
    Line L1;
    Line L2(5,6,7,8);
    cout << "L1: should have all zeros for values" << endl;
    cout << L1 << endl;

    cout << "Enter Two Points For Line: ";
    cin >> L1;
    cout << L1 << endl;
    if (L1.parallel(L2)){
        cout <<"L1 and L2 are parallel" << endl; // easy test is 1 2 3 4 for points in L1
    } else {
        cout <<"L1 and L2 are not parallel" << endl;
    }
    L1.Print();
    L2.Print();
    //For L2:
    //Point 1: x: 5 y: 6
    //Point 2: x: 7 y: 8
    //Slope: 1
    //Length: 2.82843
    //Y-intercept: (0,1)
    //Vertical: 0
    //Horizontal: 0


    Line L3 (0,5,0,7);
    cout << L3.vertical() << endl; // true
    cout <<L3.horizontal() << endl; // false

    Line L4 (2,0,9,0);
    cout << L4.vertical() << endl; // false
    cout <<L4.horizontal() << endl; // true




    return 0;
}
