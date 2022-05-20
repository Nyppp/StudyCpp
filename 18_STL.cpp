#include <iostream>
#include <list> //연결리스트 STL
#include <vector> //가변배열 STL

using namespace std;
int main()
{
    list<int> listInt;
    listInt.push_front(10);

    //list 클래스 내에 존재하는 iterator 클래스(inner class)
    list<int>::iterator iter = listInt.begin(); //해당 반복자는 시작노드를 가리키게 됨
    int iData = *iter; // 10 리턴

    //iterator는 포인터가 아닌, 클래스 객체임 -> *iter 또한 역참조 연산의 클래스 객체에 대한 오버로딩임.
    //iterator가 다른 값은 제쳐두고, 데이터 값만을 가져오게끔 오버로딩

    //벡터도 존재
    vector<int> vecInt;
    vector<int>::iterator vecIter = vecInt.begin();
    
    //아래 두 구문은 같은 동작
    *vecIter = 100;
    vecInt[0] = 100;

    //반복자가 가리키는 값을 idata에 삽입
    int iData = *vecIter;

    //반복자 인덱스를 증가 -> 다음 데이터값을 가리킴
    ++vecIter;
    iData = *vecIter;
    
    //iterator는 end를 가리키면, 모두 마지막 데이터의 다음 값을 가리킨다는 뜻임(nullptr)
    for(iter = listInt.begin(); iter != listInt.end(); ++iter)
    {
        cout << *iter << endl; 
    }

    return 0;
}