#include <iostream>
#include "CArr.h"

int main()
{
    //클래스를 탬플릿화 했기에 여러 타입에 대해 대응가능
    CArr<float> c = {};
    CArr<int> b = {};
    

    c.PushBack(5.7f);

    b.PushBack(5);

    c.PrintArr();

    b.PrintArr();

    return 0;
}