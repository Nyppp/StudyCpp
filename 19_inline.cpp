#include <iostream>

// 인라인함수 -> 사용 될 때마다, 그 자리에 함수 내용을 코드로 넣음
inline void Test() { std::cout << "hello"; }

// 일반적 함수는 스택에 저장되어, 함수 호출마다 그 스택을 찾아가서 함수를 호출하게 됨
void Test1()
{
    std::cout << "hello";
}

//클래스에 구현된 함수는, 모두 인라인으로 처리됨 -> 함수 호출 시, 그 코드를 추가함 -> 함수호출x

int main()
{
    Test();

    Test1();
    return 0;
}