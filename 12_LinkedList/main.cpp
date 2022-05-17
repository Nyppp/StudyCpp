#include <iostream>

#include "LinkedList.cpp"

//가변배열과 리스트의 차이점
//가변배열 : 시작주소를 알고있기 때문에, 시작주소에 + 포인터연산을 하면 바로 접근가능
//리스트 : 맨 끝 원소를 접근할 때, 원소의 갯수만큼 연산이 필요함 -> 맨끝 원소에 대한 tail을 안다고 해도, 중간 원소를 접근할 때도 마찬가지임.

int main()
{
    tLinkedList List = {};
    InitList(&List);

    for(int i = 1; i < 5; ++i)
    {
        PushFront(&List, i);
    }

    ReleaseList(&List);

}