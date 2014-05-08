#ifndef BATTLE_H
#define BATTLE_H
#include "Role.h"
#include "Animation.h"
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
#endif // BATTLE_H
