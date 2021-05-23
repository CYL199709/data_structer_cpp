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

//链接队列类
template <class T>
class LinkQueue {
   public:
    LinkQueue();              //构造函数，创造空队列
    ~LinkQueue();             //析构函数，删除队列
    bool IsEmpty();           //队列空返回true，否则false
    bool Insert(const T& x);  //在队尾插入元素x,成功返回true,否则返回false
    bool GetElement(T& x);  //求队头元素的值放入x中,成功返回true,否则返回false
    bool Delete(T& x);  //从队头删除一个元素，并将该元素的值放入x中
    void OutPut(ostream& out) const;  //将队列放到输出流out中输出

   private:
    int size;                  //元素个数
    LinkNode<T>*front, *rear;  //队头结点
};

//构造函数，创造空队列
template <class T>
LinkQueue<T>::LinkQueue() {
    size = 0;
    front = NULL;
    rear = NULL;
}

//析构函数，删除队列
template <class T>
LinkQueue<T>::~LinkQueue() {
    T x;
    while (front != NULL) Delete(x);
}

//队列空返回true，否则false
template <class T>
bool LinkQueue<T>::IsEmpty() {
    return size == 0;
}

//在队尾插入元素x,成功返回true,否则返回false
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

//求队头元素的值放入x中,成功返回true,否则返回false
template <class T>
bool LinkQueue<T>::GetElement(T& x){
    if(IsEmpty()) return false;
    x = front->data;
    return true;
} 

//从队尾删除一个元素，并将该元素的值放入x中
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

//将队列放到输出流out中输出
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
