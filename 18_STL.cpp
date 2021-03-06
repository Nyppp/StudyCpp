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

    //iterator는 포인터가 아닌, 클래스 객체임 -> *iter 또한 역참조 연산의 클래스 객체에 대한 오버로딩임.
    //iterator가 다른 값은 제쳐두고, 데이터 값만을 가져오게끔 오버로딩

    //벡터도 존재
    vector<int> vecInt;
    for(int i = 10; i > 2; --i)
    {
        vecInt.push_back(i);
    }

    vector<int>::iterator vecIter = vecInt.begin();

    for(; vecIter != vecInt.end();)
    {
        if(*vecIter %2 ==0)
        {
            vecIter = vecInt.erase(vecIter);
        }
        else
        {
            ++vecIter;
        }
    }

    for(int i = 0; i < vecInt.size(); ++i)
    {
        std::cout<<vecInt[i];
    }
    return 0;
}