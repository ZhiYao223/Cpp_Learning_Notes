#include "point.h"

//点类    只留下函数的实现，函数名前加上Point::，表明这是一个Point作用域下的函数
void Point::setcoordinate(int x, int y)
{
	m_X = x;
	m_Y = y;
}
void Point::getcoordinate(int x, int y)
{
	cout << "(" << x << "," << y << ")" << endl;
}
void Point::setX(int X)   //设置x          
{
	m_X = X;
}
int Point::getX()      //获取X
{
	return m_X;
}
void Point::setY(int Y)   //设置Y
{
	m_Y = Y;
}
int Point::getY()   //获取Y
{
	return m_Y;
}
