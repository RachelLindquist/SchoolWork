#include <iostream>
#include <cmath>
using namespace std;



bool compareDelta(double a, double b, double c){
	if (abs(a-b) <= c){
		return true;
	} else{
		return false;
	}
	
	
	
}
int main(){
	double a,b,c;
	cout <<"Number1: ";
	cin >> a;
	cout << endl;
	
	cout <<"Number2: ";
	cin >> b;
	cout << endl;
	
	cout << "Delta: ";
	cin >> c;
	cout << endl;
	
	cout <<"This set of numbers would return a " << compareDelta(a,b,c) <<"." << endl;
	
	
	return 0;
}
