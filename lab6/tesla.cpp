#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include<cmath>

using namespace std;

void printStory(){
    cout << "You find your way to SpaceX the night before the Roadster is mounted atop the rocket which is to send it into space." << endl;
    cout <<"The building is dark and the roadster is hidden somewhere in large open dark room (15x15)." << endl;
    cout <<"In addition to the roadster, two other cars (a Yugo and ford pinto) are being stored in this facility as well. " << endl;
    cout << endl;
    cout << "Elon Musk is sleeping somewhere in the same room and you have to avoid waking him to find your way to the roadster." << endl;
    cout << "Once awoken he will randomly move through the building looking for you. " << endl;
    cout << "If he lands next to you, you can get away from him only once. " << endl;
    cout << "The second time you will be the \"Starman\" and blasted into space with his roadster. " << endl;
    cout << "Once he is a awake your only chance to avoid being \"Starman\" is to make your escape in his roadster." << endl;
    cout << "If you get into either of the other two cars you will be caught and become the \"Starman\". " << endl;

}

void createRoom(string array[][15]){
    unsigned int Ex = rand()%15;
    unsigned int Ey = rand()%15;
    unsigned int Ry = rand()%15;
    unsigned int Rx = rand()%15;
    unsigned int Yx = rand()%15 ;
    unsigned int Yy = rand()%15;
    unsigned int Px = rand()%15;
    unsigned int Py = rand()%15;
    unsigned int Cx = rand()%15;
    unsigned int Cy = rand()%15;
    while (Ry == Ey && Rx == Ex){
        Ry = rand()%15;
        Rx = rand()%15;
    }
    while ((Yx == Ex && Yy == Ey)|| (Yx == Rx && Yy == Ry)){
        Yx = rand()%15;
        Yy = rand()%15;
    }
    while ((Px == Ex && Py == Ey)|| (Px == Rx && Py == Ry) || (Px == Yx && Py == Yy)){
        Px = rand()%15;
        Py = rand()%15 ;
    }
    while ((Cx == Ex && Cy == Ey)|| (Cx == Rx && Cy == Ry) || (Cx == Yx && Cy == Yy) || (Cx == Px && Cy == Py)){
        Cx = rand()%15;
        Cy = rand()%15;
    }

    for (unsigned int i = 0; i < 15; i ++){
        for (unsigned int j = 0; j < 15; j++){
            if (i == Ex && j == Ey){
                array[i][j] = "E";
            } else if (i == Rx && j == Ry){
                array [i][j] = "R";
            } else if (i == Yx && j == Yy){
                array [i][j] = "Y";
            } else if (i == Px && j == Px){
                array[i][j] = "P";
            } else if (i == Cx && j == Cy){
                array[i][j] = "C";
            } else{
                array[i][j] = "B";
            }
        }
    }
}

int moveChar(string array[][15]){
    unsigned int Cx = 0;
    unsigned int Cy = 0;
    for (unsigned int i = 0; i < 15; i++){
        for (unsigned int j = 0; j < 15; j++){
            if (array[i][j].compare("C")==0){
                Cx = i;
                Cy = j;
            }
        }
    }
    unsigned int m = 0;
    char d;
    cout <<"Which way would you like to move? " << endl;
    if (Cx == 0 && Cy == 0){
        cout <<"South(s)" << endl;
        cout <<"East (e)" << endl;
        cin >> d;
        if (d == 's'){
            m = 3;
        } else {
            m = 1;
        }
    } else if (Cx == 0 && Cy == 14){
        cout <<"South(s)" << endl;
        cout <<"West(w)" << endl;
        cin >> d;
        if (d == 's'){
            m = 3;
        } else {
            m = 4;
        }
    } else if (Cx == 14 && Cy == 14){
        cout <<"North(n)" << endl;
        cout <<"West(w)" << endl;
        cin >> d;
        if (d == 'n'){
            m = 1;
        } else{
            m = 4;
        }
    } else if (Cx == 14 && Cy == 0){
        cout <<"North(n)" << endl;
        cout <<"East(e)" << endl;
        cin >> d;
        if (d == 'n'){
            m = 1;
        } else {
            m = 2;
        }
    } else if (Cx == 0){
        cout << "West(w)" << endl;
        cout << "East(e)" << endl;
        cout << "South(s)" << endl;
        cin >> d;
        if (d == 'w'){
            m = 4;
        } else if (d == 'e'){
            m = 2;
        } else {
            m = 3;
        }
    } else if (Cx == 14){
        cout << "North(n)" << endl;
        cout << "East(e)" << endl;
        cout << "West(w)" << endl;
        cin >> d;
        if (d == 'n'){
            m =1;
        } else if (d == 'e'){
            m = 2;
        } else {
            m = 4;
        }
    } else if (Cy == 14){
        cout << "North(n)" << endl;
        cout << "West(w)" << endl;
        cout << "South(s)" << endl;
        cin >> d;
        if (d == 'n'){
            m = 1;
        } else if (d == 'w'){
            m = 4;
        } else {
            m = 3;
        }
    } else if (Cy == 0){
        cout << "North(n)" << endl;
        cout << "East(e)" << endl;
        cout << "South(s)" << endl;
        cin >> d;
        if (d == 'n'){
            m = 1;
        } else if (d =='e'){
            m =2;
        } else {
            m = 3;
        }
    } else{
        cout << "North(n)" << endl;
        cout << "East(e)" << endl;
        cout << "South(s)" << endl;
        cout <<"West(w) " << endl;
        cin >> d;
        if (d == 'n'){
            m = 1;
        } else if (d == 'e'){
            m = 2;
        } else if (d == 's'){
            m = 3;
        } else {
            m = 4;
        }
    }
    return m;
}
bool caught (string room[][15]){
    int Cx,Cy,Ex,Ey;
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (room[i][j].compare("C") == 0){
                Cx = i;
                Cy = j;
            }
            if (room[i][j].compare("E") == 0){
                Ex = i;
                Ey = j;
            }
        }
    }
    if (abs(Cx-Ex) == 1 || abs(Cy-Ey) == 1){
        return true;
    }
    return false;
}
bool wrongCar(string array[][15], int x, int y){
    int Px,Py,Yx,Yy;
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (array[i][j].compare("P") == 0){
                int Px = i;
                int Py = j;
            }
            if (array[i][j].compare("Y") == 0){
                int Yx = i;
                int Yy = j;
            }
        }
    }
    if ((Px == x && Py == y )||(Yx == x && Yy == y)){
        return true;
    }
    return false;
}

bool foundCar(string array[][15],int x, int y){
    int Rx,Ry;
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (array[i][j].compare("R") == 0){
                int Rx = i;
                int Ry = j;
            }
        }
    }
    if (Rx == x && Ry == y ){
        return true;
    }
    return false;
}
char modifyRoom(int d, string array[][15], bool awake){
    unsigned int Cx = 0;
    unsigned int Cy = 0;
    unsigned int Ex = 0;
    unsigned int Ey = 0;
    unsigned int Rx = 0;
    unsigned int Ry = 0;
    for (unsigned int i = 0; i < 15; i++){
        for (unsigned int j = 0; j < 15; j++){
            if (array[i][j].compare("C") == 0){
                Cx = i;
                Cy = j;
            }
            if (array[i][j].compare("E") == 0){
                Ex = i;
                Ey = j;
            }
            if (array[i][j].compare("R") == 0){
                Rx = i;
                Ry = j;
            }
        }
    }
    int bx = fabs(Cx-Rx);
    int by = fabs(Cy-Ry);
    int newX = 0;
    int newY = 0;
    // north
    if (d == 1 && !wrongCar(array,Cx-1,Cy) && !foundCar(array,Cx-1,Cy)){ // north
        array[Cx-1][Cy]="C";
        array[Cx][Cy] = "B";
        newX = Cx-1;
        newY = Cy;
        if (fabs(newX-Rx) > bx){
            cout <<"You are getting further away" << endl;
        } else {
            cout << "You are getting closer" << endl;
        }
    } else if (d == 2 && !wrongCar(array,Cx,Cy+1) && !foundCar(array,Cx,Cy+1)){  // east
        array[Cx][Cy+1]="C";
        array[Cx][Cy] = "B";
        newX = Cx;
        newY = Cy+1;
        if (fabs(newY-Ry) < by){
            cout <<"You are getting further away" << endl;
        } else {
            cout << "You are getting closer" << endl;
        }
    } else if (d == 3 && !wrongCar(array,Cx+1,Cy) && !foundCar(array,Cx+1,Cy)) { // south
        array[Cx+1][Cy]="C";
        array[Cx][Cy] = "B";
        newX = Cx+1;
        newY = Cy;
        if (fabs(newX-Rx) < bx){
            cout <<"You are getting further away" << endl;
        } else {
            cout << "You are getting closer" << endl;
        }
    } else if (!wrongCar(array,Cx,Cy-1) && !foundCar(array,Cx,Cy-1)){ // west
        array[Cx][Cy-1] = "C";
        array[Cx][Cy] = "B";
        newX = Cx;
        newY = Cy-1;
        if (fabs(newY-Ry) < by){
            cout <<"You are getting further away" << endl;
        } else {
            cout << "You are getting closer" << endl;
        }
    }
    if (wrongCar(array,newX,newY)){
        return 's';
    } else if (foundCar(array,newX,newY)) {
        return 'r';
    }
    bool x = caught(array);
    if (awake && !x){
        if (Cx > Ex){
            if (Cy > Ey){
                array[Ex-1][Ex-1] = "E";
            } else if (Cy == Ey){
                array[Ex -1][Ex] = "E";
            } else{
                array[Ex-1][Ex+1] = "E";
            }
        } else if (Cx == Ex){
            if (Cy > Ey){
                array[Ex][Ex-1] = "E";
            } else if (Cy == Ey){
                array[Ex][Ex] = "E";
            } else{
                array[Ex][Ex+1] = "E";
            }
        } else {
            if (Cy > Ey){
                array[Ex+1][Ex-1] = "E";
            } else if (Cy == Ey){
                array[Ex +1][Ex] = "E";
            } else{
                array[Ex+1][Ex+1] = "E";
            }
        }
    }
    else if (awake){
        return 'e';
    } else{
        return'n';
    }
}

void displayRoom(string array[][15]){
    int Cx = 0;
    int Cy = 0;
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 15; j++){
            if (array[i][j].compare("C") == 0){
                Cx = i;
                Cy = j;
            }
         }
    }
    for (int i = -3; i < 4; i++){
        for (int j = -3; j < 4; j++){
            if ((Cx + i) >= 0 && (Cx + i) <=14 && (Cy +j) >=0 && (Cy + j) <= 14){
                cout << array[Cx+i][Cy+j] << " ";
            }
        }
        cout << endl;
    }
    cout << "C is your character" << endl;
    cout <<"E is Elon" << endl;
    cout << "R is the Roadster" << endl;
    cout << "Y is the Yugo" << endl;
    cout << "P is the Pinto" << endl;


}




int main(){
    srand(time(NULL));
    printStory();
    int roadFound =0, starman = 0;

    while(true){
        bool awake = false;
        int move = 0;
        string room[15][15];
        createRoom(room);
        int q = 0;
        displayRoom(room);
        int starman2 = 0;
        while(true){
            cout << "Would you like to quit? (1 for true, 2 for false) " << endl;;
            cin >> q;
            if (q==1){
                break;
           }
            int d = moveChar(room);
            char star = modifyRoom(d, room, awake);
            if (star == 'e'){
                starman2++;
                createRoom(room);
            }
            if (starman2 == 2 || star == 's'){
                starman++;
                cout <<"You survived " << move <<" turns, good luck next time " << endl;
                break;
            }
            if (star == 'r'){
                roadFound++;
                cout <<"You took " << move << " turns to find the Roadster, congrats " << endl;;
                break;
            }
            cout << "Would you like to quit? (1 for true, 2 for false) " << endl;
            cin >> q;
            if (q==1){
                break;
            }
            displayRoom(room);
            move++;
            if(move == 10){
                awake = true;
                cout << "You have moved around a lot, Elon has woken up from the noise" << endl;;
            }
        }
        if (q==1){
            break;
        }





       int playAgain;
       cout <<"Play again? " << endl;
       cout <<"1. Yes" << endl;
       cout << "2. No" << endl;
       cin >> playAgain;
       while (playAgain > 2 || playAgain <1){
           cout <<"Play again? " << endl;
           cout <<"1. Yes" << endl;
           cout << "2. No" << endl;
           cin >> playAgain;
       }
       if (playAgain == 2){
           break;
       }
    }
    cout << "You have won " << roadFound <<" times and you have lost " << starman <<" times." << endl;


    return 0;
}
