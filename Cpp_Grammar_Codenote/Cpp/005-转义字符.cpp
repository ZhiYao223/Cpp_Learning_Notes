#include <iostream>

using namespace std;

int main5()
{

	cout << "hello world\n";
	printf("zhiyao\n");
	
	//转义字符、换行符\n
	//反斜杠
	cout<<"\\\\\n" << endl;//输出一个反斜杠\ 
	
	cout << "\\\a" << endl;  //报警音效
    //水平制表符
	cout << "aaa\thello world" << endl;
	cout << "aa\thello world" << endl;
	cout << "aaaaaaa\thello world" << endl;
	cout << "aaaaaaaa\thello world" << endl;
	cout << "aaaaaaaaa\thello world" << endl;


	system("pause");

	return 0;
}

