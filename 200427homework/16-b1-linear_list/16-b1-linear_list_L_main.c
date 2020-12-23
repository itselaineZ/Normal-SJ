/*1952339 信08 张馨月*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "./16-b1-linear_list_L.h"

#define INSERT_NUM		115		//初始插入表中的元素数量
#define MAX_NUM_PER_LINE 	10		//每行最多输出的元素个数


int line_count = 0;   //打印链表时的计数器

/* 用于比较两个值是否相等的具体函数，与LocateElem中的函数指针定义相同，调用时代入
   int LocateElem(sqlist L, ElemType e, Status (*compare)(ElemType e1, ElemType e2)) */
Status MyCompare(ElemType e1, ElemType e2)
{
#if defined (ELEMENT_TYPE_IS_CHAR_P) || defined (ELEMENT_TYPE_IS_CHAR_ARRAY)
    if(strcmp(e1, e2) == 0)
#elif defined ELEMENT_TYPE_IS_STUDENT
    if(e1.num == e2.num)
#elif defined ELEMENT_TYPE_IS_STUDENT_P
    if(e1->num == e2->num)
#else
    if (e1 == e2)
#endif
        return TRUE;
    else
        return FALSE;
}

/* 用于访问某个元素的值的具体函数，与ListTraverse中的函数指针定义相同，调用时代入
   Status ListTraverse(sqlist L, Status (*visit)(ElemType e)) */
Status MyVisit(ElemType e)
{
//#ifdef ELEMENT_TYPE_IS_CHAR_ARRAY || defined ELEMENT_TYPE_IS_CHAR_P
#if defined (ELEMENT_TYPE_IS_CHAR_P) || defined (ELEMENT_TYPE_IS_CHAR_ARRAY)
    printf("%s->", e);
#elif defined ELEMENT_TYPE_IS_DOUBLE
    printf("%lf->", e);
#elif defined ELEMENT_TYPE_IS_STUDENT
    printf("%d->", e.num);
#elif defined ELEMENT_TYPE_IS_STUDENT_P
    printf("%d->", e->num);
#else
    printf("%3d->", e);
#endif

    /* 每输出MAX_NUM_PER_LINE个，打印一个换行 */
    if ((++line_count) % MAX_NUM_PER_LINE == 0)
        printf("\n");

    return OK;
}


void fillin(char* s)
{
    for (int i = 0; i < 9; ++i)
        s[i] = 'A' + rand() % 26;
    s[9] = 0;
}

int main()
{
#if defined (ELEMENT_TYPE_IS_CHAR_ARRAY) || defined (ELEMENT_TYPE_IS_CHAR_P)
    LinkList L;
    char s1[10], s2[10];//对于以上两个类型此处要做相应修改
    ElemType e1 = s1, e2 = s2;
    int      i, pos;

    InitList(&L);

    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n\n", ListLength(L));

    printf("插入%d个元素：\n", INSERT_NUM);
    srand(0);
    for (i = INSERT_NUM * 2; i > 0; i -= 2) {
        char s[20];
        fillin(s);
        ListInsert(&L, 1, s);
    }
    ListTraverse(L, MyVisit);//此处传入MyVisit函数名

    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n\n", ListLength(L));

    /* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
       最后再加一个任意输入值 */
    for (i = 0; i < 5; i++) {
        int pos;
        switch (i) {
            case 0:
                pos = 1;
                break;
            case 1:
                pos = ListLength(L);
                break;
            case 2:
                pos = -1;
                break;
            case 3:
                pos = ListLength(L) + 1;
                break;
            case 4:
                printf("请输入要取元素的位序[1..%d]：", ListLength(L));
                scanf("%d", &pos);
                break;
        }

        /* 取第1个元素以及前驱、后继 */
        if (GetElem(L, pos, &e1) == OK) {
            printf("第%d个元素=%s\n", pos, e1);

            /* 只有取得了某个元素，才能取前驱和后继 */
            if (PriorElem(L, e1, &e2) == OK)
                printf("第%d个元素(%s)的前驱=%s\n", pos, e1, e2);
            else
                printf("无法取得第%d个元素(%s)的前驱\n", pos, e1);

            if (NextElem(L, e1, &e2) == OK)
                printf("第%d个元素(%s)的后继=%s\n\n", pos, e1, e2);
            else
                printf("无法取得第%d个元素(%s)的后继\n\n", pos, e1);
        }
        else
            printf("无法取得第%d个元素\n\n", pos);
    } // end of for

    printf("请输入要查找的元素：\n");
    scanf("%s", e1);
    if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //此处传入MyCompare函数名
        printf("元素%s的位序=%d\n", e1, pos);
    else
        printf("找不到元素%s\n", e1);

    printf("\n请输入要插入元素的值：\n");
    scanf("%s", e1);
    printf("请输入要插入元素的位序：\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1) == OK) {
        printf("在%d前插入元素%s成功\n", pos, e1);
        printf("新表为：\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("在%d前插入元素%s失败\n", pos, e1);

    printf("\n请输入要删除元素的位序：\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1) == OK) {
        printf("删除第%d个元素=%s成功\n", pos, e1);
        printf("新表为：\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("删除第%d个元素失败\n", pos);

    printf("\n清空表：\n");
    ClearList(&L);
    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n", ListLength(L));

    DestroyList(&L);

#elif defined ELEMENT_TYPE_IS_STUDENT
    LinkList L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n\n", ListLength(L));

printf("插入%d个元素：\n", INSERT_NUM);
srand(0);
for (i = INSERT_NUM * 2; i > 0; i -= 2) {
    ElemType s;
    s.num = rand();
    ListInsert(&L, 1, s);
}
ListTraverse(L, MyVisit);//此处传入MyVisit函数名

printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n\n", ListLength(L));

/* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
   最后再加一个任意输入值 */
for (i = 0; i < 5; i++) {
    int pos;
    switch (i) {
        case 0:
            pos = 1;
            break;
        case 1:
            pos = ListLength(L);
            break;
        case 2:
            pos = -1;
            break;
        case 3:
            pos = ListLength(L) + 1;
            break;
        case 4:
            printf("请输入要取元素的位序[1..%d]：", ListLength(L));
            scanf("%d", &pos);
            break;
    }

    /* 取第1个元素以及前驱、后继 */
    if (GetElem(L, pos, &e1) == OK) {
        printf("第%d个元素=%d\n", pos, e1.num);

        /* 只有取得了某个元素，才能取前驱和后继 */
        if (PriorElem(L, e1, &e2) == OK)
            printf("第%d个元素(%d)的前驱=%d\n", pos, e1.num, e2.num);
        else
            printf("无法取得第%d个元素(%d)的前驱\n", pos, e1.num);

        if (NextElem(L, e1, &e2) == OK)
            printf("第%d个元素(%d)的后继=%d\n\n", pos, e1.num, e2.num);
        else
            printf("无法取得第%d个元素(%d)的后继\n\n", pos, e1.num);
    }
    else
        printf("无法取得第%d个元素\n\n", pos);
} // end of for

printf("请输入要查找的元素：\n");
scanf("%d", &e1.num);
if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //此处传入MyCompare函数名
printf("元素%d的位序=%d\n", e1.num, pos);
else
printf("找不到元素%d\n", e1.num);

printf("\n请输入要插入元素的值：\n");
scanf("%d", &e1.num);
printf("请输入要插入元素的位序：\n");
scanf("%d", &pos);
if (ListInsert(&L, pos, e1) == OK) {
    printf("在%d前插入元素%d成功\n", pos, e1.num);
    printf("新表为：\n");
    ListTraverse(L, MyVisit);
}
else
printf("在%d前插入元素%d失败\n", pos, e1.num);

printf("\n请输入要删除元素的位序：\n");
scanf("%d", &pos);
if (ListDelete(&L, pos, &e1) == OK) {
    printf("删除第%d个元素=%d成功\n", pos, e1.num);
    printf("新表为：\n");
    ListTraverse(L, MyVisit);
}
else
printf("删除第%d个元素失败\n", pos);

printf("\n清空表：\n");
ClearList(&L);
printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n", ListLength(L));

DestroyList(&L);
#elif defined ELEMENT_TYPE_IS_STUDENT_P
LinkList L;
ET a, b;
ElemType e1 = &a, e2 = &b;
int      i, pos;

InitList(&L);

printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n\n", ListLength(L));

printf("插入%d个元素：\n", INSERT_NUM);
srand(0);
for (i = INSERT_NUM * 2; i > 0; i -= 2) {
    ET s;
    s.num = rand();
    ListInsert(&L, 1, &s);
}
ListTraverse(L, MyVisit);//此处传入MyVisit函数名

printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n\n", ListLength(L));

/* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
   最后再加一个任意输入值 */
for (i = 0; i < 5; i++) {
    int pos;
    switch (i) {
        case 0:
            pos = 1;
            break;
        case 1:
            pos = ListLength(L);
            break;
        case 2:
            pos = -1;
            break;
        case 3:
            pos = ListLength(L) + 1;
            break;
        case 4:
            printf("请输入要取元素的位序[1..%d]：", ListLength(L));
            scanf("%d", &pos);
            break;
    }

    /* 取第1个元素以及前驱、后继 */
    if (GetElem(L, pos, &e1) == OK) {
        printf("第%d个元素=%d\n", pos, e1->num);

        /* 只有取得了某个元素，才能取前驱和后继 */
        if (PriorElem(L, e1, &e2) == OK)
            printf("第%d个元素(%d)的前驱=%d\n", pos, e1->num, e2->num);
        else
            printf("无法取得第%d个元素(%d)的前驱\n", pos, e1->num);

        if (NextElem(L, e1, &e2) == OK)
            printf("第%d个元素(%d)的后继=%d\n\n", pos, e1->num, e2->num);
        else
            printf("无法取得第%d个元素(%d)的后继\n\n", pos, e1->num);
    }
    else
        printf("无法取得第%d个元素\n\n", pos);
} // end of for

printf("请输入要查找的元素：\n");
scanf("%d", &e1->num);
if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //此处传入MyCompare函数名
printf("元素%d的位序=%d\n", e1->num, pos);
else
printf("找不到元素%d\n", e1->num);

printf("\n请输入要插入元素的值：\n");
scanf("%d", &e1->num);
printf("请输入要插入元素的位序：\n");
scanf("%d", &pos);
if (ListInsert(&L, pos, e1) == OK) {
    printf("在%d前插入元素%d成功\n", pos, e1->num);
    printf("新表为：\n");
    ListTraverse(L, MyVisit);
}
else
printf("在%d前插入元素%d失败\n", pos, e1->num);

printf("\n请输入要删除元素的位序：\n");
scanf("%d", &pos);
if (ListDelete(&L, pos, &e1) == OK) {
    printf("删除第%d个元素=%d成功\n", pos, e1->num);
    printf("新表为：\n");
    ListTraverse(L, MyVisit);
}
else
printf("删除第%d个元素失败\n", pos);

printf("\n清空表：\n");
ClearList(&L);
printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("表长=%d\n", ListLength(L));

DestroyList(&L);
#else
    LinkList L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n\n", ListLength(L));

    printf("插入%d个元素：\n", INSERT_NUM);
    for (i = INSERT_NUM * 2; i > 0; i -= 2)
        ListInsert(&L, 1, i);
    ListTraverse(L, MyVisit);//此处传入MyVisit函数名

    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n\n", ListLength(L));

    /* 分别取第1、最后、以及小于第1、大于最后的4种情况下的的元素值、前驱值、后继值
       最后再加一个任意输入值 */
    for (i = 0; i < 5; i++) {
        int pos;
        switch (i) {
            case 0:
                pos = 1;
                break;
            case 1:
                pos = ListLength(L);
                break;
            case 2:
                pos = -1;
                break;
            case 3:
                pos = ListLength(L) + 1;
                break;
            case 4:
                printf("请输入要取元素的位序[1..%d]：", ListLength(L));
                scanf("%d", &pos);
                break;
        }

        /* 取第1个元素以及前驱、后继 */
        if (GetElem(L, pos, &e1) == OK) {
            printf("第%d个元素=%d\n", pos, e1);

            /* 只有取得了某个元素，才能取前驱和后继 */
            if (PriorElem(L, e1, &e2) == OK)
                printf("第%d个元素(%d)的前驱=%d\n", pos, e1, e2);
            else
                printf("无法取得第%d个元素(%d)的前驱\n", pos, e1);

            if (NextElem(L, e1, &e2) == OK)
                printf("第%d个元素(%d)的后继=%d\n\n", pos, e1, e2);
            else
                printf("无法取得第%d个元素(%d)的后继\n\n", pos, e1);
        }
        else
            printf("无法取得第%d个元素\n\n", pos);
    } // end of for

    printf("请输入要查找的元素：\n");
    scanf("%d", &e1);
    if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //此处传入MyCompare函数名
        printf("元素%d的位序=%d\n", e1, pos);
    else
        printf("找不到元素%d\n", e1);

    printf("\n请输入要插入元素的值：\n");
    scanf("%d", &e1);
    printf("请输入要插入元素的位序：\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1) == OK) {
        printf("在%d前插入元素%d成功\n", pos, e1);
        printf("新表为：\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("在%d前插入元素%d失败\n", pos, e1);

    printf("\n请输入要删除元素的位序：\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1) == OK) {
        printf("删除第%d个元素=%d成功\n", pos, e1);
        printf("新表为：\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("删除第%d个元素失败\n", pos);

    printf("\n清空表：\n");
    ClearList(&L);
    printf("空表=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("表长=%d\n", ListLength(L));

    DestroyList(&L);
#endif

    return 0;
}
