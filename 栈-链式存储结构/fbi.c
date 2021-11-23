//
//  fbi.c
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/16.
//

#include "fbi.h"

int f(int i) {
    if (i < 2) {
        return i;
    }
    return f(i - 1) + f(i - 2);
}

int f2(int i) {
    if (i < 2) {
        return i;
    }
    int j, k, r;
    j = 0;
    k = 1;
    r = 0;
    for (int f = 2; f <= i; f++) {
        r = j + k;
        j = k;
        k = r;
    }
    
    return r;
}

int f3(int i) {
    if (i < 2) {
        return i;
    }
    int a[100] = {0};
    a[0] = 0;
    a[1] = 1;
    for (int k = 2; k <= i; k++) {
        a[k] = a[k-1] + a[k-2];
    }
    return a[i];
}
