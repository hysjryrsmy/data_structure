
//线性表可以分为顺序表和链表
//顺序表是在计算机内存中以数组形式保存的线性表，是指用一组地址连续的存储单元依次存储数据元素的线性结构

//顺序表可以进行随机访问，通常用一维数组实现，可以静态也可以动态分配
//从逻辑上看，线性表中的元素是按顺序依次排列的
// 线性表中所有元素的数据类型都是相同的
// 线性表受空间限制，元素个数是有限的
// 线性表中的元素具有逻辑上的顺序性
// 线性表中所有元素的数据类型都是相同的

//在顺序表中，元素都是一个挨一个存储，元素都集中在一段区间内，相对存储密度大
//顺序表在访问元素时，可以通过表头元素的地址和元素的编号（下标）在O(1)时间内访问到它
//为了保持逻辑上和物理上的连续性，顺序表在插入和删除操作时，会进行大量元素的移动，这会增加操作的时间复杂度
// 顺序表示存储结构，用一组地址连续的存储单元依次存储数据元素。如果两个元素逻辑上是相邻的，则物理位置上也是相邻的
// 顺序表占用的存储空间大小与元素的存储顺序无关，而与存储元素的个数有关 

// 函数
// insert(loc,value) : 将value插入到顺序表中下标为loc的位置 
// 顺序表插入操作的实现方法：判断插入位置是否合法；判断顺序表是否已满；将目标位置及之后的元素后移一位；将待插入的元素值插入到目标位置
//n/2个元素；时间复杂度为O(n)

// expand()          : 扩大顺序表的容量
//顺序表扩容操作的实现方法：将原来的元素存储到临时存储空间；扩大原来的存储空间；降临时存储空间里的数据元素复制到新的存储空间里；释放临时的存储空间
//扩容操作的时间复杂度为O(n)



/*
//顺序表的构造
#include <iostream>
#include <cstring>

template <typename Type> class Vector {
private:
    int size, length; //私有属性；
    //size表示顺序表当前的最大容量
    //length表示当前顺序表中的元素个数
    Type* data;
    //动态分配方法：用来指向存储元素的数组
public:

    //构造函数
    Vector(int input_size) { //表示构造一个容量为input_size的顺序表。
        size = input_size;
        length = 0;
        data = new Type[size]; //将指向存储元素值的空间的指针初始化
        //data指向一段连续size个type的空间
    }

    //new 和 delete尽量要配对使用，否则容易发生内存泄露
    //析构函数
    ~Vector() {
        delete[] data; //delete将data指向的空间回收
    }
};
int main() {
    Vector<int> a(100);
    return 0;
}
*/



/*
//顺序表的插入
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size, length;
    Type* data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, Type value) {
        //loc表示将要插入的位置
        //value表示插入的元素值

        //判断是否可以向顺序表中插入元素
        //判断loc是否合法
        if (loc < 0 || loc > length) {
            //如果传入的参数loc比0小，或者比length大，那么直接返回false
            return false;
        }

        //判断顺序表当前元素的个数是否已经达到容量的上限
        if (length >= size) {
            return false;
        }

        //每次向指定位置loc插入一个元素之前，都要将loc之后的所有元素顺次向后移动，从而给新的元素腾出一个空间
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
};
int main() {
    Vector<int> a(2);
    cout << a.insert(1, 0) << endl;
    cout << a.insert(0, 1) << endl;  
    cout << a.insert(2, 1) << endl;
    cout << a.insert(1, 2) << endl;
    cout << a.insert(0, 3) << endl;
    return 0;
}     
*/



//顺序表的扩容
//扩容：当顺序表已经填满而又需要插入元素时，将顺序表的容量扩大，从而能够继续将元素插入顺序表中。
//通过扩容，顺序表就能够实现动态的容量限制
/*
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size, length;
    Type* data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, Type value) {
        if (loc < 0 || loc > length) {
            return false;
        }
        if (length >= size) {
            //return false;
            expand(); //调用扩容方法
        }
        for (int i = length; i > loc; --i) {  
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    // 请在下面实现扩容方法 expand
    void expand() {
        Type* old_data = data;
        size = size * 2;     //将容量更新为原来的2倍
        data = new Type[size]; //开辟一段新容量大小的连续空间，让data指向他的首地址
        //把元素数据从原来的空间拷贝到新的空间里。
        for (int i = 0; i < length; ++i) {
            data[i] = old_data[i];
            
        }
        delete[] old_data;  //旧的空间回收
    }
};
int main() {
    Vector<int> a(2);
    cout << a.insert(1, 0) << endl;
    cout << a.insert(0, 1) << endl;
    cout << a.insert(2, 1) << endl;
    cout << a.insert(1, 2) << endl;
    cout << a.insert(0, 3) << endl;
    return 0;
}
*/



//顺序表构造、插入、扩容
//输入格式
//第一行输入一个整数 nn（1 \leq n \leq 1001≤n≤100），表示一共有 nn 个插入操作。
//接下来输入 nn 行，每行输入两个整数 pp，qq（0 \leq p, q \leq 1000≤p, q≤100），
//pp 代表元素插入顺序表的位置，qq 代表插入元素的值，之间用一个空格隔开。
//
//输出格式
//输出若干行，对应每一个插入操作。如果一个元素正确插入到顺序表中后，程序输出success，否则输出failed。
//如果插入过程中有执行了扩容操作，程序需要额外输出expand。

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
template <typename Type> class Vector {
private:
    int size, length;
    Type* data;
public:
    Vector(int input_size) {
        size = input_size;
        length = 0;
        data = new Type[size];
    }
    ~Vector() {
        delete[] data;
    }
    bool insert(int loc, Type val) {
        if (loc < 0 || loc > length) return false;
        if (length >= size) {
            expand();
            printf("expand\n");
        };
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = val;
        length++;
        return true;
    }
    void expand() {
        Type* old_data = data;
        size *= 2;
        data = new Type[size];
        for (int i = 0; i < length; i++) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
};
int main() {
    Vector<int> a(5);
    int n, p, q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        if (a.insert(p, q)) cout << "success" << endl;
        else cout << "failed" << endl;
    }
    return 0;
}

//C语言方式
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}Node, *LinkedList;

LinkedList insert(LinkedList head, Node *node, int index) {
    if(head == NULL) {
        if(index != 0) {
            printf("failed\n");
            return head;
        }
        head = node;
        printf("success\n");
        return head;
    }
    if(index == 0) {
        node->next = head;
        head = node;
        printf("success\n");
        return head;
    }
    Node *current_node = head;
    int count = 0;
    while (current_node->next != NULL && count < index - 1) {
        current_node = current_node->next;
        count++;
    }
    if (count == index - 1) {
        node->next = current_node->next;
        current_node->next = node;
        printf("success\n");
    }else{
        printf("failed\n");
    }
    return head;
}

void output(LinkedList head) {
    if(head == NULL){
        return;
    }
    int j = 0;
    Node* current_node = head;
    while(current_node != NULL){
        if(j != 0){
            printf(" ");
        }
        printf("%d", current_node->data);
        current_node = current_node->next;
        j++;
    }
    printf("\n");
}

void clear(LinkedList head) {
    Node *current_node = head;
    while (current_node != NULL) {
        Node *delete_node = current_node;
        current_node = current_node->next;
        free(delete_node);
    }
}

int main() {
    LinkedList linkedlist = NULL;
    int n, p[105], q[105];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d", &p[i], &q[i]);
    }
    for(int i = 0; i < n; i++) {
        Node *node = (Node *)malloc(sizeof(Node));
        node->data = q[i];
        node->next = NULL;
        linkedlist = insert(linkedlist, node, p[i]);
    }
    output(linkedlist);
    clear(linkedlist);
    return 0;
}
*/