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

//����ջ��
template <class T>
class LinkStack {
   public:
    LinkStack(int LSMaxSize);  //���캯���������ջ
    ~LinkStack();              //����������ɾ��ջ
    bool IsEmpty();            //ջ�շ���true������false
    bool Push(const T& x);  //��ջ������Ԫ��x,�ɹ�����true,���򷵻�false
    bool Top(T& x);  //��ջ��Ԫ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
    bool Pop(T& x);  //��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
    void OutPut(ostream& out) const;  //��˳��ջ�ŵ������out�����

   private:
    int size;          //Ԫ�ظ���
    LinkNode<T>* top;  //ջ�����
};

//���캯���������ջ
template <class T>
LinkStack<T>::LinkStack(int LSMaxSize) {
    top = NULL;
    size = 0;
}

//����������ɾ��ջ
template <class T>
LinkStack<T>::~LinkStack(){
    T x;
    while(top!=NULL){
        Pop(x);
    }
}   

//ջ�շ���true������false
template <class T>
bool LinkStack<T>::IsEmpty(){
    return top==NULL;
}

//��ջ������Ԫ��x,�ɹ�����true,���򷵻�false
template <class T>
bool LinkStack<T>::Push(const T& x){
    LinkNode<T> *p = new LinkNode<T>;
    if(p==NULL) return false; //newʧ���ˣ���û�пռ��
    p->data = x;
    p->next = top;
    top = p;
    size++;
    return true;
}

//��ջ��Ԫ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
template <class T>
bool LinkStack<T>::Top(T& x){
    if(IsEmpty()) return false;
    x = top->data;
    return true;
} 
//��ջ��ɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
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

//��˳��ջ�ŵ������out�����
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