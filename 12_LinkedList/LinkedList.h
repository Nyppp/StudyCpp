#pragma once
//연결리스트

typedef struct _tagNode
{
    int     iData;
    struct _tagNode*  pNextNode;
}tNode;

typedef struct _tagList
{  
    tNode*      pHeadNode;
    int         iCount;
}tLinkedList;


//연결리스트 초기화
void InitList(tLinkedList* _pList);

//연결리스트 원소 맨 뒤에 추가
void PushBack(tLinkedList* _pList, int iData);

//연결리스트 원소 맨 앞에 추가
void PushFront(tLinkedList* _pList, int iData);

//연결리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);

void GetTail(tLinkedList* _pList);
