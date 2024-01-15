#include<iostream>
#include<ConsoleEngine/EngineDebug.h>
#include<vector>
int main()
{
	{
		std::vector<int> MyVector = std::vector<int>(5);


		std::cout << MyVector.capacity() << std::endl;
		std::cout << MyVector.size();
		MyVector.resize(10);
		std::cout << MyVector.capacity() << std::endl;
		std::cout << MyVector.size();
		MyVector.resize(5);
		std::cout << MyVector.capacity() << std::endl;
		std::cout << MyVector.size();

	}

	//{
	//	std::vector<int> Newvector = std::vector<int>();
	//
	//	Newvector.reserve(10);
	//
	//	for (int i = 0; i < 12; i++)
	//
	//	{
	//		Newvector.push_back(i);
	//	}
	//	for (int i = 0; i < Newvector.size(); i++)
	//
	//	{
	//		std::cout << Newvector[i] << std::endl;
	//	}
	//	std::cout << "출력끝" << std::endl;
	//	Newvector.resize(3);
	//
	//	for (int i = 0; i < Newvector.size(); i++)
	//
	//	{
	//		std::cout << Newvector[i] << std::endl;
	//	}
	//}

	//
}

/*  왜 이상하게 나오는지 궁금하다..
0
1
2
3
4
0
1
2
*/

//템플릿 클래스를 쉽게 만들고 이해하는 방법

