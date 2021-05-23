/*Node.h*/
#ifndef NODE
#define NODE
#include <string>
#include <iostream>
using namespace std;
class Node {
   public:
    Node(string NumberOfStudent, string NameOfStudent, int grade[]);
    Node(){};                             //无参构造函数
    Node& GetNode();                      //得到节点数据
    void OutPutNode(ostream& out) const;  //输出结点数据
   private:
    string StdNumber;
    string StdName;
    int Score[3];
};

Node::Node(string NumberOfStudent, string NameOfStudent, int grade[]){
    StdNumber = NumberOfStudent;
    StdName = NameOfStudent;
    for(int i=0;i<3;i++){
        Score[i] = grade[i];
    }
}

Node& Node::GetNode(){
    return *this;
}

void Node::OutPutNode(ostream& out) const{
    out<<StdNumber<<""<<StdName<<endl;
    out<<"语文："<<Score[0];
    out<<"数学："<<Score[1];
    out<<"英语："<<Score[2];

}

ostream& operator<<(ostream& out,const Node& x){
    x.OutPutNode(out);
    return out;
}
#endif