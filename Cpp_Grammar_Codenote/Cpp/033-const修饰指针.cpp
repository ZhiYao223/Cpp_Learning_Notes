#include <iostream>
using namespace std;

//const修饰指针  --常量指针
//const修饰指针  --指针常量
//const既修饰指针，又修饰常量

int main33()
{

	system("pause");
	return 0;
}

#if 0
const int *p = &a;   
常量指针:指针的指针指向可以改，指针指向的值不能改
* p = 20;//错误，指针指向的值不能改
p = &b; //正确，指针指向考研改

int* const p = &a;
指针常量：指针的指向不能改，指针指向的值可以改
* p = 20;//正确，指向的值可以改
p = &b; //错误，指针指向不可以改

const int* const p = &a;
const 修饰指针和常量
指针的指向和指针指向的值都不可以改
* p = 20;//错误
p = &b;//错误

记忆方法： const表示常量  *表示指针  看前后顺序
const int* p = &a;    常量指针
int* const p = &a;    指针常量
#endif
