#include<iostream>
#include<map>

using namespace std;

int main()
{
	map<int, int> NewMap;

	NewMap[0] = 10;
	NewMap[2] = 5;
	NewMap[5] = 1;
	NewMap[3] = 1;
	NewMap[6] = 1;
	NewMap[10] = 1;

	//

	for (int i = 0; i < 6; i++)
	{
	cout << NewMap[i]<<endl;

	}

}