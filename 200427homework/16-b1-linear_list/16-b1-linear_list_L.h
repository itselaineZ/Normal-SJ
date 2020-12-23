/*1952339 ��08 ��ܰ��*/
//#define ELEMENT_TYPE_IS_INT		//������Ҳ��
//#define ELEMENT_TYPE_IS_DOUBLE
//#define ELEMENT_TYPE_IS_CHAR_ARRAY
//#define ELEMENT_TYPE_IS_CHAR_P
//#define ELEMENT_TYPE_IS_STUDENT
#define ELEMENT_TYPE_IS_STUDENT_P

/* P.10 ��Ԥ���峣�������� */
#define TRUE		1
#define FALSE		0
#define OK		1
#define ERROR		0
#define INFEASIBLE	-1
#define OVERFLOW	-2

typedef int Status;

/* P.28 ��ʽ���� */

#ifdef ELEMENT_TYPE_IS_DOUBLE
typedef double ElemType;
#elif defined (ELEMENT_TYPE_IS_CHAR_ARRAY)
typedef char ElemType[10];
#elif defined (ELEMENT_TYPE_IS_CHAR_P)
typedef char* ElemType;
#elif defined (ELEMENT_TYPE_IS_STUDENT)
typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
} ElemType;
#elif defined (ELEMENT_TYPE_IS_STUDENT_P)
typedef struct student {
	int   num;
	char  name[10];
	char  sex;
	float score;
	char  addr[30];
} ET, * ElemType;
#else	//ȱʡ����int����
typedef int ElemType;
#endif

typedef struct LNode {
    ElemType      data;	//�������
    struct LNode* next;	//���ֱ�Ӻ�̵�ָ��
} LNode, * LinkList;

/* P.19-20�ĳ����������Ͷ���ת��Ϊʵ�ʵ�C���� */
Status	InitList(LinkList* L);
Status	DestroyList(LinkList* L);
Status	ClearList(LinkList* L);
Status	ListEmpty(LinkList L);
int	ListLength(LinkList L);
Status	GetElem(LinkList L, int i, ElemType* e);
int	LocateElem(LinkList L, ElemType e, Status(*compare)(ElemType e1, ElemType e2));
Status	PriorElem(LinkList L, ElemType cur_e, ElemType* pre_e);
Status	NextElem(LinkList L, ElemType cur_e, ElemType* next_e);
Status	ListInsert(LinkList* L, int i, ElemType e);
Status	ListDelete(LinkList* L, int i, ElemType* e);
Status	ListTraverse(LinkList L, Status(*visit)(ElemType e));
