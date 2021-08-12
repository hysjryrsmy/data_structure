
//顺序表查找、删除、遍历操作的实现


//顺序表查找：时间复杂度为O(n)
// search(value) : 寻找顺序表中值为value的元素
// 当我们在顺序表中查找某一个元素时，我们会按元素的编号依次查找，如果找到目标元素就返回他的下标，没找到就返回-1
// 实现方法：
// 1.从下标为0的元素开始依次枚举顺序表中的所有元素
// 2.发现和目标值相等的元素则返回他的下标
// 3.枚举结束没有找到目标元素则返回-1


//顺序表删除：时间复杂度为O(n)
//remove(index) : 将顺序表中下标为index的元素移除
// 当把某一个元素从顺序表中移除时，就可以利用删除操作，删除顺序表中指定下标的元素
// 实现方法：
// 1.判断传入的参数是否合法，即下标是否在顺序表的范围内
// 2.将目标下标之后所有的元素前移一位
// 3.更新顺序表的长度


//顺序表遍历：时间复杂度为O(n)
// print()       : 输出顺序表中所有元素
// 遍历操作就是从表头到表尾依次输出顺序表中的所有元素的值
// 实现方法：
// 1.从下标为0的元素开始遍历顺序表
// 2.输出所有元素的值



//1.顺序表的查找
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
            expand();
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        Type* old_data = data;
        size = size * 2;
        data = new Type[size];
        for (int i = 0; i < length; ++i) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
    int search(const Type& value) {//查找方法的定义；引用一个Type类型的参数value，表示待查找的值，返回在顺序表中该值第一次出现的下标
        for(int i = 0; i < length; ++i){ //i：枚举的每一个下标i
            if (data[i] == value)  return i;
        }
        return -1;
    }
};
int main() {
    Vector<int> a(100);
    cout << a.insert(1, 0) << endl;
    cout << a.insert(0, 1) << endl;
    cout << a.insert(2, 1) << endl;
    cout << a.insert(1, 2) << endl;
    cout << a.insert(0, 3) << endl;
    cout << a.search(1) << endl;
    cout << a.search(4) << endl;
    return 0;
}
*/



//2.顺序表的删除
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
            expand();
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        Type* old_data = data;
        size = size * 2;
        data = new Type[size];
        for (int i = 0; i < length; ++i) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
    int search(const Type& value) {
        for (int i = 0; i < length; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    bool remove(int index) { //index:表示要删除的下标
        if (index < 0 || index >= length)  return false;
        for (int i = index + 1; i < length; ++i) { //需要将index后面的所有元素顺次向前移动
            data[i - 1] = data[i];
        }
        length = length - 1;
        return true;
    }
};
int main() {
    Vector<int> a(100);
    cout << a.insert(0, 1) << endl;
    cout << a.insert(0, 2) << endl;
    cout << a.remove(1) << endl;
    cout << a.search(0) << endl;
    cout << a.search(1) << endl;
    return 0;
}
*/



//3.顺序表的遍历
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
            expand();
        }
        for (int i = length; i > loc; --i) {
            data[i] = data[i - 1];
        }
        data[loc] = value;
        length++;
        return true;
    }
    void expand() {
        Type* old_data = data;
        size = size * 2;
        data = new Type[size];
        for (int i = 0; i < length; ++i) {
            data[i] = old_data[i];
        }
        delete[] old_data;
    }
    int search(const Type& value) {
        for (int i = 0; i < length; ++i) {
            if (data[i] == value) {
                return i;
            }
        }
        return -1;
    }
    bool remove(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        for (int i = index + 1; i < length; ++i) {
            data[i - 1] = data[i];
        }
        length = length - 1;
        return true;
    }
    void print() {
        for (int i = 0; i < length; ++i) {
            if (i > 0) {
                cout << " "; //输出每个元素之前的空格
            }
            cout << data[i];
        }
        cout << endl;
    }
};
int main() {
    Vector<int> a(100);
    cout << a.insert(0, 1) << endl;
    cout << a.insert(0, 2) << endl;
    a.print();
    cout << a.remove(1) << endl;
    a.print();
    cout << a.search(0) << endl;
    cout << a.search(1) << endl;
    return 0;
}
*/



//4.顺序表查找、删除、遍历操作的复习

//输入格式
//第一行输入一个正整数 m（1≤m≤100），代表一共有 m 个操作。
//接下来输入 m 行，每行首先输入一个整数 t，分别代表以下操作：
//t = 1，代表插入操作，输入两个整数 a 和 b（ 0≤a, b≤100），表示在 a 的位置上擦入元素 b，如果插入成功输出success，否则输出failed。
//t = 2，代表删除操作，输入一个整数 a（0≤a≤100），删除位置 a 上的元素，如果删除成功输出success，否则输出failed。
//t = 3，代表查找操作，输入一个整数 a（0≤a≤100），查找元素值为 a 的元素，如果查找成功输出success，否则输出failed。
//t = 4，代表遍历操作，输出当前顺序表的所有元素。

//输出格式
//对应每个操作，输出结果。对于前三个操作，如果操作成功输出success，否则输出failed；
//对于第四个操作，从下标为 00 的位置开始输出当前顺序表的所有元素，每两个整数之间一个空格，最后一个整数后面没有空格。



/*
#include <stdio.h>
#include <stdlib.h>

#define ERROR 0
#define OK 1

typedef struct Vector {
    int* data;
    int size, length;
} Vector;

void init(Vector* vector, int size) {
    vector->size = size;
    vector->data = (int*)malloc(sizeof(int) * vector->size);
    vector->length = 0;
}

void expand(Vector* vector) {
    int* old_data = vector->data;
    vector->size = vector->size * 3;
    vector->data = (int*)malloc(sizeof(int) * vector->size);
    free(old_data);
}

int insert(Vector* vector, int loc, int value) {
    int i;
    //判断loc是否合法
    if (loc < 0 || loc > vector->length) {
        printf("failed\n");
        return ERROR;
    }

    //判断是否需要扩容
    if (vector->length >= vector->size) {
        expand(vector);
    }

    //判断是不是要插入到表尾
    if (vector->length == loc) {
        //是表尾直接插入
        vector->data[loc] = value;
        vector->length++;
        printf("success\n");
        return OK;
    }
    else {
        //不是表尾则需移动
        for (i = vector->length - 1; i >= loc; i--) {
            vector->data[i + 1] = vector->data[i];
        }
        vector->data[loc] = value;
        vector->length++;
        printf("success\n");
        return OK;
    }
}

int search(Vector* vector, int value) {
    for (int i = 0; i < vector->length; i++)
        if (vector->data[i] == value)
            return i;
    return ERROR;
}

int delete_node(Vector* vector, int index) {
    int i;
    //判断index是否合法
    if (index >= vector->length || index < 0) {
        printf("failed\n");
        return ERROR;
    }

    //判断是不是要删除最后一个结点
    if (index == vector->length - 1) {
        //是，直接删
        vector->length--;
        printf("success\n");
        return OK;
    }
    else {
        //不是，则需要移动
        for (i = index + 1; i < vector->length; i++) {
            vector->data[i - 1] = vector->data[i];
        }
        vector->length--;
        printf("success\n");
        return OK;
    }
}

void print(Vector* vector) {
    for (int i = 0; i < vector->length; i++) {
        printf("%d", vector->data[i]);
        if (i != vector->length - 1)
            printf(" ");
    }
}

void clear(Vector* vector) {
    vector->length = 0;
    free(vector->data);
    free(vector);
}

int main() {
    Vector* a = (Vector*)malloc(sizeof(Vector));
    init(a, 20);
    int m, i;
    int t, loc, value;
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%d", &t);
        switch (t) {
        case 1:
            scanf("%d%d", &loc, &value);
            insert(a, loc, value);
            break;
        case 2:
            scanf("%d", &loc);
            delete_node(a, loc);
            break;
        case 3:
            scanf("%d", &value);
            search(a, value);
            break;
        case 4:
            print(a);
            break;
        default:
            return ERROR;
        }
    }
    clear(a);
    return 0;
}
*/