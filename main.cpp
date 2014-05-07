#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <fstream>
//#include "Enemy.h"
//#include "Character1.h"

using namespace std;
struct role { int hp; int str; int  def;int  lv; int  money;};



void monsterImage()
{
    string line;
    ifstream myfile4 ("Dragon.txt");
    if (myfile4.is_open())
    {
        while(getline(myfile4, line))
        {
            cout << line << "\n";
        }
        myfile4.close();
    }
    sleep(2);
}

void fightImage()
{
    string line;
    for(int i = 0; i < 2; i++)
    {
        line = "";
        ifstream myfile5 ("FightScene1.txt");
        if (myfile5.is_open())
        {
            while(getline(myfile5, line))
            {
                cout << line << "\n";
            }
            myfile5.close();
        }

        sleep(1);

        line = "";
        ifstream myfile6 ("FightScene2.txt");
        if (myfile6.is_open())
        {
            while(getline(myfile6, line))
            {
                cout << line << "\n";
            }
            myfile6.close();
        }
        sleep(1);
    }

}

void fight(role &player,role enemy)
{
    enemy.hp = 20;
    cout<<"------------------------"<<endl
    <<"Monster appears!"<<endl;

    monsterImage();

    int choose;
    while(player.hp>0 && enemy.hp>0)
    {
        cout<<"Please enter a number between 1 and 4 : " << endl
        <<"1.atteck"<<endl
        <<"2.defence"<<endl
        <<"3.item"<<endl
        <<"4.escape"<<endl;
        cin>>choose;
        switch(choose)
        {
            case 1:
                fightImage();
                enemy.hp=enemy.hp-((player.str-enemy.def)*2);
                player.hp=player.hp-(enemy.str-player.def);

                if ( (player.str-enemy.def) <= 0)
                    cout << "You inflicted 0 damage on the enemy." << endl;
                else
                    cout<<"You inflicted "<<((player.str-enemy.def)*2)<<" damage on the enemy."<<endl;

                if(enemy.str-player.def <= 0)
                    cout<<"Enemy inflicted 0 damage on you."<<endl;
                else
                    cout<<"Enemy inflicted "<<(enemy.str-player.def)<<" damage on you."<<endl;
                break;

            case 2:
                player.hp=player.hp-(enemy.str-player.def);
                cout<<"you got "<<(enemy.str-player.def)<<" damaged"<<endl;
                break;
            case 3:
                cout<<"your've got nothing!"<<endl;
                break;
            case 4:
                cout << "You have successfully escaped.";
                return;
        }
    }
    if(player.hp<=0)
    {
        cout<<"you die!"<<endl
        <<"game over!"<<endl;
        exit(0);
    }
    else
    {
        cout<<"you win!"<<endl;
        cout<<"you got "<<enemy.money<<endl;
        player.money += enemy.money;
    }

}

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



void castleImage()
{


}




int main(int argc, char *argv)
{
    string line1, line2;

    for(int i = 0; i < 5; i++)
    {
        ifstream myfile ("GameNameImage.txt");
        if (myfile.is_open())
        {
            while(getline(myfile, line1))
            {
                cout << line1 << "\n";
            }
            myfile.close();
        }

        sleep(1);

        line1 = "";
        ifstream myfile2 ("GameNameImage2.txt");
        if (myfile2.is_open())
        {
            while(getline(myfile2, line1))
            {
                cout << line1 << "\n";
            }
            myfile2.close();
        }
        sleep(1);
    }

    //sleep(5);

    ifstream myfile3 ("CastleImage.txt");
    if (myfile3.is_open())
    {
        while(getline(myfile3, line2))
        {
            cout << line2 << "\n";
        }
        myfile3.close();
    }
    sleep(4);
    enemyInfo();

    // area decision variables
    int areaChoice1, direction;
    string coin;

    cout << " Please select the player's category: "<<endl;
    cout << "*====================================*"<<endl << endl;
    cout << "Enter a number between 1 and 6." << endl << endl;
    cout << "1. Paladin" << endl;
    cout << "2. Mage" << endl;
    cout << "3. Assassin" << endl;
    cout << "4. Warrior" << endl;
    cout << "5. Archer" << endl;
    cout << "6. Master Darren Maczka" << endl;

    cout << endl;
    char playerCategory;

    int flag = 0;
    while ( flag == 0 )
    {
        cin >> playerCategory;
        flag = playerInfo(playerCategory, flag);
    }

    // enemy variables
    int z1HP = 5, z2HP = 8;
    string attChoice, attChoice2;
    string choice;
    cout << "\t\t\t*__________________________*\n"
    << "\t\t\t      Act 1: Lost      \n"
    << "\t\t\t*__________________________*\n\n\n\n"

    << "After a long night of running, you encounter a town. The town appears\n"
    << " to be quiet and there is no sign of those terrible creatures. You need\n"
    << " to search the town for other survivors and items. If you find other \n"
    << " people they can help you out. There is stength in numbers.\n\n";

areaSelection:
    do{
        cout<< " Where do you want to go\n"
        << "1 - Super Market\n"
        << "2 - Petrol Station\n"
        << "3 - Internet Cafe\n"
        << "4 - DIY Store\n"
        << "5 - I have had enough searching, i want to leave the town\n\n"

        << "Please enter either 1,2,3,4 or 5\n\n";
        cin >>areaChoice1;
        cout << "\n";

        switch (areaChoice1){
            case 1:
                cout << "You enter through the large revolving doors, revealing a super\n"
                << "market. After gourging on a few snacks, you notice a golden \n"
                << "coin on the floor by the doorway.\n\n"

                << "Would you like to pick the coin up?\n\n";
                cin >> coin;
                cout << "\n";
                if (coin == "yes")
                {
                    player.money += 2;
                    cout <<"You pick up the coin, it has the words 'Lucky Coin' engraved on the side of it.\n"
                    <<"Your luck skill has increased and is now " << player.money << "\n\n";
                }
                else
                {
                    cout << "You choose to ignore the coin and exit the shop\n\n";
                }

                break;
            case 2:
                cout << "You are surrounded by petrol pumps and tins of oil. If you had a car this\n"
                << "would be your lucky day. However, you dont. You exit the station hastily\n\n";

                break;
            case 3:
                player.str += 5;
                player.money += 5;
                player.def += 5;
                player.hp += 5;

                cout << "You enter the internet cafe and see a strange shadow in the right-hand\n"
                << " corner. You mutter the word 'h-h-hello....?' There is no reply. All of \n"
                << "a sudden you hear the sound of a gun cocking. The shadow comes forth and you\n"
                << " see the face of a young woman. 'Oh my god! I thought you were one of them!' \n"
                << "shouts the young woman. As you talk with her, you learn that there is an army \n"
                << "outpost to the north in a town called 'Rivet Falls'. The young woman's name is \n"
                << "Theresa, and she joins your party. Now that you have a second member, your\n."
                << "stats will increase\n\n"
                << "Your stats are now: \n\n"
                << player.str << " Strength\n"
                << player.money << " Money\n"
                << player.def << " Defense\n"
                << player.hp << " Hitpoints\n\n";

                break;
            case 4:
                cout << "After searching the store, all you can find is tools and equipment, nothing\n"
                << "of use as you already have enough equipment as it is.\n\n";
                break;
            case 5:
                cout << "You make haste towards the northern area, heading towards the army outpost\n"
                << "with your new found friend\n\n";
            default:
                cout << "Incorrect entry.\n";
        }
    }while (areaChoice1 !=5);

    cout << "As you begin to leave the town, you hear faint moaning sounds\n"
    << "in the distance. All of a sudden Theresa shouts 'Look! Behind us!'\n"
    << "The horde of zombies staggers towards the both of you. What would\n"
    << "you like to do? Run or Attack? (Please enter 1 to 'run' or 2 to 'attack')\n\n";
    cout << "Zombie HP: " << z1HP << "     Your HP: " << player.hp << "\n\n";

    cin >> attChoice;

    if (attChoice == "1")
    {
        if (player.def > 1)
        {
            cout << "You have successfully escaped from the zombies." << endl << endl;
            goto areaSelection;
        }
        else
        {
            cout << "No running from here";
        }
    }
    else
    {
        cout << "\t\t\t*__________________________*\n"
        << "\t\t\t      Zombie Horde Attack     \n"
        << "\t\t\t*__________________________*\n\n\n";

        fight(player, zombie);

        do{
            cout << "Now that you and Theresa are safe for now, you need to decide\n"
            << "which direction you would like to travel:\n\n"
            << "1 - North\n"
            << "2 - East\n"
            << "3 - South\n"
            << "4 - West\n"
            << ""
            << "Please enter 1,2,3 or 4.\n\n";

            cin  >> direction;

            switch (direction){
                case 1: cout << "You begin to travel north. After a long walk you notice a\n"
                    << "bright structure in the background. You reach the structure\n"
                    << "and realise that it is a hospital. You can hear voices shouting\n"
                    << "and asking for help. The hospital has seen some dark times and\n"
                    << "does not look welcoming. However - you cannot ignore the voices.\n"
                    << "You and thersea open the doors.\n\n"
                    << "\t\t\t*__________________________*\n"
                    << "\t\t\t      End of Level 1      \n"
                    << "\t\t\t*__________________________*\n\n\n\n";
                    break;


                case 2: cout << "You begin to travel East. However, after a while of travelling\n"
                    << "you are confronted by more zombies, you will have to fight this\n"
                    << "time, so what stance would you like to take? Offensive of defensive?\n";
                    cout << "Please enter 1 for Offensive and 2 for Defensive.\n\n";
                    cout << "Zombie HP: " << z2HP << "     Your HP: " <<player.hp << "\n\n";

                    cin >> attChoice2;

                    if (attChoice == "1")
                    {
                        cout << "\t\t\t*__________________________*\n"
                        << "\t\t\t      Zombie Horde Attack     \n"
                        << "\t\t\t*__________________________*\n\n\n";

                        fight(player, zombie);

                        cout << "After the encounter you contine your journey east. You eventually\n"
                        << " see abright structure in the background. You reach the structure\n"
                        << "and realise that it is a hospital. You can hear voices shouting\n"
                        << "and asking for help. The hospital has seen some dark times and\n"
                        << "does not look welcoming. However - you cannot ignore the voices.\n"
                        << "You and thersea open the doors.\n\n"
                        << "\t\t\t*__________________________*\n"
                        << "\t\t\t      End of Level 1      \n"
                        << "\t\t\t*__________________________*\n\n\n\n";
                    }
                    else if (attChoice == "2")
                    {
                        cout << "\t\t\t*__________________________*\n"
                        << "\t\t\t      Zombie Horde Attack     \n"
                        << "\t\t\t*__________________________*\n\n\n";

                        fight(player, troll);

                        cout<< "After the encounter you contine your journey east. You eventually\n"
                        << " see abright structure in the background. You reach the structure\n"
                        << "and realise that it is a hospital. You can hear voices shouting\n"
                        << "and asking for help. The hospital has seen some dark times and\n"
                        << "does not look welcoming. However - you cannot ignore the voices.\n"
                        << "You and thersea open the doors.\n\n"
                        << "\t\t\t*__________________________*\n"
                        << "\t\t\t      End of Level 1      \n"
                        << "\t\t\t*__________________________*\n\n\n\n";
                    }
                    break;

            case 3:
                    cout << "You see a cave in front of you. Do you want to exploit the cave or"
                         << " do you want to go back?" << endl;
                    cout << "Type go to enter inside or type leave to go back." << endl;

                    //int i;
                    //cin >> i;
                    cin >> choice;
                    if (choice == "go")
                    {


                    }
                    //else
                    else if(choice == "leave")
                    {
                        cout << "You have left the cave." << endl;
                    }
                    break;

            case 4: cout << "You begin to travel South. However, you realise that this is\n"
                    << "the way you originally came from - so you turn back.\n";
                break;

                default:
                    cout << "Incorrect entry.\n\n";
                    break;

            }
        }while (direction != 1) ;
    }

    /* TO DO:
     # add details on party escape from town & opening to next level
     # fix grammar, whitespace & text errors.
     # add more description
     # look into other ways of performing attack program
     # add detailed intro into level and game - instructions, info etc
     */


    //system ("pause");
    return 0;

}



