#pragma once
#include <iostream>
using namespace std;
#include "point.h"
class Circle
{
	//设置半径、获取半径、设置圆心、获取圆心
public:
	void setR(int r);

		int getR();

		void setCenter(Point Circle_Center);

		Point getCenter();


private:
	int m_R;
	Point m_Center;      //核心， 在类中可以让另一个类作为本来中的成员
};