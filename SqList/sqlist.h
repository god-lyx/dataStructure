# pragma warning (disable:4819)
#define LISTMAXSIZE 100//默认最大长度100
#define LISTINCREMENT 10//默认扩容10
typedef int ElemType;

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
    int inheratateList(SqList &L2);//将本顺序表赋值给另一个顺序表
    int emptyList();//置空顺序表
    int spawnList(int=8/*默认长度为8*/);
    int inputList(int=8);
    void dispList();//打印顺序表
};

int equal(ElemType e1, ElemType e2);
int greaterThan(ElemType e1, ElemType e2);
int lessThan(ElemType e1, ElemType e2);





