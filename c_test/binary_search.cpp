
#include <iostream>
#include <cassert>

using namespace std;

#define MAX_NUMBERS  64
#define TRUE         1
#define FALSE        0

int binary_search_iteration(int tb[], int n, int key)
{
	int ret = -1;
	int start = 0;
	int end = n;
	int pos = 0;

	while((start <= end))
	{
		pos = (end + start ) / 2 ; 
		// cout<<"start : "<<start<<" end : "<<end<<" cur : "<<tb[pos]<<endl;

		if (tb[pos] == key)
		{
			ret = pos;
			break;
		}
		else if (tb[pos] < key)
		{
			start = pos + 1;
		}
		else
		{
			end = pos - 1;
		}	
	}
	

	return ret;
}

int binary_search_recursively(int tb[], int start, int end, int key)
{
	int ret = -1;
	int pos = (start + end) / 2;
	
	if (start > end)
	{
		return ret;
	}

	if(tb[pos] == key)
	{
		ret = pos;
	}
	else if (tb[pos] < key)
	{
		ret = binary_search_recursively(tb, pos + 1, end, key);
	}
	else
	{
		ret = binary_search_recursively(tb, start, pos - 1, key);
	}

	return ret;
}

void test_case(void)
{
	int numbers[MAX_NUMBERS] = {0};

	for (int i = 0; i < MAX_NUMBERS; ++i)
	{
		numbers[i] = (2 * i + 3) / 2 + i;
		cout<<numbers[i]<<" ";
	}
	cout<<endl;

	assert(-1 == binary_search_iteration(numbers, MAX_NUMBERS, -1));
	assert(-1 == binary_search_iteration(numbers, MAX_NUMBERS, 66));
	assert(34 == binary_search_iteration(numbers, MAX_NUMBERS, 69));
	assert(13 == binary_search_iteration(numbers, MAX_NUMBERS, 27));
	assert(55 == binary_search_iteration(numbers, MAX_NUMBERS, 111));

	assert(44 == binary_search_recursively(numbers, 0, MAX_NUMBERS-1, 89));
	assert(25 == binary_search_recursively(numbers, 0, MAX_NUMBERS-1, 51));
	assert(61 == binary_search_recursively(numbers, 0, MAX_NUMBERS-1, 123));
	assert(8 == binary_search_recursively(numbers, 0, MAX_NUMBERS-1, 17));
	assert(-1 == binary_search_recursively(numbers, 0, MAX_NUMBERS-1, 150));

	cout<<"test passed!"<<endl;
}

int main(int argc, char const *argv[])
{
	test_case();	
	return 0;
}
