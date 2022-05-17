#include <iostream>
#include "arr.h"

//메모리 영역
//스택 < 지역변수, 함수 등 -> 컴파일 시 생성
//데이터 < 전역, static, extern 변수 등 -> 컴파일 시 생성
//ROM < 코드
//힙(동적 할당) -> 런타임 중 생성

int main()
{   
    //malloc의 반환타입 = void -> 주소를 주긴 하지만, 용도는 사용자가 직접 정의
    //힙공간에 100바이트 크기를 가진 주소를 할당하고, pInt가 가리키도록 선언
    int* pInt = (int*)malloc(100);

    float* pF = (float*)malloc(4);
    *pF = 1.23f; //힙공간에 접근해 1.23f를 집어넣음

    int* pI = (int*)pF;

    *pF = 2.4f;
    int i = *pI;
    

    
    //동적할당의 핵심
    // 1. 런타임 중에 대응 가능
    // 2. 사용자가 생성과 해제를 직접 관리해야 함
    int* pInt = nullptr;
    pInt = (int*)malloc(100);

    free(pInt);

    //가변배열
    int a = 100;
    //int arr[a] = {}; -> a는 변수, 계속 바뀔 수 있기에 인덱스x
    
    //객체(instance)
    //int a; -> a는 int 자료형을 가진 객체

    tArr arr;

    tArr arr2;

    tArr arr3;

    return 0;
}