#include <iostream>
using namespace std;

#if 0
void main()
{
	int a = 1;
	int& b = a;
	cout << "a:address:" << &a << endl;
	cout << "b:address:" << &b << endl;



	int& c = b;
	c = 4;

	cout << "a:" << a << endl;
	cout << "b:" << b << endl;
	cout << "c:" << c << endl;   
	//a,b,c的值都为4
}
#endif

#if 0
void main()
{
	int d1 = 4;
	const int& d2 = d1;  //d1 = d2 = 4;
	d1 = 5;  //d1=d2=5;
	//d2 = 6; error：不能给常量赋值

	const int d3 = 1;
	const int& d4 = d3;
	//int &d5 = d3;
	const int& d6 = 5;//只有常引用可以应用常量

	double d7 = 1.1;


}
#endif


#if 0


class Student
{
public:
	string m_name;
	int m_ID;

	void ShowStudent()
	{
		cout << "姓名：" << m_name << "\t学号：" << m_ID << endl;
	}
	//给姓名赋值
	void setname(string name)
	{
		m_name = name;
	}
	void setID(int ID)
	{
		m_ID = ID; 
	}
private:

};

int main()
{
	Student s1;
	s1.m_name = "zhangsan";
	s1.m_ID = 1;
	s1.ShowStudent();

	Student s2;
	s2.m_name = "lisi";
	s2.setID(3);
	s2.ShowStudent();

	system("pause");
	return 0;
} 
#endif

#if 0

class Person
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	int m_Password;

private:
	void func()
	{
		m_Name = "zhangsan";
		m_Car = "baoma";
		m_Password = 123456;
	}
public:
	void func2()
	{
		cout << "This is a car!" << endl;
	}
};

int main()
{
	Person p1;
	p1.m_Name = "lisi";
	//p1.m_Car = "benchi";
	//p1.Password = 12335;
	//p1.func2();
	system("pause");
	return 0;
}
#endif

#if 0

class People
{
public:
	People() {
		cout << "People的默认构造函数" << endl;
	}
	People(int age, int height) {
		m_Age = age;
		m_Height = new int(height);
		cout << "People的有参构造函数调用" << endl; 
	}
	People(const People& p) {
		cout << "people拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;浅拷贝
		//深拷贝操作
		m_Height = new int(*p.m_Height);
	}
	
	~People()
	{
		//析构代码，将堆区开辟数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL; 
		}
		cout << "People的析构函数调用" << endl; 
	}

	int m_Age;
	int* m_Height;
};

#endif

#if 0
#include<string>

//手机类
class Phone {
private:
	string brand;
	string model;
public:
	//构造函数
	Phone(const string& brand,const string& model):brand(brand),model(model){}

	//打电话的方法
	void makecall(const string& number) {
		cout << "Using" << brand << "" << model << "to make a call to" << number << endl;

	}
};

//人类
class Person
{
private:
	string name;
	Phone phone; //人类有一个手机对象作为成员
public:
	//构造函数
	Person(const string& name,const string& phoneBrand, const string& phoneModel):name(name),phone(phoneBrand,phoneModel){}

	//给手机打电话的方法
	void call(const string& number) {
		cout << name <<" is making a call... "<< endl;
		phone.makecall(number);
	}
};

int main()
{
	//创建一个人对象
	Person person("Alice", "Apple", "iphone");

	//打电话
	person.call("1234456");
	system("pause");
	return 0;
}

#endif

#if 1

class People
{
public:
	People(int age) {

	}
};


#endif
