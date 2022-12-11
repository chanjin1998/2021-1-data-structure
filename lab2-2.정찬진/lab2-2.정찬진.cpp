//소수 판별//
#include <iostream>
using namespace std;

int primeNum(int x)
{
    for (int i = 2; i <= sqrt(x); i++)
    {
        if (x % i == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}



int main()
{
    int a;
    cout << "Enter any number : ";
    cin >> a;
    if (primeNum(a) == true)
    {
        cout <<a<< " is prime number";
    }
    else cout << "소수입니다.";
}

