
#ifndef LINEARLIST_H_
#define LINEARLIST_H_
//˳�����ģ�� LinearList
//��0��ʼ����
template <class T>
class LinearList {
   private:
    int length;   //��ǰ����Ԫ�ظ���
    int MaxSize;  //���Ա������Ԫ�ظ���
    T* element;   //һά��̬����
   public:
    LinearList(int LLMaxSize);  //���캯���������ձ�
    ~LinearList();              //����������ɾ����
    LinearList<T>& Insert(int k, const T& x);
    //�ڵ�K��λ�ò���Ԫ��x,���ز��������Ա�
    bool IsEmpty() const;  // �жϱ��Ƿ�Ϊ�գ��շ���true,����false
    int GetLength() const;  //���ر�������Ԫ�ظ���
    bool GetData(int k, T& x);  //�����е�k��Ԫ�ر��浽x�У��������򷵻�false
    bool ModifyData(int k, const T& x);
    //�����е�k��Ԫ�ر��浽x�У��������򷵻�false
    int Find(const T& x);
    //����x�ڱ���λ�ã����x�������򷵻�-1
    LinearList<T>& DeleteByIndex(int k, T& x);
    //ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
    LinearList<T>& DeleteByKey(const T& x, T& y);
    //ɾ�����йؼ���ΪxԪ�أ�����ɾ��������Ա�
    void OutPut(ostream& out) const;
    //�����Ա�ŵ������out�����
};

//���캯���������ձ�
template <class T>
LinearList<T>::LinearList(int LLMaxSize) {
    MaxSize = LLMaxSize;
    element = new T[LLMaxSize];
    length = 0;
}

//����������ɾ����
template <class T>
LinearList<T>::~LinearList() {
    delete[] element;  //��new����delete
}

//�ڵ�K��λ�ò���Ԫ��x,���ز��������Ա�
template <class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x) {
    if (length == MaxSize)
        cout << "�˱��������޷������Ԫ��" << endl;
    else if (k < 0 || k > length + 1)
        cout << "Ԫ���±�Խ�磬���Ԫ��ʧ��" << endl;
    else {
        for (int i = length; i > k; i++) element[i] = element[i - 1];
        element[k] = x;
        length++;
    }
    return *this;
}

// �жϱ��Ƿ�Ϊ�գ��շ���true,����false
template <class T>
bool LinearList<T>::IsEmpty() const {
    return length == 0;
}

//���ر�������Ԫ�ظ���
template <class T>
int LinearList<T>::GetLength() const {
    return length;
}

//�����е�k��Ԫ�ر��浽x�У��������򷵻�false
template <class T>
bool LinearList<T>::GetData(int k, T& x) {
    if (k < 0 || k >= length) return false;
    x = element[k];
    return true;
}

//�����е�k��Ԫ�ر��浽x�У��������򷵻�false
template <class T>
bool LinearList<T>::ModifyData(int k, const T& x) {
    if (k < 0 || k >= length) return false;
    element[k] = x;
    return true;
}

//����x�ڱ���λ�ã����x�������򷵻�-1
template <class T>
int LinearList<T>::Find(const T& x) {
    for (int i = 0; i < length; i++) {
        if (element[i] == x) return i;
    }
    return -1;
}

//ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
template <class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k, T& x) {
    if (GetData(k, x)) {
        for (int i = k; i < length - 1; i++) {
            element[i] = element[i + 1];
        }
        length--;
    } else
        cout << "Ԫ���±�Խ�磬���Ԫ��ʧ��" << endl;
    return *this;
}

//ɾ�����е�k��Ԫ�أ����������浽x�У�����ɾ��������Ա�
template <class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x, T& y) {
    int index = Find(x);
    if (index == -1)
        cout << "Ԫ�ز����ڣ�ɾ��ʧ��" << endl;
    else {
        return DeleteByIndex(index, y);
    }
    return *this;
}

////�����Ա�ŵ������out�����
template <class T>
void LinearList<T>::OutPut(ostream& out) const {
    for (int i = 0; i < length; i++) {
        out << element[i] << endl;
    }
}

//���ز��������<<
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x) {
    x.OutPut(out);
    return out;
}

#endif