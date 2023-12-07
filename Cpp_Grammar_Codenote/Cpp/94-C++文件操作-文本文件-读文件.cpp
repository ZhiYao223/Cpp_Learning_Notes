/*
读文件步骤如下：
1、包含头文件： #include <fstream>
2、创建流对象 ifstream ifs;
3、打开文件夹并判断文件是否打开成功 ifs.open("文件路径",打开方式);
4、读数据 四种方式读取
5、关闭文件 ifs.close();

读文件可以利用ifstream,或者fstream类
利用is_open函数可以判断文件是否打开成功
close关闭文件
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//文本文件 读文件
void test94()
{
	//包含头文件

	//创建流对象
	ifstream ifs; 
	//打开文件，判断是否打开成功
	ifs.open("Produce_file/test93.txt", ios::in);  //in读 out 写
		if (!ifs.is_open())
		{
			cout << "文件打开失败" << endl;
			return;
		}
	//读数据	

	//第一种方式
	//char buf[1024] = { 0 };
	//while (ifs >> buf) //右移运算符 读取数据   遇到空格换行
	//{
	//	cout << buf << endl;  //输出数组中的数据
	//}
	
	//第二种方式
	//char buf[1024] = { 0 };
	//while (ifs.getline(buf, sizeof(buf)))  //获取行数据
	//{
	//	cout << buf << endl;  //输出数组中的数据
	//}
	
	//第三种方式
	string buf;
	while ( getline(ifs, buf))
	{
		cout << buf << endl;
	}

	//第四种方法
	//char c;
	//while ((c = ifs.get()) != EOF)   //EOF end of file   一个个字符读取并存到c中，直到读到文件尾
	//{
	//	cout << c;
	//}
	
	//关闭文件
	ifs.close();
}

int main94()
{
	test94();
	system("pause");
	return 0;
}