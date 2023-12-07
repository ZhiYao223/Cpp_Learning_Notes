#pragma optimize ("",off))
#include<iostream>
#include<map>
#include<string>
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

	Person(const Person& p)
	{
		this->m_Name = p.m_Name;
		this->m_Age = p.m_Age;
		this->m_Height = p.m_Height;
		cout << p.m_Name << ":拷贝\n";
	}
	//Person(const Person&& p)
	//{
	//	this->m_Name = p.m_Name;
	//	this->m_Age = p.m_Age;
	//	this->m_Height = p.m_Height;
	//	cout << p.m_Name << ":移动\n";
	//}

	string m_Name;
	int m_Age;
	int m_Height;
};

//自定义比较运算符重载
class Mycompare161
{
public:
	bool operator() (const Person& p1, const Person& p2) const 
	{
		return p1.m_Age > p2.m_Age;
	}
};

void printMap161(map<Person, int, Mycompare161>& m)
{
	for (map<Person, int, Mycompare161>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first.m_Name << " : " << "\t年龄:  " << it->first.m_Age 
			 << "\t身高： " << it->first.m_Height << "\t得分： " << it->second << endl; 
	}
	cout << endl;
}

void test161()
{
	map<Person,int, Mycompare161>m;  //学生   得分

	Person p1("学生A", 18, 175); 
	Person p2("学生B", 20, 180);
	Person p3("学生C", 19, 185);
	Person p4("学生D", 21, 175);
	Person p(p3);
	m.emplace(p1, 80);
	m.insert(make_pair(p1, 8));
	m.insert(make_pair(p2, 85));
	m.insert(make_pair(p3, 95));
	m.insert(make_pair(p4, 90));

	printMap161(m);
}

int main161()
{
	test161();
	system("pause");
	return 0;
}