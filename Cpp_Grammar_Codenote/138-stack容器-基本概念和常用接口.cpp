/*
		stack是一种先进后出的数据结构， 它只有一个出口
		栈不允许有遍历行为、符合先进后出
		栈中进数据称为   入栈push
		栈中弹出数据称为  出栈pop

		功能描述：栈容器常用的对外接口
		构造函数:
		stack<T> stk;//stack采用模板类实现， stack对象的默认构造形式
		stack(const stack &stk);//拷贝构造函数


		赋值操作:
		stack& operator=(const stack &stk);//重载等号操作符

		数据存取:
		push(elem);		//向栈顶添加元素push(elem);
		pop();			//从栈顶移除第一个元素
		top();			//返回栈顶元素
		
		大小操作:
		empty();	//判断堆栈是否为空
		size();		//返回栈的大小
	
*/
#include<iostream>
#include<stack>
using namespace std;
 
void test138()
{
	//创建栈容器，栈容器必须符号先进后出
	stack<int>s;
	//向栈中添加元素，叫做 压栈 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);

	while (!s.empty())
	{
		//输出栈顶元素
		cout << "栈顶元素为： " << s.top() << endl;
		//弹出栈顶元素
		s.pop();
	}
	cout << "栈的大小为：" << s.size() << endl; 
}

int main138()
{
	test138();
	system("pause");
	return 0;
}

  