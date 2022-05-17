#include <iostream>
#include "arr.cpp"

//버블정렬
void BubbleSort(int* _pData, int iCount)
{
    if(iCount <= 1)
        return;

    for(int i = 0; i < iCount; ++i)
    {
        for(int j = i ; j < iCount; ++j)
        {
            if(_pData[i] > _pData[j])
            {
                int Temp = _pData[i];
                _pData[i] = _pData[j];
                _pData[j] = Temp;
            }
        }
    }
}

//삽입정렬
void InsertionSort(int* _pData, int iCount)
{
    if(iCount <= 1)
        return;
    
    for(int i = 1; i < iCount; ++i)
    {
        int key = _pData[i];

        for(int j = i-1; j >= 0; --j)
        {
            if(key < _pData[j])
            {
                _pData[j+1] = _pData[j];
                _pData[j] = key;
            }
        }
    }
}

//선택정렬
void SelectionSort(int* _pData, int iCount)
{
    if(iCount <= 1)
        return;

    for(int i = 0; i < iCount; ++i)
    {
        int Min = _pData[i];
        int MinIndex = i;

        for(int j = i ; j < iCount; ++j)
        {
            if(Min > _pData[j])
            {
                Min = _pData[j];
                MinIndex = j;
            }
        }

        int Temp = _pData[i];
        _pData[i] = Min;
        _pData[MinIndex] = Temp;
    }
}

//합병정렬 - 합병
void Merge(int* _pData, int* Temp, int left, int mid,  int right)
{
    int i = left; //왼쪽 배열의 시작점 -> left ~ mid 까지 공간
    int j = mid+1; //오른쪽 배열의 시작점 -> mid+1 ~ right 까지 공간
    int k = left; //정렬된 배열의 시작점(정렬이 몇번까지 됐는지)

    //배열을 합치면서 좌, 우 비교
    //나누기를 모두 마치면 1개만 남게 되기에, <가 아닌 <=를 사용
    while( i <= mid && j <= right)
    {
        //왼쪽 배열 값이 오른쪽 배열 값보다 작으면
        if(_pData[i] < _pData[j])
        {
            //왼쪽 값을 정렬된 배열에 넣고, 서로의 left 증가
            Temp[k++] = _pData[i++];
        }
        else
        {
            //그 외에는 오른쪽 값을 넣음
            Temp[k++] = _pData[j++];
        }
    }
    
    //왼쪽 배열과 오른쪽 배열이 짝이 맞지 않는다면, 남은 값은 그대로 넣음
    if(i > mid)
    {
        //오른쪽 값이 남을 때
        for(int l = j; l <= right; l++)
        {
            Temp[k++] = _pData[l];
        }
    }
    else
    {
        //왼쪽 값이 남을 때
        for(int l = i; l <= mid; l++)
        {
            Temp[k++] = _pData[l];
        }
    }


    //정렬 된 데이터를 원본 배열에 넣는다.
    for(int l = left ; l <= right; l++)
    {
        _pData[l] = Temp[l];
    }
}

//합병정렬 - 분할
void Divide(int* _pData, int* Temp, int left, int right)
{
    if(left < right)
    {
        int mid = (left+right) / 2;

        //분할정복 구간
        Divide(_pData, Temp, left, mid); //왼쪽 부분을 계속 2로 나눔
        Divide(_pData, Temp, mid+1, right); //오른쪽 부분을 꼐속 2로 나눔

        //분할 정복 후에, 전체적으로 정렬된 왼쪽, 오른쪽 반씩 남게 되므로
        //그 남은구간에 대하여 최종적으로 정렬 시작하여 마무리.
        Merge(_pData, Temp, left, mid, right);
    }
}

//합병 정렬
void MergeSort(int* _pData, int iCount)
{
    if(iCount <= 1)
        return;
    
    int left = 0;
    int right = iCount-1;
    int* TempArr = new int[iCount];

    Divide(_pData, TempArr, left, right);

    delete[] TempArr;
}

void Partition(int* _pData, int left, int right)
{
    if (left >= right)
        return;

    //가장 왼쪽 배열값을 피봇으로 설정한다.
    int pivot = left;

    //피봇보다 낮은 값만 허용하는 i(low)
    int i = left+1;

    //피봇보다 높은 값만 허용하는 j(high)
    int j = right;

    while(i < j) //i와 j가 서로 교차할 때 까지 반복
    {
        while(i <= right && _pData[i] < _pData[pivot])
        {
            ++i;
        }

        while(j >= left && _pData[j] > _pData[pivot])
        {
            --j;
        }

        //만약 i가 피봇보다 크고, j가 피봇보다 크지만 서로 교차하지 않은 상태라면
        //그 둘의 값을 Swap
        if( i < j)
        {
            int Temp = _pData[i];
            _pData[i] = _pData[j];
            _pData[j] = Temp;
        }
    }

    //교차가 일어났다면, 반복문을 종료하고 피봇과 high 값을 swap
    //교차상태라면, high가 가리키는 값이 피봇보다 낮은값이기 때문에 피봇의 위치인 제일 왼쪽으로 보낸다.
    int Temp = _pData[left];
    _pData[left] = _pData[j];
    _pData[j] = Temp;
    
    //피봇을 기준으로 좌, 우 구간에 대해 분할정복
    Partition(_pData, left, j-1);
    Partition(_pData, j+1, right);
}

//퀵 정렬
void QuickSort(int* _pData, int iCount)
{
    if(iCount <= 1)
        return;
    
    int left = 0;
    int right = iCount-1;
    
    Partition(_pData, left, right);
    
}

void Test()
{

}

void Test2()
{

}

int main()
{
    void(*pFunc)(void) = nullptr; //타입 (함수포인터) (매개변수)
    pFunc = Test; //Test2를 쓰면 Test2가 할당됨, 형태가 매칭되어야 함

    pFunc(); //Test()를 호출

    tArr s = {};
    InitArr(&s);

    for(int i = 0; i < 15; ++i)
    {
        PushBack(&s, 15 - i);
    }

    std::cout<<"정렬 전\n";
    for(int i = 0; i < 15; ++i)
    {
        std::cout<< s.pInt[i] << " ";
    }

    sort(&s, &QuickSort);

    std::cout<<"\n정렬 후\n";
    for(int i = 0; i < 15; ++i)
    {
        std::cout<< s.pInt[i] << " ";
    }


    ReleaseArr(&s);

    return 0;
}