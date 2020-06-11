# include<stdio.h>
# include<malloc.h>
# include<stdlib.h>

typedef int ElementType;  // 定义数据类型，可以根据需要进行其他类型的定义

typedef struct ListNode   // 链表节点的定义
{
    ElementType Element;    // 数据域
    struct ListNode *next;  // 指向下一个节点
} Node, *PNode;

// 函数声明
PNode CreateList(void);  // 声明创建链表函数
void TraverseList(PNode List);  // 声明遍历链表函数
void InsertList(PNode List, int pos, int val);  // 声明链表插入函数PNode
void DeleteTheList(PNode List);  // 声明删除整个链表函数
void DeleteList(PNode List, int pos);   // 声明删除链表元素函数
PNode FindList(PNode List);  // 声明链表查询函数

// 主函数
int main() {
    PNode List = CreateList();  // 创建一个指针，使其指向新创建的链表的头指针
    TraverseList(List);  // 遍历链表
    FindList(List);  // 链表查询
    InsertList(List, 3, 100);  // 链表插入，在第三个位置插入数值100
    TraverseList(List);
    DeleteList(List, 3);  // 删除链表第三个节点
    TraverseList(List);
    DeleteTheList(List);  // 删除整个链表
    TraverseList(List);
    system("pause");    
    return 0;
}

// 创建链表函数定义
PNode CreateList(void) {
    int len;  // 用于定义链表长度
    int val;  // 用于存放节点数值
    PNode PHead = (PNode)malloc(sizeof(Node));  // 创建分配一个头结点内存空间
    if (PHead == NULL)  // 判断是否分配成功
    {
        printf("空间分配失败 \n");
        exit(-1);
    }
    
    PNode PTail = PHead; // 链表尾巴节点　初始指向头结点
    PTail->next = NULL;  // 

    printf("请输入节点个数:　\n");
    scanf("%d", &len); // 读取输入存入len变量
    
    for (int i = 0; i < len; i++)
    {
        PNode PNew = (PNode)malloc(sizeof(Node));

        if (PNew == NULL)
        {
            printf("分配新节点失败\n");
            exit(-1);
        }

        printf("请输入第 %d 个节点的数据:", i+1);
        scanf("%d", &val);
        PNew->Element = val;
        PTail->next = PNew;
        PNew->next = NULL;
        PTail = PNew;
    }
    printf("链表创建成功\n");
    return PHead;
}


// 定义遍历链表函数
void TraverseList(PNode List) {
    PNode P = List->next;
    printf("遍历的链表值为: ");
    if (P == NULL)
    {
        printf("链表为空");
    }
    while(P != NULL)
    {
        printf("%d ", P->Element);
        P = P->next;
    }
    printf("\n");
}

// 定义链表的查找函数
PNode FindList(PNode List) {
    PNode P = List->next;
    int num = 0;
    int val = 0;

    printf("请输入要查找的数: ");
    scanf("%d", &val);
    while(P->next != NULL && P->Element != val)
    {
        P = P->next;
        ++num;
    }

    if (P != NULL)
        printf("找到的节点: %d", num + 1);
    else
        printf("找不到该节点");
    
    printf("\n");
    return P;
}

// 定义链表插入函数
// 在链表位置第pos前插入值域为val的节点
void InsertList(PNode List, int pos, int val){
    int position = 0;
    PNode P = List;

    while(P != NULL && position < pos-1)
    {
        P = P->next;
        ++position;
    }

    PNode Tmp = (PNode)malloc(sizeof(Node));
    if(Tmp == NULL)
    {
        printf("分配内存失败!");
        exit(-1);
    }
    Tmp->Element = val;
    Tmp->next = P->next;
    P->next = Tmp;
}    

// 定义删除整个链表的函数
void DeleteTheList(PNode List)
{
    PNode P, Tmp;
    P = List->next;
    List->next = NULL;

    while (P!=NULL)
    {
        Tmp = P->next;
        free(P);
        P = Tmp;
    }

    printf("删除链表成功!");
}

// 定义删除链表指定元素的函数
void DeleteList(PNode List, int pos)
{
    int position = 0;
    PNode P = List;
    while(P != NULL && position < pos-1)
    {
        P = P->next;
        ++position;
    } 

    PNode Tmp = P->next;
    P->next = Tmp->next;
    free(Tmp);
    Tmp = NULL;
}

