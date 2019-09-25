## 排序篇

-   内部排序
    -   插入排序
        -   直接插入排序
        -   折半插入排序
        -   希尔排序
    -   交换排序
        -   冒泡排序
        -   快速排序
    -   选择排序
        -   简单选择排序
        -   堆排序
    -   归并排序
    -   基数排序
-   外部排序

### 一、插入排序

#### 1. 直接插入排序

```c
void InsertSort(ElemType a[], int len) {
    int i, j;
    ElemType temp;
    for (i = 1; i < len; ++i) {  // a[0]为有序序列，所以i从1开始
        if (a[i - 1] > a[i]) {
            temp = a[i];
            for (j = i - 1; a[j] > temp && j >= 0; --j) {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}
```

#### 2. 则版