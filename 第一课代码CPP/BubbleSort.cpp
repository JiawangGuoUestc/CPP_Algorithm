#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

void swap(vector<int> &arr, vector<int>::size_type i, vector<int>::size_type j)
{
	auto temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void printVector(const vector<int> arr)
{
	for (vector<int>::size_type i = 0; i < arr.size(); i++)
	{
		cout << arr[i] << endl;
	}
}

class Solution
{
public:
	static void BubbleSort(vector<int> &arr)
	{
		if (arr.begin() ==arr.end()  || arr.size() < 2)
			return;
		for (vector<int>::size_type i = 0; i < arr.size(); i++)
		{
			for (vector<int>::size_type j = 0; j < arr.size() - i - 1; j++)
			{
				if (arr[j] > arr[j + 1])
					swap(arr, j, j + 1);
			}
		}
	}
};

//for test 
bool isEqual(vector<int> &arr1, vector<int> &arr2)
{
	if ((arr1.begin() == arr1.end()&&arr2.begin() != arr2.end()) || (arr2.begin() == arr2.end()&&arr1.begin() != arr1.end()))
		return false;
	if ((arr1.begin() == arr1.end()&&arr2.begin() == arr2.end()))
		return true;
	for (vector<int>::size_type i = 0; i < arr1.size(); i++)
	{
		if (arr1[i] != arr2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int testTime = 500;
	int maxSize = 100;
	int maxValue = 100;
	bool succeed = true;
	
	srand(int(time(0)));
	
	vector<int> testVector1, testVector2;
	//vector预分配空间
	testVector1.resize(maxSize);
	testVector2.resize(maxSize);
	
	for (int i = 0; i < testTime; i++)
	{
		int vectorSize = rand() % maxSize;
		for (int j = 0; j < vectorSize; j++)
		{
			//向量值随机
			testVector1[j] = testVector2[j] = rand() % maxValue;
		}
		//比较自定义排序和STL排序
		Solution::BubbleSort(testVector1);
		sort(testVector2.begin(), testVector2.end());
		if (!isEqual(testVector1, testVector2))
		{
			succeed = false;
			break;
		}
		cout << "验证次数:"<<i <<"\t向量大小\t" << vectorSize << endl;
	}	
	cout << (succeed?"算法验证成功!!":"算法验证失败!!!")<< endl;
	vector<int> testVector;
	int vectorSize = rand() % maxSize;
	testVector.resize(vectorSize);
	for (int j = 0; j < vectorSize; j++)
	{
		testVector[j] = rand() % maxValue;
	}
	cout << "排序前"<<"\t排序元素个数"<< vectorSize << endl;
	printVector(testVector);
	Solution::BubbleSort(testVector);
	cout << "排序后" << "\t排序元素个数" << vectorSize << endl;
	printVector(testVector);

	system("pause");
	return 0;
}


//git