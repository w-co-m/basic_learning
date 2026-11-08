#include<stdio.h>
//结构体(struct)
//方式1：先定义结构体类型，再声明变量
struct wkw {
	int chinese_grage;
	int math_grage;
	int english_grade;
};
struct wkw qizhong, funinggu;
// 方式2：定义结构体类型的同时声明变量
struct brainking
{
	int id;
	int rank;
}gaokao,yimo;
// 方式3：匿名结构体（仅用于声明少量变量，无法重复使用）
struct 
{
	int x;
	int y;
}point_1,point_2;
//typedef的用法
typedef struct {
	int x;
	int y;
}POINT;

//重点：内存对齐（总大小是最大成员的整数倍）

//联合体(union)
//同一时间只有一个成员有效
//定义方式与结构体相同
//节约内存

//枚举(enum)
enum Weekday {
	MON,    // 默认0
	TUE,    // 默认1
	WED,    // 默认2
	THU,    // 默认3
	FRI,    // 默认4
	SAT,    // 默认5
	SUN     // 默认6
};
//也可以通过手动赋值，后一个+1


