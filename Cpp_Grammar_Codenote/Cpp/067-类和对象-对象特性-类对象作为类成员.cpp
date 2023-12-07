#include <iostream>
#include <string>
using namespace std;
//c++类中的成员可以是另一个类的对象， 我们称该成员为对象成员


//类作为对象成员
//手机类
class Phone
{
public:
	Phone(string pName)  //构造函数
	{
		cout << "Phone的构造函数调用" << endl;
		m_PName = pName; 
	}
	~Phone()  //析构函数
	{
		cout << "Phone的析构函数调用" << endl;
	}
	//手机品牌名称
	string m_PName;
};
//人类
class People
{
public:
	//Phone m_Phone = pName; 隐式转换法
	People(string name, string pName):m_Name(name),m_Phone(pName)  //构造函数时初始化
	{
		cout << "People的构造函数调用" << endl;
	}
	~People()  //析构函数
	{
		cout << "People的析构函数调用" << endl;
	}
	//姓名
	string m_Name;
	//手机
	Phone m_Phone;
};
//当其他类对象作为本类成员，构造时先构造类对象，再构造自身，构析顺序则相反。构造：先有零件，才能拼成整体；析构：先拆整体，才能拆成零件
void test5()
{
	People p("张三", "苹果max");
	cout << p.m_Name << "拿着" << p.m_Phone.m_PName << endl;
}
int main67()
{
	test5();
	system("pause");
	return 0;
}