
//线性结构：顺序表、链表、栈、队列
//非线性结构：树（一对多）、图（多对一）
//学习内容：顺序表与链表、栈与队列、树与二叉树、排序与查找、堆与优先队列、森林和并查集

//顺序表就是更高级的数组
//数组就是最简单的一类数据结构 

//malloc   分配内存
// void * malloc ( size_t size ) ;

//calloc   分配并清零内存
// void* calloc( size_t num, size_t size );
// num：对象数个数    size：每个对象的大小
// 为num个对象的数组分配内存，并初始化所有分配存储中的字节为零 
// 成功时，返回指向新分配内存的指针。为避免内存泄漏必须用free()或realloc()解分配返回的指针；失败时，返回空指针

//realloc  扩充之前分配的内存块
// void *realloc( void *ptr, size_t new_size );
// ptr：指向需要重新分配的内存区域的指针     new_size：数组的新大小（字节数）
// 成功时，返回指向新分配内存的指针。返回的指针必须用free()或realloc()归还。原指针ptr被非法化
//失败时，返回空指针。原指针ptr保持有效，并需要通过free()或realloc()归还

//free     归还之前分配的内存
//aligned_alloc(C11) 分配对齐的内存


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLOR(a, b) "\033[" #b "m" a "\033[0m"
#define GREEN(a) COLOR(a, 32)
#define RED(a) COLOR(a, 31)
//存储整型元素的顺序表；int重命名Type
typedef int Type;

typedef struct Vector {
	Type* data;  //连续的存储空间
	int size, length;
} Vec;

//顺序表的初始化
Vec* init(int n) {
	//malloc动态开辟空间;通过free释放空间，配合使用
	Vec *v = (Vec *)malloc(sizeof(Vec)); //该顺序表的首地址
	//顺序表中数据区的开辟
	v->data = (Type*)malloc(sizeof(Type) * n);
	v->size = n;
	v->length = 0;
	return v;
}

//顺序表的销毁
void clear(Vec* v) {
	if (v == NULL) return;
	free(v->data);
	free(v);
	return;
}

//顺序表的扩容
int expand(Vec* v) {
	int extr_size = v->size;
	Type* p;
	while (extr_size) {
		p = (Type*)realloc(v->data, sizeof(Type) * (v->size + extr_size));
		if (p != NULL) break;
		extr_size >>= 1;
	}
	if (p == NULL) {
		printf(RED("fail to expand!\n"));
	}
	v->size += extr_size;
	v->data = p;
	printf(GREEN("success to expand! the new size = %d\n"), v->size);
	return 1;
}

//顺序表的插入
int insert(Vec* v, int ind, Type val) {
	if (v == NULL) return 0;
	if (ind < 0 || ind > v->length) return 0;
	if (v->length == v->size) { //存满
		if (!expand(v)) return 0;
	}
	for (int i = v->length; i > ind; i--) {
		v->data[i] = v->data[i - 1];
	}
	v->data[ind] = val;
	v->length += 1;
	return 1;
}

//顺序表的删除
int erase(Vec* v, int ind) {
	if (v == NULL) return 0;
	if (ind < 0 || ind >= v->length) return 0;
	for (int i = ind + 1; i < v->length; i++) {
		v->data[i - 1] = v->data[i];
	}
	v->length -= 1;
	return 1;
}


void output(Vec* v) {
	if (v == NULL) return;
	printf("Vector(%d) : [", v->length);
	for (int i = 0; i < v->length; i++) {
		i&& printf(", ");
		printf("%d", v->data[i]);
	}
	printf("]\n");
	return;
}

int main() {
	#define MAX_N 20
	/*
	Vec* v = init(MAX_N + 5);
	srand(time(0));
	for (int i = 0; i < MAX_N; i++) {
		int op = rand() % 2;
		int ind = rand() % (v->length + 1);
		int val = rand() % 100;
		switch (op) {
			case 0: {
				printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, ind, val));
			} break;
			case 1: {
				printf("erase a iterm at %d from Vector = %d\n", ind, erase(v, ind));
			} break;
		}
		output(v), printf("\n");	
	}
	#undef MAX_N
	clear(v);
	*/
	Vec* v = init(1);
	srand(time(0));
	for (int i = 0; i < MAX_N; i++) {
		int op = rand() % 4;
		int ind = rand() % (v->length + 3) - 1; //随机生成负数或者大于v->length的值
		int val = rand() % 100;
		switch (op) {
		//插入概率增加到75%，删除的概率增加到25%
		case 1:
		case 2:
		case 0: {
			printf("insert %d at %d to Vector = %d\n", val, ind, insert(v, ind, val));
		} break;
		case 3: {
			printf("erase a iterm at %d from Vector = %d\n", ind, erase(v, ind));
		} break;
		}
		output(v), printf("\n");
	}
	#undef MAX_N
	clear(v);
	
	return 0;
}
