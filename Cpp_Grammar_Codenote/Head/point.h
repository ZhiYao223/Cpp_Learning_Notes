#pragma once   //防止头文件重复包含
#include <iostream>
using namespace std;

//点类     
//只需要成员函数、成员变量的声明，删掉函数的实现，加分号
class Point
{
public:
	//设置X,获取X坐标
	//设置Y，获取Y坐标
	void setcoordinate(int x, int y);
	//{
	//	m_X = x;
	//	m_Y = y;
	//}
	void getcoordinate(int x, int y);
	//{
	//	cout << "(" << x << "," << y << ")" << endl;
	//}
	void setX(int X);   //设置x
	//{
	//	m_X = X;
	//}
	int getX();      //获取X
	//{
	//	return m_X;
	//}
	void setY(int Y);   //设置Y
	//{
	//	m_Y = Y;
	//}
	int getY();   //获取Y
	//{
	//	return m_Y;
	//}

private:
	int m_X;        //X坐标
	int m_Y;        //Y坐标
};
