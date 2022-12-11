//////////////////////////////////////////////////////
//Program ID : Lab1-1
//이름: 정찬진
//학번: 20181692
//Program Description: Find Min and Max numbers
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

int findMin(int data[], int n) {
    int min = data[0];
    int position = 0;
    for (int i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
            position = i;
        }
    }
    return position;
}
int findMax(int data[], int n) {
    int max = data[0];
    int posi = 0;
    for (int i = 1; i < n; i++){
        if (data[i]> max) {
            max = data[i];
            posi = i;
        }
    }
    return posi;
}


int main() {
    int number, count;
    int data[10] = {0,};

    ifstream infile("FindNum.dat");
    count = 0;

    while (infile >> number) {
        data[count++] = number;
    }

    int minnum = findMin(data, count);

    cout << "Minimum number is " << data[minnum] << " at position " << minnum + 1 << endl;
    

    int maxnum = findMax(data, count);

    cout << "Maximum number is " << data[maxnum] << " at position " << maxnum + 1 << endl;
    return 0;



}