//友元详解：http://c.biancheng.net/view/2233.html
#if 0
#include <iostream>
using namespace std;
#include <string>

class Student{ 
public:
	Student(const char *name, int age, float score);
public:
	friend void show(Student* pstu);
private:
	const const char* m_name;
	int m_age;
	float m_score;
};

Student::Student(const char *name, int age, float score) :m_name(name), m_age(age), m_score(score) {}

//非成员函数
void show(Student* pstu) {
	cout << pstu->m_name << "的年龄是" << pstu->m_age << ", 成绩是" << pstu->m_score << endl;
}

int main74()
{
	Student stu("小明", 15, 90.6);
	show(&stu);//调用友元函数
	Student* pstu = new Student("李四", 16, 80.3);
	show(pstu);  //调用友元函数

	system("pause");
	return 0;
}

#endif

#if 0
#include <iostream>
using namespace std;
#include <string>
class Building
{
	friend class GoodGay; //告诉编译器，goodgay类是Building类的好友，可以访问到Building类中的私有内容
public:
	Building();//构造函数 
public:
	string m_SittingRoom;  //客厅d
private:
	string m_BedRoom; //卧室
};

class GoodGay
{
public:
	GoodGay();
	void visit();//参观函数 访问Building中的属性
	
private:
	Building* building;

};

//类外写成员函数
Building::Building()
{
	string m_SittingRoom = "客厅";
	string m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	//创建建筑物对象
	building = new Building;
}
void GoodGay::visit()
{
	cout << "好基友正在访问：" << building->m_SittingRoom << endl; 
	cout << "好基友正在访问：" << building->m_BedRoom << endl;

}
void test74()
{
	GoodGay gg;
	gg.visit();
}
int main()
{
	test74();
	system("pause");
	return 0;
}
#endif