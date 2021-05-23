#include <iostream>
using namespace std;
template <class T>
class LinearStack {
   public:
    LinearStack(int LSMaxSize);  //构造函数，创造空栈
    ~LinearStack();              //析构函数，删除栈
    bool IsEmpty();              //栈空返回true，否则false
    bool IsFull();               //栈满返回true,不满返回false
    int GetElementNumber();      //求栈中元素个数
    bool Push(const T& x);  //在栈顶插入元素x,成功返回true,否则返回false
    bool Top(T& x);  //求栈顶元素的值放入x中,成功返回true,否则返回false
    bool Pop(T& x);  //从栈顶删除一个元素，并将该元素的值放入x中
    void OutPut(ostream& out) const;  //将顺序栈放到输出流out中输出

   private:
    int top;      //栈顶
    int MaxSize;  //栈中最大元素个数
    T* element;   //一维动态数组
};

template<class T>
LinearStack<T>::LinearStack(int LSMaxSize){
    top = -1;
    element = new T[LSMaxSize];
    MaxSize = LSMaxSize;
}

template<class T>
LinearStack<T>::~LinearStack(){
    delete[] element;
}

//栈空返回true，否则false
template<class T>
bool LinearStack<T>::IsEmpty(){
    return top == -1;
}      

//栈满返回true,不满返回false
template<class T>
bool LinearStack<T>::IsFull(){
    return top + 1 == MaxSize;
}       

//求栈中元素个数
template<class T>
int LinearStack<T>::GetElementNumber(){
    return top + 1;
}  

//在栈顶插入元素x,成功返回true,否则返回false
template<class T>
bool LinearStack<T>::Push(const T& x){
    if(IsFull()) return false;
    else {
        top++;
        element[top] = x;
        return true;
    }
}  

//求栈顶元素的值放入x中,成功返回true,否则返回false
template<class T>
bool LinearStack<T>::Top(T& x){
    if(IsEmpty()) return false;
    x = element[top];
    return true;
}
//从栈顶删除一个元素，并将该元素的值放入x中
template<class T>
bool LinearStack<T>::Pop(T& x){
    if(IsEmpty()) return false;
    x = element[top];
    top--;
    return true;
} 

//将顺序栈放到输出流out中输出
template<class T>
void LinearStack<T>::OutPut(ostream& out) const{
    for(int i=0;i<=top;i++){
        out<<element[i]<<endl;
    }
} 

template<class T>
ostream& operator<<(ostream& out,LinearStack<T>& x ){
    x.OutPut(out);
    return out;
}