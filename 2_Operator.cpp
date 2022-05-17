//전처리기 구문 -> 모든 컴파일 과정중 제일 먼저 수행
#include <iostream>

//define을 사용할 경우, 코드 가독성이 늘어나고, 유지보수가 쉬워짐
#define HUNGRY  0x001 //16진수 표현 = 1
#define THIRSTY 0x002
#define TIRED   0x004
#define FIRE    0x008

#define COLD    0x010 //16
// #define POISON  0x020
// #define POISON  0x040
// #define POISON  0x080

#define POISON2  0x100 //256
// #define POISON  0x200

int main()
{
    //사칙연산은 생략.
    //증감 연산자
    //증감 연산자는 전위를 위주로 사용
    //증간연산자는 단지 1을 추가, 감소 하는것이 아니라 포인터 기준으로는 다음 인덱스, 전 인덱스 연산으로 볼 수 있음
    int a = 10;
    int data;
    data = ++a; //++연산자가 먼저 수행된 후에 = 연산자 실행 -> data = 11 / a = 11
    data = a++; // = 연산자가 먼저 수행된 후에 ++ 연산자 실행 -> 후위연산자를 사용하면 우선순위가 가장 나중임 -> data = 11 / a = 12
    
    //논리연산자
    //True(1) / False(0)
    // !(not) - 논리역 / &&(and) - 논리곱 / ||(or) - 논리합
    int trueNum = true; // 1
    trueNum = false; // 0

    //bool 타입은 true, false 정보만 담김
    bool BoolData = true;
    //bool타입은 0, 1만 들어가지 않지만, 정수 자료형의 역할을 하지는 못함
    BoolData = 100; //true -> 0이 아니면 모두 true임

    //비교연산자 == -> lvalue와 rvalue가 같으면 true, 다르면 false / != -> ==와 반대
    // >, <, >=, <= 등의 부등호

    //논리연산자 응용 -> if else 구문
    if ( 100 && 200)
    {
        data = 100;
    }
    else if( 100 && 0)
    {
        //if가 거짓이면 수행
        data = 0;
    }
    else
    {
        data = 200;
        //if와 앞의 모든 else if가 거짓이면 수행
    }

    //switch
    switch(data)
    {
        case 10:
            break;

        case 20:
            break;

        default:
            break;
    }
    //if와 switch는 동일한 기능임. 코딩 스타일에 따라 선택 하면 됨


    //삼항연산자
    int iTest = 20;
    //iTest가 20이면 100, 아니면 200이 됨
    iTest == 20 ? iTest = 100 : iTest = 200;

    //위의 삼항 연산자와 같은 동작
    if(iTest == 20)
    {
        iTest = 100;
    }
    else
    {
        iTest = 200;
    }
    

    //비트연산자
    //쉬프트 <<, >> -> 비트를 화살표 방향으로 밀어냄
    unsigned char byte = 1;
    byte <<= 1; //00000001 에서 00000010이 됨

    //비트 곱(&), 합(|), xor(^), 반전(~)
    //게임에서 캐릭터의 상태를 나타내기 위해 Status 변수를 사용한다고 예시를 들면,
    //컴파일 시, 전처리기 구문에서 HUNGRY를 읽어오고, 뒤에 오는 모든 HUNGRY를 1로 치환하여 실행
    unsigned char iStatus = HUNGRY; //00000001

    //앞서 선언한 헝그리 상태와 목마름 상태가 합쳐짐 00000011
    iStatus |= THIRSTY;

    //상태값 체크
    //THIRSTY는 2번째 자리만 1임. 만약 스테이터스가 목마르지 않은 상태면 2번 공간이 false가 됨. 나머지 공간은 당연히 false
    if(iStatus & THIRSTY)
    {
    
    }

    //특정 자리 비트 제거
    iStatus &= ~THIRSTY; //00000011 & 11111101 = 00000001
    //원래 자리는 유지되지만(1과 and연산을 하기 때문에), 비교하는 공간은 반전되어서 결과가 바뀜
    
    return 0;
}
