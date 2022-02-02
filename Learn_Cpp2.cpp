#include <iostream>
using namespace std;

int main(){
    /*문자열_string, getline
    - string: c에는 char배열을 통해 string을선언하지만 c++에서는 string 변수가 있다. 
    - getline(): input으로 string type을 받는다.*/
    string yourName;
    cout <<"your Name? ";
    getline(cin,yourName);
    cout<<"Name: "<<yourName<<endl;

    /*문자열 연산
    - size(): 문자열의 길이
    - length(): string 변수가 사용하고있는 메모리 크기 
    - append(추가할 문자열, 시작위치, 개수): 문자열 끝에 다른 문자열 추가 
    - find(찾을 문자열): 문자열에서 특정 문자열 찾기 시작위치를 반환, 못찾으면 string::npos 반환 
      반환 값 =  string::size_type 이라는 타입의 변수다.
    - compare(): 두 문자열 비교, 결과는 bool
    - replace(바꾸려는 문자열시작점, 바꿀 문자열 길이, 바꿔낄 문자열) : 특정문자열을 찾아 대체한다. 
    - capacity()
    - max_size()*/

    string str1 = "hello world";
    string str2 = " I'm C++ ! ";
    str1 += str2; // + 연산
    cout<<str1 << endl;
    cout<< "length: "<<str1.length() << " / size: "<< str1.size()<<endl; //char은 1바이트니까 당연히 둘의 값이 값다. 
    str2.append(" !!!!");
    cout<<str2 << endl;
    if(str2.find("!!!!") != string::npos){
        cout<< "find !!!!: "<<str2.find("!!!!")<<endl;
    }else{
        cout<<"can't find"<<endl;
    }
    
    if(str1.compare(str2)==0){ // 같다.
        cout<<"same"<<endl;
    }else if(str1.compare(str2)<0){// 1이 2보다 사전 편찬순으로 앞에 있는 경우 
        cout<<"1이 2보다 앞에 있습니다."<<endl;
    }else if(str1.compare(str2)>0){ // 1이 2보다 사전 편찬순으로 뒤에 있는 경우 
        cout<<"1이 2보다 뒤에 있습니다."<<endl;
    }

    string str3 ="abcd";
    string str4 ="ab";
    string str5 ="AB";
    //3에서 ab를 찾아 AB로 바꾸기 
    string::size_type index = str3.find(str4); //  바꾸려는 문자열 시작점 찾아서 저장
    if(index != string::npos){//3에 찾는 문자열이있으면 
        str3.replace(index, str4.length(), str5);
        cout << str3<<endl;
    }

//
    



    return 0;
}
