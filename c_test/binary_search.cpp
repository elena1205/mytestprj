
#include <iostream>
#include <cassert>

using namespace std;

#define MAX_NUMBERS  64
#define TRUE         1
#define FALSE        0

int binary_search(int tb[], int n, int key)
{
	int ret = FALSE;
	int start = 0;
	int end = n - 1;

	while(start < end)
	{
		cout<<"start : "<<start<<" end : "<<end<<" cur : "<<tb[(end - start + 1) / 2 + start]<<endl;

		if (tb[(end - start + 1) / 2 + start] == key)
		{
			ret = TRUE;
			break;
		}
		else if (tb[(end - start + 1) / 2 + start] < key)
		{
			start = (end - start + 1) / 2 + start;
		}
		else
		{
			end = (end - start + 1) / 2 + start;
		}	
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

	assert(binary_search(numbers, MAX_NUMBERS, 66));

}

int main(int argc, char const *argv[])
{
	test_case();	
	return 0;
}
