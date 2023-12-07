#include <iostream>
#include <string>
using namespace std;
//成员属性设置为私有
//1.可以自己控制读写权限
//2.对于写可以检测数据的有效性

//设计人类
class Person
{
public:
	void setName(string name)  //写姓名
	{
		m_Name = name;
	}
	string getName()//获取姓名
	{
		return m_Name;
	}

	void setAge(int age)  //可读可写，如果想修改（年龄范围为必须是0~150之间）
	{
		if(age<0 || age>150)    //检验年龄的有效性
		{
			cout << "您输入的年龄有误！" << endl;
			return;    //立即退出
		}
		m_Age = age;
	}
	int getAge()     //写年龄
	{
		//m_Age = 0;  //初始化为0岁
		return m_Age;
	}
	//设置情人   只写
	void setLover(string lover)
	{
		m_Lover = lover;
	}


private:        //设为私有
	//姓名、年龄、情人
	string m_Name;    //可读可写
	int m_Age;        //只读
	string m_Lover;    //只写
};

int main59()
{
	Person p;
	p.setName("张三"); //输入姓名
	cout << "姓名为：" << p.getName() << endl;  //显示姓名
	//p.getAge = 18;  //年龄为私有权限，不可修改
	p.setAge(100);

	cout << "年龄为：" << p.getAge() << endl;

	p.setLover("翠花");  //设置情人为翠花
	//cout << "情人为：" << p.getLover() << endl;  //只写权限，没有getLover()函数
	system("pause");
	return 0;
}