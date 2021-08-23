
//1. 链表结构的理解，可以分成程序内部和内存内部去理解

//2.链表的插入和删除过程，注意操作顺序，避免造成内存泄露。

//3.链表的代码实现中虚拟头节点的作用。
//带虚拟头节点的逻辑简单，不需专门指针删除头节点进行逻辑操作；提交结果表明运行时间提高很大。但需注意，返回时应返回直接时的头节点位置！
//1、防止单链表是空的而设的.当链表为空的时候, 带头结点的头指针就指向头结点.如果当链表为空的时候, 单链表没有带头结点, 那么它的头指针就为NULL.
//2、是为了方便单链表的特殊操作, 插入在表头或者删除第一个结点.这样就保持了单链表操作的统一性!
//3、单链表加上头结点之后，无论单链表是否为空，头指针始终指向头结点，因此空表和非空表的处理也统一了，方便了单链表的操作，也减少了程序的复杂性和出现bug的机会。
//4、对单链表的多数操作应明确对哪个结点以及该结点的前驱。不带头结点的链表对首元结点、中间结点分别处理等；
//而带头结点的链表因为有头结点，首元结点、中间结点的操作相同, 从而减少分支，使算法变得简单, 流程清晰。
//对单链表进行插入、删除操作时，如果在首元结点之前插入或删除的是首元结点，不带头结点的单链表需改变头指针的值，
//在C 算法的函数形参表中头指针一般使用指针的指针(在C + +中使用引用&)；而带头结点的单链表不需改变头指针的值，函数参数表中头结点使用指针变量即可。


//4.单向循环链表的结构定义和性质。
//单向循环链表 [Circular Linked List] : 由各个内存结构通过一个指针 Next 链接在一起组成，每一个内存结构都存在后继内存结构，
//内存结构由数据域和 Next 指针域组成。单向的实现就是在单链表的基础上，把链尾的 Next 指针直接指向链头，形成一个闭环；
//循环链表没有链头和链尾的说法，因为是闭环的，所以每一个内存结构都可以充当链头和链尾；


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)


typedef struct ListNode {
	int data;
	struct ListNode* next;
} ListNode;

typedef struct List {
	ListNode head;//虚拟头节点
	int length;
} List;


ListNode* getNewNode(int);  //函数声明，当前结点地址
List* getLinkList();        //整个链表的初始化
void clear_node(ListNode*); //销毁操作 
void clear(List*);          //清空链表
int insert(List*, int, int);
int erase(List*, int);    
void output(List*);         
void reverse(List*);       


int main() {
	srand(time(0));
#define max_op 20
	List* l = getLinkList();
	for (int i = 0; i < max_op; i++) {
		int val = rand() % 100;
		int ind = rand() % (l->length + 3) - 1;
		int op = rand() % 4;
		switch (op) {
		case 0:
		case 1: {
			printf("insert %d at %d to List = %d\n", val, ind, insert(l, ind, val));
		} break;
		case 2: {
			printf("erase a iterm at %d from List = %d\n", ind, erase(l, ind));
		} break;
		case 3: {
			printf(GREEN("reverse the list!\n"));
			reverse(l);
		} break;
		}
		output(l), printf("\n");
	}
#undef max_op
	clear(l);
	return 0;
}

//初始化一个结点
ListNode* getNewNode(int val) {
	ListNode* p = (ListNode*)malloc(sizeof(ListNode));
	p->data = val;
	p->next = NULL;
	return p;
}

//初始化链表
List* getLinkList() {
	List* l = (List*)malloc(sizeof(List));
	l->head.next = NULL;
	l->length = 0;
	return l;
}

//插入操作
int insert(List* l, int ind, int val) {
	if (l == NULL) return 0;
	if (ind < 0 || ind > l->length) return 0;
	ListNode* p = &(l->head), * node = getNewNode(val);
	while (ind--) p = p->next;
	node->next = p->next;
	p->next = node;
	l->length += 1;
	return 1;
}

//
int erase(List* l, int ind) {
	if (l == NULL) return 0;
	if (ind < 0 || ind >= l->length) return 0;
	ListNode* p = &(l->head), * q;
	while (ind--) p = p->next;
	q = p->next;
	p->next = q->next;
	free(q);
	l->length -= 1;
	return 1;
}

//
void reverse(List* l) {
	if (l == NULL) return;
	ListNode* p = l->head.next, * q;
	l->head.next = NULL;
	while (p) {
		q = p->next;
		p->next = l->head.next;
		l->head.next = p;
		p = q;
	}
	return;
}

//
void output(List* l) {
	if (l == NULL) return;
	printf("List(%d) = [", l->length);
	for (ListNode* p = l->head.next; p; p = p->next) {
		printf("%d->", p->data);
	}
	printf("NULL]\n");
	return;
}

//销毁操作
void clear_node(ListNode* node) {
	if (node == NULL) return;
	free(node);
	return;
}

//清除整个链表
void clear(List* l) {
	if (l == NULL) return;
	ListNode* p = l->head.next, * q;
	while (p) {
		q = p->next;
		clear_node(p);
		p = q;
	}
	free(l);
	return;
}

