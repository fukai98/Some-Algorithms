#include <iostream>
using namespace std;

typedef int ElemType;
#define MAXSIZE 100
// 交换函数
void swap(ElemType *a, ElemType *b) {
    ElemType temp = *a;
    *a = *b;
    *b = temp;
}

/* 基于插入的排序 */
// 直接插入排序
void InsertSort(ElemType a[], int len) {
    int i, j;
    ElemType temp;
    for (i = 1; i < len; ++i) {
        if (a[i - 1] > a[i]) {
            temp = a[i];
            for (j = i - 1; a[j] > temp && j >= 0; --j) {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}
// 希尔排序
int Incre[10] = {63,31,15,7, 3, 1};
void ShellSort(ElemType a[], int len, int incre[], int in_len) {
    int i, j, k, increment;
    ElemType temp;
    for (i = 0; i < in_len; ++i) {
        increment = incre[i];
        for (j = increment; j < len; ++j) {
            if (a[j] < a[j - increment]) {
                temp = a[j];
                for (k = j - increment; a[k] > temp && k >= 0; k -= increment) {
                    a[k + increment] = a[k];
                }
                a[k + increment] = temp;
            }
        }
    }
}
/* 基于交换的排序 */
// 冒泡排序
void BubbleSort(ElemType a[], int len) {
    bool flag = true;  // 用于标记，若flag为假，则顺序表已经全部有序，无需进行之后的排序操作
    for (int i = 0; i < len - 1 && flag == true; ++i) {
        flag = false;
        for (int j = len - 1; j > i; --j) {
            if (a[j - 1] > a[j]) {
                swap(&a[j - 1], &a[j]);
                flag = true;
            }
        }
    }
}
/* 基于选择的排序 */
// 简单选择排序
void SelectSort(ElemType a[], int len) {
    for (int i = 0, min = 0; i < len - 1; ++i) {
        min = i;
        for (int j = i + 1; j < len; ++j) {
            if (a[min] > a[j]) min = j;
        }
        if (min != i) swap(&a[i], &a[min]);
    }
}
/* 其他排序方法 */

int main() {
    ElemType a[MAXSIZE];
    cout << "原始数据：";
    for (int i = 0; i < MAXSIZE; ++i) {
        a[i] = MAXSIZE - i;
        cout << a[i] << " ";
    }
    cout << endl << "排序后数据：";
    // BubbleSort(a, MAXSIZE);
    // SelectSort(a, MAXSIZE);
    // InsertSort(a, MAXSIZE);
    ShellSort(a, MAXSIZE, Incre, 6);
    for (int i = 0; i < MAXSIZE; ++i) {
        cout << a[i] << " ";
    }
}
