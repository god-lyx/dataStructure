#include"linkList.h"

template<class T>
struct Node{
    T   Data;//数据域
    Node<T> *next;//指针域
};

template<class T>
class LinkList{
    int length;//链表长度
    Node<T> *header;//链表头结点指针
    public:
    LinkList();
    //取非循环单链表的第i个结点
    T operator()(int i)const;
    //在第i个结点之前插入数据域为e的结点
    Status insertNode(int i, T e);
};

template<class T>
LinkList<T>::LinkList()
{
    length = 0;
    header      = new Node<T>;//开辟单个结点的内存
    header->Data = 0;
    header->next = NULL;//后继为空
}

template<class T>
T LinkList<T>::operator()(int i)const
{
    if(!length || (i<1 || i>length))return ERROR;
    Node<T> *p = header;
    while(0 < i--) p = p->next;
    return p->Data;
}

template<class T>
Status LinkList<T>::insertNode(int i, T e)
{//头结点始终为空
    Node<T> *pnewNode, *ptargetNode = header;//新结点及其前一位结点
    if(i<1||i>length+1)return ERROR;
    while (0 < --i) ptargetNode = ptargetNode->next;
    pnewNode = new Node<T>;
    pnewNode->Data = e;
    pnewNode->next = ptargetNode->next;
    ptargetNode->next = pnewNode;
    length++;
    return OK;
}
