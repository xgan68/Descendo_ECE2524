#ifndef ANIMATION_H
#define ANIMATION_H
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






void castleImage()
{


}

#endif // ANIMATION_H
