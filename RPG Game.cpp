#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>

using namespace std;

struct Playerdata
{
    string name;
    int age;
    string gender;
};

int save = 0;
int save1 = 0;
bool firstGemFound = false;
int monsterHealth = 100;
int heroHealth = 100;

void power(int &health)
{
    int ch;
    int damage = 1;
    do
    {
        cout << "1. decrease health" << endl;
        cout << "2. Double damage" << endl;
        cout << "3. Lightening spell" << endl;
        cin >> ch;
        save = ch;
        switch (ch)
        {
        case 1:
            health -= 30;
            break;
        case 2:
            damage *= 2;
            break;
        case 3:
            health -= 50;
            break;
        default:
            cout << "Invalid choice, please try again." << endl;
            continue;
        }
        break;
    } while (true);
}
void attack()
{
    int ch;
    cout << "1. Punch" << endl;
    cout << "2. Kick" << endl;
    cout << "3. Combo attack" << endl;
    cin >> ch;
    save1 = ch;
    switch (ch)
    {
    case 1:
        cout << "You punched the villager." << endl;
        break;
    case 2:
        cout << "You kicked the villager." << endl;
        break;
    case 3:
        cout << "You performed a combo attack on the villager." << endl;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void attack1(int &health)
{
    int ch;
    cout << "1. Punch" << endl;
    cout << "2. Kick" << endl;
    cout << "3. Combo attack" << endl;
    cout << "4. You want to use your special powers" << endl;
    cin >> ch;
    save1 = ch;
    switch (ch)
    {
    case 1:
        cout << "You punched the Monster. Monster health is " << health - 10 << endl;
        health -= 10;
        break;
    case 2:
        cout << "You kicked the Monster. Monster health is " << health - 20 << endl;
        health -= 20;
        break;
    case 3:
        cout << "You performed a combo attack on the Monster. Monster health is " << health - 30 << endl;
        health -= 30;
        break;
    case 4:
        power(health);
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void attack2(int &health)
{
    int random = rand() % 3 + 1;
    int ch;
    cout << "1. Punch" << endl;
    cout << "2. Kick" << endl;
    cout << "3. Combo attack" << endl;

    save1 = ch;
    switch (random)
    {
    case 1:
        cout << "Monster punch the hero. Hero health is " << health - 10 << endl;
        health -= 10;
        break;
    case 2:
        cout << "Monster king the hero. Hero health is " << health - 20 << endl;
        health -= 20;
        break;
    case 3:
        cout << "Monster performed a combo attack on the hero. Hero health is " << health - 30 << endl;
        health -= 30;
        break;
    default:
        cout << "Invalid choice." << endl;
        break;
    }
}

void interactWithVillager(const string &name, const string &villagerType)
{
    bool senti = true;
    do
    {
        cout << "Hi...\nI am here to find a gem of a crown\nCan you help me?" << endl;
        int random = rand() % 2 + 1;
        if (random == 1)
        {
            cout << name << " is ready to help you." << endl;
            int ch;
            cout << "1. Give me information about the gem" << endl;
            cout << "2. You want to attack the villager" << endl;
            cin >> ch;
            switch (ch)
            {
            case 1:
                if (villagerType == "Jack")
                {
                    cout << "Jack: Oh, you're here to find a gem. One of the gems is in the village." << endl;
                    int ch1;
                    cout << "Hero:\n1. Where is it?\n2. Give me any hint to find the gem." << endl;
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                    case 2:
                        cout << "Jack: I don't know where it is, but I know it is in the village." << endl;
                        senti = false; // Exit loop after getting information
                        break;
                    }
                }
                else if (villagerType == "Farmer")
                {
                    cout << "Farmer: Oh, you're here to find a gem. One of the gems is in the village." << endl;
                    int ch1;
                    cout << "Hero:\n1. Where is it?\n2. Give me any hint to find the gem." << endl;
                    cin >> ch1;
                    switch (ch1)
                    {
                    case 1:
                        cout << "Farmer: I don't know the exact location but their name starts with T!" << endl;
                        senti = false; // Exit loop after getting information
                        break;
                    case 2:
                        cout << "Farmer: You might find a gem in someone's house, and their name starts with T." << endl;
                        senti = false; // Exit loop after getting information
                        break;
                    }
                }
                else if (villagerType == "Tommy")
                {
                    Playerdata player;
                    cout << "Tommy: Oh, you're here to find a gem. I own one of the gems." << endl;
                    int ch1;
                    cout << "Hero:\n1. Give me that Gem" << endl;
                    cin >> ch1;
                    if (ch1 == 1)
                    {
                        cout << "Tommy: Okay, I will give you the gem if you promise me that you will find all the gems of the crown and bring brightness to the Kingdom again!" << endl;
                        int ch7;
                        cout << "1. Promise" << endl;
                        cout << "2. Not Promise" << endl;
                        cin >> ch7;
                        switch (ch7)
                        {
                        case 1:
                            cout << "You promised Tommy and received one of the GEMS." << endl;
                            cout << "Congrats! You have your first GEM." << endl;
                            char save;
                            firstGemFound = true;
                            senti = false;
                            break;
                        case 2:
                            cout << "Unfortunately! Tommy denied giving you the GEM." << endl;
                            break;
                        }
                    }
                }
                break;
            case 2:
                attack();
                break;
            }
        }
        else
        {
            cout << name << " is not ready to help you." << endl;
            int ch3;
            cout << "Do you want to attack the villager? (press 1 for yes and 2 for no)" << endl;
            cin >> ch3;
            switch (ch3)
            {
            case 1:
                attack();
                break;
            case 2:
                break;
            }
        }
    } while (senti);
}

void fisherman(const string &name, const string &villagerType)
{
    bool trading = true;
    bool gun = false;
    do
    {
        if (villagerType == "Fisherman")
        {
            cout << "Fisherman: Hi! How can I help you?" << endl;
            int ch1;
            cout << "Hero: I came to know that you are selling weapons (press 1 to start trading):" << endl;
            cin >> ch1;
            if (ch1 == 1)
            {
                cout << "Fisherman: I am a trader. What do you want?" << endl;
                cout << "Hero:" << endl;
                cout << "1. I need a Knife" << endl;
                cout << "2. I need a Bomb" << endl;
                cout << "3. I need a Gun" << endl;
                cout << "4. End trading" << endl;

                int ch7;
                cin >> ch7;
                switch (ch7)
                {
                case 1:
                {
                    cout << "Fisherman: Here it is. It is very sharp, be careful." << endl;
                    int ch6;
                    cout << "Hero: How much for this? (press 1)" << endl;
                    cin >> ch6;
                    if (ch6 == 1)
                    {
                        cout << "Fisherman: It is only 14 Bucks!" << endl;
                        cout << "Fisherman: Do you want to buy it? (1 for Yes, 2 for No)" << endl;
                        int ch5;
                        cin >> ch5;
                        if (ch5 == 1)
                        {
                            cout << "Hero: Yes, I want to buy the knife." << endl;
                            cout << "You bought a knife from the Trader." << endl;
                            trading = false;
                        }
                        else if (ch5 == 2)
                        {
                            cout << "No, I don't want to buy the knife." << endl;
                            trading = false;
                        }
                        else
                        {
                            cout << "Invalid choice! Try again." << endl;
                        }
                    }
                    else
                    {
                        cout << "Invalid choice! Try again." << endl;
                    }
                    break;
                }
                case 2:
                {
                    cout << "Fisherman: If you want a bomb you must have a permit for it. Do you have a permit?" << endl;
                    int ch4;
                    cout << "Hero: (press 1 for yes and 2 for no)" << endl;
                    cin >> ch4;
                    if (ch4 == 1)
                    {
                        cout << "Fisherman: Please show me!" << endl;
                        cout << "Fisherman: Ok! You have a permit. You can buy a bomb." << endl;
                        cout << "1. To buy bomb\n2. To refuse to buy a bomb" << endl;
                        int ch3;
                        cin >> ch3;
                        switch (ch3)
                        {
                        case 1:
                            cout << "You bought a bomb!" << endl;
                            trading = false;
                            break;
                        case 2:
                            cout << "Ok, I will buy it later." << endl;
                            trading = false;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                        }
                    }
                    else if (ch4 == 2)
                    {
                        cout << "Fisherman: You are not able to buy a bomb." << endl;

                        cout << "1. I need a Knife" << endl;
                        cout << "2. I need a Bomb" << endl;
                        cout << "3. I need a Gun" << endl;
                        cout << "4. End trading" << endl;
                        cin >> ch7;
                    }
                    else
                    {
                        cout << "Invalid choice! Try again." << endl;
                    }
                    break;
                }
                case 3:
                {
                    cout << "Fisherman: So you want a gun." << endl;
                    cout << "Hero: (press 1 for yes and 2 for no)" << endl;
                    int ch4;
                    cin >> ch4;
                    if (ch4 == 1)
                    {
                        cout << "Fisherman: Here it is." << endl;
                        cout << "Hero: Yes, I want this one." << endl;
                        cout << "1. How much for this one?\n2. Refuse to buy the gun" << endl;
                        int ch3;
                        cin >> ch3;
                        switch (ch3)
                        {
                        case 1:
                            cout << "It's about 10 Bucks." << endl;
                            cout << "1. To buy gun" << endl;
                            int ch0;
                            cin >> ch0;
                            switch (ch0)
                            {
                            case 1:
                                cout << "Congrats! You purchased a gun." << endl;
                                gun = true;
                                trading = false;
                                break;
                            default:
                                cout << "Invalid choice." << endl;
                                break;
                            }
                            break;
                        case 2:
                            cout << "Ok, I will buy it later." << endl;
                            break;
                        default:
                            cout << "Invalid choice!" << endl;
                            break;
                        }
                    }
                    else if (ch4 == 2)
                    {
                        cout << "Hero: I will not show my permit." << endl;
                        cout << "Fisherman: You are not able to buy a gun." << endl;
                    }
                    else
                    {
                        cout << "Invalid choice! Try again." << endl;
                    }
                    break;
                }
                case 4:
                    cout << "Trading Ended..." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
                }
            }
        }

    } while (trading);
}

void village()
{
    cout << "                           Level 1" << endl;
    cout << "Hero found a village and decide to go there! " << endl;
    cout << "In the village He Intract with different villagers....." << endl;
    string arr[4] = {"Jack", "Farmer", "Tommy", "Fisherman"};
    string name;
    bool foundVillager = false;

    cout << "Names of villagers are:" << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }

    cout << "Enter the name of the villager you want to interact with: ";
    cin >> name;

    for (int i = 0; i < 4; i++)
    {
        if (name == arr[i])
        {
            foundVillager = true;
            cout << "Chat with " << name << endl;

            if (name == "Fisherman")
            {
                fisherman(name, arr[i]);
            }
            else
            {
                interactWithVillager(name, arr[i]);
            }

            break;
        }
    }
    if (!foundVillager)
    {
        cout << "No such villager found. Please try again." << endl;
    }
}

void forest(Playerdata &player, int &heroHealth, int &monsterHealth)
{
    bool gun = false; // Assuming gun is initialized elsewhere when the player buys it

    while (true)
    {
        cout << "                                 Level 2" << endl;
        cout << "Press (1) to enter Level 2: ";
        int n;
        cin >> n;

        if (n == 1)
        {
            if (!firstGemFound)
            {
                cout << "You need to find the first gem before you can enter Level 2." << endl;
                village();
                return;
            }
            else
            {
                break; // ✅ THIS IS MISSING
            }
        }
        else
        {
            cout << "Invalid choice. Returning to village." << endl;
            village();
            return;
        }
    }

    // Proceed with the rest of the forest function since conditions are met
    int random = rand() % 10 + 1;
    int num;
    int shoot = 3;
    cout << "2nd Location After finding first gem:" << endl;
    cout << "You enter the Forest and you see a large snake around a shiny chest. You may find something in the chest. You have to kill the snake before getting the chest (if you have a gun)." << endl;
    cout << "Guess the number to shoot the snake between 1 to 10: ";
    cin >> num;

    while (shoot > 0)
    {
        if (num == random)
        {
            cout << "Snake is shot down." << endl;
            break;
        }
        else
        {
            cout << "Target missed." << endl;
            shoot--;
            cout << "Shoots remaining: " << shoot << endl;
            if (shoot > 0)
            {
                cin >> num;
            }
        }

        if (shoot == 0)
        {
            cout << "Hero is dead (press 1 to restart game):" << endl;
            int restartChoice;
            cin >> restartChoice;
            if (restartChoice == 1)
            {
                forest(player, heroHealth, monsterHealth);
                return;
            }
            else
            {
                return;
            }
        }
    }

    cout << "There is a chest near the snake's body. You have to solve a problem to open this." << endl;
    string pro;

    cout << "Riddle: What has keys but can't open locks?" << endl;
    cout << "If you want to get a hint press H" << endl;
    cin >> pro;

    if (pro == "H" || pro == "h")
    {
        cout << "Hint: Keys have two colors!" << endl;
    }

    do
    {
        cout << "Your answer: ";
        cin >> pro;
        if (pro == "piano")
        {
            cout << "Correct Answer. Chest opens." << endl;
            cout << "Congrats! The 2nd GEM is found. Only one GEM is left." << endl;
            break;
        }
        else
        {
            cout << "Wrong Answer. Try again." << endl;
        }
    } while (true);
}

void cave()
{
    cout << "                                           Level 3" << endl;
    cout << "This is the Last stage of the game \nYou find 2 of the GEMS only 1 left. If you find it, the Kingdom will shine again and become happy.\n";
    cout << "Now you are in the cave and there is a monster in the cave. You have to kill him to get the GEM!!!" << endl;
    cout << endl;
    cout << "" << endl;
    cout << endl;
    int c;
    cout << "1. You want to talk with Monster" << endl;
    cout << "2. You want to attack the monster" << endl;
    cin >> c;
    switch (c)
    {
    case 1:
    {
        int c1;
        cout << "1. Why did you do this to the kingdom? Why did you hide all the gems of the crown and plunge the kingdom into darkness?" << endl;
        cin >> c1;
        switch (c1)
        {
        case 1:
            cout << "Monster (The Boss!): I did this to take control over the kingdom and spread darkness." << endl;
            cout << "You have to fight with Monster to get the gem" << endl;
            cout << "press (f) to start fight" << endl;
            char c2;
            cin >> c2;
            int heroHealth = 100;
            int monsterHealth = 100;
            if (c2 == 'f')
            {
                cout << "Fight started" << endl;
                do
                {
                    cout << "Your turn:" << endl;
                    attack1(monsterHealth);

                    if (monsterHealth <= 0)
                    {
                        cout << "Monster defeated!" << endl;
                        break;
                    }

                    cout << "Enemy Turn: " << endl;
                    attack2(heroHealth);

                    if (heroHealth <= 0)
                    {
                        cout << "You are defeated!" << endl;
                        break;
                    }

                    cout << "Your Remaining Health : " << heroHealth << endl;
                    cout << "Monster Health: " << monsterHealth << endl;
                } while (true);
                if (heroHealth > 0)
                {
                    cout << "Congrats! You found the 3rd or Last gem of the Crown \n By collecting all the gems you complete the promise from Tommy, and the kingdom shines and lives happily again." << endl;
                }
                else
                {
                    cout << "You are defeated! Game Over!" << endl;
                }
            }
            break;
        }
    }
    break;
    }
}
bool fileExists(string &filename)
{
    ifstream File(filename);

    return File.good();
}
void loadGame(Playerdata &player, string &filename)
{
    ofstream file(filename, ios::binary);
    file.write((char *)(&player), sizeof(Playerdata));
    file.close();
}
void intro(Playerdata &player)
{
    int ch;
    string filename = "savegame.txt";
    do
    {
        cout << "1. New game" << endl;
        cout << "2. Load game" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\t\t\t\t\t\t\t\t\t\t\t------THE LOST KINGDOM------" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "| Once Upon a time there was a Kingdom that brights with the special crown \n Crown have 3 GEMS in it. It looks Fabolous \n Due to this crown Kingdom always happy and shines \n One day some creepy thing appears in the Kingdom and take all the 3 GEMS of the crown and hide them in different places \n After this Kingdom fall in darkness \n Now you are the last hope of the Kingdom |" << endl;
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << "Enter the name of your hero: ";
            cin >> player.name;
            cout << "Enter the age of your hero: ";
            cin >> player.age;
            cout << "Enter the gender of your hero: ";
            cin >> player.gender;

            break;
        case 2:
            string filename;
            cout << "Enter the filename to load: ";
            cin >> filename;
            if (fileExists(filename))
            {
                loadGame(player, filename);
                cout << "Game loaded successfully." << endl;
            }
            else
            {
                cout << "No flie found start new game" << endl;
                intro(player);
            }
            break;
        }
    } while (ch != 1 && ch != 2);
}
void infile(Playerdata player, string filename)
{
    ifstream file(filename, ios::binary);
    if (file.good())
    {
        file.read((char *)(&player), sizeof(Playerdata));
    }
    else
    {
        cout << "File not found" << endl;
        intro(player);
    }
}
int main()
{
    srand(time(0));
    bool gem = true, gun = true;
    Playerdata player;
    bool firstGemFound = false;
    int time = 5;
    int health = 100;
    string filename = "savegame.txt";
    while (true)
    {
        // Reset the game state
        intro(player);
        bool save = false;
        cout << "Select only one power:" << endl;

        int choice;
        bool continueGame = true;
        do
        {
            village();
            cout << "Do you want to continue interacting with villagers? (press 1 for yes and 2 for no)" << endl;
            cin >> choice;
            if (choice == 2)
            {
                continueGame = false;
                break;
            }
        } while (continueGame);

        forest(player, heroHealth, monsterHealth);

        cave();
        cout << "Do you want to save the game? (1 for Yes, 2 for No)" << endl;
        int saveChoice;
        cin >> saveChoice;
        if (saveChoice == 1)
        {
            string filename;
            cout << "Enter name of file to fave game:";
            cin >> filename;
            fileExists(filename);
            save = true;
        }
        cout << "Do you want to restart the game? (press 1 for yes and 2 for no)" << endl;
        cin >> choice;
        if (choice == 2)
        {
            break;
        }
    }
}