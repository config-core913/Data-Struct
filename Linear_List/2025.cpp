#include<iostream>
using namespace std;
//2025年真题，408的09年真题
//查找链表的倒数第k个元素
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
//查找倒数第k个结点
bool Search_k(LinkList L,int k){
	LinkList p = L->next;
	int count = 0;	//链表中元素的个数
	while(p){
		p = p->next;
		count++;
	}
	if(k > count) return 0;//元素个数小于k
	int j = 1;
	LinkList q = L->next;
	while(j < count - k + 1){
		q = q->next;
		j++;
	}
	cout << "倒数第" << k << "个元素为：" << q->data << " ";
	return 1;
}
int main(){
	LinkList L;
	cout << "请输入链表元素：";
	Tail_head(L);
	PrintList(L);
	Search_k(L, 3);
	return 0;
}