#include <iostream>
#include <wchar.h>
#include <assert.h> //경고 출력 기능을 포함한 헤더

//wcslen을 직접 구현
unsigned int GetLength(const wchar_t* c)
{
    int Length = 0;
    for(Length ; '\0' != c[Length] ; ++Length) {}

    return Length;
}

//wcscat을 직접 구현
void StrCat(wchar_t* _pDest, unsigned int _iBufferSize, const wchar_t* _pSrc)
{
    int iDestLen = GetLength(_pDest);
    int iSrcLen = GetLength(_pSrc);

    if(_iBufferSize < iDestLen + iSrcLen + 1) //'\0'문자 까지 계산
    {
        assert(false); //두 문자 길이가 버퍼 사이즈보다 크면 중단
    }

    //마지막 null문자를 추가하기 위해 _pSrc의 null문자까지 더함
    for(int i = 0; i < iSrcLen + 1; ++i)
    {
        //문자열의 끝 + i(src 길이만큼) 위치에 붙일 문자열 추가
        _pDest[iDestLen + i] = _pSrc[i];
    }
}

// wcscmp() 구현하기 같으면 0
// 다른 경우 lvalue가 우열이 높으면 1, rvalue가 우열이 높으면 -1 출력
int StrCmp(const wchar_t* _Str1, const wchar_t* _Str2)
{
    int Str1Len = GetLength(_Str1);

    for(int i = 0 ; i < Str1Len + 1 ; ++i)
    {
        if(_Str1[i] > _Str2[i])
        {
            return 1;
        }
        else if(_Str1[i] < _Str2[i])
        {
            return -1;
        }
    }
    return 0;
}


int main()
{
    //문자
    char c = 'd'; //char타입은 ascii코드표에 근거하여 해석
    bool b = 1; //bool타입은 0과 1을 ture, false로 해석함

    int i = 0; //int는 정수 그대로 인식

    wchar_t wc = L'a'; //wchar, 한 글자당 2바이트

    char szChar[10] = "abcdef";

    //둘이 같은 값을 집어넣고 있지만, char는 문자 자료형을 위주로 사용하기 때문에
    //선언 방법이 다름(ascii 기반 vs 순수 정수)
    //둘다 2바이트 자료형이고, 같은 값을 사용하고 있기는 함
    wchar_t szWChar[10] = L"abcdef";
    short arrShort[10] = {98,99,100,101,102,};
    //배열 선언 = 스택 메모리에 10바이트 할당 -> 데이터 복사 명령 수행

    //Read - Only - Memory(ROM)
    
    //문자열 = 주소값 -> 포인터에서 문자열로 초기화가 가능함
    const wchar_t* pChar = L"abcdef";
    //포인터 선언 = ROM 공간(코드)를 참조하여 초기화
    //값의 수정이 불가능함 -> 코드가 실행 중에 코드를 수정하는 동작임
    //*(pChar+1)= 'z'; -> 에러 발생(런타임 중에 에러가 남)

    wchar_t szTest[10] = L"아아아";

    wchar_t szName[10] = L"Raimond";
    
    //wcslen은 문자열 길이를 반환하는 함수, 매개변수로 const 포인터를 가짐
    int iLen = GetLength(szName);

    //wcscat 함수는 목표가 되는 문자열 위치에 2번째 매개변수를 가져다 붙임
    //두번째 매개변수는 수정이 안되어야 하고, 첫번째는 수정이 가능해야함
    //매개변수는 wchar_t, const wchar_t* 로 구성됨
    //wcscat_s();

    

    //핵심
    //const가 붙은 매개변수는 탐색, 접근 위주의 동작의 대상임
    //const가 없음 -> 그 매개변수는 대부분 수정됨

    wchar_t szString[10] = L"abc";

    //StrCat(szString, 10, L"deasdasdadadsf");
    //wcscat_s(szString, 10, L"defwqewquheqwheuqwe");
    //크기가 10인데, 10을 넘어가면 '\0'이 들어갈 공간이 없어서 예외처리발생

    int iRet = StrCmp(L"abcde", L"abcdef");
    
    return 0;
}