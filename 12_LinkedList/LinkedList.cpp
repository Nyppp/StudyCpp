#include "LinkedList.h"
#include <iostream>

void InitList(tLinkedList* _pList)
{
    _pList->pHeadNode = nullptr;
    _pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int iData)
{
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = iData;
    pNode->pNextNode = nullptr;
    
    if(_pList->pHeadNode == nullptr)
    {
        _pList->pHeadNode = pNode;
        
    }
    else
    {
        tNode* CurrentNode = _pList->pHeadNode;

        while(CurrentNode->pNextNode != nullptr)
        {
            CurrentNode = CurrentNode -> pNextNode;
        }

        CurrentNode->pNextNode = pNode;
    }

    ++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int iData)
{
    tNode* pNode = (tNode*)malloc(sizeof(tNode));

    pNode->iData = iData;
    pNode->pNextNode = _pList->pHeadNode;
    _pList->pHeadNode = pNode;
    ++_pList->iCount;
}

void ReleaseList(tLinkedList* _pList)
{
    tNode* pDeleteNode = _pList->pHeadNode;
    tNode* pNext = _pList->pHeadNode;

    while(pDeleteNode != nullptr)
    {
        pNext = pNext->pNextNode;

        free(pDeleteNode);
        pDeleteNode = pNext;
    }

    _pList->iCount = 0;
}