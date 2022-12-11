// lab4.정찬진(20181692)//

////////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <string>
#define MAX_NUM 10


using namespace std;
struct term {
    int row, col, val;
};
term a[MAX_NUM];
term b[MAX_NUM];
term c[MAX_NUM];


void original(string myarray[6][6]) {
    int i = 0;
    int j = 0;
    ifstream f("hw1.txt"); 
    while (!f.eof()) { 
        f >> myarray[i][j];
        j++;
        if (myarray[i][j] == "\n") {  
            i++;
            j = 0;
        }
    }
    cout << "1)  Original matrix : A\n" << endl;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            cout << myarray[i][j] << " ";
        }
        cout << endl;
    }
}


void find_row(string myarray[6][6]) {
    int Imyarray[6][6];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            Imyarray[i][j] = atoi((myarray[i][j].c_str())); 
        }
    }
    int l = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            if (Imyarray[i][j] != 0) {
                a[l].row = i; 
                a[l].col = j; 
                a[l].val = Imyarray[i][j]; 
                l++;
            }
        }
    }
    cout << "\n2)  (matrix B) - row major\n" << endl;
    for (int i = 0; i < 8; i++) {
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    }
}

void trans_b(term a[]) {
    int currentb = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (a[j].col == i) {
                b[currentb].row = a[j].col; 
                b[currentb].col = a[j].row;
                b[currentb].val = a[j].val;
                currentb++;
            }
        }
    }

    cout << "\n3)  (Btrans) - Transposed matrix B, column major\n" << endl;
    for (int i = 0; i < 8; i++) {
        cout << b[i].row << " " << b[i].col << " " << b[i].val << endl;
    }
}

void fast_row(term a[]) {
    int row_terms[MAX_NUM], starting_pos[MAX_NUM];
    int i, j;
    for (i = 0; i < 6; i++)
        row_terms[i] = 0; 
    for (i = 0; i < 8; i++)
        row_terms[a[i].col]++; 
    starting_pos[0] = 0; 

    for (i = 1; i <= 6; i++)
        starting_pos[i] = starting_pos[i - 1] + row_terms[i - 1];
    for (i = 0; i < 8; i++) { 
        j = starting_pos[a[i].col]++;
        c[j].row = a[i].col; c[j].col = a[i].row;
        c[j].val = a[i].val;
    }
    cout << "\n4) (matrix B) - Fast transpos (Btrans -> B)\n" << endl;
    for (int i = 0; i < 8; i++) {
        cout << c[i].row << " " << c[i].col << " " << c[i].val << endl;
    }

}
int main() {

    string myarray[6][6]; 

    original(myarray);
    find_row(myarray);
    trans_b(a);
    fast_row(b);

    return 0;
}