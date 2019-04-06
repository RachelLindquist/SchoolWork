// Please place your information here
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// This prototype is complete
class stringManip {
    public:
        stringManip();
        stringManip(string input);
        string retrieve();
        void setString(string input);
        void chop();
        void padString(int n);
        void center(int length);
        void truncate(int n);
        void removeNonAlpha();
        void convertToUpperCase();
        void convertToLowerCase();
    private:
        string tobeEdited;
};

// Not all functions are defined here

// Default Constructor
stringManip::stringManip(){
    tobeEdited = "";
}

// Overloaded Constructor
stringManip::stringManip(string in_string){
    tobeEdited = in_string;
}

// retrieve function
string stringManip::retrieve(){
    return tobeEdited;
}

void stringManip::setString(string in_string){
    tobeEdited = in_string;
}

void stringManip::chop(){
    string temp;
    int j;
    int i;
    while (isspace(tobeEdited[i])){
        i++;
    }
    temp = tobeEdited.substr(i,tobeEdited.size());
    j= temp.size()-1;
    while(isspace(temp[j])){
        j--;
    }
    temp = temp.substr(0,j+1);
    tobeEdited = temp;

}

// padString() function
void stringManip::padString(int length){
    while(tobeEdited.size() < length){
        tobeEdited = tobeEdited + " ";
    }


}

// Add rest of functions here
void stringManip::center(int length){
    this->chop();
    string temp = tobeEdited;
    int extra = length-temp.size();
    if (extra %2==0){
        extra = extra / 2;
        for (int i = 0; i < extra; i++){
            temp = " " + temp + " ";
        }
    } else {
        extra = extra / 2;
        for (int i = 0; i < extra; i++){
            temp = " " + temp + " ";
        }
        temp = temp + " ";
    }

    tobeEdited = temp;
}

void stringManip ::truncate(int n){
    if (n < tobeEdited.size()){
        tobeEdited = tobeEdited.substr(0,n);
    }
}

void stringManip::removeNonAlpha(){
    string temp;
    for (int i = 0; i < tobeEdited.size(); i++){
        if (isalpha(tobeEdited[i])){
            temp = temp + tobeEdited[i];
        }
    }
    tobeEdited = temp;
}

void stringManip:: convertToUpperCase(){
    string temp;
    for (int i = 0; i < tobeEdited.size(); i++){
        temp = temp + string(1, toupper(tobeEdited[i]));
    }
    tobeEdited = temp;
}

void stringManip:: convertToLowerCase(){
    string temp;
    for (int i = 0; i < tobeEdited.size(); i++){
        temp = temp + string(1, tolower(tobeEdited[i]));
    }
    tobeEdited = temp;
}

// Add test cases to main()
int main(){
    stringManip S1;
    stringManip S2("testing 123");

    // Test case for padString() You should correct some of your own.
    cout << "S2 before padString(20): <" << S2.retrieve() << ">" << endl;
    S2.padString(20);
    cout << "S2 after padString(20): <" << S2.retrieve() << ">" << endl;
    cout << "Should be: <testing 123       >" << endl;
    S2.chop();
    cout << "<" <<S2.retrieve() <<">" << endl; // output <testing 123>

    stringManip S3("Test3");
    S3.truncate(3);
    cout <<S3.retrieve() << endl; // output Tes
    stringManip S4("12345s7890");
    S4.removeNonAlpha();
    cout <<S4.retrieve() << endl; //output s

    stringManip S5 ("ThIs");
    S5.convertToUpperCase();
    cout << S5.retrieve()<<endl; // output THIS

    stringManip S6 ("tHaT");
    S6.convertToLowerCase();
    cout <<S6.retrieve()<<endl; // output that

    stringManip S7("    b           ");
    S7.center(4);
    cout << "<" << S7.retrieve()<< ">" << endl; // output < b  >

    S7.center (5);
    cout << "<" << S7.retrieve() << ">" << endl; // output <  b  >









    return 0;
}
