//lab2-2.정찬진//
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

int Large_prime(int x)
{
    int y = x + 1;
    while (primeNum(y) != false)
    {
        y = y + 1;
    }
    return y;
}
int main()
{
    int a;
    cout << "Enter any number : ";
    cin >> a;
    if (primeNum(a) == true)
    {
        cout << a << " is not prime number" << endl;
    }
    else
    {
        cout << a << " is prime number" << endl;
    }
    cout << "prime number larger than given number : " << Large_prime(a);
}

