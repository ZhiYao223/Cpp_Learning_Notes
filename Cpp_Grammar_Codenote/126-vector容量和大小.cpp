/*
	功能描述：
	对vector容器的容量和大小操作

	函数原型：
	empty();            //判断容器是否为空
	capacity();            //容器容量
	size();              //返回容器中元素个数
	resize(int num);     //重新指定容器的长度为num，若容器变长，则以默认值填充新位置
						//如果容器变短，则末尾超出容器长度的元素被删除
	resize(int num, elem); //重新指定容器的长度为num， 若容器变长，则以elem值填充新位置。
							//如果容器变短，则末尾超出容器长度的元素被删除


*/
#include<vector>
#include<iostream>
using namespace std;

void printVector126(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl; 
}

void test126()
{
	vector<int> v1;
	for (size_t i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector126(v1);

	if (v1.empty()) //为真， 代表容器为空
	{
		cout << "v1为空" << endl; 
	}
	else
	{
		cout << "v1不为空" << endl; 
		cout << "v1的容量为：" << v1.capacity() << endl;   //13
		cout << "v1的大小为：" << v1.size() << endl; 
	}
	//cout << "sizeof(容器） = " << sizeof(v1) << endl;   //16

	//重新指定大小
	v1.resize(15, 100);        //利用重载版本，可以指定那个默认填充值 此处用100
	printVector126(v1);  //如果重新指定的比原来长，默认用0来填充

	v1.resize(5);           //如果重新指定的比原来短，超出的部分会被删除掉
	printVector126(v1);


}

int main126()
{
	test126();
	system("pause");
	return 0;

}