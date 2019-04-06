#include <iostream>


using namespace std;


string determineSubstance(double bp){
	if (100*.95 <= bp && bp <=100*1.05){
		return "Water";
	} else if (357*.95 <= bp && bp <= 357*1.05 ){
		return "Mercury";
	} else if (1187*.95<= bp  && bp<= 1187*1.05){
		return "Copper";
	} else if (2193*.95 <= bp && bp <= 2193*1.05){
		return "Silver";
	} else if (2660*.95 <=bp && bp<= 2660*1.05){
		return "Gold";
	} else {
		return "Unknown";
	}
	
	
	
	
}


int main(){
	int boil;
	cout << "Enter Boiling Point: " << endl;
	
	cin >> boil;
	
	cout << "Your substance is " << determineSubstance(boil) << endl;
	
	
	return 0;
}
