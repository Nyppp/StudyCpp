#pragma once

class CArr
{
private:
    int*    m_pInt;
    int     m_iCount;
    int     m_iMaxCount;

public:
    CArr();
    ~CArr();

public:
    void PushBack(int _iData);
    void Resize(int _iResizeCount);
    void PrintArr();

    int& operator [](const int _Index);
};