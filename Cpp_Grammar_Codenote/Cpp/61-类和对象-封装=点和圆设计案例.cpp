#if 0
#include <iostream>
using namespace std;
//点类

class Point
{
public:
	//设置X,获取X坐标
	//设置Y，获取Y坐标
	void setcoordinate(int x,int y)
	{
		m_X = x;
		m_Y = y;
	}
	void getcoordinate(int x, int y)
	{
		cout << "(" << x << "," << y << ")" << endl;
	}
	void setX(int X)   //设置x
	{ 
		m_X = X;
	}
	int getX()      //获取X
	{
		return m_X; 
	}
	void setY(int Y)   //设置Y
	{
		m_Y = Y;
	}
	int getY()   //获取Y
	{
		return m_Y;
	}

private:
	int m_X;        //X坐标
	int m_Y;        //Y坐标
};

class Circle
{
	//设置半径、获取半径、设置圆心、获取圆心
public:
	void setR(int r)
	{
		m_R = r; 
	}
	int getR()
	{
		return m_R; 
	}
	void setCenter(Point Circle_Center)
	{
		m_Center = Circle_Center;
	}
	Point getCenter()
	{
		return m_Center;
	}

private:
	int m_R;
	Point m_Center;      //核心， 在类中可以让另一个类作为本来中的成员
};
//判断点和圆的关系
void IsInCircle(Circle& c, Point& p) //引用一个圆和点
{
	//计算两点之间距离平方
	int distance = (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
				   (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
	//计算半径的平方
	int rDistance = c.getR() * c.getR();

	//判断关系
	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main61()
{
	//创建圆
	Circle c;  
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;
	p.setX(10);
	p.setY(10);

	//判断关系
	IsInCircle(c, p);
	system("pause");
	return 0;
}
#endif