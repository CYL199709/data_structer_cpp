#include <iostream>
#include <queue>  // 队列
#include <stack>  //栈

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
    LinkedBinTree();   //创建空二叉树
    ~LinkedBinTree();  //删除二叉树
    bool IsEmpty();
    //以指定元素值创建根节点
    LinkNode<T>* CreateRoot(const T& x);
    void Clear();            //清空二叉树
    LinkNode<T>* GetRoot();  //获取根结点
    //将一个节点作为指定节点的左孩子插入
    LinkNode<T>* InsertLeftChild(LinkNode<T>* pNode, const T& x);
    //将一个节点作为指定节点的右孩子插入
    LinkNode<T>* InsertRightChild(LinkNode<T>* pNode, const T& x);
    //修改指定结点的元素值
    bool ModifyNodeValue(LinkNode<T>* pNode, const T& x);
    //获取指定结点的元素值
    bool GetNodeValue(LinkNode<T>* pNode, const T& x);
    //修改指定结点的左孩子结点
    LinkNode<T>* GetLeftChild(LinkNode<T>* pNode);
    //获取指定结点的右孩子结点
    LinkNode<T>* GetRightChild(LinkNode<T>* pNode);
    //按递归方式先序遍历
    void PreOrderTraverse(LinkNode<T>* pNode);
    //按递归方式中序遍历
    void InOrderTraverse(LinkNode<T>* pNode);
    //按递归方式后序遍历
    void PostOrderTraverse(LinkNode<T>* pNode);
    void PreOrderTraverse();    //按非递归方式先序遍历
    void InOrderTraverse();     //按非递归方式中序遍历
    void PostOrderTraverse();   //按非递归方式后序遍历
    void LevelOrderTraverse();  //按非递归方式层序遍历
    //按非递归方式获取指定结点的双亲结点
    LinkNode<T>* GetParent(LinkNode<T>* pNode);
    //删除以指定结点为根的子树
    void DeleteSubTree(LinkNode<T>* pNode);
    //由DeleteSubTree调用按非递归方式删除以指定结点为根的子树
    void DeleteSubTreeNode(LinkNode<T>* pNode);
    //按非递归方式根据关键字查找结点
    LinkNode<T>* SearchByKey(const T& x);

   private:
    LinkNode<T>* m_pRoot;  //指向根节点的指针
};

template <class T>
LinkedBinTree<T>::LinkedBinTree() {
    m_pRoot = NULL;
}

//删除二叉树
template <class T>
LinkedBinTree<T>::~LinkedBinTree(){
    clear();
} 
template <class T>
bool LinkedBinTree<T>::IsEmpty() {
    if (m_pRoot == NULL) return true;
    return false;
}

//以指定元素值创建根节点
template <class T>
LinkNode<T>* LinkedBinTree<T>::CreateRoot(const T& x) {
    if (m_pRoot != NULL)
        m_pRoot->m_data = x;
    else
        m_pRoot = new LinkNode<T> x;
    return m_pRoot;
}

//清空二叉树
template <class T>
void LinkedBinTree<T>::Clear(){
    DeleteSubTree(m_pRoot);
}
//获取根结点
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetRoot() {
    return m_pRoot;
}
//将一个节点作为指定节点的左孩子插入
template <class T>
LinkNode<T>* LinkedBinTree<T>::InsertLeftChild(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return NULL;
    LinkNode<T>* pNewNode;
    pNewNode = new LinkNode<T>(x);
    if (pNewNode == NULL) return NULL;
    pNode->m_pLeftChild = pNewNode;
    return pNewNode;
}
//将一个节点作为指定节点的右孩子插入
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
//修改指定结点的元素值
template <class T>
bool LinkedBinTree<T>::ModifyNodeValue(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return false;
    pNode->m_data = x;
    return true;
}

//获取指定结点的元素值
template <class T>
bool LinkedBinTree<T>::GetNodeValue(LinkNode<T>* pNode, const T& x) {
    if (pNode == NULL) return false;
    x = pNode->m_data;
    return true;
}
//获得指定结点的左孩子结点
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetLeftChild(LinkNode<T>* pNode) {
    if (pNode == NULL) return NULL;
    return pNode->m_pLeftChild;
}
//获取指定结点的右孩子结点
template <class T>
LinkNode<T>* LinkedBinTree<T>::GetRightChild(LinkNode<T>* pNode) {
    if (pNode == NULL) return NULL;
    return pNode->m_pRightChild;
}
//按递归方式先序遍历
template <class T>
void LinkedBinTree<T>::PreOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
}
//按递归方式中序遍历
template <class T>
void LinkedBinTree<T>::InOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    PreOrderTraverse(pNode->m_pLeftChild);
    cout << pNode->m_data << " ";
    PreOrderTraverse(pNode->m_pRightChild);
}
//按递归方式后序遍历
template <class T>
void LinkedBinTree<T>::PostOrderTraverse(LinkNode<T>* pNode) {
    if (pNode == NULL) return;
    PreOrderTraverse(pNode->m_pLeftChild);
    PreOrderTraverse(pNode->m_pRightChild);
    cout << pNode->m_data << " ";
}
//按非递归方式先序遍历
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

//按非递归方式中序遍历
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
 //按非递归方式后序遍历
 //中右左->左右中
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
//按非递归方式层序遍历
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
//按非递归方式获取指定结点的双亲结点
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
//删除以指定结点为根的子树
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
//由DeleteSubTree调用按非递归方式删除以指定结点为根的子树
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
//按非递归方式根据关键字查找结点
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
