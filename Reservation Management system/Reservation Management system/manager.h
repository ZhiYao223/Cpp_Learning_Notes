#pragma once
#include<iostream>
using namespace std;
#include "Identity.h"

//���ݵ�������Manager��
class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���(����Ա����������)
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//�����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();
	
};