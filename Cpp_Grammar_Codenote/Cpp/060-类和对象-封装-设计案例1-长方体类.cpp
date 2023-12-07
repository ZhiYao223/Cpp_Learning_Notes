#include <iostream>
#include <string>

using namespace std;

class Cube
{
public:
	//设置长宽高
	void setValue(int length, int wide, int high)
	{
		m_L = length;
		m_W = wide;
		m_H = high;
	}
	//获取长宽高
	int getValue()
	{
		cout << "长为：" << m_L << "\t宽为：" << m_W << "\t高为：" << m_H << endl;
		return 0;
	}
	//获取长方体表面积
	int getAera()
	{
		return m_L * m_W * 2 + m_L * m_H * 2 + m_W * m_H * 2;
	}
	//获取长方体体积
	int getVolume()
	{
		return m_L * m_W * m_H;
	}
	//分别利用全局函数和成员函数判断两个立方体是否相等
	int getm_L()
	{
		return m_L;
	}
	int getm_W()
	{
		return m_W;
	}
	int getm_H()
	{
		return m_H;
	}

private:   //属性
	int m_H;
	int m_L;
	int m_W;
	//长、宽、高
};
void Issame(Cube cube1, Cube cube2)
{
	//if (cube1.getAera() == cube2.getAera() && cube1.getVolume() == cube2.getVolume() )
	if(cube1.getm_L()==cube2.getm_L() && cube1.getm_W()==cube2.getm_W() && cube1.getm_H()==cube2.getm_H() \
	  && cube1.getAera() == cube2.getAera() && cube1.getVolume() == cube2.getVolume())
	{
		cout << endl;
		cout << "长方体cube1与长方体cube2相同" << endl; 
	}
	else
	{
		cout << endl;
		cout << "长方体cube1和长方体cube2不同" << endl;
	}
}
int main60()
{
	Cube cube1;
	cube1.setValue(1, 1, 3);
	cube1.getValue();
	cout << "长方体表面积为：" << cube1.getAera() << endl;
	cout << "长方体体积为：" << cube1.getVolume() << endl; 

	cout << endl;

	Cube cube2;
	cube2.setValue(2, 2, 3);
	cube2.getValue();
	cout << "长方体表面积为：" << cube2.getAera() << endl;
	cout << "长方体体积为：" << cube2.getVolume() << endl;
	
	//利用全局函数判断
	Issame(cube1,cube2); //判断两个长方体是否相同

	//利用成员函数判断
	
	system("pause");
	return 0;
}