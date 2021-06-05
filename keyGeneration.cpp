#include <iostream>
#include <cstdlib>
using namespace std;

int gcd(int a, int b)
{
    int q, r1, r2, r;
    if (a > b)
    {
        r1 = a;
        r2 = b;
    }
    else
    {
        r1 = b;
        r2 = a;
    }
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
    }
    return r1;
}

int inverse(int a, int b)
{
    int inv;
    int q, r, r1 = a, r2 = b, t, t1 = 0, t2 = 1;
    while (r2 > 0)
    {
        q = r1 / r2;
        r = r1 - q * r2;
        r1 = r2;
        r2 = r;
        t = t1 - q * t2;
        t1 = t2;
        t2 = t;
    }
    if (r1 == 1)
        inv = t1;
    if (inv < 0)
        inv = inv + a;
    return inv;
}
int main()
{
    int p, q, e, n, d;
    int phi_n;
    cout << "-----Key Generation-----\n\nEnter two prime numbers: ";
    cin >> p;
    cin >> q;
    n = p * q;
    phi_n = (p - 1) * (q - 1);
    do
        e = rand() % (phi_n - 2) + 2;
    while (gcd(e, phi_n) != 1);
    cout << "\n\nPublic key(n,e): (" << n << ", " << e << ")";
    d = inverse(phi_n, e);
    cout << "\n\nPrivate key(n,d): (" << n << ", " << d << ")\n\n";
}