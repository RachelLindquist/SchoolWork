#include <iostream>
//# include <array>
#include <iomanip>
using namespace std;

//const int RAND_MAX = 100;
const int MAX_BAR_SIZE = 60;

int randomNumber(int max){
    if (max > RAND_MAX){
        return rand()%(RAND_MAX);
    }
    return rand()%max;
}

int maxVal (int array[], int length){
    int max = array[0];
    for (int i = 0; i < length; i++){
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;
}

int minVal (int array[], int length){
    int min = array[0];
    for (int i = 0; i < length; i++){
        if (array[i] < min){
            min = array[i];
        }
    }
    return min;
}
int sum (int array[],int length){
    int sum = 0;
    for (int i = 0; i < length; i++){
        sum += array[i];
    }
    return sum;
}

float meanVal(int array[], int length){
    float total = 0;
    for (int i = 0; i < length; i++){
        total = total + array[i];
    }
    return total / length;
}
int count (int array[], int num, int length){
    int count = 0;
    for (int i = 0; i < length; i++){
        if (array[i] == num){
            count++;
        }
    }
    return count;
}

void printFin (int countA[], int end, int sample, int a[]){
    int scale = 1;
    if (maxVal(countA,end+1)>70){
        int scale = maxVal(countA, end+1)/MAX_BAR_SIZE;
    }
    cout << "Index     Value Bar" << endl;
    for (int i = 0; i < end+1; i++){
        cout << setw(5)<< i << setw(9) << countA[i];
        for (int j = 0; j < countA[i]/scale; j++){
            cout <<"*";
        }
        cout << endl;
    }
    cout <<"Scale: " << scale << " per *" << endl;
    cout << endl;
    cout << "Range: 0 to " << end << endl;
    cout << "Sample Count: " << sample << endl;
    cout << "Min Value: " << minVal(countA,end+1) << endl;
    cout <<"Max Value: " << maxVal(countA,end+1) << endl;
    cout << "Sum Value: " << sum(countA,end+1) << endl;
    cout << "Mean Value: " << meanVal(countA, end+1) << endl;
}
int main()
{
    int endRange,numberOfSamples;
    cout << "Enter End Range: " << endl;
    cin >> endRange;
    cout << endl;
    cout <<"Enter number of Samples: " << endl;
    cin >> numberOfSamples;
    cout << endl;
    cout << endl;
    int array[numberOfSamples+1];
    for (int i = 0; i < numberOfSamples+1; i++){
        array[i] = randomNumber(endRange+1);
    }
    int countArray[endRange+1];
    for (int i = 0; i < endRange+1; i++){
        countArray[i] = count (array,i,numberOfSamples+1);
    }
    printFin(countArray, endRange, numberOfSamples, array);
    return 0;
}
