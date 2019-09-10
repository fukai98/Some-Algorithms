/*
 数据结构常用算法总结
 栈
*/
#include <stdlib.h>
#include <iostream>
using namespace std;

/* 顺序栈 */
// 顺序栈结构体定义
#define MaxSize 50     // 定义占中最大元素个数
typedef int ElemType;  // 元素种类
typedef struct {
    ElemType data[MaxSize];  // 存放栈中元素
    int top;                 // 栈顶指针（指向数组下标）
} SqStack;
// 初始化
void StackInit(SqStack *s) { s->top = -1; }
// 判断空
bool StackEmpty(const SqStack *s) {
    if (s->top == -1) {
        return true;
    } else {
        return false;
    }
}
// 进栈
bool Push(SqStack *s, ElemType e) {
    if (s->top == MaxSize - 1) return false;
    s->data[++s->top] = e;
    return true;
}
// 出栈
bool Pop(SqStack *s, ElemType *e) {
    if (s->top == -1) return false;
    *e = s->data[s->top--];
    return true;
}
// 读取栈顶元素
bool GetTop(const SqStack *s, ElemType *e) {
    if (s->top == -1) return false;
    *e = s->data[s->top];
    return true;
}

/* 共享栈 */
typedef struct {
    ElemType data[MaxSize];
    int top1;
    int top2;
} SqDoubleStack;
// 进栈
bool Push(SqDoubleStack *s, ElemType e, int n) {
    if (s->top1 + 1 == s->top2) return false;
    if (n == 1) {
        s->data[++s->top1] = e;
    } else if (n == 2) {
        s->data[--s->top2] = e;
    }
    return true;
}
// 出栈
bool Pop(SqDoubleStack *s, ElemType *e, int n) {
    if (n == 1) {
        if (s->top1 == -1) return false;
        *e = s->data[s->top1--];
    } else if (n == 2) {
        if (s->top2 == MaxSize) return false;
        *e = s->data[s->top2++];
    }
    return true;
}

/* 链栈 */
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;
// 进栈（类似于链表头插法）
bool Push(LinkStack *s, ElemType e) {
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    ++s->count;
    return true;
}
// 出栈
bool Pop(LinkStack *s, ElemType *e) {
    StackNode *p;
    if (s->top == NULL) return false;
    *e = s->top->data;
    p = s->top;
    s->top = p->next;
    free(p);
    --s->count;
    return true;
}
