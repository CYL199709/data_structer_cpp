//�����ܣ�ʵ�� ��ʮ����ת��Ϊ����������
// ����ȡ�෨
#include<iostream>
using namespace std;
#include"LinkStack.h"

void conversation(int n,int base);

int main(){
    int n,base;
    cout<<"������ʮ��������Ҫת���Ľ�����"<<endl;
    cin>>n>>base;
    conversation(n,base);
    return 0;
}

void conversation(int n,int base){
    int x,y;
    y=n;
    LinkStack<int> s(100);
    while(y){
        s.Push(y%base);
        y=y/base;
    }
    cout<<"ʮ������"<<n<<"ת��Ϊ"<<base<<"������Ϊ��";
    while(!s.IsEmpty()){
        s.Pop(x);
        cout<<x;    
    }
}