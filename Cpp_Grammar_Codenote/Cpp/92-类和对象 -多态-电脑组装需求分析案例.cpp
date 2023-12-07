/*

*/
#include <iostream>
using namespace std;
//抽象不同零件类
//抽象CPU类
class CPU
{
public:
	virtual void calculate() = 0;

};
//抽象显卡类
class VideCard
{
public:
	virtual void display() = 0;

};

//抽象内存条类
class Memory
{
public:
	virtual void storage() = 0;

};

//电脑类
class Computer
{
public:
	Computer(CPU* cpu, VideCard* vc, Memory* mem)
	{
		m_cpu = cpu;
		m_vc = vc;
		m_mem = mem; 
	}
	//提供工作的函数,让零件工作起来，调用接口
	void work()
	{
		m_cpu->calculate();
		m_vc->display();
		m_mem->storage();
	}

	//提供析构函数， 释放3个电脑零件
	~Computer()
	{
		if (m_cpu != NULL)  //释放CPU零件
		{
			delete m_cpu;
			m_cpu = NULL;
		}
		if (m_vc != NULL)  //释放显卡
		{
			delete m_vc;
			m_vc = NULL;
		}
		if (m_mem != NULL)  //释放内存条
		{
			delete m_mem;
			m_mem = NULL;
		}
		
	}
private:
	CPU* m_cpu; //CPU的零件指针
	VideCard* m_vc; //显卡零件指针
	Memory* m_mem; //内存条零件指针
};
//具体厂商
class IntelCpu :public CPU 
{
public:
	virtual void calculate()
	{
		cout << "Intel的CPU开始计算了！" << endl;

	}
};
class IntelVideoCard :public VideCard
{
public:
	virtual void display()
	{
		cout << "Intel的显卡开始显示了！" << endl;

	}
};

class IntelMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Intel的内存条开始存储了！" << endl;

	}
};


//Lenovo厂商
class LenovoCPU :public CPU
{
public:
	virtual void calculate()
	{
		cout << "Lenovo的CPU开始计算了！" << endl;

	}
};
class LenovoVideoCard :public VideCard
{
public:
	virtual void display()
	{
		cout << "Lenovo的显卡开始显示了！" << endl;

	}
};
class LenovoMemory :public Memory
{
public:
	virtual void storage()
	{
		cout << "Lenovo的内存条开始存储了！" << endl;

	}
};
void test92()
{
	//第一台电脑零件
	CPU *intelCpu = new IntelCpu;
	VideCard* intelCard = new IntelVideoCard;
	Memory* intelMem = new IntelMemory;

	//创建第一台电脑
	Computer* computer1 = new Computer(intelCpu, intelCard, intelMem);
	computer1->work();
	delete computer1;

	cout << "-----------------------------------------------" << endl; 
	cout << "第二台电脑开始工作" << endl;
	//第2台电脑
	Computer* computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new IntelMemory);
	computer2->work();
	delete computer2;

	cout << "-----------------------------------------------" << endl;
	cout << "第三台电脑开始工作" << endl;
	//第3台电脑
	Computer* computer3 = new Computer(new LenovoCPU, new LenovoVideoCard, new IntelMemory);
	computer3->work();
	delete computer3;
}
int main92()
{
	test92();
	system("pause");
	return 0;
}