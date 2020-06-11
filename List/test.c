#include <stdio.h>
#include <stdlib.h>

typedef struct student
{
    char *name; // 学生名字
    int num;    // 学生学号
    int age;    // 学生年龄
} student;

int main(void)
{
    student stu1; // 定义一个结构体变量stu1
    /* 给结构体变量stu1的成员进行赋值 */
    stu1.name = "Liuyao";
    stu1.num = 520;
    stu1.age = 23;
    printf("\n============================================\n");
    printf("My name is %s\n", stu1.name);
    printf("My num is %d\n", stu1.num);
    printf("My age is %d\n", stu1.age);
    printf("欢迎关注果果小师弟学习笔记！\n", stu1.age);
    printf("============================================\n");
    system("pause");
}
