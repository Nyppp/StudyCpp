#pragma once

#include <assert.h>

//c++기준, 클래스와 구조체는 큰 차이가 없음.
//다만 구조체는 default 접근제한자가 public임. (클래스는 private)

//기능이 적거나, 단순 데이터 집합이면 구조체 사용
//추가기능 존재하거나 데이터가 많다면 클래스 사용

template <typename T> //구조체 템플릿
struct tListNode
{
    T            Data;
    tListNode*   pNext; 
    //본인 선언 내부에 존재하기 때문에, 탬플릿 자료형임을 명시할 필요없음
    //하지만 다른 곳에서 사용한다면, 반드시 명시해야함
    tListNode*   pPrev;

    //구조체 생성자
    tListNode() : Data(), pNext(nullptr), pPrev(nullptr) {} //default

    tListNode(T _data, tListNode<T>* _pNext, tListNode<T>* _pPrev) 
        : Data(_data)
        , pNext(_pNext)
        , pPrev(_pPrev) 
        {

        } //입력이 존재하는 생성자(오버로딩)
};

template <typename T>
class CList
{
private:
    int             m_iCount;
    tListNode<T>*   m_pHead; 
    tListNode<T>*   m_pTail;
    //탬플릿 자료형을 포인터로 가리킬 때는, <T> 붙여줘야 함
    //가리키는 탬플릿이 어떤 자료형인지 알기 위해
    
public:
    CList();
    ~CList();

public:
    void push_back(const T& _data);
    void push_front(const T& _data);
    int size() {return m_iCount;}

public:
    class iterator;
    iterator begin();
    iterator end();
    iterator erase(iterator& _iter);
    iterator insert(const iterator& _iter, const T& _data);

    class iterator
    {
    private:
        CList<T>*           m_pList;
        tListNode<T>*       m_pNode;
        bool                m_bValid;

    public:
        iterator() : m_pList(nullptr), m_pNode(nullptr), m_bValid(false) {}
        iterator(CList<T>* _pList, tListNode<T>* _pNode) : m_pList(_pList), m_pNode(_pNode), m_bValid(false) 
        {
            if(_pList != nullptr && _pNode != nullptr)
            {
                m_bValid = true;
            }
        }
        ~iterator()
        {

        }

    public:
        T& operator * ()
        {
            return m_pNode->Data;
        }

        bool operator ==(const iterator& _otheriter)
        {
            if(m_pList == _otheriter.m_pList && m_pNode == _otheriter.m_pNode)
            {
                return true;
            }
            else
                return false;
        }

        bool operator !=(const iterator& _otheriter)
        {
            return !(*this==_otheriter);
        }

        iterator& operator ++()
        {
            if(m_pNode == nullptr || m_bValid != true)
            {
                assert(false);
            }
            else
            {
                m_pNode = m_pNode->pNext;
            }

            return *this;
        }

        iterator& operator ++(int)
        {
            iterator* newIter = new iterator(this->m_pList, this->m_pNode);
            ++(*this);
            return newIter;
        }

        iterator& operator --()
        {
            if(m_pNode == m_pList->m_pHead || m_bValid != true)
            {
                assert(false);
            }
            else
            {
                m_pNode = m_pNode->pPrev;
            }
            return *this;
        }

        iterator& operator --(int)
        {
            iterator* newIter = new iterator(this->m_pList, this->m_pNode);
            --(*this);
            return newIter; 
        }

        friend class CList;
    };
};

template <typename T>
CList<T>::CList() : m_pHead(nullptr), m_pTail(nullptr), m_iCount(0) {}

template <typename T>
CList<T>::~CList()
{
    tListNode<T>* pDeleteNode = m_pHead;
    while(pDeleteNode -> pNext != nullptr)
    {
        tListNode<T>* Next = pDeleteNode->pNext;
        delete(pDeleteNode);
        pDeleteNode = pDeleteNode ->pNext;
    }
}

template <typename T>
void CList<T>::push_back(const T& _data)
{
    //데이터만 존재하는 앞, 뒤 연결이 없는 새로운 노드 생성
    tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, nullptr); 

    if(m_pHead == nullptr)
    {
        //아무것도 없는 리스트에 노드를 넣었기 때문에 헤드와 꼬리가 동일함
        m_pHead = pNewNode;
        m_pTail = pNewNode;
    }
    else
    {
        //꼬리의 다음 노드를 새로 생성한 노드로 넣고, 새로 생성한 노드의 이전 노드를 현재 꼬리로 지정
        m_pTail->pNext = pNewNode;
        pNewNode->pPrev = m_pTail;

        //꼬리를 가리키는 포인터를 새로 생성한 노드로 변경
        m_pTail = pNewNode;
    }

    //데이터 개수 증가
    ++m_iCount;
}

template <typename T>
void CList<T>::push_front(const T& _data)
{
    //다음 노드가 헤드노드인 맨 앞에 올 새로운 노드 생성
    tListNode<T>* pNewNode = new tListNode<T>(_data, nullptr, m_pHead);

    //헤드의 앞 노드로 새로 생성된 노드 지정
    m_pHead->pPrev = pNewNode;

    //헤드 포인터를 새로 생성한 노드로 지정
    m_pHead = pNewNode;

    //데이터 개수 증가
    ++m_iCount;
}



template<typename T>
typename CList<T>::iterator CList<T>::begin()
{
    return iterator(this, m_pHead);
}

template<typename T>
typename CList<T>::iterator CList<T>::end()
{
    return iterator(this, nullptr);
}

template<typename T>
typename CList<T>::iterator CList<T>::erase(iterator& _iter)
{
    if(end() == _iter || _iter.m_bValid == false)
    {
        assert(false);
    }

    if(m_iCount == 1)
    {
        _iter.m_pNode = nullptr;
    }

    if(_iter.m_pNode == m_pHead)
    {
        
        m_pHead = _iter.m_pNode->pNext;
        _iter.m_pNode->pNext->pPrev = nullptr;
        _iter.m_pNode = nullptr;
    }

    else if(_iter.m_pNode == m_pTail)
    {
        m_pTail = _iter.m_pNode->pPrev;
        _iter.m_pNode->pPrev->pNext = nullptr;
        _iter.m_pNode = nullptr;
    }

    else
    {
        _iter.m_pNode->pPrev->pNext = _iter.m_pNode->pNext;
        _iter.m_pNode->pNext->pPrev = _iter.m_pNode->pPrev;

        _iter.m_pNode = _iter.m_pNode->pNext;
    }

    --m_iCount;

    return iterator(this, _iter.m_pNode);
}

template<typename T>
typename CList<T>::iterator CList<T>::insert(const iterator& _iter, const T& _data)
{
    if(end() == _iter)
    {
        assert(false);
    }

    tListNode<T>* newNode = new tListNode<T>(_data, nullptr, nullptr);

    if(_iter.m_pNode == m_pHead)
    {
        _iter.m_pNode->pPrev = newNode;
        newNode->pNext = _iter.m_pNode;

        m_pHead = newNode;
    }
    else
    {
        //새로 추가된 노드와, 들어갈 자리의 앞에 있는 노드의 연결 구성
        _iter.m_pNode->pPrev->pNext = newNode;
        newNode->pPrev = _iter.m_pNode->pPrev;

        //새로 추가된 노드와, 그 뒤로 밀려난 노드의 연결 구성
        _iter.m_pNode->pPrev = newNode;
        newNode->pNext = _iter.m_pNode;
    }
    
    ++m_iCount;

    return iterator(this, newNode);
}