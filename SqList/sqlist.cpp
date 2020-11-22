# pragma warning (disable:4819)
#include <sqlist.h>
#include <iostream>
#include <cstdlib>
#include <ctime>


SqList::SqList()
{
    listsize = LISTMAXSIZE;
    elem = new ElemType[listsize];
    length = 0;
}

SqList::~SqList()
{
    delete[] elem;
}

int SqList::insertElem(ElemType e, int i)
{
    ElemType *newbase; int istart, iend;
    if(i<1||i>length+1)return 0;//元素位置不合法
    if (length + 1 > LISTMAXSIZE)
    {//超出最大容量，扩容
        newbase = new ElemType[length+LISTINCREMENT];
        if(!newbase)return 0;//扩容失败，插入失败
        for(istart=0;istart<length;istart++){
            newbase[istart] = elem[istart];
            delete[] elem;//删除原内存
            elem = newbase;//elem指向新内存空间
            listsize += LISTINCREMENT;
        }
    }
    for(iend=length;iend>=i;iend--){
            elem[iend] = elem[iend-1];
        }//i之后元素向后移位
        elem[i-1] = e;
        ++length;
    return 1;//插入成功
}

int SqList::listEmpty(){
    if (length == 0) return 1;//空
    return 0;//非空
}

int SqList::getElem(int i, ElemType &e)
{
    if(i<1||i>length)return 0;//位置无效
    e = elem[i-1];
    return 1;//获取成功
}

int equal(ElemType e1, ElemType e2){
    return (e1==e2)?(1):(0);
}

int greaterThan(ElemType e1, ElemType e2){
    return (e1>e2)?(1):(0);
}

int lessThan(ElemType e1, ElemType e2){
    return (e1<e2)?(1):(0);
}

int SqList::compareElem(ElemType e, int (*compare)(ElemType, ElemType))
{
    int i;
    for(i=0;i<length;i++){
        if(compare(elem[i], e))return(i+1);//返回位置序号（从1开始）
    }
    return 0;//没有匹配
}

int SqList::getPrevious(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) - 1;//前一个元素的i
    return getElem(i, e2);
}

int SqList::getNext(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) + 1;//后一个元素的i
    return getElem(i, e2);
}

int SqList::deleteElem(int i, ElemType &e)
{
    int j;
    if(i<1||i>length)return 0;
    getElem(i, e);
    for(j=i-1;j<length-1;j++){
        elem[j] = elem[j+1];
    }
    --length;
    return 1;
}

int SqList::inheratateList(SqList &L2)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(L2.insertElem(elem[i],i+1))continue;
        else return 0;
    }
    return 1;
}

int SqList::emptyList()
{
    length = 0;
    return 1;//用已有函数判断是否置空
}

int SqList::spawnList(int l)
{
    int i;
    if(emptyList()){
        unsigned seed = std::time(0);
        std::srand(seed);
        for(i=0;i<l;i++){
            insertElem(std::rand()%100, 1);
        }
    return 1;
    }
    else return 0;
}

int SqList::inputList(int l)
{
    int i, input;
    emptyList();
    for(i=0;i<l;i++){
        std::cout<<"请输入第"<<i+1<<"个元素（共"<<l<<"个）"<<std::endl;
        std::cin>>input;
        if(insertElem(input,i+1))continue;
        else return 0;
    }
    return 1;
}

void SqList::dispList()
{
    int i;
    if(length==0){std::cout<<"空表"<<std::endl;return;}
    std::cout<<"当前顺序表元素为："<<std::endl;
    for(i=0;i<length;i++){
        //std::cout<<"【"<<setw(2)<<i<<"】";
        printf("【%2d】",i+1);
    }
    std::cout<<std::endl;
    for(i=0;i<length;i++){
        //std::cout<<"   "<<setw(2)<<elem[i]<<"    "<<std::endl;
        printf("  %2d  ",elem[i]);
    }
    printf("\n");

}
