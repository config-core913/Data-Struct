#include <iostream>
using namespace std;
//2017年第一大题
//单链表原地逆置
typedef int ElemType;
typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode,*LinkList;
//尾插法
void Insert_tail(LinkList &L){
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
//逆置
void reverse(LinkList &L){
	if(L){
		LinkList pre,curr,next;
		pre = NULL;
		curr = L->next;
		L->next = NULL;
		while(curr){
			next = curr->next;
			curr->next = pre;
			pre = curr;
			curr = next;
		}
		L->next = pre;
	}
}
int main(){
	LinkList L;
	cout << "请输入链表元素：";
	Insert_tail(L);
	PrintList(L);
	cout << "链表逆置之后：";
	reverse(L);
	PrintList(L);
	return 0;
	//testtgv
	//test
	//test
	//test
	//test
	//test
	//test
	//test
}