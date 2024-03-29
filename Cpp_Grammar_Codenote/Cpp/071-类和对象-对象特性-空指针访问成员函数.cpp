//空制指针可以调用成员函数，但该成员函数不能访问成员变量

#include <iostream>
using namespace std;

//空指针调用成员函数
class People
{
public:
	void ShowClassName()
	{
		cout << "this is People class" << endl; 
	}
	void ShowPeopleAge()
	{
		if (this == NULL)   //提高代码的健壮性，避免传入空指针使代码奔溃
		{
			return;
		}
		cout << "age = " << m_age << endl;  //传入的指针为空，this->m_age没有确定的对象，无法访问里面的成员，代码崩掉
	}
	
	int m_age;
};
void test8()
{
	People* p = NULL;

	p->ShowClassName();
	p->ShowPeopleAge();
}
int main71()
{
	test8();
	system("pause");
	return 0;
}