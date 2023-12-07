#include <iostream>
using namespace std;
//struct和class的区别
//struct默认权限为公共	class默认权限为私有

class c1
{
	int m_A;   //默认权限  是私有
};

struct c2
{
	int m_A;   //默认权限  是公有
};


int main58()
{
	//c1 a;   //c1.m_A = 100;
	//a.m_A = 100;      //class默认私有，因此类外不可以访问

	c2 b;   //
	b.m_A = 100;       //在struct默认的权限为公共，因此可以访问

	system("pause");
	return 0;
}