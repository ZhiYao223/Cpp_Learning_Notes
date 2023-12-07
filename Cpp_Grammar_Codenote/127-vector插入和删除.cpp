/*
	vector 插入和删除:
	push back(ele);						//尾部插入元素ele
	pop back();							//删除最后一个元素
	insert(const iterator pos, ele);	//选代器指向位置pos插入元素ele
	insert(const_iterator pos，int count,ele); //选代器指向位置pos插入count个元素ele
	erase(const iterator pos);				//删除选代器指向的元素
	erase(const_iterator start,const iterator end); //删除选代器从start到end之间的元素
	clear();								//删除容器中所有元素


*/
#include<iostream>
#include<vector>
using namespace std; 

void printVector127(vector<int>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] <<" ";
	}
	cout << endl; 
}

void test127()
{
	vector<int>v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.push_back(60);
	//遍历
	printVector127(v1);

	//尾删
	v1.pop_back();				 //删除最后一个元素
	printVector127(v1);
	
	//插入
	v1.insert(v1.begin(), 100);  //第一个参数是迭代器
	printVector127(v1);

	v1.insert(v1.begin(), 2, 1000); //在第一个元素处插入2个1000
	printVector127(v1);

	v1.insert(v1.begin() + 2, 2, 99);  //在第三个元素处插入2个99
	printVector127(v1);

	//删除，参数也是迭代器
	v1.erase(v1.begin());
	printVector127(v1);

	v1.erase(v1.begin(),  v1.end() - 1); //只留下最后一个元素
	printVector127(v1); 

	//v1.erase(v1.begin(), v1.end());   //相当于清空
	v1.clear();
	printVector127(v1);
}

int main127()
{
	test127();
	system("pause");
	return 0;
}
/*
	在C++中，可以使用std::vector的erase函数来删除元素。
	erase函数接受一个迭代器参数，表示要删除的元素位置。
	有两种常用的方法可以使用remove和erase结合来删除vector中的元素。

	remove(nums.begin(), nums.end(), 3) 是一个用于删除vector中值为3的元素的操作。具体步骤如下：
	remove函数是算法库中的一个函数，需要包含 <algorithm> 头文件来使用。
	nums.begin() 和 nums.end() 分别是要操作的vector的起始迭代器和结束迭代器，表示操作范围为整个vector。
	3 是要删除的目标元素，指定了需要删除的元素的值。
	remove(nums.begin(), nums.end(), 3) 执行后，会将值为3的元素移到vector的末尾，并返回指向新的逻辑结束位置的迭代器。
	值为3的元素并未在执行 remove 函数后真正被删除，它仍然保留在vector的末尾，
	只是被移动到了后面，通过返回的迭代器可以准确地得知新的逻辑结束位置。如果想要将这个元素从vector中真正地删除，
	可以使用erase函数，如 nums.erase(remove(nums.begin(), nums.end(), 3), nums.end())。这样可以一步到位地将目标元素删除。
*/
#if 0
#include <algorithm>
#include <vector>

int main127() {
	std::vector<int> nums = { 1, 2, 3, 4, 5 };

	// 删除值为3的元素
	nums.erase(std::remove(nums.begin(), nums.end(), 3), nums.end());

	// 输出结果：1 2 4 5
	for (int num : nums) {
		std::cout << num << " ";
	}

	return 0;
}
#endif
/*
这被叫作 erase-remove，执行删除操作后，iter 指向最后一个元素之后的位置，
所以它标识了被删除序列的第一个元素，被删除序列的结束位置由 std::end(words) 指定。
当然，在一条语句中，也能先移除元素，然后再删除末尾不想要的元素：
words.erase(std::remove(std::begin(words), std::end(words),"none"), std::end(words));
remove() 算法返回的迭代器作为 erase() 的第一个参数，erase() 的第二个参数是所指向容器中最后一个元素后一个位置的迭代器。

可以使用成员函数 erase() 来删除容器中的一个或多个元素。如果只删除单个元素，那么只需要提供一个参数，
例如：auto iter = data.erase(std::begin(data)+1); //Delete the second element
删除一个元素后，vector 的大小减 1；但容量不变。会返回一个迭代器，它指向被删除元素后的一个元素。
这里的返回值和表达式 std::begin(data)+1 相关；如果移除了最后一个元素，会返回 std::end(data)。

如果要移除一个元素序列，只需要传入两个迭代器，用来指定移除元素的范围。例如：
auto iter = data.erase(std::begin(data)+1,std::begin(data)+3);
不要忘记，第二个迭代器指向这段元素末尾的下一个位置。上面的语句删除了位于 std::begin(data)+1 和 std::begin(data)+2 的元素。
返回的迭代器指向被删除元素后的位置，它是 std::begin(data)+1 ；如果删除了最后一个元素，它就是 std::end(data)。

*/

