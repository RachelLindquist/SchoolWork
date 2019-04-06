#include <iostream>
#include <cmath>
using namespace std;

const double TOLERANCE = 0.0001;



double f(double x){
	return x*x*x*x + 2*x*x*x -31*x*x - 32*x + 60;
}

double fprime(double x){
	return 4*x*x*x + 6*x*x -62*x -32;
}

double newtonRoot(double guess){
	double x = guess;
	double a,b,c;
	do {
		a = f(x);
		b = fprime(x);
		c = a/b;
		x = x - c;
	} while (abs(c)>= TOLERANCE);
	return x;
}

int main(){
	
	double g;
	
	while(true){
		cout <<"Enter Guess: ";
		cin >> g;
		cout << endl;
		
		if (g <-10 || g > 10){
			continue;
		}
		char c;
		cout << "Root: " << newtonRoot(g) << endl;
		cout <<"Enter Another Guess: y/n? ";
		cin >> c;
		if (c == 'n'){
			break;
		}
		cout << endl;
		
	}
	
	return 0;
}
