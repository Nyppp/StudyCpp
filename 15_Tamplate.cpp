#include <iostream>

//int로 선언된 함수, 하지만 float나 다른 타입에 대한 동작은 함수를 다시 만들어야 한다.(오버로딩)
// -> 이를 단축하기 위해 탬플릿 기능 사용
/*
int Add(int a, int b)
{
    return a + b;
}*/

//함수 탬플릿
template<typename T> //T는 치환 자료형, 사용자가 원하는 타입으로 변환 가능
T Add(T a, T b)
{
    return a + b;
}

int main()
{
    int i = Add<int>(10,20);
    //탬플릿 함수는 컴파일 때 만들어져서 메모리에 적재되는 것이 아닌,
    //타입을 지정해서 선언했을 때 그 자료형에 맞춰 만들어짐
    //함수탬플릿 != 함수 -> 함수탬플릿은 함수를 만들어주는 틀의 역할

    return 0;
}