#include <iostream>

//�Լ�
int Add(int left, int right)
{
    //int �Լ��� intŸ���� �����͸� �ݵ�� ��ȯ�ؾ� �Ѵ�.
    return left + right;
}

//�Լ��� �ٽ��� ���� �ڵ带 ������ �ݺ����� �ʵ��� '���ȭ' ��Ű�� ����.
//���丮���� ����Ѵٸ�, �Ź� �ݺ����� �ٿ��ִ� �� ���� �Լ��� ¥ �д�.

//�ݺ����� ����� factorial ����
int Factorial(int N) 
{
    int Value = 1;
    for(int i = 1 ; i <= N; ++i)
    {
        Value *= i;
    }
    return Value;
} 

//��͸� ����� factorial ����
//����Լ��� �������� �þ����, ��� ȣ��� Ż�⿡ ���� �߰� ����� ����.
//�ӵ��� ���� ������ ������
int Re_Factorial(int N) 
{
    if(N==1)
    {
        return 1;
    }

    return N * Re_Factorial(N-1);
}



//�ݺ��� ���� �Ǻ���ġ ����
int Fibonacci(int N)
{
    if(N == 1)
    {
        return 1;
    }
    else if(N == 0)
    {
        return 0;
    }
    
    int iValue = 0;
    int iPrev1 = 0;
    int iPrev2 = 1;

    for(int i = 0; i < N-1; ++i)
    {
        iValue = iPrev1 + iPrev2;
        iPrev1 = iPrev2;
        iPrev2 = iValue;
    }

    return iValue;
}

//�Ǻ���ġ ���� - ���
int Re_Fibonacci(int N)
{
    if(N == 1)
    {
        return 1;
    }
    else if(N == 0)
    {
        return 0;
    }

    return Re_Fibonacci(N-1) + Re_Fibonacci(N-2);
}

//�Լ��� �����ε� != �������̵�
//���� �Լ����� ���������, �Ű������� �ٸ� -> �ñ״�ó�� �ٸ�
//���� �ٸ� ����� ������ �� ����
void Test(int a)
{

}

void Test(int a, int b)
{

}

//���α׷��� ��� �����Լ��� ȣ���Ͽ� ������
int main()
{
    //�� ���� �����Լ� ������ ���ο� �Լ��� ȣ���Ͽ� ��� ���
    int iData = Add(100,200);

    //�ݺ��� -> for, while ���� + �پƴϱ� ����
    
    //������ ���� ������ ����(���Լ���), ť(���Լ���) ���
    //�Լ��� ���� ���
    //�Լ� ȣ�� ��, �Լ� �� ������ ������ �ľ�, �޸� �Ҵ��Ŵ
    
    // int iValue = Factorial(10);
    // int Re_iValue = Re_Factorial(10);

    // int Fibo = Fibonacci(10);
    // int Re_Fibo = Re_Fibonacci(10);
    

    return 0;
}