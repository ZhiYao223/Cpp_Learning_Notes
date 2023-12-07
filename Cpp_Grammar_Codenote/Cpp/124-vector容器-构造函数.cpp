/*
	vector：
	功能： vector数据结构和数组非常相似， 也称为单端数组
	vector 与普通数组区别
	不同之处在于数组是静态空间，而vector可以动态扩展

	动态扩展：
	并不是在原有空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝到新空间，释放原空间

	vector头部一般是封闭的，从尾端插入，删除元素：
	front() -----第一个元素
	back()  -----最后一个元素
	v.begin() -----第一个元素地址
	v.rbegin()-----最后一个元素地址
	v.end()-------最后一个元素的后一个地址
	v.rend()------第一个元素的前一个地址
	push_back()----从尾端插入元素
	pop_back() ----从尾端删除元素
	insert()  -----插入元素
	vector容器的迭代器是支持随机访问的迭代器

	vector构造函数
	功能描述：创建vector容器

	函数原型：
	vector<T> v;   //采用模板实现类实现，默认构造函数
	vector(v.begin(), v.end()); //将v[begin(),end()]区间中的元素拷贝给本身
	vector(n, elem);  //构造函数将n个elem拷贝给本身
	vector(const vector &vec); //拷贝构造函数

	vector的多种构造方式没有可比性，灵活使用即可
*/


#include<iostream>
#include<vector>
using namespace std;
void printVector124(vector<int>& v1);  //函数声明
//vector容器的构造
void test124()
{
	vector<int>v1; //默认构造   无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);   //插入数据
	}
	printVector124(v1);

	//通过区间方式进行构造
	vector<int>v2(v1.begin(), v1.end());  //传入两个迭代器，拷贝区间数据到v2
	printVector124(v2);

	//n个elem方式构造
	vector<int>v3(10, 100); //赋值10个100
	printVector124(v3);

	//拷贝构造
	vector<int>v4(v3);
	printVector124(v4);

}
void printVector124(vector<int>&v1)
{
	//方式1
	//for (auto const& it : v1)
	//{
	//	cout << it << " "; 
	//}

	//方式2
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;
}

int main124()
{
	test124();
	system("pause");
	return 0;
}
