#include <iostream>

using namespace std;

template <typename T>

T multiply(T x, T y) 
{
    return x*y;
}


int main()
{
    cout <<multiply(2,3);

}
