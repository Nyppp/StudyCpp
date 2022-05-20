#include <iostream>
#include "CList.h"

int main()
{
    //클래스 탬플릿은 개발자가 여러번 만들 것을 하나의 틀로 재사용할수 있게 만들어주는 기능
    CList<int> c;

    for(int i = 0; i < 5; ++i)
    {
        c.push_back(i);
    }

    
    return 0;
}
