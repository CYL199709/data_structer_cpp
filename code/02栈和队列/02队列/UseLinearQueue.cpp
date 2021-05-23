//�����ܣ�����������
#include <iostream>
using namespace std;
#include "LinkQueue.h"
//�����k�еĿո�nΪ������
void PrintSpace(int n, int k) {
    for (int i = 1; i <= n - k; i++) cout << " ";
}
void YangHui(int n) {
    LinkQueue<int> Q;
    int x,y;
    PrintSpace(n, 1);
    cout << 1 << endl;
    Q.Insert(0);
    Q.Insert(1);
    Q.Insert(1);
    for(int i=2;i<=n;i++){
        PrintSpace(n,i);
        Q.Insert(0);
        do{
            Q.Delete(x);
            Q.GetElement(y);
            Q.Insert(x+y);
            if(y) cout<<y<<' ';
            else cout<<endl;
        }while(y);        
    }
    
}

int main(){
    int n;
    cout<<"������������ǵ�������\n";
    cin>>n;
    YangHui(n);
    return 0;
}