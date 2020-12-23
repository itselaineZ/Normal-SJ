/*1952339 ��08 ��ܰ��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "./16-b1-linear_list_L.h"

#define INSERT_NUM		115		//��ʼ������е�Ԫ������
#define MAX_NUM_PER_LINE 	10		//ÿ����������Ԫ�ظ���


int line_count = 0;   //��ӡ����ʱ�ļ�����

/* ���ڱȽ�����ֵ�Ƿ���ȵľ��庯������LocateElem�еĺ���ָ�붨����ͬ������ʱ����
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

/* ���ڷ���ĳ��Ԫ�ص�ֵ�ľ��庯������ListTraverse�еĺ���ָ�붨����ͬ������ʱ����
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

    /* ÿ���MAX_NUM_PER_LINE������ӡһ������ */
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
    char s1[10], s2[10];//���������������ʹ˴�Ҫ����Ӧ�޸�
    ElemType e1 = s1, e2 = s2;
    int      i, pos;

    InitList(&L);

    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n\n", ListLength(L));

    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    srand(0);
    for (i = INSERT_NUM * 2; i > 0; i -= 2) {
        char s[20];
        fillin(s);
        ListInsert(&L, 1, s);
    }
    ListTraverse(L, MyVisit);//�˴�����MyVisit������

    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n\n", ListLength(L));

    /* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
       ����ټ�һ����������ֵ */
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
                printf("������ҪȡԪ�ص�λ��[1..%d]��", ListLength(L));
                scanf("%d", &pos);
                break;
        }

        /* ȡ��1��Ԫ���Լ�ǰ������� */
        if (GetElem(L, pos, &e1) == OK) {
            printf("��%d��Ԫ��=%s\n", pos, e1);

            /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
            if (PriorElem(L, e1, &e2) == OK)
                printf("��%d��Ԫ��(%s)��ǰ��=%s\n", pos, e1, e2);
            else
                printf("�޷�ȡ�õ�%d��Ԫ��(%s)��ǰ��\n", pos, e1);

            if (NextElem(L, e1, &e2) == OK)
                printf("��%d��Ԫ��(%s)�ĺ��=%s\n\n", pos, e1, e2);
            else
                printf("�޷�ȡ�õ�%d��Ԫ��(%s)�ĺ��\n\n", pos, e1);
        }
        else
            printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
    } // end of for

    printf("������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%s", e1);
    if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //�˴�����MyCompare������
        printf("Ԫ��%s��λ��=%d\n", e1, pos);
    else
        printf("�Ҳ���Ԫ��%s\n", e1);

    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%s", e1);
    printf("������Ҫ����Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1) == OK) {
        printf("��%dǰ����Ԫ��%s�ɹ�\n", pos, e1);
        printf("�±�Ϊ��\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("��%dǰ����Ԫ��%sʧ��\n", pos, e1);

    printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1) == OK) {
        printf("ɾ����%d��Ԫ��=%s�ɹ�\n", pos, e1);
        printf("�±�Ϊ��\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("ɾ����%d��Ԫ��ʧ��\n", pos);

    printf("\n��ձ�\n");
    ClearList(&L);
    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n", ListLength(L));

    DestroyList(&L);

#elif defined ELEMENT_TYPE_IS_STUDENT
    LinkList L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n\n", ListLength(L));

printf("����%d��Ԫ�أ�\n", INSERT_NUM);
srand(0);
for (i = INSERT_NUM * 2; i > 0; i -= 2) {
    ElemType s;
    s.num = rand();
    ListInsert(&L, 1, s);
}
ListTraverse(L, MyVisit);//�˴�����MyVisit������

printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n\n", ListLength(L));

/* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
   ����ټ�һ����������ֵ */
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
            printf("������ҪȡԪ�ص�λ��[1..%d]��", ListLength(L));
            scanf("%d", &pos);
            break;
    }

    /* ȡ��1��Ԫ���Լ�ǰ������� */
    if (GetElem(L, pos, &e1) == OK) {
        printf("��%d��Ԫ��=%d\n", pos, e1.num);

        /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
        if (PriorElem(L, e1, &e2) == OK)
            printf("��%d��Ԫ��(%d)��ǰ��=%d\n", pos, e1.num, e2.num);
        else
            printf("�޷�ȡ�õ�%d��Ԫ��(%d)��ǰ��\n", pos, e1.num);

        if (NextElem(L, e1, &e2) == OK)
            printf("��%d��Ԫ��(%d)�ĺ��=%d\n\n", pos, e1.num, e2.num);
        else
            printf("�޷�ȡ�õ�%d��Ԫ��(%d)�ĺ��\n\n", pos, e1.num);
    }
    else
        printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
} // end of for

printf("������Ҫ���ҵ�Ԫ�أ�\n");
scanf("%d", &e1.num);
if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //�˴�����MyCompare������
printf("Ԫ��%d��λ��=%d\n", e1.num, pos);
else
printf("�Ҳ���Ԫ��%d\n", e1.num);

printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
scanf("%d", &e1.num);
printf("������Ҫ����Ԫ�ص�λ��\n");
scanf("%d", &pos);
if (ListInsert(&L, pos, e1) == OK) {
    printf("��%dǰ����Ԫ��%d�ɹ�\n", pos, e1.num);
    printf("�±�Ϊ��\n");
    ListTraverse(L, MyVisit);
}
else
printf("��%dǰ����Ԫ��%dʧ��\n", pos, e1.num);

printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
scanf("%d", &pos);
if (ListDelete(&L, pos, &e1) == OK) {
    printf("ɾ����%d��Ԫ��=%d�ɹ�\n", pos, e1.num);
    printf("�±�Ϊ��\n");
    ListTraverse(L, MyVisit);
}
else
printf("ɾ����%d��Ԫ��ʧ��\n", pos);

printf("\n��ձ�\n");
ClearList(&L);
printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n", ListLength(L));

DestroyList(&L);
#elif defined ELEMENT_TYPE_IS_STUDENT_P
LinkList L;
ET a, b;
ElemType e1 = &a, e2 = &b;
int      i, pos;

InitList(&L);

printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n\n", ListLength(L));

printf("����%d��Ԫ�أ�\n", INSERT_NUM);
srand(0);
for (i = INSERT_NUM * 2; i > 0; i -= 2) {
    ET s;
    s.num = rand();
    ListInsert(&L, 1, &s);
}
ListTraverse(L, MyVisit);//�˴�����MyVisit������

printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n\n", ListLength(L));

/* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
   ����ټ�һ����������ֵ */
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
            printf("������ҪȡԪ�ص�λ��[1..%d]��", ListLength(L));
            scanf("%d", &pos);
            break;
    }

    /* ȡ��1��Ԫ���Լ�ǰ������� */
    if (GetElem(L, pos, &e1) == OK) {
        printf("��%d��Ԫ��=%d\n", pos, e1->num);

        /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
        if (PriorElem(L, e1, &e2) == OK)
            printf("��%d��Ԫ��(%d)��ǰ��=%d\n", pos, e1->num, e2->num);
        else
            printf("�޷�ȡ�õ�%d��Ԫ��(%d)��ǰ��\n", pos, e1->num);

        if (NextElem(L, e1, &e2) == OK)
            printf("��%d��Ԫ��(%d)�ĺ��=%d\n\n", pos, e1->num, e2->num);
        else
            printf("�޷�ȡ�õ�%d��Ԫ��(%d)�ĺ��\n\n", pos, e1->num);
    }
    else
        printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
} // end of for

printf("������Ҫ���ҵ�Ԫ�أ�\n");
scanf("%d", &e1->num);
if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //�˴�����MyCompare������
printf("Ԫ��%d��λ��=%d\n", e1->num, pos);
else
printf("�Ҳ���Ԫ��%d\n", e1->num);

printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
scanf("%d", &e1->num);
printf("������Ҫ����Ԫ�ص�λ��\n");
scanf("%d", &pos);
if (ListInsert(&L, pos, e1) == OK) {
    printf("��%dǰ����Ԫ��%d�ɹ�\n", pos, e1->num);
    printf("�±�Ϊ��\n");
    ListTraverse(L, MyVisit);
}
else
printf("��%dǰ����Ԫ��%dʧ��\n", pos, e1->num);

printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
scanf("%d", &pos);
if (ListDelete(&L, pos, &e1) == OK) {
    printf("ɾ����%d��Ԫ��=%d�ɹ�\n", pos, e1->num);
    printf("�±�Ϊ��\n");
    ListTraverse(L, MyVisit);
}
else
printf("ɾ����%d��Ԫ��ʧ��\n", pos);

printf("\n��ձ�\n");
ClearList(&L);
printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
printf("��=%d\n", ListLength(L));

DestroyList(&L);
#else
    LinkList L;
    ElemType e1, e2;
    int      i, pos;

    InitList(&L);

    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n\n", ListLength(L));

    printf("����%d��Ԫ�أ�\n", INSERT_NUM);
    for (i = INSERT_NUM * 2; i > 0; i -= 2)
        ListInsert(&L, 1, i);
    ListTraverse(L, MyVisit);//�˴�����MyVisit������

    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n\n", ListLength(L));

    /* �ֱ�ȡ��1������Լ�С�ڵ�1����������4������µĵ�Ԫ��ֵ��ǰ��ֵ�����ֵ
       ����ټ�һ����������ֵ */
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
                printf("������ҪȡԪ�ص�λ��[1..%d]��", ListLength(L));
                scanf("%d", &pos);
                break;
        }

        /* ȡ��1��Ԫ���Լ�ǰ������� */
        if (GetElem(L, pos, &e1) == OK) {
            printf("��%d��Ԫ��=%d\n", pos, e1);

            /* ֻ��ȡ����ĳ��Ԫ�أ�����ȡǰ���ͺ�� */
            if (PriorElem(L, e1, &e2) == OK)
                printf("��%d��Ԫ��(%d)��ǰ��=%d\n", pos, e1, e2);
            else
                printf("�޷�ȡ�õ�%d��Ԫ��(%d)��ǰ��\n", pos, e1);

            if (NextElem(L, e1, &e2) == OK)
                printf("��%d��Ԫ��(%d)�ĺ��=%d\n\n", pos, e1, e2);
            else
                printf("�޷�ȡ�õ�%d��Ԫ��(%d)�ĺ��\n\n", pos, e1);
        }
        else
            printf("�޷�ȡ�õ�%d��Ԫ��\n\n", pos);
    } // end of for

    printf("������Ҫ���ҵ�Ԫ�أ�\n");
    scanf("%d", &e1);
    if ((pos = LocateElem(L, e1, MyCompare)) > 0)       //�˴�����MyCompare������
        printf("Ԫ��%d��λ��=%d\n", e1, pos);
    else
        printf("�Ҳ���Ԫ��%d\n", e1);

    printf("\n������Ҫ����Ԫ�ص�ֵ��\n");
    scanf("%d", &e1);
    printf("������Ҫ����Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListInsert(&L, pos, e1) == OK) {
        printf("��%dǰ����Ԫ��%d�ɹ�\n", pos, e1);
        printf("�±�Ϊ��\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("��%dǰ����Ԫ��%dʧ��\n", pos, e1);

    printf("\n������Ҫɾ��Ԫ�ص�λ��\n");
    scanf("%d", &pos);
    if (ListDelete(&L, pos, &e1) == OK) {
        printf("ɾ����%d��Ԫ��=%d�ɹ�\n", pos, e1);
        printf("�±�Ϊ��\n");
        ListTraverse(L, MyVisit);
    }
    else
        printf("ɾ����%d��Ԫ��ʧ��\n", pos);

    printf("\n��ձ�\n");
    ClearList(&L);
    printf("�ձ�=%s\n", (ListEmpty(L) == TRUE) ? "TRUE" : "FALSE");
    printf("��=%d\n", ListLength(L));

    DestroyList(&L);
#endif

    return 0;
}
