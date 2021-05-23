#include<iostream>

using namespace std;

template <class T1>
class LinkNode {
    template <class T>
    friend class LinkList;  //����ʽ��������Ϊ����
   public:
    LinkNode() { next = NULL; }

   private:
    T1 data;
    LinkNode<T1>* next;
};

//��1��ʼ����
template <class T>
class LinkList {
   public:
    LinkList();
    ~LinkList();
    LinkList<T>& Insert(int k, const T& x);
    bool IsEmpty() const;   // �жϱ��Ƿ�Ϊ�գ��շ���true,����false
    int GetLength() const;  //���ر�������Ԫ�ظ���
    bool GetData(int k, T& x);  //�����е�k��Ԫ�ر��浽x�У��������򷵻�false
    bool ModifyData(int k, const T& x);
    //�����е�k��Ԫ�ر��浽x�У��������򷵻�false
    int Find(const T& x);
    //����x�ڱ���λ�ã����x�������򷵻�-1
    LinkList<T>& DeleteByIndex(int k, T& x);
    //ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
    LinkList<T>& DeleteByKey(const T& x, T& y);
    //ɾ�����йؼ���ΪxԪ�أ�����ɾ��������Ա�
    void OutPut(ostream& out) const;
    //�����Ա�ŵ������out�����
   private:
    LinkNode<T>* head; //ָ������ĵ�һ��ͷ����ָ��
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

//�ڵ�K��λ�ò���Ԫ��x,���ز��������Ա�
template<class T>
LinkList<T>& LinkList<T>::Insert(int k, const T& x){
    LinkNode<T> *p=head;
    LinkNode<T> *newNode = new LinkNode<T>;
    newNode->data = x;
    if(k<1 || k>GetLength()+1){
        cout<<"Ԫ���±�Խ�磬���Ԫ��ʧ��";
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
// �жϱ��Ƿ�Ϊ�գ��շ���true,����false
template<class T>
bool LinkList<T>::IsEmpty() const{
    return head->next == NULL;
} 

//���ر�������Ԫ�ظ���
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

//�����е�k��Ԫ�ر��浽x�У��������򷵻�false
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

//�����е�k��Ԫ�ر��浽x�У��������򷵻�false
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
//����x�ڱ���λ�ã����x�������򷵻�-1
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
    

//ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
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
        cout<<"Ԫ���±�Խ�磬ɾ��ʧ��\n";
    return *this;
}

//ɾ�����йؼ���ΪxԪ�أ�����ɾ��������Ա�
template<class T>   
LinkList<T>& LinkList<T>::DeleteByKey(const T& x, T& y){
    int index=Find(x);
    if(index!=0) return DeleteByIndex(index,y);
    else{
        cout<<"û�д�Ԫ�أ�ɾ��ʧ��\n";
        return *this;
    }
}

//�����Ա�ŵ������out�����
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