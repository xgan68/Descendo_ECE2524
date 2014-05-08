#ifndef ROLE_H
#define ROLE_H

using namespace std;
struct role { int hp; int str; int  def;int  lv; int  money;};

role troll, zombie, dragon, demon;
role player;



void enemyInfo()
{
    // Zombies
    zombie.hp = 10;
    zombie.str = 5;
    zombie.def = 2;
    zombie.money = 10;

    /* These enemy roles have not been implemented. The program can be
       made better and more challenging by implementing these roles.
    // Troll
    troll.hp = 30;
    troll.str = 10;
    troll.def = 3;
    troll.money = 100;

    // Dragon
    dragon.hp = 99;
    dragon.str = 20;
    dragon.def = 10;
    dragon.money = 500;

    // Demons
    demon.hp = 150;
    demon.str = 30;
    demon.def = 20;
    demon.money = 1000;
    */
}

int playerInfo(char playerCategory, int flag)
{
    switch (playerCategory)
    {
        case '1':           // Paladin
            player.hp  = 27;
            player.str = 12;
            player.def = 11;
            player.money = 100;
            flag = 1;
            break;

        case '2':           // Mage
            player.hp  = 24;
            player.str = 16;
            player.def = 10;
            player.money = 100;
            flag = 1;
            break;

        case '3':           // Assassin
            player.hp = 25;
            player.str = 20;
            player.def = 10;
            player.money = 100;
            flag = 1;
            break;

        case '4':           // Warrior
            player.hp = 33;
            player.str = 4;
            player.def = 13;
            player.money = 100;
            flag = 1;
            break;

        case '5':           // Archer
            player.hp = 20;
            player.str = 20;
            player.def = 10;
            player.money = 100;
            flag = 1;
            break;

        case '6':          // Darren
            player.hp  = 30;
            player.str = 30;
            player.def = 30;
            player.money = 100;
            flag = 1;
            break;

        default:
            cout << "Please enter a number between 1 and 6." << endl;
            flag = 0;
            break;
    }
    return flag;
}


#endif // ROLE_H
