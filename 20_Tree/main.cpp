#include <iostream>
#include <map>
#include <set>
#include <string>
#include "CBST.h"

using std::map;
using std::make_pair;

using std::set;

#define MAN 1
#define WOMAN 2


struct tStdInfo
{
    wchar_t szName[20];
    unsigned char age;
    unsigned char gender;

    tStdInfo() : szName{}, age(0), gender(0)
    {

    }

    tStdInfo(const wchar_t* _pName, unsigned char _age, unsigned char _gender) : szName{}, age(_age), gender(_gender)
    {
        wcscpy(szName, _pName);
    }
};

//map으로 stdinfo를 담을때, pair는 이러한 형태의 구조일 것.
// struct pair
// {
//     const wchar_t*  first;
//     tStdInfo        second;
// };

//열거형
enum class MY_TYPE
{
    TYPE_1, //0, 따로 지정하지 않으면 0부터 시작해서 점점 늘어남
    TYPE_2, //1
    TYPE_3, //2
    TYPE_5 = 100, //직접 숫자를 지정할 수도 있으며, 이 다음 열거형은 101이 됨
    TYPE_6 //101
};

enum class OTHER_TYPE
{
    //TYPE_1 //다른 열거형에 같은 멤버 이름을 넣을수 있음 -> 모호성 발생
    //이를 방지하기 위해 enum class 나타남 -> 열거체가 어느 클래스 소속인지 명시해야 함.
    TYPE_1
};

//enum과 define의 차이
//define은 전처리기에 해당됨 -> 컴파일 이전에 먼저 실행됨 -> CLASS_1은 CLASS_1으로 인식되지 않고, 그냥 0 그 자체가 됨
//enum은 컴파일 시에 실행됨 -> TYPE_1이 0 자체가 아니고, TYPE_1으로 보고, 그 값을 대입시켜줌 -> 타입이 잡힘
#define CLASS_1 0
#define CLASS_2 1

//define은 코드가 꼬였을 때, 수정이 복잡해지지만 enum은 수정이 편함
//enum은 디버깅 시, 어떤 타입이며 어느 소속의 열거체인지 알려주기 때문임

int main()
{

    int a = (int)MY_TYPE::TYPE_3; // a = 2와 동일한 동작

    int b = (int)OTHER_TYPE::TYPE_1; //열거형 클래스는 형변환을 명시해줘야 함
    //이진탐색트리
    //데이터 입력시 O(logN), 탐색효율 O(logN)
    //트리가 한쪽으로 치중된 형태라면, 탐색효율 x -> 자가균형 필요(avl, red-black 등)

    //트리 기반 자료구조들 - set, map
    set<int> setInt;

    setInt.insert(100);
    setInt.insert(50);
    setInt.insert(200);

    //맵은 자료형이 <키, 데이터> 로 선언됨, 페어를 입력받음
    map<const wchar_t*, tStdInfo> mapData;

    tStdInfo info(L"홍길동", 18, MAN);
    tStdInfo info2(L"이지혜", 25, WOMAN);

    //페어로 만들어서 맵에 데이터 입력
    mapData.insert(make_pair(L"홍길동", info));

    map<const wchar_t*, tStdInfo>::iterator mapiter;
    mapiter = mapData.find(L"홍길동");

    if(mapiter == mapData.end())
    {
        std::cout << "유효한 데이터가 아닙니다.";
    }
    else
    {
        std::cout << "이름 : " << mapiter->second.szName << std::endl;
        std::cout << "나이 : " << (int)mapiter->second.age << std::endl;
        std::cout << "성별 : ";
        if (MAN == mapiter->second.gender)
        {
            std::cout << "남자"<< std::endl;
        }
        else if(WOMAN == mapiter->second.gender)
        {
            std::cout << "여자"<< std::endl;
        }
        else
        {
            std::cout << "알 수 없음"<< std::endl;
        }
    }

    map<std::string, tStdInfo> mapStdInfo;

    //string 클래스에는 문자열을 넣을 수 있음
    std::string str = "abcdef"; //문자열 객체에 문자 자체를 집어넣음 -> 주소 아닌, 값 관리
    str += "hijk"; //문자열 연산 가능
    //문자열은 들어오는 값 크기에 따라 공간을 재할당 -> 동적할당 사용 -> 힙메모리 공간 사용
    //string은 결국 vector<char>와 유사한 동작임. -> 가변배열을 기반으로 한 동작

    CBST<int, int> bstint;

    bstint.insert(make_bstpair(100,0));
    bstint.insert(make_bstpair(50,0));
    bstint.insert(make_bstpair(200,0));

    CBST<int, int>::iterator bstiter = bstint.begin();

    bstiter = bstint.find(50);

    tPair<int, int>* pPair;

    pPair->first;
    pPair->second;


    for(bstiter = bstint.begin(); bstiter != bstint.end(); ++bstiter)
    {
        std::cout << bstiter->first << " "<< bstiter->second << std::endl;
    }

    return 0;
}