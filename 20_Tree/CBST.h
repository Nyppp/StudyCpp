#pragma once
#include <assert.h>

//노드의 연결 관계에 대한 열거형 선언
enum class NODE_TYPE
{
    PARENT, //0
    LCHILD, //1
    RCHILD, //2
    END //3
};

template <typename T1, typename T2>
struct tPair
{
    T1      first;
    T2      second;
    
public:
    //custom-pair 생성 함수
    tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second);
};

template<typename T1, typename T2>
tPair<T1, T2> make_bstpair(const T1& _first, const T2& _second)
{
    //임시객체 구조체 선언으로 바로 리턴시킴
    return tPair<T1, T2>{ _first, _second };
}


template <typename T1, typename T2>
struct tBSTNode
{
    tPair<T1, T2>   pair;
    
    //연결된 노드들을 묶어놓은 노드 배열 -> END개(3개) 만큼 할당하였고,
    //PARENT(0번인덱스)는 부모노드, LCHILD(1번인덱스)는 왼쪽자식, RCHILD(2번인덱스)는 오른쪽 자식노드가 들어감.
    tBSTNode*       arrNode[ (int)NODE_TYPE::END ];

    //루트 노드인지 여부 반환
    bool IsRoot()
    {
        if(arrNode[(int)NODE_TYPE::PARENT] == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //부모로부터 자신이 왼쪽 노드인지 여부 반환
    bool IsLeftChild()
    {
        if( arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //부모로부터 자신이 오른쪽 노드인지 여부 반환
    bool IsRightChild()
    {
        if( arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //자신의 자식이 없는지 여부 반환
    bool IsLeaf()
    {
        if(arrNode[(int)NODE_TYPE::LCHILD] == nullptr && arrNode[(int)NODE_TYPE::RCHILD] == nullptr)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    //자신의 자식이 2개 있다면 true 반환
    bool IsFull()
    {
        if(arrNode[(int)NODE_TYPE::LCHILD] == nullptr && arrNode[(int)NODE_TYPE::RCHILD] == nullptr)
        {
            return false;
        }
        else
        {
            return true;
        }
    }

    //노드 기본 생성자
    tBSTNode() : pair(), arrNode{} {}

    //이니셜라이저를 가진 생성자
    tBSTNode(const tPair<T1, T2>& _pair, tBSTNode* _pParent, tBSTNode* _pLChild, tBSTNode* _pRChild)
        : pair(_pair), arrNode{ _pParent, _pLChild, _pRChild } {}

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

public:
    bool insert(const tPair<T1, T2>& _pair);
    tBSTNode<T1, T2>* GetInOrderSuccessor(tBSTNode<T1, T2>* _node);
    tBSTNode<T1, T2>* GetInOrderPredecessor(tBSTNode<T1, T2>* _node);

    //트리의 삭제
    //삭제할 노드가 자식이 없는 경우 -> 그냥 삭제하면 됨
    //자식이 한개 있는 경우 -> 자식을 바로 올리면 됨
    //자식이 두개 있는 경우 -> 중위 순회의 우열을 따라서, 중위 선행자나, 중위 후속자가 삭제한 자리에 와야 함
    //만약 자식이 두개 있는데, 둘중 하나를 삭제한 자리에 올린다면, 중위 서열이 깨지며 트리 구조가 많이 바뀌게 됨
    //그리고 중위선행자, 후속자 사이에서도 그 둘의 자식노드 여부에 따라 결정됨 -> 그러나 자식이 2개인 노드의 중위 선행자, 후속자는 모두 말단 노드이기 때문에 따로 설계x


    class iterator;
public:
    iterator begin();
    iterator end();
    iterator find(const T1& _key);
    iterator erase(const iterator& _iter);

//노드 삭제를 위해 erase함수만이 내부적으로 따로 호출하기 위해 만든 DeleteNode 함수
private:
    tBSTNode<T1, T2>* DeleteNode(tBSTNode<T1, T2>* _node);

public:
    class iterator
    {
    private:
        CBST<T1, T2>*       m_pBST;
        tBSTNode<T1, T2>*   m_pNode; //nullptr인 경우, end() 반복자로 취급


    public:
        iterator() : m_pBST(nullptr), m_pNode(nullptr) {}
        iterator(CBST<T1, T2>* _pBST, tBSTNode<T1, T2>* _pNode) : m_pBST(_pBST), m_pNode(_pNode) {}

    public:
        bool operator ==(const iterator& _other)
        {
            if(m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
            {
                return true;
            }
            else
                return false;
        }

        bool operator !=(const iterator& _other)
        {
            if(m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
            {
                return false;
            }
            else
                return true;
        }

        

        //트리의 경우, 값이 수정되면 구조가 뒤틀리는 문제가 발생하기에 const로 제한
        const tPair<T1, T2> operator *()
        {
            if(m_pNode == nullptr)
            {
                assert(false);
            }

            return m_pNode->pair;
        }

        const tPair<T1, T2>* operator ->()
        {
            if(m_pNode == nullptr)
            {
                assert(false);
            }

            return &m_pNode->pair;
        }

        iterator& operator ++()
        {
            m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
            return *this;
        }

        friend class CBST<T1, T2>;
    };
};

template <typename T1, typename T2>
typename CBST<T1,T2>::iterator CBST<T1,T2>::begin()
{
    //시작점은, 중위순회 기준으로 가장 왼쪽 하단에 존재하는 노드가 시작노드가 됨
    tBSTNode<T1, T2>* SearchNode = m_pRoot;
    while(SearchNode->arrNode[(int)NODE_TYPE::LCHILD] != nullptr)
    {
        SearchNode = SearchNode->arrNode[(int)NODE_TYPE::LCHILD];
    }
    return iterator(this, SearchNode);
}

template <typename T1, typename T2>
typename CBST<T1,T2>::iterator CBST<T1,T2>::end()
{
    return iterator(this, nullptr);
}

template <typename T1, typename T2>
typename CBST<T1,T2>::iterator CBST<T1,T2>::find(const T1& _key)
{
    //노드가 이동할 방향을 담음
    NODE_TYPE node_type = NODE_TYPE::END;

    tBSTNode<T1, T2>* searchNode = m_pRoot;
    while(true)
    {
            if(_key > searchNode->pair.first)
            {
                node_type = NODE_TYPE::RCHILD;
                
            }
            else if(_key < searchNode->pair.first)
            {
                node_type = NODE_TYPE::LCHILD;
            }
            //같은 노드가 나온다면, key 탐색 성공
            else
            {
                break;
            }

            //노드를 진행시켰는데, 그 노드가 nullptr이라면, 더는 내려갈 길이 없음 -> 키가 존재하지 않음
            if(searchNode->arrNode[(int)node_type] == nullptr)
            {
                searchNode = nullptr;
                break;
            }
            else
            {
                //진행이 가능하다면, 다음 노드로 넘어가서 다시 key값 비교
                searchNode = searchNode->arrNode[(int)node_type];
            }
    }

    return iterator(this, searchNode);
}

template <typename T1, typename T2>
typename CBST<T1,T2>::iterator CBST<T1,T2>::erase(const CBST<T1,T2>::iterator& _iter)
{
    if(this == _iter.m_pBST)
    {
        assert(false);
    }

    tBSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);
    return iterator(this, pSuccessor);
}

template <typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1,T2>::DeleteNode(tBSTNode<T1, T2>* _node)
{

    tBSTNode<T1, T2>* pSuccessor = nullptr;

    //자식이 하나도 없다면, 해당 노드를 그냥 지워버림
    if (_node->IsLeaf() == true)
    {
        // 삭제시킬 노드의 후속자를 찾아둔다 -> 삭제 할 노드가 곧 후속자이기 때문
        pSuccessor = GetInOrderSuccessor(_node);

        //노드가 한개뿐인 경우
        if(_node == m_pRoot)
        {
            m_pRoot = nullptr;
        }
        else
        {
            //부모 노드로 접근하여, 삭제할 노드를 가리키는 포인터를 nullptr로 바꿈
            if(_node->isLeftChild() == true) 
            {
                //삭제할 노드가 왼쪽 자식이었을 때
                _node->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
            }
            else
            {
                //오른쪽 자식이었을 때
                _node->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
            }
        }

        delete _node;
    }

    //자식이 2개인 경우
    else if(_node->IsFull())
    {

    }

    //자식이 1개인 경우
    else
    {

    }

    --m_iCount;
    return pSuccessor;
}

template <typename T1, typename T2>
bool CBST<T1,T2>::insert(const tPair<T1, T2>& _pair)
{
    tBSTNode<T1, T2>* pNewNode = new tBSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);
    
    //루트노드가 없다면, 새로 삽입하는 노드가 루트노드가 됨
    if(m_pRoot == nullptr)
    {
        m_pRoot = pNewNode;
    }
    else
    {
        tBSTNode<T1, T2>* currentNode = m_pRoot;

        //노드가 이동할 방향을 담을 열거형 변수
        NODE_TYPE node_type = NODE_TYPE::END;

        while(true)
        {
            //삽입 노드의 키가 현재 노드보다 작으면 왼쪽으로 보냄
            if(currentNode->pair.first > pNewNode->pair.first)
            {
                node_type = NODE_TYPE::LCHILD;
                
            }
            //크다면 오른쪽으로
            else if(currentNode->pair.first < pNewNode->pair.first)
            {
                node_type = NODE_TYPE::RCHILD;
            }
            else
            {
                //중복값에 대해서는 예외처리, 중복값은 허용하지 않는다.
                return false;
            }

            //노드 이동 후, 그 공간이 nullptr 이라면, 노드를 삽입한다.
            if(currentNode->arrNode[(int)node_type] == nullptr)
            {
                currentNode->arrNode[(int)node_type] = pNewNode;
                pNewNode->arrNode[(int)NODE_TYPE::PARENT] = currentNode;
                break;
            }
            else
            {
                currentNode = currentNode->arrNode[(int)node_type];
            }

            //직접 포인터를 이용해 부모, 왼쪽, 오른쪽 자식을 선언해 사용할 때보다 간결하고, 유지보수가 쉬운 코드 작성가능.
        }

    }

    ++m_iCount;
    return true;
}



template <typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1,T2>::GetInOrderSuccessor(tBSTNode<T1, T2>* _node)
{
    NODE_TYPE node_type = NODE_TYPE::END;
    tBSTNode<T1, T2>* searchNode;
    
    //왼쪽 자식노드가 있으면, 거기로 가고(key보다 큰 값)
    if( _node->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
    {
        searchNode = _node->arrNode[(int)NODE_TYPE::RCHILD];

        //왼쪽 자식의 오른쪽 자식이 있다면 그 노드로 감(부모와 오른쪽 자식 사이의 key값 탐색)
        while(searchNode->arrNode[(int)NODE_TYPE::LCHILD] != nullptr)
        {
            searchNode = searchNode->arrNode[(int)NODE_TYPE::LCHILD];
        }
    }
    
    //없다면, 부모 노드로 이동, 자기보다 큰 부모(자신이 부모의 왼쪽자식일 때 까지)를 찾음
    else
    {
        searchNode = _node;


        while(true)
        {
            if(searchNode->IsRoot())
            {
                return nullptr;
            }
            
            if( searchNode-> IsLeftChild() == true)
            {
                searchNode = searchNode->arrNode[(int)NODE_TYPE::PARENT];
                break;
            }
            else
            {
                searchNode = searchNode->arrNode[(int)NODE_TYPE::PARENT];
            }
        }
        
    }
    return searchNode;
}

template <typename T1, typename T2>
tBSTNode<T1, T2>* CBST<T1,T2>::GetInOrderPredecessor (tBSTNode<T1, T2>* _node)
{
    NODE_TYPE node_type = NODE_TYPE::END;
    tBSTNode<T1, T2>* searchNode;
    
    //오른쪽 자식노드가 있으면, 거기로 가고(key보다 큰 값)
    if( _node->arrNode[(int)NODE_TYPE::LCHILD] != nullptr)
    {
        searchNode = _node->arrNode[(int)NODE_TYPE::LCHILD];

        //오른쪽 자식의 왼쪽 자식이 있다면 그 노드로 감(부모와 오른쪽 자식 사이의 key값 탐색)
        while(searchNode->arrNode[(int)NODE_TYPE::RCHILD] != nullptr)
        {
            searchNode = searchNode->arrNode[(int)NODE_TYPE::RCHILD];
        }
    }
    
    //없다면, 부모 노드로 이동, 자기보다 큰 부모(자신이 부모의 왼쪽자식일 때 까지)를 찾음
    else
    {
        searchNode = _node;


        while(true)
        {
            if(searchNode->IsRoot())
            {
                return nullptr;
            }
            
            if( searchNode-> IsRightChild() == true)
            {
                searchNode = searchNode->arrNode[(int)NODE_TYPE::PARENT];
                break;
            }
            else
            {
                searchNode = searchNode->arrNode[(int)NODE_TYPE::PARENT];
            }
        }
        
    }
    return searchNode;
}

