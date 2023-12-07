#if 0
//空指针
#include <iostream>
using namespace std;

int main()
{
	//空指针:指针变量指向内存中编号为0的空间，可以用来初始化指针变量
	int* P = NULL;
	//空指针不能进行访问
	//0-255之间的内存编号是系统占用的，因此用户不能访问
	//*p = 100;     //error 访问权限冲突
	cout << *p << endl;  //error  只要有*p出现，都报错


	system("pause");
	return 0;
}
#endif 

//野指针
#include <iostream>
using namespace std;
int main32()
{
	//野指针
	//在程序中要尽量避免野指针，野指针指向一块未知的非法空间，该空间未向系统申请，故无权限对其进行读写操作
	//空指针和野指针都不是我们申请的空间，因此不要访问，否则会出错
	int* p = (int *)0x1100;
	cout << *p << endl;

	system("pause");
	return 0;

}