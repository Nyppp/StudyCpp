#include <iostream>
#include "arr.h"

//�޸� ����
//���� < ��������, �Լ� �� -> ������ �� ����
//������ < ����, static, extern ���� �� -> ������ �� ����
//ROM < �ڵ�
//��(���� �Ҵ�) -> ��Ÿ�� �� ����

int main()
{   
    //malloc�� ��ȯŸ�� = void -> �ּҸ� �ֱ� ������, �뵵�� ����ڰ� ���� ����
    //�������� 100����Ʈ ũ�⸦ ���� �ּҸ� �Ҵ��ϰ�, pInt�� ����Ű���� ����
    int* pInt = (int*)malloc(100);

    float* pF = (float*)malloc(4);
    *pF = 1.23f; //�������� ������ 1.23f�� �������

    int* pI = (int*)pF;

    *pF = 2.4f;
    int i = *pI;
    

    
    //�����Ҵ��� �ٽ�
    // 1. ��Ÿ�� �߿� ���� ����
    // 2. ����ڰ� ������ ������ ���� �����ؾ� ��
    int* pInt = nullptr;
    pInt = (int*)malloc(100);

    free(pInt);

    //�����迭
    int a = 100;
    //int arr[a] = {}; -> a�� ����, ��� �ٲ� �� �ֱ⿡ �ε���x
    
    //��ü(instance)
    //int a; -> a�� int �ڷ����� ���� ��ü

    tArr arr;

    tArr arr2;

    tArr arr3;

    return 0;
}