#pragma once
#include <assert.h>

template <typename T1, typename T2>
struct tPair
{
    T1      first;
    T2      second;
};

template <typename T1, typename T2>
struct tBSTNode
{
    tPair<T1, T2> pair;
    
    tBSTNode* pParent;
    tBSTNode* pLeftChild;
    tBSTNode* pRightChild;

};

//stl map 구현
template <typename T1, typename T2>
class CBST
{
private:
    tBSTNode<T1, T2>*       m_pRoot;
    int                     m_iCount;

public:
    CBST() : m_pRoot(nullptr), m_iCount(0) {}
    ~CBST() {};

public:
    bool insert(const tPair<T1, T2>& _pair);
};

template <typename T1, typename T2>
bool CBST<T1,T2>::insert(const tPair<T1, T2>& _pair)
{
    tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>();
    pNewNode->pair = _pair;
    pNewNode->pParent = nullptr;
    pNewNode->pLeftChild = nullptr;
    pNewNode->pRightChild = nullptr;

    //루트노드가 없다면, 새로 삽입하는 노드가 루트노드가 됨
    if(m_pRoot == nullptr)
    {
        m_pRoot = pNewNode;
    }
    else
    {
        tBSTNode<T1, T2>* currentNode = m_pRoot;
        while(true)
        {
            //삽입 노드의 키가 현재 노드보다 작으면 왼쪽으로 보냄
            if(currentNode->pair.first > pNewNode->pair.first)
            {
                //자식이 비어있다면, 그 자리에 노드삽입
                if(currentNode->pLeftChild == nullptr)
                {
                    currentNode->pLeftChild = pNewNode;
                    pNewNode->pParent = currentNode;
                    break;
                }
                currentNode = currentNode->pLeftChild;
            }

            //크다면, 오른쪽으로 보냄
            else if(currentNode->pair.first < pNewNode->pair.first)
            {
                if(currentNode->pRightChild == nullptr)
                {
                    currentNode->pRightChild = pNewNode;
                    pNewNode->pParent = currentNode;
                    break;
                }
                currentNode = currentNode->pRightChild;
            }
            else
            {
                //일반적인 맵은 중복 키값을 허용하지 않음 -> 멀티 맵은 허용
                return false;
            }
        }

    }

    ++m_iCount;
    return true;
}