#include <iostream>
using namespace std;
//1.构造函数的分类及调用
//按照参数分类	无惨构造(默认构造)  和  有参构造
//按照类型分类	普通构造     拷贝构造
class People1
{
public:
	//构造函数
	People1()   //无参构造
	{
		cout << "People1的无参构造函数调用" << endl;
	}
	People1(int a) //有参构造
	{
		age = a; 
		cout << "People1的有参构造函数调用" << endl;
	}
	//拷贝构造函数
	People1(const People1 &p)//之所以用引用，是因为值传递过程会反复调用拷贝构造函数，地址传递省内存，const防误改
	{
		//将传入的人身上的所有属性，拷贝到我身上
		age = p.age;
		cout << "People1的拷贝构造函数调用" << endl;
	}
	~People1()
	{
		cout << "People的析构函数调用" << endl; 
	}

	int age;
};

//调用构造函数
void test2()
{
	//括号法（常用）
	People1 p;  //默认构造函数的调用
	People1 p2(10); //调用有参构造函数
	People1 p3(p2); //调用拷贝构造函数
	//调用无参构造函数时，不能加括号，如：People1 p1();编译器会认为这是一个函数声明
	
	cout << "p2的年龄为：" << p2.age << endl;
	cout << "p3的年龄为：" << p2.age << endl;

	//显示法
	//People1 p1;
	//People1 p2 = People1(10);
	//People1 p3 = People1(p2);

	People1(10);//当改行单独写时，就是匿名对象：当前执行结束后，系统会立即回收掉匿名对象马上析构
	cout << "aaaaa" << endl;
	//不要利用拷贝构造函数初始化匿名对象  编译器会认为Person(p3) == Person p3; 对象声明
	//Person(p4);
	
	//隐式转换法
	People1 p4 = 10; //相当于写了 People1 p4 = People1(10);
	People1 p5 = p4; //拷贝构造   People1 p5 = People1(p4);
}

int main64()
{
	test2();
	system("pause");
	return 0;
}