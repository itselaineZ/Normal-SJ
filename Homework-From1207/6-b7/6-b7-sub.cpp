/* 1952339 ��08 ��ܰ�� */

#include <cstdio>   //NULL
//�������������κ�ϵͳͷ�ļ�

/* ----- �����������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char* str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    int rt = 0;
    for (; str && *str; ++rt, ++str)
        ;
    return rt;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcat(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1 || !s2)
        return s1;
    char* p = s1;
    while (p && *p++)
        ;
    for (p = p - s1 == 0 ? s1 : p-1; p && s2 && *s2; *p = *s2, ++p, ++s2)
        ;
    *p = 0;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strcpy(char* s1, const char* s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1)
        return 0;
    char* p = s1;
    for (; p && s2 && *s2; *p = *s2, ++s2, ++p)
        ;
    *p = 0;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strncpy(char* s1, const char* s2, const int len)
{
    if (!s1)
        return 0;
    char* p = s1;
    int i;
    for (i = 0; s2  && *s2 && i < len; *p = *s2, ++s2, ++p, ++i)
        ;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    const char* p = s1, * q = s2;
    for (; p && q && *p && *q && *p == *q; ++p, ++q)
        ;
    if (!*p && !*q)
        return 0;
    return *p - *q;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char* s1, const char* s2)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    const char* p = s1, * q = s2;
    char a, b;
    for (; p && q && *p && *q; ++p, ++q) {
        a = *p;
        b = *q;
        if (*p >= 'A' && *p <= 'Z')
            a += 'a' - 'A';
        if (*q >= 'A' && *q <= 'Z')
            b += 'a' - 'A';
        if (a != b)
            break;
    }
    if((!p && !q) || (p && q && ! *p && ! *q))
        return 0;
    if (!p)
        return -1;
    if (!q)
        return 1;
    a = *p;
    b = *q;
    if (*p >= 'A' && *p <= 'Z')
        a += 'a' - 'A';
    if (*q >= 'A' && *q <= 'Z')
        b += 'a' - 'A';
    return a - b;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    const char* p = s1, * q = s2;
    int i;
    for (i = 0; p && q && *p && *q && i < len && *p == *q; ++i, ++p, ++q)
        ;

    if(*p == *q || i == len)
        return 0;
    return *p - *q;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char* s1, const char* s2, const int len)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!s1 && !s2)
        return 0;
    if (!s1)
        return -1;
    if (!s2)
        return 1;
    const char* p = s1, * q = s2;
    int i;
    char a, b;
    for (i = 0; i < len && p && q && *p && *q; ++i, ++p, ++q) {
        a = *p;
        b = *q;
        if (*p >= 'A' && *p <= 'Z')
            a += 'a' - 'A';
        if (*q >= 'A' && *q <= 'Z')
            b += 'a' - 'A';
        if (a != b)
            break;
    }
    if (*p == *q || i == len)
        return 0;
    a = *p;
    b = *q;
    if (*p >= 'A' && *p <= 'Z')
        a += 'a' - 'A';
    if (*q >= 'A' && *q <= 'Z')
        b += 'a' - 'A';
    return a - b;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strupr(char* str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    for (char* p = str; p && *p; ++p)
        *p = *p >= 'a' && *p <= 'z' ? *p - 'a' + 'A' : *p;
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strlwr(char* str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    for (char* p = str; p && *p; ++p)
        *p = *p >= 'A' && *p <= 'Z' ? *p - 'A' + 'a' : *p;
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    const char* p = str;
    for (; p && *p && *p != ch; ++p)
        ;
    if (!str)
        return 0;
    return *p == ch ? p-str+1 : 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    const char* x = str;
    for (; x && *x; ++x) {
        const char* q = substr, *p = x;
        for (; q && *p && *q && *p == *q; ++p, ++q)
            ;
        if (q && !*q)
            return x-str+1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char* str, const char ch)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!str)
        return 0;
    int len = tj_strlen(str);
    const char* p = str + len - 1;
    for (p = p < str ? str : p; p >= str && *p != ch; --p)
        ;
    return p < str ? 0 : p-str+1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char* str, const char* substr)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!str || !substr)
        return 0;
    int len = tj_strlen(str);
    for (const char* x = str + len - 1; x >= str; --x) {
        const char* q = substr, * p = x;
        for (; *p && *q && *q == *p; ++p, ++q)
            ;
        if (!*q)
            return x - str + 1;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char* tj_strrev(char* str)
{
    /* ע�⣺�����ڲ����������κ���ʽ�����飨������̬���飩 */
    if (!str)
        return NULL;
    char* p = str;
    int len = tj_strlen(str);
    char c;
    for (char* q = str + len - 1; p < q; ++p, --q) {
        c = *p;
        *p = *q;
        *q = c;
    }
    return str;
}