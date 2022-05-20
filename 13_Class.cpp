#include <iostream>

//클래스와 구조체의 차이
//클래스에는 접근 제한 지정자가 존재
//private, protected, public

//앞서 만든 가변배열을 예시로, 
//pushback을 한번 하면 배열에 1개의 값만 들어가지만,
//iCount 변수를 조작하면 인덱스와 실제 데이터 갯수의 혼동이 일어남

class CMY
{
    //private : 이 공간에 있는 멤버는 외부에서 접근 불가, 클래스 내부에서만 처리가능
private:
    int m_iPrivate;
    float m_fPrivate;

    //public : 누구나 접근 가능

public:
    int m_iPublic;

    //멤버 함수 -> 객체를 통해서만 접근 가능함
    void SetInt(int i)
    {
        //private한 변수가 공개적인 멤버함수를 통해 수정됨 -> getter, setter 방식
        //this 키워드 = 해당 멤버함수를 호출한 객체의 주소
        this->m_iPrivate = i;
    }

    //대입연산자 = 를 클래스 CMY의 자료에 맞춰 함수 오버로딩
    CMY& operator =(const CMY& _other)
    {
        m_iPrivate = _other.m_iPrivate;
        m_fPrivate = _other.m_fPrivate;

        return *this;
        //만약 void 타입이라면, c = c1 = c2 동작에서, c1 = c2 이후 리턴값이 없게 되기에
        //c = ;로 되어서 에러가 발생 -> c1 = c2 이후 결과값을 리턴하여 c = c1으로 유지하기 위해 CMY객체 리턴
    }

    //이 클래스를 상속받은 객체만이 접근 가능
protected:
    int m_iProtected;

public:
    //생성자 반환타입없음, 멤버 변수를 클래스 생성과 동시에 초기화해줌
    CMY() : m_iPrivate(100), m_fPrivate(0.f) //이니셜라이저 -> 멤버들을 생성자 이전에 초기화시킴
    {
        
    }

    //소멸자 -> 객체, 멤버들을 해제시켜줌, 선언된 지역 범위를 벗어나면 해제
    ~CMY()
    {

    }

    //위 둘은 모두 자동으로 호출됨, 만들지 않으면 기본으로 만들어짐
};


int main()
{
    int i = 0;

    
    CMY c;
    CMY c2;
    CMY c3;

    c.SetInt(100);
    c2.SetInt(300);
    c3.SetInt(500);

    c = c2 = c3;
    
    {
        //자료형 * 변수명;      -> 자료형의 포인터
        // *포인터변수;         -> 포인터가 가리키는 값으로 역참조
        // &변수;              -> 변수가 가진 주소값
        // 자료형& 변수명;      -> 레퍼런스 변수 선언(참조)
        
        int a = 10;

        //포인터를 통해, a의 주소에 접근해서 값 변경
        int* p = &a;
        *p = 30;

        //iRef는 a를 참조하기에, iRef가 곧 a가 됨
        //int* const p와 똑같은 방법으로, 레퍼런스 변수에 어떤 변수를 넣으면, 그 뒤로 다른 변수를 넣을 수 없음
        //주소 연산을 확실하게 할 수 있음
        int& iRef = a;
        iRef = 50; 
        //원본 수정 시, 역참조 연산자가 필요없음
        //포인터처럼 주소를 조작하여 값을 변경할 여지가 없음 -> 사용자 입장에서의 실수가 줄어듦

        const int& iRefConst = a;
        //a 값 수정 불가능 -> const int* const p와 동일한 취급
    }
    
    return 0;
}