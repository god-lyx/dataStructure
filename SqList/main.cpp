#include "sqlist.h"
#include<iostream>
using namespace std;

int main(){
    int option, i, e, e2;
    printf("*******顺序表操作*******\n");
    SqList<int> L, L2, L3;
    while(1)
    {
    cout<<"当前顺序表为";
    L.dispList();
    printf("操作代码：");
    scanf("%d", &option);
    switch(option){
        case 1:
        printf("插入元素的位序，值：");
        printf("\n");
        scanf("%d %d", &i, &e);
        if(L.insertElem(e, i))printf("操作成功！\n");
        else printf("操作失败。\n");
        printf("\n");
        L.dispList();
        printf("*********************************************\n");
        printf("\n");
        printf("\n");
        printf("*********************************************\n");
        continue;
        case 2:
        printf("判断是否为空表\n");
        if(L.listEmpty())printf("是空表\n");
        else printf("非空\n");
        continue;

        case 3:
        printf("取指定位序的元素，请输入该位置：");
        scanf("%d", &i);
        if(L.getElem(i, e))printf("取得第%d位元素%d\n", i, e);
        else printf("操作失败\n");
        continue;

        case 4:
        cout<<"比较元素"<<endl;
        cout<<"待比较元素"<<endl;
        cin>>e;
        cout<<"【1】相等元素，【2】大于该元素，【3】小于该元素"<<endl;
        cin>>option;
        switch(option){
            case 1:
            if(!(i = L.compareElem(e, equal)))cout<<"没有匹配到该元素"<<endl;
            else {
                L.getElem(i, e);
                cout<<"第"<<i<<"位元素"<<e<<"满足该关系"<<endl;
                }
            break;

            case 2:
            if(!(i = L.compareElem(e, greaterThan)))cout<<"没有匹配到该元素"<<endl;
            else {
                L.getElem(i, e);
                cout<<"第"<<i<<"位元素"<<e<<"满足该关系"<<endl;
                }
            break;

            case 3:
            if(!(i = L.compareElem(e, lessThan)))cout<<"没有匹配到该元素"<<endl;
            else {
                L.getElem(i, e);
                cout<<"第"<<i<<"位元素"<<e<<"满足该关系"<<endl;
                }
            break;
        }
        continue;

        case 5:
        cout<<"取前一个元素，请输入目标元素"<<endl;
        cin>>e;
        if(!L.getPrevious(e, e2))cout<<"不存在该元素"<<endl;
        else cout<<"前驱为"<<e2<<endl;
        continue;

        case 6:
        cout<<"取后一个元素，请输入目标元素"<<endl;
        cin>>e;
        if(!L.getNext(e, e2))cout<<"不存在该元素"<<endl;
        else cout<<"后继为"<<e2<<endl;
        continue;

        case 7:
        cout<<"请输入要删除元素的位序："<<endl;
        cin>>i;
        if(!L.deleteElem(i, e))cout<<"位序不合法，操作失败"<<endl;
        else cout<<"成功删除第"<<i<<"位元素"<<e<<endl;
        continue;

        case 8:
        cout<<"将顺序表赋值给另一个顺序表"<<endl;
        if(!L.inheratateList(L2))cout<<"操作失败！"<<endl;
        else{
            cout<<"操作成功，生成新顺序表：";
            L2.dispList();
            cout<<endl;
        }
        continue;

        case 9:
        cout<<"置空当前顺序表"<<endl;
        if(L.emptyList())cout<<"操作成功"<<endl;
        else cout<<"操作失败"<<endl;
        continue;

        case 10:
        cout<<"随机生成列表"<<endl;
        if(!L.spawnList())cout<<"操作失败"<<endl;
        else{
            cout<<"创建成功!"<<endl;
        }
        continue;

        case 11:
        cout<<"输入顺序表:"<<endl;
        cout<<"请输入顺序表长度（默认长度为8）：";
        cin>>i;
        cout<<endl;
        if(!L.inputList(i))cout<<"操作失败"<<endl;
        else cout<<"操作成功"<<endl;
        continue;

        case 12:
        cout<<"并运算"<<endl;
        cout<<"表1：";
        L.dispList();
        cout<<"表2：";
        L2.dispList();
        L3 = L + L2;
        cout<<"并集为"<<endl;
        L3.dispList();
        continue;
    
        case 13:
        cout<<"进入学生信息系统"<<endl;
        Student Stu;
        SqList<Student> L3;
        while(1){
            cout<<"当前学生表为：";
            L3.dispStu();
            cout<<"请输入操作数：";
            cin>>option;
            switch(option){
                case 1:
                cout<<"输入学生信息："<<endl;
                L3.inputStudent(Stu);
                L3.insertElem(Stu,1);
                continue;
            default:
                break;
            }
        }
    }
    }
}