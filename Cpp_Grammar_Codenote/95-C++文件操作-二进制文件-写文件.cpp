/*
以二进制方式对文件进行读写操作
打开方式要指定为ios::binary

二进制方式写文件主要利用流对象调用成员函数write
函数原型： ostream& write(const char * buffer, int len);
参数解释：字符指针buffer指向内存中一段存储空间，len是读写的字节数
*/
#include <iostream>
#include <fstream>
#include <string>



using namespace std; 
//二进制文件 写文件
class Person
{
public:
	char m_Name[64];//姓名
	int m_Age; //年龄
};

void test95()
{
	ofstream ofs; //创建流对象
	ofs.open("D:/Learn Zone/C++ files/Practical_Grammar/Practical_Grammar/Produce_file/person.txt", ios::out | ios::binary); //二进制形式写文件，并打开
	//或者将上两行合并 ofstream ofs("Produce_file/Person.txt", ios::out | ios::binary);
	Person p = { "张三", 18 };
	ofs.write((const char*)&p, sizeof(Person)); //写文件，将取址符号强转为 const char*型

}

int main95()
{
	test95();
	system("pause");
	return 0;
}
