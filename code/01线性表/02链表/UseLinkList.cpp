#include<iostream>
using namespace std;
#include"LinkList.h"
int main(){
    LinkList<int> IntegerLList;
    int x,y;
    IntegerLList.Insert(1,100);
    IntegerLList.Insert(2,200);
    IntegerLList.Insert(3,300);
    IntegerLList.Insert(4,400);
    cout<<"当前表的长度为："<<IntegerLList.GetLength()<<endl;
    cout<<"当前表的元素为：\n"<<IntegerLList<<endl;
    if(IntegerLList.GetData(2,x))
        cout<<"表中第2个元素为："<<x<<endl;
    x = 100;
    cout<<"元素100在表中的位置为："<<IntegerLList.Find(x)<<endl;
    x=150;
    IntegerLList.ModifyData(0,150);
    IntegerLList.DeleteByIndex(1,x);
    x=400;
    IntegerLList.DeleteByKey(x,y);
    cout<<"当前表的长度为："<<IntegerLList.GetLength()<<endl;
    cout<<"当前表的元素为：\n"<<IntegerLList<<endl;
    return 0;
}