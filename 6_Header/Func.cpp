#include <iostream>
#include "Func.h" //해당 헤더파일을 참조

//함수를 cpp파일 내부에 선언하면(함수 선언부분이 main보다 아래에 있으면) 에러를 발생시킴
//main함수보다 위에서 선언하거나 헤더파일을 통해 선언 이후 구현을 cpp파일에서 하면, main보다 아래에 있어도 에러x
//컴파일러가 링크 단계에서 먼저 선언된 함수의 구현부분을 찾아다님

//링크 과정 = cpp파일과 h파일에 대한 obj들을 합쳐서 exe파일로 나타내는 과정
int Add(int a, int b)
{
    return a+b;
}

int Sub(int a, int b)
{
    return a-b;
}

int Div(int a, int b)
{
    return a/b;
}

int Mul(int a, int b)
{
    return a*b;
}

//분할 구현은 헤더가 꼬이거나 함수가 여러 cpp파일에서 구현되어 사용되는 경우 문제가 생김 -> 스파게티 코드
//또한 전역변수의 이용이 어려움 -> 함수가 다른 cpp파일의 데이터 영역을 인식할 수 없게 됨

//헤더에 전역변수를 선언하면 -> 모든 cpp파일에 변수가 복사됨 -> 개별적 컴파일은 문제가 없지만 exe파일로 합칠땐 문제 발생 -> 동일한 변수가 여러개 나타나기 때문

int main()
{
    int a = Add(30,20);
}


