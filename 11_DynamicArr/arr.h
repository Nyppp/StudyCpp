#pragma once

//가변배열 구현
typedef struct _tagArr
{
    int*    pInt;
    int     iCount;
    int     iMaxCount;
}tArr;

//배열 초기화 함수
void InitArr(tArr* _pArr);

//데이터 추가 함수
void PushBack(tArr* _pArr, int _iData);

//배열 크기 확장 함수
void Reallocate(tArr* _pArr);

//배열 할당 해제 함수
void ReleaseArr(tArr* _pArr);

//버블정렬 사용한 가변배열 정렬
void sort(tArr* _pArr, void(*SortFunc)(int*, int));