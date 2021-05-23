#include <iostream>
using namespace std;
//˳��ѭ������

template <class T>
class LinearQueue {
   public:
    LinearQueue(int LQMaxSize);
    ~LinearQueue();
    bool IsEmpty();
    bool IsFull();
    bool Insert(const T& x);  //��β����Ԫ��x
    bool GetElement(T& x);    //��ͷԪ�ص�ֵ����x��
    bool Delete(T& x);        //��ͷɾ��Ԫ�أ�����ֵ����x��
    void OutPut(ostream& out) const;

   private:
    int size;
    int MaxSize;
    int front, rear;
    T* element;  //һά��̬����
};

template <class T>
LinearQueue<T>::LinearQueue(int LQMaxSize) {
    size = 0;
    MaxSize = LQMaxSize;
    front = 0;
    rear = 0;
    element = new T[LQMaxSize];
}

template <class T>
LinearQueue<T>::~LinearQueue() {
    delete[] element;
}

template <class T>
bool LinearQueue<T>::IsEmpty() {
    return size == 0;
}
template <class T>
bool LinearQueue<T>::IsFull() {
    return size == MaxSize;
}

//��β����Ԫ��x
template <class T>
bool LinearQueue<T>::Insert(const T& x) {
    if (IsFull()) return false;
    element[rear] = x;
    size++;
    rear = (rear + 1) % MaxSize;
    return true;
}

//��ͷԪ�ص�ֵ����x��
template <class T>
bool LinearQueue<T>::GetElement(T& x) {
    if (IsEmpty()) return false;
    x = element[front];
    return true;
}

//��ͷɾ��Ԫ�أ�����ֵ����x��
template <class T>
bool LinearQueue<T>::Delete(T& x) {
    if (IsEmpty()) return false;
    x = element[front];
    front = (front + 1) % MaxSize;
    size--;
    return true;
}
template <class T>
void LinearQueue<T>::OutPut(ostream& out) const {
    for (int i = 0; i < size; i++)
        out << element[(i + front) % MaxSize] << endl;
}
template <class T>
ostream& operator<<(ostream& out, LinearQueue<T>& x) {
    x.OutPut(out);
    return out;
}

