#include <iostream>

int main()
{
    //자료형 data type
    //1바이트 = 8비트 -> 256가지의 경우의 수
    //정수형 : char(1) short(2) int(4) long(4) long long(8)
    //음수의 정의 = 2의 보수로 보면 된다.(모든 바이트를 역전시키고, 1을 더한 값) -> 128 + x = 0을 만족하는 x값
    int i = 0;

    //표현범위 0~255 (unsigned = 음수X)
    unsigned char c = 0;
    c = 0;
    c = -1; // c = 255 -> 언더플로우

    //표현범위 -128 ~ 127 (따로 선언이 없다면 signed임)
    char c1 = 0;
    c1 = 255; // c1 = -128 -> 오버플로우

    //실수형 : float(4) double(8) -> 플로트와 더블의 데이터 크기 차이는 정밀도 차이
    //실수를 상수로 적을 때, 끝에 f를 붙이면 float, 아니면 double이 됨

    //해당 식은 소수 표현식을 사용하는 4.0을 정수표현식인 4로 형변환 시킨 후 계산함 -> 추가연산 발생함
    int a = 4 + 4.0;

    //정수 부분 비트표현 21 = 10101 / 소수 부분 비트표현 = 11010 
    //11010 = 1/2 + 1/4 + 0 + 1/8 + 0 = 0.5 + 0.25 + 0 + 0.0625 + 0 = 0.8125
    //소수점 그대로 비트표현식을 따르면 21.8125 = 10101.11010
    //소수점을 가장 앞으로 끌어와 정규화시키면, 0.1010111010 x 2^5(5자리 옮겼기 때문에)
    //맨앞 비트는 부호, 나머지 7비트는 지수, 나머진 가수부분이다
    // 0(부호 1비트) 00000101(지수부분 8비트) 1010111010(가수부분 23비트) .....(남은 데이터부분은 0으로)
    // 32비트로 표현하면 -> 0000001011010111010000000000000000 가 된다.

    float b = 21.8125; // 4바이트 float => 0000001011010111010000000000000000(2)

    //실수 데이터는 소수점 부분이 길어질수록 정확도가 떨어지고, 근삿값을 표현해줌
    //조건문에서 '실수'에 대한 비교를 할 경우에는, 원하는 결과가 나오지 않을 때가 많음
    //ex)1이상의 수를 원하는데 결과값이 0.999999f 라면, 1에 매우 근사한 값이지만 조건문 실행이 안됨

    // 정수는 정수끼리, 실수는 실수끼리 연산하고, 부득이할 경우 명시적 캐스팅으로 연산해야 한다.
    float f = 10.2415f + (float)20;
    // **핵심 : 정수 표현과 실수 표현 방식은 다르다.**

    return 0;
}