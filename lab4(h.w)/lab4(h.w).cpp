//lab4 (hw1) 20181692 정찬진
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>

using namespace std;

void Left_Justification();
void Right_Justification();
void Center_Justification();

int main()
{
    int n;
    while (true)
    {
        cout << "**********************************" << endl;
        cout << "1. Left     Justification" << endl;
        cout << "2. Right    Justification" << endl;
        cout << "3. Centered Justification" << endl;
        cout << "4. Terminate " << endl;
        cout << "Enter your choice : ";
        cin >> n;
        cout << endl;
        if (n == 4) break;
        for (int i = 0; i < 8; i++)
        {
            for (int j = 1; j <= 10; j++) cout << j % 10;
        }
        cout << endl;

        switch (n) {
        case 1:
            Left_Justification();
            break;
        case 2:
            Right_Justification();
            break;
        case 3:
            Center_Justification();
            break;
        default:
            break;
        }
    }
}


void Left_Justification()
{
    char buffer[80];
    char leftbuffer[80];
    ifstream infile;
    infile.open("hw1.txt", ios::in);

    while (infile.getline(buffer, 80))//1 라인을 읽음
    {
        int i = 0;
        int j = 0;

        while (buffer[i] == ' ') i++;//데이터 만날때까지 인덱스 증가
        while (buffer[j] != '\0')
        {
            leftbuffer[j] = buffer[i];//출력 버퍼로 데이터 복사
            i++;
            j++;
        }
        leftbuffer[j] = '\0';

        cout << leftbuffer << endl;//왼쪽으로 정렬된 라인 출력
    }
}
void Right_Justification()
{
    char buffer[80];
    char rightbuffer[80];
    ifstream infile;
    infile.open("hw1.txt", ios::in);
    while (infile.getline(buffer, 80)) { // 1 라인을 읽음
        int i = 0;
        int j = 0;
        int k = 0;
        while (buffer[i] == ' ') i++;//데이터 만날때까지 인덱스 증가
        while (buffer[k] != '\0') k++;
        //글자 수 = k 
        //공백 수 = 80-k

        for (int h = 0; h < 79 - k; h++) {
            rightbuffer[j++] = ' ';
        }
        while (buffer[i] != '\0')
        {
            rightbuffer[j] = buffer[i];//출력 버퍼로 데이터 복사
            i++;
            j++;
        }
        rightbuffer[j] = '\0';

        cout << rightbuffer << endl;//오른쪽으로 정렬된 라인 출력
    }
}
void Center_Justification()
{
    char buffer[80];
    char centerbuffer[80];
    ifstream infile;
    infile.open("hw1.txt", ios::in);
    while (infile.getline(buffer, 80)) { // 1 라인을 읽음
        int i = 0;
        int j = 0;
        int k = 0;
        while (buffer[i] == ' ') i++;//데이터 만날때까지 인덱스 증가
        while (buffer[k] != '\0') k++;
        //글자 수 = k 
        //앞뒤 공백 수 (80-k)/2 
        for (int h = 0; h < (79 - k) / 2; h++) {
            centerbuffer[j++] = ' ';
        }
        while (buffer[i] != '\0')
        {
            centerbuffer[j] = buffer[i];
            i++;
            j++;
        }
        centerbuffer[j] = '\0';

        cout << centerbuffer << endl;//가운데로 정렬된 라인 출력
    }
}