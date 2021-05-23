//图的邻接矩阵表示的类模板
#include <iostream>
using namespace std;
const int MY_INFINITY = INT_MAX;
const int MAX_VERTEX_NUM = 30;
template <class T>
class AdjGraph {
   private:
    T m_vertex[MAX_VERTEX_NUM];  //顶点集合
    int m_nAdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
    int m_nVertexNum;  //顶点数目；
    int m_nGraphType;  //图的类型(0:无向图，1:有向图)
   public:
   AdjGraph(int nGraphType); //创建图
   //以递归方式从下标为nV的顶点开始对图做深度优先遍历
   bool DFSTraverse(int nV,int);
   //由DFSTraverse调用以递归方式完成图的深度优先遍历
   void DFS(int nV,bool bVisited[]);
   bool DFSTraverse(int nV);//以非递归方式对图做深度优先遍历
   //从下表为nV的顶点开始对图作广度优先遍历
   void BFSTraverse(int nV);
   int GetVertexNum(); //获取顶点数目
   int GeyFirstEdge(int nV); //获取与指定顶点nV相关联的第一条边
   //获取与指定边(nV1,nV2)或<nV1,nV2>有相同关联顶点nV1的下一条边
   int GetNextEdge(int nV1,int nV2);

};
