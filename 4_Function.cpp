#include <iostream>

//함수
int Add(int left, int right)
{
    //int 함수는 int타입의 데이터를 반드시 반환해야 한다.
    return left + right;
}

//함수의 핵심은 같은 코드를 여러번 반복하지 않도록 '모듈화' 시키는 것임.
//팩토리얼을 사용한다면, 매번 반복문을 붙여넣는 것 보다 함수로 짜 둔다.

//반복문을 사용한 factorial 구현
int Factorial(int N) 
{
    int Value = 1;
    for(int i = 1 ; i <= N; ++i)
    {
        Value *= i;
    }
    return Value;
} 

//재귀를 사용한 factorial 구현
//재귀함수는 가독성이 늘어나지만, 재귀 호출과 탈출에 대한 추가 비용이 들어간다.
//속도가 느린 단점이 존재함
int Re_Factorial(int N) 
{
    if(N==1)
    {
        return 1;
    }

    return N * Re_Factorial(N-1);
}



//반복을 통한 피보나치 수열
int Fibonacci(int N)
{
    if(N == 1)
    {
        return 1;
    }
    else if(N == 0)
    {
        return 0;
    }
    
    int iValue = 0;
    int iPrev1 = 0;
    int iPrev2 = 1;

    for(int i = 0; i < N-1; ++i)
    {
        iValue = iPrev1 + iPrev2;
        iPrev1 = iPrev2;
        iPrev2 = iValue;
    }

    return iValue;
}

//피보나치 수열 - 재귀
int Re_Fibonacci(int N)
{
    if(N == 1)
    {
        return 1;
    }
    else if(N == 0)
    {
        return 0;
    }

    return Re_Fibonacci(N-1) + Re_Fibonacci(N-2);
}

//함수의 오버로딩 != 오버라이딩
//같은 함수명을 사용하지만, 매개변수가 다름 -> 시그니처가 다름
//서로 다른 기능을 구현할 수 있음
void Test(int a)
{

}

void Test(int a, int b)
{

}

//프로그램은 모두 메인함수를 호출하여 시작함
int main()
{
    //그 이후 메인함수 내에서 새로운 함수를 호출하여 기능 사용
    int iData = Add(100,200);

    //반복문 -> for, while 있음 + 다아니까 생략
    
    //데이터 관리 구조는 스택(후입선출), 큐(선입선출) 사용
    //함수는 스택 사용
    //함수 호출 시, 함수 블럭 내부의 변수들 파악, 메모리 할당시킴
    
    // int iValue = Factorial(10);
    // int Re_iValue = Re_Factorial(10);

    // int Fibo = Fibonacci(10);
    // int Re_Fibo = Re_Fibonacci(10);
    

    return 0;
}