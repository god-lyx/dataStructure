#include <sqlist.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <iomainp>

template<class ElemType>
class SqList
{
private:
    ElemType       *elem;//指向元素地址
    int            length;//顺序表当前长度
    int            listsize;//最大容量
public:
    SqList();//为顺序表分配内存
    ~SqList();
    int insertElem(ElemType e, int i);//在第i位之前插入元素e
    int listEmpty();//判断线性表是否为空
    int getElem(int i, ElemType &e);//取第i个元素；
    int compareElem(ElemType e, int (*compare)(ElemType, ElemType));//返回第一个与e满足compare关系的元素序号
    int getPrevious(ElemType e, ElemType &e2);
    int getNext(ElemType e, ElemType &e2);//取某元素的前驱、后继，用e2返回   
    int deleteElem(int i,ElemType &e);//删除第i个元素
    int inheratateList(SqList<ElemType> &L2);//将本顺序表赋值给另一个顺序表
    int emptyList();//置空顺序表
    int spawnList(int=8/*默认长度为8*/);
    int inputList(int=8);
    void dispList();//打印顺序表
};


template<class ElemType>
SqList<ElemType>::SqList()
{
    listsize = LISTMAXSIZE;
    elem = new ElemType[listsize];
    length = 0;
}

template<class ElemType>
SqList<ElemType>::~SqList()
{
    delete[] elem;
}

template<class ElemType>
int SqList<ElemType>::insertElem(ElemType e, int i)
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

template<class ElemType>
int SqList<ElemType>::listEmpty(){
    if (length == 0) return 1;//空
    return 0;//非空
}

template<class ElemType>
int SqList<ElemType>::getElem(int i, ElemType &e)
{
    if(i<1||i>length)return 0;//位置无效
    e = elem[i-1];
    return 1;//获取成功
}

template<typename ElemType>
int equal(ElemType e1, ElemType e2){
    return (e1==e2)?(1):(0);
}

template<typename ElemType>
int greaterThan(ElemType e1, ElemType e2){
    return (e1>e2)?(1):(0);
}

template<typename ElemType>
int lessThan(ElemType e1, ElemType e2){
    return (e1<e2)?(1):(0);
}

template<class ElemType>
int SqList<ElemType>::compareElem(ElemType e, int (*compare)(ElemType, ElemType))
{
    int i;
    for(i=0;i<length;i++){
        if(compare(elem[i], e))return(i+1);//返回位置序号（从1开始）
    }
    return 0;//没有匹配
}

template<class ElemType>
int SqList<ElemType>::getPrevious(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) - 1;//前一个元素的i
    return getElem(i, e2);
}

template<class ElemType>
int SqList<ElemType>::getNext(ElemType e, ElemType &e2)
{
    int i = compareElem(e, equal) + 1;//后一个元素的i
    return getElem(i, e2);
}

template<class ElemType>
int SqList<ElemType>::deleteElem(int i, ElemType &e)
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

template<class ElemType>
int SqList<ElemType>::inheratateList(SqList<ElemType> &L2)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(L2.insertElem(elem[i],i+1))continue;
        else return 0;
    }
    return 1;
}

template<class ElemType>
int SqList<ElemType>::emptyList()
{
    length = 0;
    return 1;//用已有函数判断是否置空
}

template<class ElemType>
int SqList<ElemType>::spawnList(int l)
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

template<class ElemType>
int SqList<ElemType>::inputList(int l)
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

template<class ElemType>
void SqList<ElemType>::dispList()
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