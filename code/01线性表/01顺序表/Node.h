/*Node.h*/
#ifndef NODE
#define NODE
#include <string>
#include <iostream>
using namespace std;
class Node {
   public:
    Node(string NumberOfStudent, string NameOfStudent, int grade[]);
    Node(){};                             //�޲ι��캯��
    Node& GetNode();                      //�õ��ڵ�����
    void OutPutNode(ostream& out) const;  //����������
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
    out<<"���ģ�"<<Score[0];
    out<<"��ѧ��"<<Score[1];
    out<<"Ӣ�"<<Score[2];

}

ostream& operator<<(ostream& out,const Node& x){
    x.OutPutNode(out);
    return out;
}
#endif