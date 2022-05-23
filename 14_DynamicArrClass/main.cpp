#include <iostream>
#include "CArr.h"

int main()
{
    // //클래스를 탬플릿화 했기에 여러 타입에 대해 대응가능
    // CArr<float> c = {};
    // CArr<int> b = {};

    // CArr<int> t1; //기본 생성
    // CArr<int> t2(t1); //복사생성자
    // CArr<int> t3 = t1; //t3를 기본 생성 후, t1을 대입 -> 복사생성자로 한번에 처리가능 -> 컴파일러가 복사생성자로
    
    CArr<int> myvector;
    CArr<int>::iterator iter = myvector.begin();
    
    for(int i = 10 ; i > 0 ; --i)
    {
        myvector.PushBack(i);
    }

    for(int i = 0 ; i < myvector.size(); ++i)
    {
        std::cout << myvector[i];
    }

    std::cout<<'\n';

    //pushback을 하고나서는, 반복자를 다시 지정해주어야 한다(메모리 재할당으로 배열의 주소가 바뀜)
    iter = myvector.begin();

    for( ; iter != myvector.end();)
    {
        if(*iter <= 5)
        {
            iter = myvector.erase(iter);
        }
        else 
        //iterator 증가를 반복문에 넣으면, 제거를 해서 인덱스가 당겨졌는데 거기서 인덱스 증가를 더 하게 되기에,
        //스킵되는 인덱스가 생겨남
        {
            ++iter;
        }
    }

    for(int i = 0 ; i < myvector.size(); ++i)
    {
        std::cout << myvector[i];
    }

    return 0;
}