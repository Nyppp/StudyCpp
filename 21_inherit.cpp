#include <iostream>
//객체지향 언어 특징
//1. 캡슐화(은닉성)
//2. 상속
//3. 다형성
//4. 추상화

using namespace std;

class CParent
{
protected:
    int m_i;

public:
    void setInt(int _a)
    {
        m_i = _a;
    }

    //c++에서 클래스 다형성을 위해 제공하는 virtual 키워드(가상함수)
    //이 virtual 함수는 이 함수를 호출하는 클래스가 어떤 클래스인지 정보를 확인하게끔 해줌
    //각 클래스들은 자신만의 고유한 가상함수 테이블을 가진다. -> 포인터로 함수를 호출할 때,
    //자신이 가리키고 있는 객체가 가진 고유 테이블을 통해 테이블에 맞는 함수를 호출하게 됨
    virtual void Output()
    {
        cout << "parent\n";
    }

public:
    CParent() : m_i(0) { }
    ~CParent() { }
};

//CParent를 상속받는 CChild 클래스
class CChild : public CParent 
{
private:
    float m_f;

public:
    void setFloat(float _f)
    {
        m_f = _f;

        //m_i가 protected로 선언되었기 때문에, 상속관계의 클래스에서 접근 가능.
        m_i = 100;
    }

    //parent 클래스의 output 함수를 '오버라이딩'.
    void Output()
    {
        cout << "child\n";
    }

    //이건 CChild 클래스 내부의 Output 함수를 '오버로딩' -> 같은 블럭이나 클래스 내에서 재정의하며, 매개변수가 다름
    void Output(int _i)
    {
        cout << _i;    
    }

    void ChildOutput()
    {
        cout << "only child\n";
    }

public:
    //CChild 생성자에는 이니셜라이저 맨 앞에, 부모 클래스에 대한 생성자 동작이 함축되어 있음
    // ***부모 클래스 생성자 호출은, 이니셜라이저 순서에 상관없이 가장 먼저 실행됨 + 생략해도 무관***
    CChild() : CParent(), m_f(0.f) 
    { 
        //생성자 이니셜라이저로는 상속 관계에 있는 변수를 사용할 수 없지만,
        //생성자 함수 내부 동작으로는 사용할 수 있음 -> 초기화는 부모 클래스에서.
        m_i = 0; 
        
    }
    
    ~CChild()
    {
        //자식 소멸자를 먼저 호출하고 실행한 다음, 부모 소멸자를 호출함
        //부모 소멸자를 먼저 실행해버리면 안되기에
        
    }
};

void FuncA()
{
    cout << "A\n";
}

void FuncB()
{
    FuncA();
    cout << "B\n";
    //여기에서, funcB를 실행하면, A B 순으로 나옴
    //하지만 여기서 출력되는 A는 FuncA가 먼저 호출 스택에 쌓인 게 아니고,
    //FuncB를 먼저 호출한 다음, 그 내부에 존재하는 FuncA(); 구문을 만나 B 다음에 A가 쌓이고,
    //실행은 A를 먼저 하게되는 순서임 -> 호출 순서는 B A 순이며 실행 순서는 A B 순서임
    //이는 상속 클래스의 생성자 동작과 유사함 

    //만약 FuncA가 뒤에 있다면, 이는 소멸자의 동작임
}

//이 클래스의 경우, CParent -> CChild -> CChildChild 순서대로 메모리가 쌓임
class CChildChild : public CChild
{
private:
    long long m_ll;

public:
    CChildChild() : m_ll(0) {};
};

int main()
{
    //멤버가 int 한 개 뿐이므로 4바이트 크기의 객체
    //CParent의 기능만을 수행하는 객체
    CParent parent; 

    //CParent의 4바이트를 상속 + Cchild의 float 4바이트 = 8바이트 객체
    //CParent 클래스의 기능 + CChild 클래스의 기능이 있는 객체임.
    //그러나, 상속 관계라 해도 상속 클래스의 private 공간에는 접근 불가능
    //상속을 받은 객체의 메모리 순서는 부모 -> ...(상속이 여러 계층일 경우 계속 부모) -> 자신 순서로 메모리에 적재됨 
    CChild child;

    parent.setInt(10);
    child.setInt(10);

    //상속 관계에서의 생성자
    //parent -> 기존 생성자 처럼 동작
    //child -> parent 부분과 child 부분이 존재함 -> 생성자 호출은 두 부분 모두 호출
    //호출 순서는 child 클래스가 먼저 호출되고, 부모 순으로 올라감 -> 메모리 뒷쪽부터 생성자호출
    //그러나 눈에 보이는 출력으로는, 부모가 먼저 호출되는 것 처럼 보일 수 있음.
    //하지만, 자식 클래스 생성자를 호출하면서, 위로 올라가 부모 클래스 생성자를 호출하기 때문에,
    //실행 순서는 부모 생성자가 먼저 오지만, 호출 순서는 자식 클래스가 먼저임

    //상속
    //자식과 부모 클래스는 상속 관계에서 다른 클래스의 멤버를 초기화할 수 없음(이니셜라이저), protected 키워드를 가진 변수의 값 대입은 가능.
    //생성자 호출 순서 : 자식 -> 부모
    //초기화(생성자 동작 실행) 순서 : 부모 -> 자식
    //소멸자 순서 (호출 + 실행) : 자식 -> 부모
    
    //오버로딩 - 함수 이름이 같지만, 매개변수 갯수나 타입이 다른 경우
    //오버라이딩 - 함수 이름과 매개변수 갯수, 타입이 모두 같지만 기능이 다름 -> 상속 클래스의 함수 재정의
    
    parent.Output();
    child.Output();

    //자식 클래스를 통해서 부모 함수를 명시적으로 호출가능
    //child.CParent::Output();

    //상속과 포인터

    //CChild 타입은 parent 클래스와 child 클래스에 대한 메모리가 존재하기에 이는 문제x
    //CChild* pChild = &parent;

    //CParent 타입은 CChild 클래스에 대한 정보가 없음.
    //메모리 구조가 맞지 않음 + CChild 내에 구현된 기능 사용불가
    //CParent* pParent = &child;

    //자식 포인터로 부모 클래스를 가리키면 안됨
    //부모 포인터는 자식 클래스를 받아올 수 있음(문법오류x, 캐스팅x)

    //이 속성을 이용해서, 상속 관계가 많은 클래스는 모두
    //최상위 부모 클래스의 포인터를 이용해 가리킬 수 있음
    //하지만 그 포인터만으로는 객체가 어떤 타입인지 정확히 알수없음

    CParent* pParent = nullptr;

    parent.Output();
    pParent = &parent;
    pParent->Output();

    child.Output();
    pParent = &child;
    pParent->Output();

    //다운캐스팅
    //부모 클래스에서 자식에만 존재하는 함수를 호출할 때, 다운 캐스팅 사용
    //dynamic_cast 사용

    //pParent에는 child에만 존재하는 기능, 멤버를 접근할 수 없음(부모 클래스 포인터기 떄문에)
    //pParent->ChildOutput(); -> 에러 발생

    //C 스타일의 강제 캐스팅 -> 실제로 동작하긴 하지만, 위험요소가 많음
    //pParent가 child를 가리킨다는 확인이 있어야만 하며, pParent가 가리키는 객체가 바뀌면, 에러가 발생함
    // ((CChild*)pParent)->ChildOutput();

    //다이나믹 캐스트는 강제 형변환과 다르게, 실패할 경우 nullptr을 반환시켜준다. -> 안전성 보장
    CChild* pChild = dynamic_cast<CChild*>(pParent);
    if(pChild != nullptr)
    {
        pChild->ChildOutput();
    }




    return 0;
}

