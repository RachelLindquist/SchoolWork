#include <iostream>

#include <cmath>

#include <iomanip>

using namespace std;

double totalCurrent(double a, double w, double t, double p){
	return a*sin(w*t-p);
}

double resistorDrop(double r, double a, double w, double t, double p){
	return r*a*sin(w*t-p);
}

double inductorDrop(double l, double w, double a, double t, double p){
	return l*w*a*cos(w*t-p);
}

double capacitorDrop(double a, double c, double w, double t, double p){
	return (-a/(c*w))*cos(w*t-p);
}

double appliedVolt(double v, double w, double t){
	return v * sin(w*t);
}


int main(){
 	double v,h,r,i,c,a,p,t,ac,w;
 	double V,I,VR,VL,VC;
 	
	cout << "RLC Circuit Summary:" << endl;
	cout << endl;
	cout << "Voltage: ";
	cin >> v;
	cout <<"-Volts @ ";
	cin >> h;
	cout <<"-Hz" << endl;
	cout <<"Resistor Value: ";
	cin >> r;
	cout <<"-ohms" << endl;
	
	cout <<"Inductor Value: ";
	cin >> i;
	cout <<"-H" <<endl;
	
	cout <<"Capacitor Value: ";
	cin >> c;
	cout <<"-F" << endl;
	
	ac = 1/h;
	w = 2*M_PI*h;
	t = ac/20; 
	cout << t << endl; 
	
	a = (w*v)/sqrt(pow((w*w*i-1/c),2)+r*r*w*w) ;
	double f = (i*w)/r;
	double q = 1/(r*c*w);
	p = atan(f-q); //FIXME
	
	cout <<"Calculated Patameters:" << endl;
	
	cout << "	Current Amplitude:       " << a <<"-amps" << endl;
	cout << "   Phase Angle:    	 " << p*180/M_PI << "-degrees" << endl;
	cout << endl;
	cout << "	Iter." <<setw(15)<<"Time" <<setw(15)<<"V"<<setw(15) <<"I" <<setw(15)<< "VR" <<setw(15)  <<	"VL"<<setw(15)<< 	"VC" << endl;
	
 	
	int k = 0;
	for (double j = 0; j < (2*ac); j+=t){
		I = totalCurrent(a,w,j,p);
		VL = inductorDrop(i,w,a,j,p);
		VR = resistorDrop(r,a,w,j,p);
		VC = capacitorDrop(a,c,w,j,p);
		V = appliedVolt(v,w,j);
		if (abs(V- (VR+VL +VC)) >= 0.1){
			cout << "ERROR" << endl;
		}
		cout <<setw(15) << k  << setw(15)<< j << setw(15) <<V << setw(15)<<I <<setw(15)<< VR << setw(15) << VL << setw(15) << VC <<endl;
		
		k++;
	}
	
	
	
	return 0;
}
