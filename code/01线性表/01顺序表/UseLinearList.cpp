#include<iostream>
using namespace std;
#include"LinearList.h"
int main(){
    LinearList<int> IntegerLList(10);
    int x,y;
    IntegerLList.Insert(0,100);
    IntegerLList.Insert(1,200);
    IntegerLList.Insert(2,300);
    IntegerLList.Insert(3,400);
    cout<<"��ǰ��ĳ���Ϊ��"<<IntegerLList.GetLength()<<endl;
    cout<<"��ǰ���Ԫ��Ϊ��\n"<<IntegerLList<<endl;
    if(IntegerLList.GetData(2,x))
        cout<<"���е�2��Ԫ��Ϊ��"<<x<<endl;
    x = 100;
    cout<<"Ԫ��100�ڱ��е�λ��Ϊ��"<<IntegerLList.Find(x)<<endl;
    x=150;
    IntegerLList.ModifyData(0,150);
    IntegerLList.DeleteByIndex(1,x);
    x=400;
    IntegerLList.DeleteByKey(x,y);
    cout<<"��ǰ��ĳ���Ϊ��"<<IntegerLList.GetLength()<<endl;
    cout<<"��ǰ���Ԫ��Ϊ��\n"<<IntegerLList<<endl;
    return 0;
}