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
    

    return 0;
}