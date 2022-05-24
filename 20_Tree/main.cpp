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

int main()
{
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
    tPair<int, int> pair;
    pair.first = 100;

    bstint.insert(pair);

    pair.first = 150;

    bstint.insert(pair);

    pair.first = 200;

    bstint.insert(pair);

    return 0;
}