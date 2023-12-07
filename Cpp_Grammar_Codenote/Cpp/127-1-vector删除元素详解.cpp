#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main127_1()
{
	//可以使用 vector 的成员函数 pop_back() 来删除容器尾部的元素。
	vector<int>data1(100, 99);
	data1.pop_back(); //Remove the last element

	vector<int>data2(100, 99);
	//swap(data2.begin(), data2.end() - 1);


	/*
	如果要去掉容器中多余的容量，例如不再向容器中添加新元素，
	那么可以通过使用成员函数 shrink_to_fit() 来实现
	*/
	data2.shrink_to_fit(); 

	/*
	可以使用成员函数 erase() 来删除容器中的一个或多个元素。
	如果只删除单个元素，那么只需要提供一个参数。
	删除一个元素后，vector 的大小减 1；但容量不变。
	会返回一个迭代器，它指向被删除元素后的一个元素。
	*/
	auto iter1 = data1.erase(data1.begin() + 1); //删除第二个元素

	/*
	如果要移除一个元素序列，只需要传入两个迭代器，用来指定移除元素的范围。
	不要忘记，第二个迭代器指向这段元素末尾的下一个位置。
	删除了位于 std::begin(data)+1 和 std::begin(data)+2 的元素。
	返回的迭代器指向被删除元素后的位置，它是 std::begin(data)+1 ；
	如果删除了最后一个元素，它就是 std::end(data)。
	*/
	auto iter2 = data1.erase(data1.begin() + 1, data1.end() + 3);

	vector<string>words{ "one", "none","some","all","horse","best","many" };
	auto iter3 = remove(begin(words), end(words), "none");
	return 0;
}