#if 0
#include <iostream>
using namespace std;

class Building
{
	//相当于一个全局函数声明，开头加上friend，说明goodGay全局函数是Building好朋友,
	//可以访问BUilding中的私有成员，如卧室
	friend void goodGay(Building* building); 
public:
	Building()
	{
		m_SittingRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRoom;  //卧室

};
//全局函数
void goodGay(Building *building)
{
	cout << "好基友的全局函数正在访问：  " << building->m_SittingRoom << endl;
	//m_BedRoom本来是私有属性，无法访问，但可以在类中最上面加上一行，使friend声明，然后就可以访问私有成员卧室
	cout << "好基友的全局函数正在访问：  " << building->m_BedRoom << endl;
}
void test03()
{
	Building building;
	goodGay(&building);
}
int main73()
{
	test03();
	system("pause");
	return 0;
}
#endif