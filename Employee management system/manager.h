//Ա���еľ�����
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager :public Worker   
{
public:
	Manager(int id, string name, int dID);//���캯��

	virtual void showInfo();//��ʾ������Ϣ      //��д�����еĴ��麯��

	virtual string getDeptName();//��ȡ��λ����
};