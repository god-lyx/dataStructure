#define OK 1
#define ERROR 0
typedef int Status;
#include <cstddef>

template<class T>
class LinkList;//链表

template<class T>
struct Node;//链表结点

template<class T>
struct Node {
	T   Data;//数据域
	Node<T>* next;//指针域
};

template<class T>
class LinkList {
	Node<T>* header;//链表头结点指针
public:
	int length;//链表长度
	LinkList();
	//取非循环单链表的第i个结点
	T operator()(int i)const;
	//在第i个结点之前插入数据域为e的结点
	Status insertNode(int i, T e);
	//判断非循环单链表是否为空
	Status ifEmpty();
	//查找与e满足compare()关系的结点,默认查找第一个
	int* compareNode(T e, Status(*compare)(T, T));
	//返回某结点(已知数据域)前驱的位序
	int getPrevious(T e);
	//返回后继的位序
	int getNext(T e);
	//删除数据域为e的第一个结点
	Status removeFirst(T e, int L = 1);
	//删除重复的结点
	Status removeRedundant();
};

//compare函数实例
template<class T>
Status equal(T e1, T e2) {
	return e1 == e2;
}

template<class T>
Status lessThan(T e1, T e2) {
	return (e1 < e2);
}

template<class T>
Status greaterThan(T e1, T e2) {
	return (e1 > e2);
}
//compare函数

template<class T>
LinkList<T>::LinkList()
{
	length = 0;
	header = new Node<T>;//开辟单个结点的内存
	header->Data = 0;
	header->next = NULL;//后继为空
}

template<class T>
T LinkList<T>::operator()(int i)const//算符重载，返回第i位指针数据域
{
	if (!length || (i<1 || i>length))return ERROR;//长度为零或位序不合法，返回error
	Node<T>* p = header;//循环开始于头节点
	while (0 < i--) p = p->next;
	return p->Data;
}

template<class T>
Status LinkList<T>::insertNode(int i, T e)
{//头结点始终为空
	if (i<1 || i>length + 1)return ERROR;
	Node<T>* pnewNode, * ptargetNode = header;//新结点及其前一位结点
	while (0 < --i) ptargetNode = ptargetNode->next;
	pnewNode = new Node<T>;
	pnewNode->Data = e;
	pnewNode->next = ptargetNode->next;//交换
	ptargetNode->next = pnewNode;//过程
	length++;
	return OK;
}

template<class T>
Status LinkList<T>::ifEmpty() {
	return (!length) ? OK : ERROR;
}

template<class T>
inline int* LinkList<T>::compareNode(T e, Status(*compare)(T, T))
{
	Node<T>* pinit = header->next; int* target = new int[length]; int* ptar = target;//储存所有符合compare的结点序号
	int L = 1; 
	while ((L <= length) ) {
		if (compare(pinit->Data, e)) *ptar = L;
		ptar = ptar++;
		pinit = pinit->next;//下一位结点
		L++;//及其对应的位序
	}
	return target;//返回储存目标结点位序的数组
}

template<class T>
inline int LinkList<T>::getPrevious(T e)
{
	return *compareNode(e, equal) ? *compareNode(e, equal) - 1 : 0;
}

template<class T>
inline int LinkList<T>::getNext(T e)
{
	return *compareNode(e, equal) ? (*compareNode(e, equal)) + 1 : 0;
}

template<class T>
inline Status LinkList<T>::removeFirst(T e, int L)
{
	int ord = *compareNode(e, equal);
	if (!ord)return ERROR;//不存在该结点，删除失败
	Node<T>* pObjNode = header;
	for (int i = 1; i < ord; i++) {
		pObjNode = pObjNode->next;
	}//前一位结点
	pObjNode->next = pObjNode->next->next;//没有回收废弃指针的内存，待高人指点
	length--;
	return OK;
}

template<class T>
inline Status LinkList<T>::removeRedundant()
{//依次对每一位结点使用compareNode方法，
	if (length<=1) return OK;//少于一个元素，没有重复
	Node<T>* pObjNode = header->next; int L = 1; int frmv;//目标结点、扫描范围、删除指示
	while (pObjNode->next) {//末尾指针之前
		frmv = removeFirst(pObjNode->Data, L+1);
		if(frmv)length--;
		L++;
		pObjNode = pObjNode->next;
	}
	return OK;
}

