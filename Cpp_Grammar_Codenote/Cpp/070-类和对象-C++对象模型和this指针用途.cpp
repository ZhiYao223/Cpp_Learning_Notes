#if 0
成员变量和成员函数是分开存储的
this指针通过提供特殊的对象指针，this指针，解决上述问题，this指针指向被调用的成员函数所属的对象
this 指针是隐含每一个非静态成员函数内的一种指针
this 指针不需要定义，直接使用即可
用途：
1.当形参和成员变量同名时，可以用this指针来区分
2.在类的非静态成员函数中返回对象本身，可使用return *this
this指针学习链接：
http://c.biancheng.net/view/2226.html
https://blog.csdn.net/qq_21989927/article/details/111474451
#endif

#if 0
#include <iostream>
using namespace std;

class People
{
public:
	People(int age) 
	{
		//age = age;  //鼠标放在age上，阴影表示这三处age是同一个，输出乱码
		this->age = age;//this指针指向的是p1,  通过this区分重名变量，输出18
	}
	//引用指向本身内存，不用引用就调用拷贝函数，拷贝指向另一个内存，不加引用的话 \
	//回的就不是p2了，而是别的people对象(只是age都是20)
	//返回是值People的话，相当于创建了一个新对象，同时调用了拷贝构造函数
	People& PeopleAddage(People &p)
	{
		this->age += p.age; 
		return *this;  //返回p2这个对象的本体
		//改成return this; 函数返回类型People* ，后面调用.改成->也可以
	}
	int age;
};

//1.解决名称冲突
void test08()
{
	People p1(18);
	cout << "p1的年龄为：" << p1.age << endl;
}
//2.返回对象本身用*this
void test8()
{
	People p1(10);
	People p2(10);
	//p2.PeopleAddage(p1);  //将p1的年龄加到p2身上
	p2.PeopleAddage(p1).PeopleAddage(p1).PeopleAddage(p1);//链式编程思想
	cout << "p2的年龄为：" << p2.age << endl;
}
int main()
{
	test08();
	test8();
	system("pause");
	return 0;
}
#endif

#include <iostream>
#include <string.h>
using namespace std;

class Student {
public:
	void setname(string name);
	void setage(int age);
	void setscore(float score);
	void show();
private:

	string name = " ";
	int age = 0;
	float score = 0;
};

void Student::setname(string name) {
	this->name = name;
}
void Student::setage(int age) {
	this->age = age;
}
void Student::setscore(float score) {
	this->score = score;
}
void Student::show() {
	cout << this->name << "的年龄是" << this->age << "，成绩是" << this->score << endl;
}

int main70() {
	Student* pstu = new Student;
	pstu->setname("李华");
	pstu->setage(16);
	pstu->setscore(96.5);
	pstu->show();

	return 0;
}




