/*
	
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;
//vector容器中存放自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age; 
	}
	string m_Name;
	int m_Age;
};

void test114_1()
{

	vector<Person> v;  //创建一个容器v
	//准备一些数据
	Person p1("唐僧", 10);
	Person p2("孙悟空", 20);
	Person p3("猪八戒", 30);
	Person p4("沙悟净", 40);
	Person p5("白龙马", 50);
   
	//向容器中添加上述数据
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);

	//遍历容器中的数据
	for(vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		//*it是Person类型的指针
		//cout << "姓名：" << (*it).m_Name << " 年龄：" << (*it).m_Age << endl; 
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << endl; 
	}
	cout << endl << endl;
}

//存放自定义数据类型 指针
void test114_2()
{
	vector<Person*> v;  //创建一个容器v
	//保存以下五个数据的地址
	Person p1("唐僧", 10);
	Person p2("孙悟空", 20);
	Person p3("猪八戒", 30);
	Person p4("沙悟净", 40);
	Person p5("白龙马", 50);

	//向容器中添加上述数据的地址
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);

	//通过叠加器遍历容器中的数据
	for (vector<Person*>::iterator it = v.begin(); it != v.end(); it++)
	{	
		//*it解出来的是Person*的数据类型
		Person* p = (*it);
		cout << "姓名：" << (*it)->m_Name << "年龄：" << (*it)->m_Age << endl; 
	}
	cout << endl << endl;
}

void test114_3()
{
	//将Person类型的数据存入容器w
	vector<Person> w = { {"唐僧",10},{"孙悟空",20},{"猪八戒",30},{"沙悟净",40}, {"白龙马",50} };
	
	// 使用迭代器遍历 persons 容器中的元素 auto表示自动推导变量的类型
	//将容器首个元素地址赋值给it迭代器变量,并依次递增，知道指向容器最后一个元素的后一个位置结束
	for (auto it = w.begin(); it != w.end(); ++it) 
	{
		//作用是将迭代器 it 指向的元素的值赋值给名为 w 的常量引用。
		//这样，我们可以通过 w 直接访问该元素的值，而且不能通过 w 修改迭代器所指向的元素。
		const auto& w = *it;    //通过*解引用地址，取出元素并赋值给w的常量引用
		//w = 10;    错误，不能修改迭代器指向的元素 
		cout << "姓名：" << w.m_Name << "年龄：" << w.m_Age << endl;
	}
	cout << endl << endl;
}

void test114_4()
{
	//将string类型的五个数据存入name容器
	vector<string> name = { "唐僧", "孙悟空", "猪八戒", "沙悟净" };

	//遍历输出容器中的数据  size_t 是常用于在容器中从0开始索引的整数类型
	for (size_t i = 0; i < name.size(); ++i)
	{
		cout << name[i] << "  ";
	}
	cout << endl << endl;
}

void test114_5()
{
	//将数据存入容器
	vector<string> name = { "唐僧", "孙悟空", "猪八戒", "沙悟净" };

	//遍历输出容器中的五个数据 
	//使用范围 - based for 循环遍历容器 name 中的每个元素，并将每个元素的值赋给名为 it 的常量引用变量。
	//这样，我们可以通过 it 直接访问容器中每个元素的值，而且不能通过 it 修改容器的元素。
	for (auto const& it : name)    //it为迭代器变量
	{
		cout << it << "  ";   
	}
	cout << endl << endl;
}

void test114_6()
{
	
}

int main114()
{
	test114_1();
	test114_2();
	test114_3();
	test114_4();
	test114_5();
	system("pause");
	return 0;
}