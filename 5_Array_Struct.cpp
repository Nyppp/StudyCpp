#include <iostream>

//구조체, 사용자 정의 자료형
//int와 float을 묶어서 하나의 자료형으로 선언한 것임
typedef struct _tagMyST
{
    int a;
    float f;
}MYST;

typedef struct _tagBig
{
    MYST k;
    char c; //char은 1바이트이지만 다른 타입의 크기의 배수가 되도록 맞춰서 늘림(패딩)
    //k구조체 내부에 4바이트단위의 자료형밖에 없기 때문에 1바이트에서 4바이트로 패딩
}BIG;

//typedef 없이 선언된 구조체
struct NewStruct
{
    int a;
    short b;
};

int main()
{
    //배열
    //int 자료 10묶음의 데이터를 모두 0으로 선언
    //연속적인 메모리를 가짐
    int iArray[10] = {};

    //이런 경우 에러로도 잡아주지 않고, 어떠한 다른 변수에 값이 들어갈 경우가 존재하기 때문에
    //배열 인덱스 접근에 대해 주의
    // iArray[20] = 100;

    //구조체 선언의 2가지 방법 -> 멤버 접근, 배열식 선언
    MYST t;
    t.a = 10;
    t.f = 10.1234f;

    MYST t2 = {10 ,10.1234f};

    int iSize = sizeof(BIG);
    std::cout<<iSize;
    return 0;
}   