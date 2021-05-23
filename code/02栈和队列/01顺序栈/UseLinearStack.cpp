//程序功能：实现 将十进制转换为其他进制数
// 除基取余法
#include<iostream>
using namespace std;
#include"LinkStack.h"

void conversation(int n,int base);

int main(){
    int n,base;
    cout<<"请输入十进制数和要转化的进制数"<<endl;
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
    cout<<"十进制数"<<n<<"转化为"<<base<<"进制数为：";
    while(!s.IsEmpty()){
        s.Pop(x);
        cout<<x;    
    }
}