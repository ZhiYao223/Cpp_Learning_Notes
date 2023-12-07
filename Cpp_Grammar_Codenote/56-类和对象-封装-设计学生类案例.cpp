#if 0
#include <iostream>
#include <string>
using namespace std;
//类的成员一般加m_前缀(member),可以清晰地表示它是一个类的成员
class Student
{
public:   //公共权限，类中的属性和行为，统一称为成员
	//属性： 姓名，学号
	//属性：成员属性，成员变量
	//行为：成员函数，成员方法
	string m_name;
	int m_ID;
	//行为：显示姓名和学号
	void ShowStudent()
	{
		cout << "姓名：" << m_name << "\t学号：" << m_ID << endl;
	}

	//给姓名赋值
	void setname(string name)
	{
		m_name = name;
	}
	//给学号赋值
	void setID(int ID)
	{
		m_ID = ID;
	}
private:
};


int main56()
{
	//创建一个具体的学生
	Student s1;
	//给s1对象，进行属性赋值操作
	s1.m_name = "张三";   //姓名赋值
	s1.m_ID = 1;          //ID赋值
	s1.ShowStudent();     //显示学生信息

	Student s2;
	s2.m_name = "李四";    //姓名赋值
	s2.m_ID = 2;          //ID赋值
	s2.ShowStudent();     //显示学生信息

	Student s3;
	s3.setname("王五");   //姓名赋值
	s3.setID(3);          //ID赋值
	s3.ShowStudent();     //显示学生信息
	system("pause");
	return 0;
}

#endif