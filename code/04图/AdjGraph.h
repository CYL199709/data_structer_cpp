//ͼ���ڽӾ����ʾ����ģ��
#include <iostream>
using namespace std;
const int MY_INFINITY = INT_MAX;
const int MAX_VERTEX_NUM = 30;
template <class T>
class AdjGraph {
   private:
    T m_vertex[MAX_VERTEX_NUM];  //���㼯��
    int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int m_nVertexNum;  //������Ŀ��
    int m_nGraphType;  //ͼ������(0:����ͼ��1:����ͼ)
   public:
   AdjGraph(int nGraphType); //����ͼ
   //�Եݹ鷽ʽ���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
   bool DFSTraverse(int nV,int);
   //��DFSTraverse�����Եݹ鷽ʽ���ͼ��������ȱ���
   void DFS(int nV,bool bVisited[]);
   bool DFSTraverse(int nV);//�Էǵݹ鷽ʽ��ͼ��������ȱ���
   //���±�ΪnV�Ķ��㿪ʼ��ͼ��������ȱ���
   void BFSTraverse(int nV);
   int GetVertexNum(); //��ȡ������Ŀ
   int GeyFirstEdge(int nV); //��ȡ��ָ������nV������ĵ�һ����
   //��ȡ��ָ����(nV1,nV2)��<nV1,nV2>����ͬ��������nV1����һ����
   int GetNextEdge(int nV1,int nV2);

};
