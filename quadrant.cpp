#include <iostream>

using namespace std;


int whichQuadrant(int x, int y){
	if (x == 0 && y == 0){
		cout << "Center Point" << endl;
		return 'C';
	} else if (x == 0 && y != 0){
		cout << "On Y-Axis" << endl;
		return 'X';
	} else if (x!=0 && y== 0){
		cout << "On X-Axis" << endl;
		return 'Y';
	} else if (x > 0 && y > 0){
		cout << "Quadrant is Q1" << endl;
		return 1;
	} else if (x < 0 && y > 0){
		cout << "Quadrant is Q2" << endl;
		return 2;
	} else if (x < 0 && y < 0){
		cout << "Quadrant is Q3" << endl;
		return 3;
	} else{
		cout <<"Quadrant is Q4" << endl;
		return 4;
	}
	
}


int main (){
	int x,y;
	
	cout <<"Enter X Y Pair: " << endl;
	
	cin >> x;
	cin >> y;
	cout << endl;
	
	
	
	return 0;
}

