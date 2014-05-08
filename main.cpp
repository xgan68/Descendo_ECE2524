#include <iostream>
#include <stdlib.h>
#include <string>
#include <unistd.h>
#include <fstream>
#include "Battle.h"
#include "Animation.h"
//#include "Enemy.h"
//#include "Character1.h"









int main()//(int argc, char *argv)
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
    << "\t\t\t      Act 1: The Lost Orb      \n"
    << "\t\t\t*__________________________*\n\n\n\n"

    << "After decades of searching, you encounter a castle. The castle\n"
    << "appears to be abandoned and there is no sign of dragons. You need\n"
    << "to search the castle for clues and items. If you find other \n"
    << "people they can help you out, but you must act swiftly.\n"
       << "There are nearby dragons approaching.\n\n";
areaSelection:
    do{
        cout<< " Where do you want to go\n"
        << "1 - Armory\n"
        << "2 - Chieftain's Room\n"
        << "3 - Castle's Mystic Pool\n"
        << "4 - Food Storage\n"
        << "5 - I am intolerable of this village.  I must leave.\n\n"

        << "Please enter either 1, 2, 3, 4 or 5\n\n";
        cin >>areaChoice1;
        cout << "\n";

        switch (areaChoice1){
            case 1:
            cout << "You have entered the armory.  After going through scraps of metals\n"
                 <<  " and weaponry, you discover money under the pile.\n"
                  << "Do you want to pick the money up?\n\n"

                << "Would you like to pick the coin up?\n\n";
                cin >> coin;
                cout << "\n";
                if (coin == "yes")
                {
                    player.money += 2;
                    cout <<"You picked up the money and put it away in your inventory.\n"
                        << "Suddenly, you feel richer.\n"
                    <<"Your money has increased and is now "<< player.money << "\n\n";
                }
                else
                {
                    cout << "You choose to ignore the money and exit the shop\n\n";
                }

                break;
            case 2:
                    cout << "The Cheiftain's Room has many documentations on the village's history.\n"
                         << "However, the Castle appears not to have any connections with the sacred orb.\n"
                         << "You exit the Cheiftain's Room immediately\n\n";

                break;
            case 3:
                player.str += 5;
                player.money += 5;
                player.def += 5;
                player.hp += 5;

                cout << "You find the Castle's Mystic Pool and see a strange shadow in front of the\n"
                     << "water.  You approach this shadow cautiously, but it appears to be a \n"
                     << "fox spirit ghost.  It begins to speak to you and tells you the true\n"
                     << "history of the Castle.  The Castle was pillaged by dragons, \n"
                     << "and they took the orb to their hidden cavern down South. Also, it \n"
                     << "explains how this pool has special properties and if you drink some,\n"
                     << "you will find new powers.  You just drank from the Mystic Pool.\n\n"
                << "Your stats are now: \n\n"
                << player.str << " Strength\n"
                << player.money << " Money\n"
                << player.def << " Defense\n"
                << player.hp << " Hitpoints\n\n";

                break;
            case 4:
                cout << "You enter the village's food store, but all you can find are stale and rotten food.\n"
                     << "This village seems to have been abandoned for a long time due to the stench."
                     << "You leave Immediately.\n\n";
            break;
            case 5:
                cout << "You leave the village and head South , which is heading towards the demonic \n"
                     << " cavern with your new found powers.\n\n";
            default:
                cout << "Incorrect entry.\n";
        }
    }while (areaChoice1 !=5);

    cout << "As you begin to leave the Castle, you sense a disturbance\n"
    << "nearby. All of a sudden, you turn around and fend off a Dragon.\n"
    << "There is a horde of dragons swiftly heading towards you. What would\n"
    << "you like to do? Run or Attack? (Please enter 'run' or 'attack')\n\n";
    cout << "Dragon HP: " << z1HP << "     Your HP: " << player.hp << "\n\n";

    cin >> attChoice;

    if (attChoice == "1")
    {
        if (player.def > 1)
        {
            cout << "You have successfully escaped from the Dragon." << endl << endl;
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
        << "\t\t\t      Dragon Horde Attack     \n"
        << "\t\t\t*__________________________*\n\n\n";

        fight(player, zombie);

        do{
            cout << "Now that you have deflected the Dragon attacks,"
                 << " you are safe for now.\n"
                 << "However, you have been driven off course.\n"
                 << "Which direction would you like to travel?:\n\n"
            << "1 - North\n"
            << "2 - East\n"
            << "3 - South\n"
            << "4 - West\n"
            << ""
            << "Please enter 1,2,3 or 4.\n\n";

            cin  >> direction;

            switch (direction){
            // north leads to your death because you forgot the village was in that direction
                case 1: cout << "You begin to travel North. After a long walk you noticed \n"
                    << "another bright structure in the background. You reach the structure\n"
                    << "and realise that it is the same village.  You hear the flames blazing\n"
                    << "out of the dragons from the previous horde you have defended off.\n"
                    << "You have been heavily damaged from the previous fight and are killed\n"
                    << "by the horde of dragons.\n"
                    << "You have failed.\n"
                    << "\t\t\t*__________________________*\n"
                    << "\t\t\t      Game Over      \n"
                    << "\t\t\t*__________________________*\n\n\n\n";
                    break;


                case 2: cout << "You begin to travel East. However, after a while of travelling\n"
                    << "you are confronted by more Dragons, you will have to fight this\n"
                    << "time, so what stance would you like to take? Offensive of defensive?\n";
                    cout << "Please enter 1 for Offensive and 2 for Defensive.\n\n";
                    cout << "Dragon HP: " << z2HP << "     Your HP: " <<player.hp << "\n\n";

                    cin >> attChoice2;

                    if (attChoice == "1")
                    {
                        cout << "\t\t\t*__________________________*\n"
                        << "\t\t\t      Dragon Horde Attack     \n"
                        << "\t\t\t*__________________________*\n\n\n";

                        fight(player, zombie);
                        cout << "You continue to travel East. However, you find yourself in front\n"
                             << "of an impassable mountain.  So you turn back.\n";


                    }
                    else if (attChoice == "2")
                    {
                        cout << "\t\t\t*__________________________*\n"
                        << "\t\t\t      Dragon Horde Attack     \n"
                        << "\t\t\t*__________________________*\n\n\n";

                        fight(player, troll);

                        cout << "You continue to travel East. However, you find yourself in front\n"
                             << "of an impassable mountain.  So you turn back.\n";
                    }
                    break;

            case 3:
                    cout << "As you are traveling South, You see a cave in front of you.\n"
                         << "Do you want to exploit the cave or"
                         << " do you want to go back?" << endl;
                    cout << "Type go to enter inside or type leave to go back." << endl;

                    //int i;
                    //cin >> i;
                    cin >> choice;
                    if (choice == "go")
                    {
                        cout << "After traveling within the cave, you find the sacred orb.\n"
                             << "You leave immediately and have completed your mission\n\n";
                    }
                    //else
                    else if(choice == "leave")
                    {
                        cout << "You have left the cave." << endl;
                    }
                    break;

            case 4: cout << "You begin to travel West. However, there is nothing to be seen\n"
                << "here.  This area appears to pillaged my dragons due to the burned marks.\n"
                << "So you turn back\n";
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
