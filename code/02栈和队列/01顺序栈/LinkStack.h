#include <iostream>
using namespace std;
template <class T1>
class LinkNode {
    template <class T>
    friend class LinkStack;

   public:
    LinkNode() { next = NULL; }

   private:
    T1 data;
    LinkNode<T1>* next;
};

//链接栈类
template <class T>
class LinkStack {
   public:
    LinkStack(int LSMaxSize);  //构造函数，创造空栈
    ~LinkStack();              //析构函数，删除栈
    bool IsEmpty();            //栈空返回true，否则false
    bool Push(const T& x);  //在栈顶插入元素x,成功返回true,否则返回false
    bool Top(T& x);  //求栈顶元素的值放入x中,成功返回true,否则返回false
    bool Pop(T& x);  //从栈顶删除一个元素，并将该元素的值放入x中
    void OutPut(ostream& out) const;  //将顺序栈放到输出流out中输出

   private:
    int size;          //元素个数
    LinkNode<T>* top;  //栈顶结点
};

//构造函数，创造空栈
template <class T>
LinkStack<T>::LinkStack(int LSMaxSize) {
    top = NULL;
    size = 0;
}

//析构函数，删除栈
template <class T>
LinkStack<T>::~LinkStack(){
    T x;
    while(top!=NULL){
        Pop(x);
    }
}   

//栈空返回true，否则false
template <class T>
bool LinkStack<T>::IsEmpty(){
    return top==NULL;
}

//在栈顶插入元素x,成功返回true,否则返回false
template <class T>
bool LinkStack<T>::Push(const T& x){
    LinkNode<T> *p = new LinkNode<T>;
    if(p==NULL) return false; //new失败了，如没有空间等
    p->data = x;
    p->next = top;
    top = p;
    size++;
    return true;
}

//求栈顶元素的值放入x中,成功返回true,否则返回false
template <class T>
bool LinkStack<T>::Top(T& x){
    if(IsEmpty()) return false;
    x = top->data;
    return true;
} 
//从栈顶删除一个元素，并将该元素的值放入x中
template <class T>
bool LinkStack<T>::Pop(T& x){
    LinkNode<T> *p;
    if(IsEmpty()) return false;
    else{
        x = top->data;
        p=top;
        top = top->next;
        delete p;
        size--;
        return true;
    }

}  

//将顺序栈放到输出流out中输出
template <class T>
void LinkStack<T>::OutPut(ostream& out) const{
    LinkNode<T> *p;
    p=top;
    for(int i=0;i<size;i++){
        out<<p->data<<endl;;
        p=p->next;
    }
}  

template<class T>
ostream& operator<<(ostream& out,const LinkStack<T>& x){
    x.OutPut(out);
    return out;
}