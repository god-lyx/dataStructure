#include<iostream>
#include"linkList.h"
using namespace std;

int main(){
    int option, i, e, output;
    LinkList<int> L;
    while(1){
    cout<<"**************单链表测试**************"<<endl;
    cout<<"【1】取非循环单链表的第i个结点；"<<endl;
    cout<<"【2】在第i个结点前插入数据域为e的结点"<<endl;

    cout<<"请输入操作码：";
    cin>>option;

    switch(option){
        case 1:
        cout<<"请输入取出元素的位序：";
        cin>>i;

        if(output = L(i))
            cout<<"第i个结点的数据域为："<<output<<endl;
        else cout<<"操作失败！"<<endl;
        continue;

        case 2:
        cout<<"输入插入位序：";
        cin>>i;
        cout<<"输入数据域：";
        cin>>e;

        if(!L.insertNode(i, e))cout<<"操作失败！"<<endl;
        continue;
    }
}
}