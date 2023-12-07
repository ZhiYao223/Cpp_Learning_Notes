/*
	operator参数有两个，为二元谓词
*/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//二元谓词
class Mycompare
{
public:
	bool operator()(int val1, int val2)
	{
		return val1 > val2; 
	}
};
void printVector165(vector<int>& v)
{
	for (auto const& it : v)
	{
		cout << it << " ";
	}
}

void test165_1()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	printVector165(v);//排序前



	cout << endl;

	sort(v.begin(), v.end()); //升序排序后
	printVector165(v);

	cout << endl; 

	sort(v.rbegin(), v.rend());  //降序排序后
	printVector165(v);
	cout << endl;
}
void test165_2()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	printVector165(v);//排序前
	cout << endl; 
	//使用函数对象改变算法策略， 排序从大到小
	sort(v.begin(), v.end(), Mycompare());
	printVector165(v);
}
int main165()
{
	test165_1();
	test165_2();
	system("pause");
	return 0;
}