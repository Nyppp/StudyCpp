#include <iostream>
#include "CList.h"
#include <list>

using namespace std;
int main()
{
    //클래스 탬플릿은 개발자가 여러번 만들 것을 하나의 틀로 재사용할수 있게 만들어주는 기능
    CList<int> mylist;

    list<int> stdclist;

    stdclist.push_back(100);
    stdclist.push_back(200);
    stdclist.push_back(300);
    list<int>::iterator stditer= stdclist.begin();

    stdclist.erase(++stditer);
    

    mylist.push_back(100);
    mylist.push_back(200);
    mylist.push_back(300);
    mylist.push_back(400);

    CList<int>::iterator listiter = mylist.begin();
    mylist.erase(listiter);

    for(listiter = mylist.begin(); listiter != mylist.end(); ++listiter)
    {
        std::cout << *listiter << std::endl;
    }
    
    return 0;
}
