#include <iostream>
using namespace std;
void convertToBinary(int n)
{
    int k, m, i;
    for (i = 7; i >= 0; i--)
    {
        m = 1 << i;
        k = n & m;
        if (k == 0)
            std::cout << "0";
        else
            std::cout << "1";
    }
}
int main()
{
    convertToBinary(5);

    return 0;
}