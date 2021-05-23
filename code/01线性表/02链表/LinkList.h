#include<iostream>

using namespace std;

template <class T1>
class LinkNode {
    template <class T>
    friend class LinkList;  //将链式表类声明为友类
   public:
    LinkNode() { next = NULL; }

   private:
    T1 data;
    LinkNode<T1>* next;
};

//从1开始计数
template <class T>
class LinkList {
   public:
    LinkList();
    ~LinkList();
    LinkList<T>& Insert(int k, const T& x);
    bool IsEmpty() const;   // 判断表是否为空，空返回true,否则false
    int GetLength() const;  //返回表中数据元素个数
    bool GetData(int k, T& x);  //将表中第k个元素保存到x中，不存在则返回false
    bool ModifyData(int k, const T& x);
    //将表中第k个元素保存到x中，不存在则返回false
    int Find(const T& x);
    //返回x在表中位置，如果x不存在则返回-1
    LinkList<T>& DeleteByIndex(int k, T& x);
    //删除表中第k个元素，并把它保存到x中，返回删除后的线性表
    LinkList<T>& DeleteByKey(const T& x, T& y);
    //删除表中关键字为x元素，返回删除后的线性表
    void OutPut(ostream& out) const;
    //将线性表放到输出流out中输出
   private:
    LinkNode<T>* head; //指向链表的第一个头结点的指针
};

template<class T>
LinkList<T>::LinkList(){
    head = new LinkNode<T>();
}

template<class T>
LinkList<T>::~LinkList(){
    T x;
    int len=GetLength();
    for(int i=len;i>=1;i--){
        DeleteByIndex(i,x);
    }
    delete head;
}

//在第K个位置插入元素x,返回插入后的线性表
template<class T>
LinkList<T>& LinkList<T>::Insert(int k, const T& x){
    LinkNode<T> *p=head;
    LinkNode<T> *newNode = new LinkNode<T>;
    newNode->data = x;
    if(k<1 || k>GetLength()+1){
        cout<<"元素下标越界，添加元素失败";
    }
    else{
        for(int i=1;i<k;i++){
            p=p->next;
        }
        newNode->next = p->next;
        p->next = newNode;
    }
    return *this;

}
// 判断表是否为空，空返回true,否则false
template<class T>
bool LinkList<T>::IsEmpty() const{
    return head->next == NULL;
} 

//返回表中数据元素个数
template<class T>
int LinkList<T>::GetLength() const{
    int length = 0;
    LinkNode<T> *p=head->next;
    while(p){
        length++;
        p=p->next;
    }
    return length;
}

//将表中第k个元素保存到x中，不存在则返回false
template<class T>
bool LinkList<T>::GetData(int k, T& x){
    LinkNode<T> *p=head->next;
    int index=1;
    if(k<1||k>GetLength()) return false;
    while(p!=NULL && index<k){
        index++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }
    else{
        x=p->data;
        return true;
    }
}

//将表中第k个元素保存到x中，不存在则返回false
template<class T>
bool LinkList<T>::ModifyData(int k, const T& x){
    LinkNode<T> *p=head->next;
    int index=1;
    if(k<1||k>GetLength()) return false;
    while(p!=NULL && index<k){
        index++;
        p=p->next;
    }
    if(p==NULL){
        return false;
    }
    else{
        p->data=x;
        return true;
    }
}

template<class T>
//返回x在表中位置，如果x不存在则返回-1
int LinkList<T>::Find(const T& x){
    LinkNode<T> *p=head->next;
    int index=1;
    while(p!=NULL && p->data!=x){
        p=p->next;
        index++;
    }
    if(p!=NULL)
        return index;
    else
        return 0;
}
    

//删除表中第k个元素，并把它保存到x中，返回删除后的线性表
template<class T>
LinkList<T>& LinkList<T>::DeleteByIndex(int k, T& x){
    if(GetData(k,x)){
        LinkNode<T> *p=head;
        LinkNode<T> *q=NULL;
        for(int i=1;i<k;i++){
            p=p->next;
        }
        q=p->next;
        p->next = q->next;
        delete q;
    }
    else
        cout<<"元素下标越界，删除失败\n";
    return *this;
}

//删除表中关键字为x元素，返回删除后的线性表
template<class T>   
LinkList<T>& LinkList<T>::DeleteByKey(const T& x, T& y){
    int index=Find(x);
    if(index!=0) return DeleteByIndex(index,y);
    else{
        cout<<"没有此元素，删除失败\n";
        return *this;
    }
}

//将线性表放到输出流out中输出
template<class T>  
void LinkList<T>::OutPut(ostream& out) const{
    LinkNode<T> *p=head->next;
    while(p!=NULL){
        out<<p->data<<endl;
        p=p->next;
    }
}

template<class T>
ostream& operator<<(ostream& out,LinkList<T>& x){
    x.OutPut(out);
    return out;
}