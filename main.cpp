#include <iostream>
#include <algorithm>

using namespace std;

//最大连续子序列之和
/*void test(){
	int arr[] = {-2, 11, -4, 13, -5, -2};
	int number = sizeof(arr) / sizeof(arr[0]);
	int max = 0, sum = 0;

	for(int i = 0;i < number; i++){
		sum += arr[i];
		if(sum > max)
			max = sum;
		if(sum < 0)
			sum = 0;
	}
	cout << max << endl;
}*/

//最长递增自子序列 {-2,11,13,17,18}
/*void test(){
	int arr[] = {-2, 11, -4, 13, 17, -3, 18};
	int n = sizeof(arr) / sizeof(arr[0]);
	int length[n]{1};

	for(int i = 1; i < n; i++){
		int xxx[n]{0};
		int max{0};
		for(int j = 0; j < i; j++){
			if(arr[i] > arr[j])
				xxx[j] = length[j] + 1;
		}
		for(int k = 0; k < n; k++){
			if(xxx[k] > max)
				max = xxx[k];
		}
		length[i] = max;
	}

	int max{0};
	for(int i = 0; i < n; i++){
		if(length[i] > max)
			max = length[i];
	}
	cout << max << endl;
}*/

//掘金和背包
void swap(int a[], int b[])
{
	for(int i = 0; i < 10; i++){
		a[i] = b[i];
	}
}
void test()
{
	int n = 5;
	int w = 10;
	int g[n] = {6,3,5,4,6};
	int p[n] = {2, 2, 6, 5, 4};

	int preResults[10];
	int results[10];

	for (int i = 0; i < w; i++)
		preResults[i] = i+1 < p[0] ? 0 : g[0];


	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (j+1 < p[i])
				results[j] = 0;
			else
			{
				int num = j - p[i] < 0 ? 0 : j - p[i];
				results[j] = std::max(preResults[j], preResults[num] + g[i]);
			}
		}

		for (int i = 0; i < w; i++)
		{
			cout << results[i] << endl;
		}
		printf("\n");
		swap(preResults, results);
	}
	cout << results[w - 1] << endl;
}
int main()
{
	test();
	return 0;
}