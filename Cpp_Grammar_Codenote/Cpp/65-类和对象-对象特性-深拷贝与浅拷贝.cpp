#include <iostream>
using namespace std;

//深拷贝与浅拷贝
class People
{
public:
	People()
	{
		cout << "People的默认构造函数调用" << endl;
	}
	People(int age,int height)
	{
		m_Age = age;
		m_Height = new int(height);  //new开辟的是堆区，是个地址，需要用指针来接收
		cout << "People的有参构造函数调用" << endl; 
	}
	//自己实现拷贝构造函数，解决拷贝带来的问题
	People(const People &p)
	{
		cout << "People拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
		//m_Height = p.m_Height;//浅拷贝，编译器默认实现就是这行代码
		
		m_Height = new int(*p.m_Height);//深拷贝操作
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

	int m_Age;//年龄
	int *m_Height;
};
//堆区的变量会自动释放，但是需要整个程序结束之后，这显然是影响性能的，因此需要手动释放
//new开辟的数据，由程序员手动开辟，手动释放，释放利用操作符==delete==
void test3()
{
	People p1(18, 160);
	cout << "p1的年龄为：" << p1.m_Age <<"身高为："<<*p1.m_Height << endl;
	People p2(p1);
	cout << "p2的年龄为：" << p2.m_Age << "身高为：" << *p2.m_Height << endl;
}

//浅拷贝带来的问题：堆区的内存重复释放
//浅拷贝的问题，要利用深拷贝进行解决

int main65()
{
	test3();
	system("pause");
	return 0;
}