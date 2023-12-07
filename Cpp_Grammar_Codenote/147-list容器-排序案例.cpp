/*
	案例描述： 将 Person自定义数据类型进行排序，Person中属性有姓名，年龄，身高
	排序规则： 将按照年龄进行升序，如果年龄相同按照身高进行降序

*/
#include<list>
#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->m_Name = name;
		this->m_Age = age;
		this->m_Height = height;
	}
public:
	string m_Name; //姓名
	int m_Age; //年龄
	int m_Height; //身高

};

void printList147(list<Person>& L)
{
	for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "姓名：" << it->m_Name << " 年龄：" << it->m_Age << " 身高: " << it->m_Height << endl;
	}
	cout << endl;
}

bool ComparePerson(Person& p1, Person& p2)
{
	//按年龄 升序 
	if (p1.m_Age == p2.m_Age)
	{
		//年龄相同，按照身高降序
		return p1.m_Height > p2.m_Height;
	}
	else
	{
		return p1.m_Age < p2.m_Age;
	}
}

void test147_1()
{
	list<Person>L;  //创建容器
	//准备数据
	Person p1("刘备", 35, 175);
	Person p2("曹操", 45, 180);
	Person p3("孙权", 40, 170);
	Person p4("赵云", 25, 190);
	Person p5("张飞", 35, 185);
	Person p6("关羽", 35, 200);

	//插入数据
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	printList147(L);

	cout << "------------------------------------------------------" << endl; 
	L.sort(ComparePerson);//排序

	printList147(L);

}



int main147()
{
	test147_1();
	system("pause");
	return 0;
}
