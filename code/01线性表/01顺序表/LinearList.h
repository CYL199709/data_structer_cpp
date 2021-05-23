
#ifndef LINEARLIST_H_
#define LINEARLIST_H_
//顺序表类模板 LinearList
//从0开始计数
template <class T>
class LinearList {
   private:
    int length;   //当前数组元素个数
    int MaxSize;  //线性表中最大元素个数
    T* element;   //一维动态数组
   public:
    LinearList(int LLMaxSize);  //构造函数，创建空表
    ~LinearList();              //析构函数，删除表
    LinearList<T>& Insert(int k, const T& x);
    //在第K个位置插入元素x,返回插入后的线性表
    bool IsEmpty() const;  // 判断表是否为空，空返回true,否则false
    int GetLength() const;  //返回表中数据元素个数
    bool GetData(int k, T& x);  //将表中第k个元素保存到x中，不存在则返回false
    bool ModifyData(int k, const T& x);
    //将表中第k个元素保存到x中，不存在则返回false
    int Find(const T& x);
    //返回x在表中位置，如果x不存在则返回-1
    LinearList<T>& DeleteByIndex(int k, T& x);
    //删除表中第k个元素，并把它保存到x中，返回删除后的线性表
    LinearList<T>& DeleteByKey(const T& x, T& y);
    //删除表中关键字为x元素，返回删除后的线性表
    void OutPut(ostream& out) const;
    //将线性表放到输出流out中输出
};

//构造函数，创建空表
template <class T>
LinearList<T>::LinearList(int LLMaxSize) {
    MaxSize = LLMaxSize;
    element = new T[LLMaxSize];
    length = 0;
}

//析构函数，删除表
template <class T>
LinearList<T>::~LinearList() {
    delete[] element;  //有new就有delete
}

//在第K个位置插入元素x,返回插入后的线性表
template <class T>
LinearList<T>& LinearList<T>::Insert(int k, const T& x) {
    if (length == MaxSize)
        cout << "此表已满，无法添加新元素" << endl;
    else if (k < 0 || k > length + 1)
        cout << "元素下标越界，添加元素失败" << endl;
    else {
        for (int i = length; i > k; i++) element[i] = element[i - 1];
        element[k] = x;
        length++;
    }
    return *this;
}

// 判断表是否为空，空返回true,否则false
template <class T>
bool LinearList<T>::IsEmpty() const {
    return length == 0;
}

//返回表中数据元素个数
template <class T>
int LinearList<T>::GetLength() const {
    return length;
}

//将表中第k个元素保存到x中，不存在则返回false
template <class T>
bool LinearList<T>::GetData(int k, T& x) {
    if (k < 0 || k >= length) return false;
    x = element[k];
    return true;
}

//将表中第k个元素保存到x中，不存在则返回false
template <class T>
bool LinearList<T>::ModifyData(int k, const T& x) {
    if (k < 0 || k >= length) return false;
    element[k] = x;
    return true;
}

//返回x在表中位置，如果x不存在则返回-1
template <class T>
int LinearList<T>::Find(const T& x) {
    for (int i = 0; i < length; i++) {
        if (element[i] == x) return i;
    }
    return -1;
}

//删除表中第k个元素，并把它保存到x中，返回删除后的线性表
template <class T>
LinearList<T>& LinearList<T>::DeleteByIndex(int k, T& x) {
    if (GetData(k, x)) {
        for (int i = k; i < length - 1; i++) {
            element[i] = element[i + 1];
        }
        length--;
    } else
        cout << "元素下标越界，添加元素失败" << endl;
    return *this;
}

//删除表中第k个元素，并把它保存到x中，返回删除后的线性表
template <class T>
LinearList<T>& LinearList<T>::DeleteByKey(const T& x, T& y) {
    int index = Find(x);
    if (index == -1)
        cout << "元素不存在，删除失败" << endl;
    else {
        return DeleteByIndex(index, y);
    }
    return *this;
}

////将线性表放到输出流out中输出
template <class T>
void LinearList<T>::OutPut(ostream& out) const {
    for (int i = 0; i < length; i++) {
        out << element[i] << endl;
    }
}

//重载插入运算符<<
template <class T>
ostream& operator<<(ostream& out, const LinearList<T>& x) {
    x.OutPut(out);
    return out;
}

#endif