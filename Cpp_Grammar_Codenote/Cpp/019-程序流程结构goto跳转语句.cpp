#include <iostream>
using namespace std;
int main19()
{
	cout << "1.xxxx" << endl;
	cout << "2.xxxx" << endl;
	goto Flag;
	cout << "3.xxxx" << endl;
	cout << "4.xxxx" << endl;
	Flag:                     //跳转到此处
	cout << "5.xxxx" << endl;
	system("pause");
	return 0;
	//在程序中不建议使用goto语句，以免造成程序流程混乱
}