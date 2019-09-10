# 数据结构常用算法总结

- [栈](#### 1. 顺序栈)
### 一、线性表

#### 1. 顺序表

1.1 顺序表结构体定义

```c++
#define MAXSIZE 100
typedef int ElemType;
typedef struct {
    ElemType data[MAXSIZE];
    int length;
} SqList;
```

1.2 顺序表的插入

```c++
// 在顺序表L的第i个位置处插入新的元素e
bool ListInsert(SqList *L, int i, ElemType e) {
    if (L->length == MAXSIZE) return false;
    if (i < 1 || i > L->length + 1) return false;
    for (int j = L->length; j >= i; --j) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}
```

1.3 顺序表的删除

```c++
// 删除顺序表L第i个位置上的元素，并赋值给e
bool ListDelete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) return false;
    *e = L->data[i - 1];
    for (int j = i; j < L->length; ++j) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}
```

1.4 获取顺序表指定元素的位置

```c++
// 返回指定元素在顺序表中的位置i
int LocateElem(const SqList *L, ElemType e) {
    for (int i = 0; i < L->length; ++i) {
        if (L->data[i] == e) return i + 1;
    }
    return 0;
}
```



#### 2. 单链表

2.1 单链表结构体定义

```c++
/* 链表(具有头结点) */
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;
```

2.2 单链表的插入

```c++
// 头插法建立单链表，将数组a中元素传入单链表
void ListHeadInsert(LinkList *L, ElemType a[], int n) {
    LNode *s;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    for (int i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        s->next = (*L)->next;
        (*L)->next = s;
    }
}
// 尾插法建立单链表，将数组a中元素传入单链表
void ListTailInsert(LinkList *L, ElemType a[], int n) {
    LNode *s, *r;
    *L = (LinkList)malloc(sizeof(LNode));
    (*L)->next = NULL;
    r = (*L);
    for (int i = 0; i < n; ++i) {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}
// 在第i个结点位置之前插入新的数据元素e
bool ListInsert(LinkList *L, int i, ElemType e) {
    int cnt = 1;
    LNode *p, *s;
    p = *L;
    for (; p != NULL && cnt < i; ++cnt) p = p->next;
    if (p == NULL || i < cnt) return false;
    s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
```

2.3 单链表的删除

```c++
// 删除L的第i个结点，并用e返回
bool ListDelete(LinkList *L, int i, ElemType *e) {
    int cnt = 1;
    LNode *p, *q;
    p = *L;
    for (; p->next != NULL && cnt < i; ++cnt) p = p->next;
    if (p->next == NULL || i < cnt) return false;
    q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
// 清空整个单链表
void ListClear(LinkList *L) {
    LNode *p, *q;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
}
```

2.4 单链表元素的查找

```C++
// 返回第i个元素的结点的指针
LNode *GetElem(LinkList L, int i) {
    LNode *p = L->next;
    if (i < 0) return NULL;
    if (i == 0) return L;
    for (int cnt = 1; p != NULL && cnt < i; ++cnt) p = p->next;
    return p;
}
// 查找单链表中数据等于e的结点指针，否则返回NULL
LNode *LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    while (p != NULL && p->data != e) {
        p = p->next;
    }
    return p;
}
```





### 二、栈

#### 1. 顺序栈

1.1 顺序栈的结构体定义

```c
#define MaxSize 50     // 定义占中最大元素个数
typedef int ElemType;  // 元素种类
typedef struct {
    ElemType data[MaxSize];  // 存放栈中元素
    int top;                 // 栈顶指针（指向数组下标）
} SqStack;
```

1.2 初始化

```c
void StackInit(SqStack *s) { s->top = -1; }
```

1.3 判断栈空

-   函数间的参数传递本质是单向的变量拷贝
-   此处使用指针是为了降低复制大型对象造成的额外负担
-   使用const以防止修改变量

```c
bool StackEmpty(const SqStack *s) {
    if (s->top == -1) {
        return true;
    } else {
        return false;
    }
}
```

1.4 进栈

```c
bool Push(SqStack *s, ElemType e) {
    if (s->top == MaxSize - 1) return false;
    s->data[++s->top] = e;
    return true;
}
```

1.5 出栈

```c
bool Pop(SqStack *s, ElemType *e) {
    if (s->top == -1) return false;
    *e = s->data[s->top--];
    return true;
}
```

1.6 读取栈顶元素

```c
bool GetTop(const SqStack *s, ElemType *e) {
    if (s->top == -1) return false;
    *e = s->data[s->top];
    return true;
}
```



#### 2. 共享栈

2.1 共享栈结构体定义

```c
typedef struct {
    ElemType data[MaxSize];
    int top1;
    int top2;
} SqDoubleStack;
```

2.2 进栈

```c
bool Push(SqDoubleStack *s, ElemType e, int n) {
    if (s->top1 + 1 == s->top2) return false;
    if (n == 1) {
        s->data[++s->top1] = e;
    } else if (n == 2) {
        s->data[--s->top2] = e;
    }
    return true;
}
```

2.3 出栈

```c
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
```

##### 

#### 3. 链栈

3.1 链栈结构体定义

```c
typedef struct StackNode {
    ElemType data;
    struct StackNode *next;
} StackNode, *LinkStackPtr;
```

3.2 进栈

```c
bool Push(LinkStack *s, ElemType e) {
    StackNode *p = (StackNode *)malloc(sizeof(StackNode));
    p->data = e;
    p->next = s->top;
    s->top = p;
    ++s->count;
    return true;
}
```

3.3 出栈

```c
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
```

