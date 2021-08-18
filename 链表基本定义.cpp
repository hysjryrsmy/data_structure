
//链表特点：元素之间前后依赖，串联而成；链表的元素不能随机访问；元素前面和后面不会出现多个元素相连的情况；一般只有一个表头

//链表的构造、插入、遍历、删除、反转


//链表的插入：时间复杂度为O(n)
//insert(node,index) : 将node插入到链表中下标为index的位置
//实现方法：
// 1.找到链表中要插入的位置
// 2.令待插入结点的next指针指向插入位置的当前结点
// 3.令插入位置之前的当前结点的next指针指向待插入结点


//链表的遍历：时间复杂度O(n)
//从头结点开始通过当前结点的指针找到下一节点直至表尾，并输出所有结点的值  
//output() : 输出整个链表
//实现方法：
// 1.定义一个用于遍历的变量，初始指向头结点
// 2.输出遍历变量所在结点的值，并更新遍历变量为当前结点的下一个结点
// 3.重复操作 2，直到遍历完所有结点



/*
#include<iostream>
// 请在下面实现结点类 Node
template<typename Type> class Node {
    //创建链表的元素
public:
    Type data;   //数据域
    Node<Type>* next; //指针域
   //构造函数
    Node(const Type& _data) {
        //链表结点的定义
        data = _data;
        next = NULL;
    }
};

// 请在下面实现链表类 LinkedList
template<typename Type> class LinkedList {
private:
    Node<Type>* head;
    //构造函数
public:
    LinkedList() {
        head = NULL;
    }
    //析构函数
    ~LinkedList() {
        //删除整个链表
        Node<Type>* current_node = head;
        //循环遍历整个链表
        while (current_node != NULL) {
            Node<Type>* delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
};

int main() {
    LinkedList<int> linkedlist;
    return 0;
}
*/




//链表的插入
/*
#include<iostream>
template <typename Type> class Node {
public:
    Type data;
    Node<Type>* next;
    Node(const Type& _data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type>* head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type>* current_node = head;
        while (current_node != NULL) {
            Node<Type>* delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    // 请在下面实现插入方法 insert
    //Node<Type> *node：表示要插入的结点
    //int index：表示插入结点后，这个结点是第index个结点
    void insert(Node<Type>* node, int index) {
        if (head == NULL) { //头指针为空指针，即链表为空
            if (index != 0) {
                return;
            }
            head = node;
            return;
        }
        if (index == 0) { //结点插入后是链表首位
            node->next = head;
            head = node;
            return;
        }
        Node<Type>* current_node = head;
        int count = 0;
        //寻找目标位置的前一个位置
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next; //指向下一个结点
            count++;
        }
        if (count == index - 1) {
            //新结点node的指针指向目标位置的后一个位置
            node->next = current_node->next;
            //目标位置的前一个结点指向新结点
            current_node->next = node;
        }
    }
};
int main() {
    LinkedList<int> linkedlist;
    for (int i = 1; i <= 10; i++) {
        Node<int>* node = new Node<int>(i);
        linkedlist.insert(node, i - 1);
    }
    return 0;
}
*/



//如何遍历链表，将链表的元素从头到尾依次输出
/*
#include<iostream>
using std::cout;
using std::endl;
template <typename Type> class Node {
public:
    Type data;
    Node<Type>* next;
    Node(const Type& _data) {
        data = _data;
        next = NULL;
    }
};
template <typename Type> class LinkedList {
private:
    Node<Type>* head;
public:
    LinkedList() {
        head = NULL;
    }
    ~LinkedList() {
        Node<Type>* current_node = head;
        while (current_node != NULL) {
            Node<Type>* delete_node = current_node;
            current_node = current_node->next;
            delete delete_node;
        }
    }
    void insert(Node<Type>* node, int index) {
        if (head == NULL) {
            if (index != 0) {
                return;
            }
            head = node;
            return;
        }
        if (index == 0) {
            node->next = head;
            head = node;
            return;
        }
        Node<Type>* current_node = head;
        int count = 0;
        while (current_node->next != NULL && count < index - 1) {
            current_node = current_node->next;
            count++;
        }
        if (count == index - 1) {
            node->next = current_node->next;
            current_node->next = node;
        }
    }
    // 请在下面实现输出方法 output
    void output() {
        //判断链表是否为空
        if (head == NULL) {
            return;
        }
        Node<Type>* current_node = head;
        //遍历链表
        while (current_node != NULL) { //满足的条件，current_node指针不能为空
            //输出结点的数据域
            cout << current_node->data << " ";
            current_node = current_node->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList<int> linkedlist;
    for (int i = 1; i <= 10; i++) {
        Node<int>* node = new Node<int>(i);
        linkedlist.insert(node, i - 1);
    }
    //输出创建的链表
    linkedlist.output();
    return 0;
}
*/


//链表创建、插入、遍历操作的复习
//输入格式
//第一行输入是一个整数 n（1≤n≤100），表示一共要执行 n 次插入操作。
//接下来输入 n 行，每行输入两个整数 p 和 q（0≤p, q≤100），
//其中 p 表示结点插入链表中的位置（从下标为 0 开始），q 表示插入元素的值，两个整数之间用一个空格隔开。

//输出格式
//输出一共 n + 1 行。前 n 行对应每次插入操作，一行一个结果，如果一个元素成功插入到了链表中，
//请输出success，如果插入失败则输出failed。
//第 n + 1 行输出最后的链表，每两个整数之间用一个空格隔开，行末不需要多余的空格。

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node, * LinkedList;

LinkedList insert(LinkedList head, Node* node, int index) {
    if (head == NULL) {
        if (index != 0) {
            printf("failed\n");
            return NULL;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if (index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node* current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
        return head;
    }
    return NULL;
}

void output(LinkedList head) {
    if (head = NULL) return;
    Node* current_node = head;
    while (current_node != NULL) {
        printf("%d ", current_node->data);
        current_node = current_node->next;
    } // printf("%d\n", current_node->data);
    printf("\n");
}

void clear(LinkedList head) {
    if (head->next == NULL) {
        return;
    }
    Node* current_node = head;
    while (current_node != NULL) {
        Node* delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n, p, q;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &p, &q);
        Node* node = (Node*)malloc(sizeof(Node));
        node->data = q;
        node->next = NULL;
        if (insert(linkedlist, node, p) != NULL) {
            linkedlist = insert(linkedlist, node, p);
            continue;
        }
        free(node);
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}