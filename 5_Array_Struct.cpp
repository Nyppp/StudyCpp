#include <iostream>

//����ü, ����� ���� �ڷ���
//int�� float�� ��� �ϳ��� �ڷ������� ������ ����
typedef struct _tagMyST
{
    int a;
    float f;
}MYST;

typedef struct _tagBig
{
    MYST k;
    char c; //char�� 1����Ʈ������ �ٸ� Ÿ���� ũ���� ����� �ǵ��� ���缭 �ø�(�е�)
    //k����ü ���ο� 4����Ʈ������ �ڷ����ۿ� ���� ������ 1����Ʈ���� 4����Ʈ�� �е�
}BIG;

//typedef ���� ����� ����ü
struct NewStruct
{
    int a;
    short b;
};

int main()
{
    //�迭
    //int �ڷ� 10������ �����͸� ��� 0���� ����
    //�������� �޸𸮸� ����
    int iArray[10] = {};

    //�̷� ��� �����ε� ������� �ʰ�, ��� �ٸ� ������ ���� �� ��찡 �����ϱ� ������
    //�迭 �ε��� ���ٿ� ���� ����
    // iArray[20] = 100;

    //����ü ������ 2���� ��� -> ��� ����, �迭�� ����
    MYST t;
    t.a = 10;
    t.f = 10.1234f;

    MYST t2 = {10 ,10.1234f};

    int iSize = sizeof(BIG);
    std::cout<<iSize;
    return 0;
}   