#include<iostream>
#include<vector>
using namespace std;

class Solution
{
public:
	int search(vector<int>& nums, int target)
	{
		int left = 0;
		int right = nums.size() - 1; //定义target在左闭右闭的区间里[left, right]
		while (left <= right)         //当left = right,区间[left, right]已然有效，所以用<=
		{
			int middle = left + ((right - left) / 2); //防止溢出 计算数组元素中间值
			if (nums[middle] > target)
			{
				right = middle - 1;    //target在左区间，所以left[left, middle-1]
			}
			else if (nums[middle] < target)
			{
				right = middle + 1;		//target在右区间，所以[middle+1, right]
			}
			else                        //nums[middle] == target
			{
				return middle;           //数组中找到目标值，直接返回下标
			}
		}
		return -1;  //未找到目标
	}
};
int main2()
{
	vector<int>v; 
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	Solution m;
	int value = m.search(v, 3);
	cout << value << endl;
	system("pause");
	return 0;
}

#if 0
class Solution {
public:
	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size();
		while (left < right) {
			int middle = left + ((right - left) >> 1);
			if (nums[middle] > target) {
				right = middle;
			}
			else if (nums[middle] < target) {
				left = middle + 1;
			}
			else {
				return middle;
			}
		}
		return -1;   //未找到目标值
	}
};
#endif