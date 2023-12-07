//友元详解：http://c.biancheng.net/view/2233.html

#include <iostream>
using namespace std;
#include <string>
class Address; //提前声明Address类

//声明Student类
class Student
{
public:
	Student(const char* name, int age, float score);
public:
	void show(Address *addr);
private:
	const char* m_name;
	int m_age;
	int m_score;
};


class Address
{
	friend void Student::show( Address* addr);
public:
	Address(const char* province, const char* city, const char* district);

private:
	const char* m_province; //省份
	const char* m_city; //城市
	const char* m_district;//市区
};
//实现Student类
Student::Student(const char* name, int age, float score) :
	m_name(name), m_age(age), m_score(score){}

void Student::show( Address *addr)
{
	cout << m_name << "的年龄是： " << m_age << "  成绩是  " <<m_score;
	cout << "  家庭住址： " << addr->m_province << "省" << addr->m_city << "市" << addr->m_district << "区" << endl;

}
//实现Address类
Address::Address(const char* province, const char* city, const char* district) :
	m_province(province), m_city(city), m_district(district){}

int main75()
{
	Student stu("王明",16,95.5f);
	Address addr("陕西", "西安", "雁塔");
	stu.show(&addr);

	Student* pstu = new Student("李磊", 16, 80.4);
	Address* paddr = new Address("广东", "佛山", "顺德");
	pstu->show(paddr);

	system("pause");
	return 0;
}

