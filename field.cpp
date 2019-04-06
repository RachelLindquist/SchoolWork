#include <iostream>
#include<cmath>

using namespace std;

const double Q = 0.0000000001;
const double k = 90000000000;

double Efield(double r, double a=1){
	if (r < a){
		return k*Q*(r/(a*a*a));
	} else {
		return k*Q/(r*r);
	}
	
}

int main(){
	double r,a;
	
	cout <<"Enter r: ";
	cin >> r;
	cout << endl;
	
	cout <<"Enter a: ";
	cin >> a;
	cout << endl;
	
	cout <<"Efield: " << Efield(r,a) << endl;
	
	
	return 0;
}
