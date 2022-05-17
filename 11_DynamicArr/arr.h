#pragma once

//�����迭 ����
typedef struct _tagArr
{
    int*    pInt;
    int     iCount;
    int     iMaxCount;
}tArr;

//�迭 �ʱ�ȭ �Լ�
void InitArr(tArr* _pArr);

//������ �߰� �Լ�
void PushBack(tArr* _pArr, int _iData);

//�迭 ũ�� Ȯ�� �Լ�
void Reallocate(tArr* _pArr);

//�迭 �Ҵ� ���� �Լ�
void ReleaseArr(tArr* _pArr);

//�������� ����� �����迭 ����
void sort(tArr* _pArr, void(*SortFunc)(int*, int));