#include <iostream>
#include "CArr.cpp"

int main()
{
    CArr c = {};
    

    for(int i = 1; i <= 5 ; ++i)
    {
        c.PushBack(i);
    }

    c.PrintArr();

    return 0;
}