#pragma once

#include <iostream>
#include <assert.h>

template<typename T> //클래스 탬플릿
class CArr
{
private:
    T*      m_pData; //어떤 자료형이 오든 대응 가능하게끔 가변배열을 탬플릿화함
    int     m_iCount;
    int     m_iMaxCount;

public:
    CArr();
    ~CArr();

public:
    void PushBack(const T& _iData);
    void Resize(int _iResizeCount);
    void PrintArr();
    int size() { return m_iCount; }

    T& operator [](const int _Index);

    class iterator;
    iterator begin();
    iterator end();

    //inner 클래스는 밖의 클래스가 선언되어도 자동으로 생기지 않기 때문에,
    //클래스 객체 크기에 영향을 주지 않음 + 상위 클래스의 private 멤버에 접근 가능함
    class iterator
    {
    private:
        //반복자는 가변배열에서 메모리 재 할당을 할 때마다, 원본주소와 다른 주소를 가지게 됨
        //-> 원본 주소가 계속 바뀌기 때문. -> stl 벡터 라이브러리는 메모리를 그대로 쓰는 게 아니라, 메모리가 다르다면 에러를 출력함
        CArr*   m_pArr;     //반복자가 가리킬 데이터를 관리하는 가변배열 주소
        T*      m_pData;    //데이터의 시작 주소
        int     m_iIdx;     //가리키는 데이터의 인덱스

    public:
        iterator() : m_pArr(nullptr), m_pData(nullptr), m_iIdx(-1) {} //인덱스 -1 == end 반복자
        iterator(CArr* _pArr, T* _pData, int _iIdx) : m_pArr(_pArr),m_pData(_pData), m_iIdx(_iIdx) {}
        ~iterator() {}

    public:
        //역참조 연산자 오버로딩
        T& operator * ()
        {
            //반복자가 알고있는 주소와 가변배열이 알고있는 주소가 다른 경우, assert
            //혹은 반복자가 end를 가리키는 경우 assert
            if (m_pArr->m_pData != m_pData || m_iIdx == -1)
            {
                assert(false);
            }
            return m_pData[m_iIdx]; //반복자가 가리키는 데이터 시작주소의 iIdx번째를 반환
        }

        T& operator ++ ()
        {
            if(m_iIdx == -1)
            {
                assert(false);
            }
            return m_pData[++m_iIdx];
        }

        T& operator -- ()
        {
            if(m_iIdx == -1)
            {
                m_iIdx = m_pArr->m_iCount
                return m_pData[m_pArr->m_iCount];
            }

            else if(m_iIdx == 0)
            {
                assert(false);
            }

            return m_pData[--m_iIdx];
        }
    };
};

//클래스탬플릿은 함수들이 cpp파일이 아닌, 헤더파일에 구현되어 있어야 한다
//클래스탬플릿의 함수는 실행파일의 어떤 자료형이 정해졌을 때 만들어지는데,
//선언만 존재하는 헤더파일 공간에 float에 대한 선언만 만들어지고,
//cpp파일에 존재하는 실제 기능들은 아직 만들어져있지 않게 됨 -> 선언만 존재하고, 구현이 불러와지지 않음
//cpp파일을 컴파일 할때, 이 시점 기준으로는 T에 뭐가 와야할지 모르기 때문임

//기존의 클래스 함수들도 클래스가 탬플릿이 되었기에 함수 탬플릿이 됨

//생성자 -> 이니셜라이저는 멤버변수 선언 순서대로 쓰는것이 좋음
template<typename T>
CArr<T>::CArr() : m_pData(nullptr), m_iCount(0), m_iMaxCount(2)
{
    m_pData = new T[2];

    //c++ new와 c malloc의 차이
    //malloc으로 생성한 데이터 공간은 인자값이 상수이기 때문에, 컴파일러가 용도를 알 수 없음 -> 포인터로 명시
    //new 키워드는 메모리 할당 의도를 컴파일러가 알 수 있음 -> 사이즈를 받지 않고, 자료형을 받기 때문
    //클래스를 new로 생성한 경우, 생성자까지 함께 호출시키는 기능을 해줌 -> malloc은 불가능 + 해제할 때도 어떤 용도였는지 앎
    // -> delete를 할 때도, 객체가 클래스라면, 소멸자를 호출해줌
}

//소멸자
template<typename T>
CArr<T>::~CArr()
{
    // []의 기능 : 해당 포인터의 연속된 부분을 모두 지운다.(배열 메모리 해제)
    delete[] m_pData;
}

template<typename T>
void CArr<T>::PushBack(const T& _iData)
{
    if(m_iMaxCount <= m_iCount)
    {
        Resize(m_iMaxCount*2);
    }

    m_pData[m_iCount++] = _iData;
}

template<typename T>
void CArr<T>::Resize(int _iResizeCount)
{
    if(m_iMaxCount >= _iResizeCount)
    {
        assert(false);
    }

    T* pNew = new T[_iResizeCount];

    for(int i = 0 ; i < m_iCount ; ++i)
    {
        pNew[i] = m_pData[i];
    }

    delete[] m_pData;

    m_pData = pNew;
    m_iMaxCount = _iResizeCount;
}

template<typename T>
T& CArr<T>::operator[](const int _Index)
{
    //배열 인덱스로 접근하게 되면, 수정이 가능하기도 하지만
    //값을 리턴하기도 해야 함 -> 레퍼런스 변수를 리턴시켜서 값으로 사용하기도, 수정도 가능하게 함
    return m_pData[_Index]; //pInt 포인터에서 index만큼 이동한 주소를 레퍼런스로 하는 int 변수를 리턴
}

template<typename T>
void CArr<T>::PrintArr()
{
    for(int i = 0; i < m_iCount; ++i)
    {
        std::cout << m_pData[i] << " ";
    }
    std::cout << '\n';
}

template<typename T>
//inner클래스가 리턴타입인 경우, typename으로 명시해줌
typename CArr<T>::iterator CArr<T>::begin()
{
    if(this->m_iCount == 0)
    {
        return iterator(this, m_pData, -1); //데이터가 들어간 게 없다면 end반복자 반환
    }
    //시작을 가리키는 iterator를 만들어서 반환
    return iterator(this, m_pData, 0); //임시객체로 만들어서 반환
}

template<typename T>
typename CArr<T>::iterator CArr<T>::end()
{
    return iterator(this, m_pData, -1);
}