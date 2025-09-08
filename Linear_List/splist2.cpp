#include <cstddef>
#include<iostream>
using namespace std;
//按序号（奇偶）拆分链表
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
//头插法
void Tail_head(LinkList &L){
	L = new LNode;
	L->next = NULL;
	ElemType x;
	cin >> x;
	while(x != 9999){
		LinkList s = new LNode;
		s->data = x;
		s->next = L->next;
		L->next = s;
		cin >> x;
	}
}
//打印链表
void PrintList(LinkList L){
	LinkList p = L->next;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
//拆分链表
LinkList SqList(LinkList L){
	if(!L) return NULL;

	LinkList B = new LNode;
	B->next = NULL;
	LinkList p = L->next;
	LinkList rA,rB;
	rA = L;
	rB = B;
	
	while(p){
		rA->next = p;
		p = p->next;
		rA = rA->next;
		if(p){
			rB->next = p;
			rB = rB->next;
			p = p->next;
		}
	}
	rA->next = NULL;
	rB->next = NULL;
	return B;
}
int main(){
	LinkList L;
	cout << "请输入链表元素：";
	Tail_head(L);
	cout << "拆分前：";
	PrintList(L);
	LinkList B = SqList(L);
	cout << "链表A: ";
	PrintList(L);
	cout << "链表B: ";
	PrintList(B);
	return 0;
}