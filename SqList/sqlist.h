#define LISTMAXSIZE 100//默认最大长度100
#define LISTINCREMENT 10//默认扩容10

template<typename ElemType>int equal(ElemType e1, ElemType e2);
template<typename ElemType>int greaterThan(ElemType e1, ElemType e2);
template<typename ElemType>int lessThan(ElemType e1, ElemType e2);

template<class ElemType>
class SqList;

