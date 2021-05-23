#include <iostream>
using namespace std;
template <class T>
class LinearStack {
   public:
    LinearStack(int LSMaxSize);  //���캯���������ջ
    ~LinearStack();              //����������ɾ��ջ
    bool IsEmpty();              //ջ�շ���true������false
    bool IsFull();               //ջ������true,��������false
    int GetElementNumber();      //��ջ��Ԫ�ظ���
    bool Push(const T& x);  //��ջ������Ԫ��x,�ɹ�����true,���򷵻�false
    bool Top(T& x);  //��ջ��Ԫ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
    bool Pop(T& x);  //��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
    void OutPut(ostream& out) const;  //��˳��ջ�ŵ������out�����

   private:
    int top;      //ջ��
    int MaxSize;  //ջ�����Ԫ�ظ���
    T* element;   //һά��̬����
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

//ջ�շ���true������false
template<class T>
bool LinearStack<T>::IsEmpty(){
    return top == -1;
}      

//ջ������true,��������false
template<class T>
bool LinearStack<T>::IsFull(){
    return top + 1 == MaxSize;
}       

//��ջ��Ԫ�ظ���
template<class T>
int LinearStack<T>::GetElementNumber(){
    return top + 1;
}  

//��ջ������Ԫ��x,�ɹ�����true,���򷵻�false
template<class T>
bool LinearStack<T>::Push(const T& x){
    if(IsFull()) return false;
    else {
        top++;
        element[top] = x;
        return true;
    }
}  

//��ջ��Ԫ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
template<class T>
bool LinearStack<T>::Top(T& x){
    if(IsEmpty()) return false;
    x = element[top];
    return true;
}
//��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
template<class T>
bool LinearStack<T>::Pop(T& x){
    if(IsEmpty()) return false;
    x = element[top];
    top--;
    return true;
} 

//��˳��ջ�ŵ������out�����
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