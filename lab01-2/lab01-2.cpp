//////////////////////////////////////////////////////
//이름: 정찬진
//학번: 20181692
///////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
#include <cstdio>

using namespace std;

void WordCount(string buffer, int* wc)
{
    int i = 0;
    const int IN = 1, OUT = 0;
    int state = 0;
    *wc = 0;

    while (buffer[i] != '\0')
    {
        if (isalpha(buffer[i]))
        {
            if (state == OUT)
            {
                ++* wc;
                state = IN;
            }
        }
        else if (buffer[i] == ' ')
        {
            state = OUT;
        }
        i++;
    }
}

int main() {

    ifstream infile;

    char buffer[80];
    int wc = 0;
    int total = 0;

    infile.open("lab1-2.txt", ios::in);

    if (infile.fail())
    {
        cout << "can't open the input file" << endl;
        exit(1);
    }

    while (infile.getline(buffer, 80))
    {
        cout << buffer << endl;
        WordCount(buffer, &wc);
        cout << wc << endl;
        total = total + wc;
    }
    cout << endl;
    cout << "Total Number of Words :" << total << endl;

    return 0;
}