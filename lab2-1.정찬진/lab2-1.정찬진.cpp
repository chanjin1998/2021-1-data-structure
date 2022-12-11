//20181692 정찬진//
#include <iostream>
#include <string>
using namespace std;
int add(int x, int y)
{
    if (x == 0) 
    {
        return y;
    }
    else
    {
        while (1)
        {
            x = x - 1;
            y = y + 1;
            if (x==0)
                break;

        }
        return y;
    }
}


int diffs(int i, int j)
{
    if (i == 0) return j;
    if (j == 0) return i;
    else
    {
        while (1)
        {
            i = i - 1;
            j = j - 1;
            if (i == 0)
                break;
        }
    }
    
}
int sum(int d)
{
    int sum = 0;
    if (d != 0)
    {
        while(1)
        {
            sum += d;
            d = d-1;
            if (d == 0)
                break;
        }
        return sum;
    }
    else
        return d;
        
}

string Reverse(string l)
{
    if (l.length() == 1)
        return l;
    else 
        return Reverse(l.substr(1, l.length())) + l.at(0);

}

int main()
{
    int a, b, c, d, e;
    string s;
    cout << "Enter number1 : ";
    cin >> a;
    cout << "Enter number2 : ";
    cin >> b;
    cout << "Sum is : " << add(a, b) << endl;
    cout << "Enter number1 : ";
    cin >> c;
    cout << "Enter number2 : ";
    cin >> d;
    cout << "Difference is : " << diffs(c, d) << endl;
    cout << "Enter any positive integer : ";
    cin >> e;
    cout << "Sum of numbers : " << sum(e) << endl;
    cout << "Enter the string : ";
    cin >> s;
    cout << "Reverse of the string is : " << Reverse(s);
}

