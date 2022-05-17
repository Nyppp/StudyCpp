#include "arr.h"
#include <iostream>

void InitArr(tArr* _pArr)
{
    _pArr->pInt = (int*)malloc(sizeof(int) * 10);
    _pArr->iCount = 0;
    _pArr->iMaxCount = 10;
}

void PushBack(tArr* _pArr, int _iData)
{
    if(_pArr->iCount <= _pArr->iMaxCount)
    {
        Reallocate(_pArr);
    }

    _pArr->pInt[_pArr->iCount++] = _iData;
}

void Reallocate(tArr* _pArr)
{
    _pArr->iMaxCount *= 2;

    int* pNew = (int*)malloc(_pArr->iMaxCount*sizeof(int));

    for(int i = 0; i < _pArr->iCount; ++i)
    {
        pNew[i] = _pArr->pInt[i];
    }

    free(_pArr->pInt);
    _pArr->pInt = pNew;
}

void sort(tArr* _pArr)
{
    if(_pArr ->iCount <= 1)
    {
        return;
    }
    
    for(int i = 0; i < _pArr->iCount; ++i)
    {
        for(int j = i ; j < _pArr->iCount; ++j)
        {
            if(_pArr->pInt[i] > _pArr->pInt[j])
            {
                int Temp = _pArr->pInt[i];
                _pArr->pInt[i] = _pArr->pInt[j];
                _pArr->pInt[j] = Temp;
            }
        }
    }
}

void ReleaseArr(tArr* _pArr)
{
    free(_pArr->pInt);
    _pArr->iCount = 0;
    _pArr->iMaxCount = 0;
}

void sort(tArr* _pArr, void(*SortFunc)(int*, int))
{
    SortFunc(_pArr->pInt, _pArr->iCount);
}