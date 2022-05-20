#include <iostream>

//클래스 내의 static 멤버함수는 객체 없이 사용할 수 있음
//static void ~~~(); -> 클래스이름::~~~() 로 사용

namespace MYSPCAE
{
    int g_int; 
    //전역변수 이지만, 이름공간에 포함되었기 때문에, 이름공간을 거쳐야함
}

//using namespace std -> std 이름공간 내의 모든것을 이름공간 거치지않고 사용
using std::cout;
using std::endl; 
using std::cin;
//이름공간 내의 특정 기능만 생략할수도 있음

void MyEndl()
{
    wprintf(L"\n");
}

class CMyOStream
{
public:
    CMyOStream& operator << (const int _data)
    {
        wprintf(L"%d", _data);
        return *this;
    }
    CMyOStream& operator << (const wchar_t* _data)
    {
        wprintf(L"%s", _data);
        return *this;
    }
    CMyOStream& operator << (void(*_pFunc)(void))
    {
        _pFunc();
        return *this;
    }
    CMyOStream& operator >> (int& _data)
    {
        scanf("%d", &_data);
        return *this;
    }
};

CMyOStream mycout; //클래스에 아무것도없으면 1바이트가 할당됨

int main()
{
    MYSPCAE::g_int = 0;

    //cout, cin은 모두 std라는 이름공간에 존재함(iostream)
    //사용자가 동일한 이름의 함수를 만들면 구분이 안되기 때문에, 이름공간으로 구분
    setlocale(LC_ALL, "korean");
    _wsetlocale(LC_ALL, L"korean");

    int a = 0;
    mycout >> a;

    mycout << a << MyEndl << L"한글";
    

    return 0;
}