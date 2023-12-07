#include <iostream>
using namespace std;
#include <string>

class Building;

class GoodGay
{
public:
	GoodGay();
	void visit1();   //让visit()函数可以访问Building中私有成员
	void visit2();   //让visit()函数不可以访问Building中私有成员
private:
	Building *building;

};
//含有友元成员函数的类，要放在该友元所访问的类的前面
//因为GoodGay类需要声明Building类变量，所以Building类必须在GoodGay之前声明；
//因为Building的定义中需要将GoodGay的成员函数声明成友元成员函数，所以Building类必须在GoodGay之后定义；
//因为GoodGay中的构造函数需要调用Building的构造函数，所以GoodGay类中的构造函数的实现必须在Building类的定义之后；
class Building
{
	//告诉编译器，Goodgay类下的visit成员函数作为本类的好朋友，可以访问私有成员
	friend void GoodGay::visit1();
	friend void GoodGay::visit2();
public:
	Building();
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom; //卧室
};

//类外实现成员函数
Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	building = new Building;
}

void GoodGay::visit1()
{
	cout << "visit函数正在访问: " << building->m_SittingRoom << endl;
	cout << "visit函数正在访问：" << building->m_BedRoom << endl; 
}
void GoodGay::visit2()
{
	cout << "visit2函数正在访问：" << building->m_SittingRoom << endl;
	cout << "visit2函数正在访问：" << building->m_BedRoom << endl;
}
void test76()
{
	GoodGay gg;
	gg.visit1();
	gg.visit2();
}
int main76()
{
	test76();

	system("pause");
	return 0;
}