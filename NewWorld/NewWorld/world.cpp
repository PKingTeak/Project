#include<iostream>
#include<conio.h>
#include "Player.h"
#include "Monster.h"
#include "FightZone.h"
#include "Town.h"
int main()
{
    
   //random seed
    int Value = 0;
    __int64 Seed = reinterpret_cast<__int64>(&Value);
    srand(static_cast<unsigned int>(Seed));
    FightZone FightZone;
    Town Town;
    Player NewPlayer = Player();
    NewPlayer.SetName("PKT");

    while (true)
    {
        NewPlayer.StatusRender();
        printf_s("어디로 가시겠습니까?\n");
        printf_s("1번 마을\n");
        printf_s("2번 던전\n");

        int input = _getch();

        switch (input)
        {
        case '1':
            Town.In(NewPlayer);
            break;
        case '2':
            FightZone.In(NewPlayer);
            break;
        default:
            break;
            
        }

            _getch();
        system("cls");
    }
    //fightZone
    //town


}