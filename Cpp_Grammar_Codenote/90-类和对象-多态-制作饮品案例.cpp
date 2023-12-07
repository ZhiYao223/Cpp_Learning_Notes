#include <iostream>
using namespace std;

//多态案例2 制作饮品
class AbstractDrinking
{
public:
	//煮水
	virtual void Boil() = 0;     //纯虚函数
	//冲泡
	virtual void Brew() = 0;
	//倒入杯
	virtual void PournCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;

	//制作饮品
	void MakeDrink()
	{
		Boil();
		Brew();
		PournCup();
		PutSomething();

	}
};

/**********************************************************************************
 制作咖啡
**********************************************************************************e*/
class Coffe :public AbstractDrinking
{
	//子类必须重写父类中的纯虚函数
public:
	//煮水
	virtual void Boil()
	{
		cout << "煮水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡咖啡" << endl;
	}
	//倒入杯
	virtual void PournCup()
	{
		cout << "倒入杯中" << endl; 
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入糖和牛奶" << endl; 
	}
};

/**********************************************************************************
 制作茶
**********************************************************************************e*/
class Tea :public AbstractDrinking
{
	//烧开水
	virtual void Boil()
	{
		cout << "烧开水" << endl;
	}
	//冲泡
	virtual void Brew()
	{
		cout << "冲泡" << endl;
	}
	//倒入杯
	virtual void PournCup()
	{
		cout << "倒入杯中" << endl;
	}
	//加入辅料
	virtual void PutSomething()
	{
		cout << "加入枸杞" << endl;
	}
};
//具体的实现
void dowork(AbstractDrinking* abs) //AbstractDrinking * abs =new Coffe
{
	abs->MakeDrink();
	delete abs;  //释放

}
void test90()
{
	//制作咖啡
	dowork(new Coffe); 
	cout << "-----------------------------" << endl;
	//制作茶叶
	dowork(new Tea);
}

int main90()
{
	test90();
	system("pause");
	return 0;
}