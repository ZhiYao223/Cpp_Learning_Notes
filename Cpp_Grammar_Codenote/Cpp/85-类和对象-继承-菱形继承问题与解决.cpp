//vbptr 虚基类指针 指向vbtable虚基类表    v-virtual  b-base ptr-pointer
#include <iostream>
using namespace std;

//动物类
class Animal
{
public:
	int m_Age;
};

//利用虚继承，解决菱形继承的问题
//继承之前，加上关键类virtual变为虚继承， Animal成为虚基类
//羊类
class Sheep :virtual public Animal {};

//驼类
class Tuo :virtual public Animal {};

//羊驼类
class SheepTuo :public Sheep, public Tuo{};


void test85()
{
	SheepTuo st;

	st.Sheep::m_Age = 18;
	st.Tuo::m_Age = 28;
	//当菱形继承，两个父类拥有相同数据，需要加以作用域区分
	cout << "st.Sheep::m_Age =" << st.Sheep::m_Age << endl;
	cout << "st.Tuo::m_Age =" << st.Tuo::m_Age << endl;
	//这份数据我们知道，只有一份就可以，菱形继承导致数据有两份，资源浪费
	cout << "st.m_Age = " << st.m_Age << endl; //自身访问，若子类没有加virtual，本该出现二义性无法访问。

}


int main85()
{
	test85();
	system("pause");
	return 0;
}
