#include <iostream>
using namespace std;
template <class T1>
class LinkNode {
    template <class T>
    friend class LinkQueue;

   public:
    LinkNode() { next = NULL; }

   private:
    T1 data;
    LinkNode<T1>* next;
};

//���Ӷ�����
template <class T>
class LinkQueue {
   public:
    LinkQueue();              //���캯��������ն���
    ~LinkQueue();             //����������ɾ������
    bool IsEmpty();           //���пշ���true������false
    bool Insert(const T& x);  //�ڶ�β����Ԫ��x,�ɹ�����true,���򷵻�false
    bool GetElement(T& x);  //���ͷԪ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
    bool Delete(T& x);  //�Ӷ�ͷɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
    void OutPut(ostream& out) const;  //�����зŵ������out�����

   private:
    int size;                  //Ԫ�ظ���
    LinkNode<T>*front, *rear;  //��ͷ���
};

//���캯��������ն���
template <class T>
LinkQueue<T>::LinkQueue() {
    size = 0;
    front = NULL;
    rear = NULL;
}

//����������ɾ������
template <class T>
LinkQueue<T>::~LinkQueue() {
    T x;
    while (front != NULL) Delete(x);
}

//���пշ���true������false
template <class T>
bool LinkQueue<T>::IsEmpty() {
    return size == 0;
}

//�ڶ�β����Ԫ��x,�ɹ�����true,���򷵻�false
template <class T>
bool LinkQueue<T>::Insert(const T& x){
    LinkNode<T> *p = new LinkNode<T>;
    if(p==NULL) return false;  
    p->data = x;
    if(front == NULL) {
        front = p;
        rear = p;
    }
    else{
        rear->next = p;
        rear = p;
    }
    size++;
    return true;
    
}

//���ͷԪ�ص�ֵ����x��,�ɹ�����true,���򷵻�false
template <class T>
bool LinkQueue<T>::GetElement(T& x){
    if(IsEmpty()) return false;
    x = front->data;
    return true;
} 

//�Ӷ�βɾ��һ��Ԫ�أ�������Ԫ�ص�ֵ����x��
template <class T>
bool LinkQueue<T>::Delete(T& x){
    LinkNode<T> *p;
    if(IsEmpty()) return false;
    p=front;
    x= front->data;
    front = front->next;
    delete p;
    size--;
    return true;
}

//�����зŵ������out�����
template <class T>
void LinkQueue<T>::OutPut(ostream& out) const{
    LinkNode<T> *p=front;
    for(int i=0;i<size;i++){
        out<<p->data<<end;
        p=p->next;
    }      
} 

template <class T>
ostream& operator<<(ostream& out,LinkQueue<T> x){
    x.OutPut(out);
    return out;
}
