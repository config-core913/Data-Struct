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
	if(k > count) return 0;
	int j = 0;
	LinkList q = L->next;
	while(j < count){
		q = q->next;
		j++;
	}
	
}
int main(){
	LinkList L;
	Tail_head(L);
	
	return 0;
}