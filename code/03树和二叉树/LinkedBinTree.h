#include <iostream>
#include <queue>  // ����
#include <stack>  //ջ

template <class T>
class LinkNode {
    template <class T1>
    friend class LinkedBinTree;

   public:
    LinkNode() {
        m_pLeftChild = NULL;
        m_pRightChild = NULL;
    }
    LinkNode(const T& x) {
        m_data = x;
        m_pLeftChild = NULL;
        m_pRightChild = NULL;
    }

   private:
    T m_data;
    LinkNode<T>*m_pLeftChild, *m_pRightChild;
};

template <class T>
class LinkedBinTree {
   public:
    LinkedBinTree();   //�����ն�����
    ~LinkedBinTree();  //ɾ��������
    bool IsEmpty();
    //��ָ��Ԫ��ֵ�������ڵ�
    LinkNode<T>* CreateRoot(const T& x);
    void Clear();            //��ն�����
    LinkNode<T>* GetRoot();  //��ȡ�����
    //��һ���ڵ���Ϊָ���ڵ�����Ӳ���
    LinkNode<T>* InsertLeftChild(LinkNode<T>* pNode, const T& x);
    //��һ���ڵ���Ϊָ���ڵ���Һ��Ӳ���
    LinkNode<T>* InsertRightChild(LinkNode<T>* pNode, const T& x);
    //�޸�ָ������Ԫ��ֵ
    bool ModifyNodeValue(LinkNode<T>* pNode, const T& x);
    //��ȡָ������Ԫ��ֵ
    bool GetNodeValue(LinkNode<T>* pNode, const T& x);
    //�޸�ָ���������ӽ��
    LinkNode<T>* GetLeftChild(LinkNode<T>* pNode);
    //��ȡָ�������Һ��ӽ��
    LinkNode<T>* GetRightChild(LinkNode<T>* pNode);
    //���ݹ鷽ʽ�������
    void PreOrderTraverse(LinkNode<T>* pNode);
    //���ݹ鷽ʽ�������
    void InOrderTraverse(LinkNode<T>* pNode);
    //���ݹ鷽ʽ�������
    void PostOrderTraverse(LinkNode<T>* pNode);
    void PreOrderTraverse();    //���ǵݹ鷽ʽ�������
    void InOrderTraverse();     //���ǵݹ鷽ʽ�������
    void PostOrderTraverse();   //���ǵݹ鷽ʽ�������
    void LevelOrderTraverse();  //���ǵݹ鷽ʽ�������
    //���ǵݹ鷽ʽ��ȡָ������˫�׽��
    LinkNode<T>* GetParent(LinkNode<T>* pNode);
    //ɾ����ָ�����Ϊ��������
    void DeleteSubTree(LinkNode<T>* pNode);
    //��DeleteSubTree���ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
    void DeleteSubTreeNode(LinkNode<T>* pNode);
    //���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
    LinkNode<T>* SearchByKey(const T& x);

   private:
    LinkNode<T>* m_pRoot;  //ָ����ڵ��ָ��
};

template <class T>
LinkedBinTree<T>::LinkedBinTree() {
    m_pRoot = NULL;
}

//ɾ��������
template <class T>
LinkedBinTree<T>::~LinkedBinTree(){
    clear();
} 
template <class T>
bool LinkedBinTree<T>::IsEmpty() {
    if (m_pRoot == NULL) return true;
    return false;
}

//��ָ��Ԫ��ֵ�������ڵ�
template <class T>
LinkNode<T>* LinkedBinTree<T>::CreateRoot(const T& x) {
    if (m_pRoot != NULL)
        m_pRoot->m_data = x;
    else
        m_pRoot = new LinkNode<T> x;
    return m_pRoot;
}

//��ն�����
template <class T>
void LinkedBinTree<T>::Clear(){
    DeleteSubTree(m_pRoot);
}
//��ȡ�����
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetRoot() {
    return m_pRoot;
}
//��һ���ڵ���Ϊָ���ڵ�����Ӳ���
template <class T>
LinkNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return NULL;
    LinkNode<T>* pNewNode;
    pNewNode = new LinkNode<T>(x);
    if (pNewNode == NULL) return NULL;
    pNode->m_pLeftChild = pNewNode;
    return pNewNode;
}
//��һ���ڵ���Ϊָ���ڵ���Һ��Ӳ���
template <class T>
LinkNode<T>* LinkedBinTree<T>::InsertRightChild(LinkNode<T>* pNode,
                                                const T& x) {
    if (pNode == NULL) return NULL;
    LinkNode<T>* pNewNode;
    pNewNode = new LinkNode<T>(x);
    if (pNewNode == NULL) return NULL;
    pNode->m_pRightChild = pNewNode;
    return pNewNode;
}
//�޸�ָ������Ԫ��ֵ
template <class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return false;
    pNode->m_data = x;
    return true;
}

//��ȡָ������Ԫ��ֵ
template <class T>
bool LinkedBinTree<T>::GetNodeValue(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return false;
    x = pNode->m_data;
    return true;
}
//���ָ���������ӽ��
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetLeftChild(LinkNode<T>* pNode) {
    if (pNode == NULL) return NULL;
    return pNode->m_pLeftChild;
}
//��ȡָ�������Һ��ӽ��
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetRightChild(LinkNode<T>* pNode) {
    if (pNode == NULL) return NULL;
    return pNode->m_pRightChild;
}
//���ݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
}
//���ݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::InOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    PreOrderTraverse(pNode->m_pLeftChild);
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pRightChild);
}
//���ݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
    cout << pNode->m_data << " ";
}
//���ǵݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::PreOrderTraverse() {
    stack<LinkNode<T>*> s;
    LinkNode<T>* pNode = NULL;
    if (m_pRoot == NULL) return;
    s.push(m_pRoot);
    while (!s.empty()) {
        pNode = s.top();
        s.pop();
        cout << pNode->m_data << " ";
        if (pNode->m_pRightChild) {
            s.push(pNode->m_pRightChild)
        }
        if (pNode->m_pLeftChild) {
            s.push(pNode->m_pLeftChild)
        }
    }
}

//���ǵݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::InOrderTraverse(){
    stack<LinkNode<T>*> s;
    LinkNode<T>* cur = m_pRoot;
    while(cur!=NULL&&!s.empty()){
        if(cur!=NULL){
            s.push(cur);
            cur=cur->m_pLeftChild;
        }
        else{
            cur=st.top();
            st.pop();
            cout<<cur->m_data<<" ";
            cur = cur->right;
        }
    }

}  
 //���ǵݹ鷽ʽ�������
 //������->������
template <class T> 
void LinkedBinTree<T>::PostOrderTraverse(){
    stack<LinkNode<T>*> s;
    stack<LinkNode<T>*> s1;
    LinkNode<T>* pNode = NULL;
    if (m_pRoot == NULL) return;
    s.push(m_pRoot);
    while (!s.empty()) {
        pNode = s.top();
        s.pop();
        s1.push(pNode);
        if (pNode->m_pLeftChild) {
            s.push(pNode->m_pLeftChild)
        }
        if (pNode->m_pRightChild) {
            s.push(pNode->m_pRightChild)
        }      
    }
    while(!s1.empty()){
        pNode = s1.top();
        s1.pop();
        cout<<pNode->m_data<<" ";
    }
}
//���ǵݹ鷽ʽ�������
template <class T>
void LinkedBinTree<T>::LevelOrderTraverse() {
    LinkNode<T>* pNode = NULL;
    queue<LinkNode<T>*> q;
    if (m_pRoot == NULL) return;
    q.push(m_pRoot);
    while (!q.empty()) {
        pNode = q.front();
        q.pop();
        cout << pNode->m_data << " ";
        if (pNode->m_pLeftChild) q.push(pNode->m_pLeftChild);
        if (pNode->m_pRightChild) q.push(pNode->m_pRightChild);
    }
}
//���ǵݹ鷽ʽ��ȡָ������˫�׽��
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetParent(LinkNode<T>* pNode) {
    LinkNode<T>* pCurNode = NULL;
    queue<LinkNode<T>*> q;
    if (m_pRoot == NULL) return NULL;
    if (m_pRoot == pNode) return NULL;
    q.push(m_pRoot);
    while (!q.empty()) {
        pCurNode = q.front();
        q.pop();
        if (pCurNode->m_pLeftChild == pNode ||
            pCurNode->m_pRightChild == pNode) {
            return pCurNode;
        }
        if (pCurNode->m_pLeftChild) q.push(pCurNode->m_pLeftChild);
        if (pCurNode->m_pRightChild) q.push(pCurNode->m_pRightChild);
    }
    return NULL;
}
//ɾ����ָ�����Ϊ��������
template <class T>
void LinkedBinTree<T>::DeleteSubTree(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    LinkNode<T>* pParentNode = NULL;
    if (pNode == m_pRoot)
        m_pRoot = NULL;
    else if (pParentNode = GetParent(pNode) != NULL) {
        if(pParentNode->m_pLeftChild == pNode) pParentNode->m_pLeftChild = NULL;
        else pParentNode->m_pRightChild = NULL;
    }
    else return;
    DeleteSubTreeNode(pNode);
}
//��DeleteSubTree���ð��ǵݹ鷽ʽɾ����ָ�����Ϊ��������
template <class T>
void LinkedBinTree<T>::DeleteSubTreeNode(LinkNode<T>* pNode){
    if (pNode == NULL) return;
    queue<LinkNode<T>*> q;
    LinkNode<T>* pCurNode = NULL;
    q.push(pNode);
    while(!q.empty()){
        pCurNode = q.front();
        q.pop();
        if (pCurNode->m_pLeftChild) q.push(pCurNode->m_pLeftChild);
        if (pCurNode->m_pRightChild) q.push(pCurNode->m_pRightChild);
        delete pCurNode;
    }
}
//���ǵݹ鷽ʽ���ݹؼ��ֲ��ҽ��
template <class T>
LinkNode<T>* LinkedBinTree<T>::SearchByKey(const T& x){
    LinkNode<T>* pNode = NULL;
    queue<LinkNode<T>*> q;
    if (m_pRoot == NULL) return;
    q.push(m_pRoot);
    while (!q.empty()) {
        pNode = q.front();
        q.pop();
        if(pNode->m_data==x) return pNode;
        if (pNode->m_pLeftChild) q.push(pNode->m_pLeftChild);
        if (pNode->m_pRightChild) q.push(pNode->m_pRightChild);
    }
    return NULL:
}
