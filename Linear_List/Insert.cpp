#include<iostream>
using namespace std;
//在有序的单链表中插入元素，插入后仍然有序
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
//尾插法
void Tail_Insert(LinkList &L){
	L = new LNode;
	L->next = NULL;
	LinkList p = L;
	ElemType x;
	cin >> x;
	while(x != 9999){
		LinkList s = new LNode;
		s->data = x;
		s->next = p->next;
		p->next = s;
		p = s;
		cin >> x;
	}
}
//打印输出
void PrintList(LinkList L){
	LinkList p = L->next;
	while(p){
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}
void Insert(LinkList L,ElemType element){
	LinkList pre,curr;
	pre = L->next;
	curr = L->next->next;
	while(curr){
		if(curr->data >= element && pre->data < element){
			break;
		}
		pre = pre->next;
		curr = curr->next;
	}
	LinkList s = new LNode;
	s->data = element;
	s->next = pre->next;
	pre->next = s;

}
int main(){
	LinkList L;
	cout << "请输入链表元素：";
	Tail_Insert(L);
	cout << "插入前：";
	PrintList(L);
	cout << "插入后：";
	Insert(L,5);
	PrintList(L);
	return 0;
}