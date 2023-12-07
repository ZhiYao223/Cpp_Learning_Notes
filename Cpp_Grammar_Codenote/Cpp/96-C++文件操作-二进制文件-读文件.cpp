#include <iostream>
using namespace std;
#include <fstream>

class Person
{
public:
	char m_Name[64];//姓名
	int m_Age; //年龄
};
//二进制文件
void test96()
{
	ifstream ifs;
	ifs.open("D:/Learn Zone/C++ files/Practical_Grammar/Practical_Grammar/Produce_file/person.txt", ios::in | ios::binary);
	//打开文件，判断是否打开成功
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		return;
	}
	//读文件
	Person p;
	ifs.read((char*)&p, sizeof(Person));      
	cout << "姓名： " << p.m_Name << "   年龄:  " << p.m_Age << endl;
	ifs.close();



}

int main96()
{
	test96();
	system("pause");
	return 0;
}