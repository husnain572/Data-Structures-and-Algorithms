#include <iostream>
using namespace std;
int countSetBits(int num)
{
    int count = 0;
    while (num > 0)
    {
        int lastDig=num & 1;
        count+=lastDig;
        num = num >> 1;

    }
   
    return count;

}
int main()
{
    cout<<countSetBits(10);
    return 0;
}