//
//  match.c
//  栈-链式存储结构
//
//  Created by 小红李 on 2021/11/16.
//

#include "match.h"
#include "stack.h"

bool match(char *c) {
    if (c == NULL) {
        return false;
    }
    LinkStack *s;
    char e;
    s = (LinkStack *)malloc(sizeof(LinkStack));
    s->count = 0;
    s->top = NULL;
    while (*c) {
        if ('{' == *c || '(' == *c) {
            push(s, *c);
        } else if ('}' == *c) {
            pop(s, &e);
            if ('{' != e) {
                return false;
            }
        } else if (')' == *c) {
            pop(s, &e);
            if ('(' != e) {
                return false;
            }
        }
        c++;
    }
    return true;
}
