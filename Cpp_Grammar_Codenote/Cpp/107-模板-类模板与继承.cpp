/*
当类模板碰到继承时，需要注意：
当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
如果不指定，编译器无法给子类分配内存
如果想灵活指定出父类中T的类型，子类也需要变为类模板
总结：如果父类是类模板，子类需要指定出父类中T的数据类型
*/

#include <iostream>

using namespace std;

template<class T>
class Base       //父类
{
	T m;         //父类成员
};

//class Son: public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int> //必须指定一个类型
{

};
void test107_1()
{
	Son c;     //子类Son继承父类Base 且指定为int型 即c为int型
}


//类模板继承类模板，可以利用T2指定父类中的T类型
template<class T1, class T2>     //想将子类Son1作通用类型模版，需要在前面加template
class Son1 :public Base<T2>
{
public:
	Son1()    //构造函数
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;

	}
};
void test107_2()
{
	Son1<int, char> child;   //T1为int  T2为char   char传递给了T2，而T2又从父类Base继承，所以m为char类型
}

int main107()
{
	test107_1();
	test107_2();
	system("pause");
	return 0;
}