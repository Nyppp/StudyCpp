#include <iostream>

typedef struct _tagMyST
{
    int     a;
    float   f;
}MYST;

int main()
{
    //구조체와 포인터
    MYST s = {}; //MYST 자료형을 가진 s 변수의 선언

    //그 a변수를 가리키는 구조체 포인터 pST
    MYST* pST = &s;
    //pST+1; //+1을 하면, s의 자료형 크기만큼(int + float = 8byte) 증가

    //구조체 s에 접근해 멤버변수 수정
    (*pST).a = 100; //역참조를 먼저(주소접근) 해야하기 문에 괄호를 치고, 멤버변수 접근
    pST->a = 100; //위와 같은 동작

    (*pST).f = 3.14f; 
    pST->f = 3.14f;
    //구조체 자료형에 맞지 않게 데이터를 집어넣으면,
    //예상하지 못한 공간에 데이터가 들어가기 때문에 결과 예측x
    //그래서 실제 공간과 상관없이 데이터를 집어넣음(검증x)


    return 0;
}