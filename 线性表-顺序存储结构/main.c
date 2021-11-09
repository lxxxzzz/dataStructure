//
//  main.c
//  线性表-顺序存储结构
//
//  Created by 小红李 on 2021/11/9.
//

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int lenght;
}SqlList;

Status get_elem(SqlList list, int i, ElemType *e) {
    if (list.lenght == 0)
        return ERROR;
    
    if (i < 1 || i > list.lenght)
        return ERROR;
    
    *e = list.data[i - 1];
    return OK;
}


/**
 思路：
 1、线性表满了抛出异常。
 2、插入位置不合理抛出异常。
 3、从数组最后一个元素向前遍历到第i个位置，分别将它们向后移动一个位置
 4、将要插入的元素填入i处
 5、表长加1
 */
Status list_insert(SqlList *list, int i, ElemType e) {
    if (list->lenght == MAXSIZE)
        // 1、已经满了
        return ERROR;
    
    if (i < 1 || i > list->lenght + 1)
        // 2、插入点不合理
        return ERROR;
    
    if (i <= list->lenght) {
        // 插入的数据位置不在表尾
        for (int j=list->lenght - 1; j>=i-1; j--) {
            // 3
            list->data[j+1] = list->data[j];
        }
    }
    
    // 4
    list->data[i-1] = e;
    // 5
    list->lenght++;
    
    return OK;
}

/**
 思路：
 1、检查是否是空表
 2、检查i的位置是否合法
 3、从i处开始遍历，将元素挨个往前移动一位
 4、表长减1
 */
Status list_delete(SqlList *list, int i, ElemType *e) {
    if (list->lenght == 0)
        return ERROR;
    
    if (i < 1 || i > list->lenght)
        return ERROR;
    
    *e = list->data[i-1];
    
    if (i <= list->lenght) {
        for (int k=i; k<list->lenght; k++) {
            list->data[k-1] = list->data[k];
        }
    }
    
    list->lenght--;
    
    return OK;
}

int main(int argc, const char * argv[]) {
    SqlList *list = (SqlList *)malloc(sizeof(SqlList) * MAXSIZE);
    list->lenght = 0;
    
    // 1、插入
    for (int i=1; i<=10; i++) {
        list_insert(list, i, i);
    }
    
    ElemType e;
    get_elem(*list, 3, &e);
    printf("%d\n", e);
    
    list_delete(list, 3, &e);
    
    return 0;
}
