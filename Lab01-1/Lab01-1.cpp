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
    int pos = 0;
    for (int i = 1; i < n; i++) {
        if (data[i] < min) {
            min = data[i];
            pos = i;
        }
    }
    return pos;
}
int findMax(int data[], int n) {
    int max = data[0];
    int posi = 0;
    for (int i = 1; i < n; i++) {
        if (data[i] > max) {
            max = data[i];
            posi = i;
        }
    }
    return posi;
}


int main() {
    int number, size;
    int data[10] = { 0, };

    ifstream infile("findNum.txt");
    size = 0;

    while (infile >> number) {
        data[size++] = number;
    }
    for (int i = 0; i < size; i++)
    {
        cout << data[i] << " ";
    }
    cout << endl;
    int minnum = findMin(data, size);

    cout << "Minimum number is " << data[minnum] << " at position " << minnum + 1 << endl;


    int maxnum = findMax(data, size);

    cout << "Maximum number is " << data[maxnum] << " at position " << maxnum + 1 << endl;
    return 0;



}