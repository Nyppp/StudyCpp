#include <iostream>
#include <assert.h>
#include "CArr.h"

//생성자 -> 이니셜라이저는 멤버변수 선언 순서대로 쓰는것이 좋음
CArr::CArr() : m_pInt(nullptr), m_iCount(0), m_iMaxCount(2)
{
    m_pInt = new int[2];

    //c++ new와 c malloc의 차이
    //malloc으로 생성한 데이터 공간은 인자값이 상수이기 때문에, 컴파일러가 용도를 알 수 없음 -> 포인터로 명시
    //new 키워드는 메모리 할당 의도를 컴파일러가 알 수 있음 -> 사이즈를 받지 않고, 자료형을 받기 때문
    //클래스를 new로 생성한 경우, 생성자까지 함께 호출시키는 기능을 해줌 -> malloc은 불가능 + 해제할 때도 어떤 용도였는지 앎
    // -> delete를 할 때도, 객체가 클래스라면, 소멸자를 호출해줌
}

//소멸자
CArr::~CArr()
{
    // []의 기능 : 해당 포인터의 연속된 부분을 모두 지운다.(배열 메모리 해제)
    delete[] m_pInt;
}

void CArr::PushBack(int _iData)
{
    if(m_iMaxCount <= m_iCount)
    {
        Resize(m_iMaxCount*2);
    }

    m_pInt[m_iCount++] = _iData;
}

void CArr::Resize(int _iResizeCount)
{
    if(m_iMaxCount >= _iResizeCount)
    {
        assert(false);
    }

    int* pNew = new int[_iResizeCount];

    for(int i = 0 ; i < m_iCount ; ++i)
    {
        pNew[i] = m_pInt[i];
    }

    delete[] m_pInt;

    m_pInt = pNew;
    m_iMaxCount = _iResizeCount;
}

int& CArr::operator[](const int _Index)
{
    //배열 인덱스로 접근하게 되면, 수정이 가능하기도 하지만
    //값을 리턴하기도 해야 함 -> 레퍼런스 변수를 리턴시켜서 값으로 사용하기도, 수정도 가능하게 함
    return m_pInt[_Index];
}

void CArr::PrintArr()
{
    for(int i = 0; i < m_iCount; ++i)
    {
        std::cout << m_pInt[i] << " ";
    }
    std::cout << '\n';
}