#include "StatusUnit.h"

#include <iostream>
void StatusUnit::StatusRender()
{
	int Size = printf_s("%s", Name);
	for (int i = 0; i < 50-Size; i++)
	{
		printf_s("-");
	}
	printf_s("\n");
	printf_s("공격력 최소 %d ~ 최대%d\n", MinAtt, MaxAtt);
	printf_s("Hp : %d\n", Hp);
	printf_s("Gold %d\n",Gold);

	for(int i=0;i<50;i++)
	{
	printf_s("-");
	}
	printf_s("\n");


}