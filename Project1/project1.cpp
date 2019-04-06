/*
* Project Title:
* - Dungeon Escape
* Description: A Zork-like game where the player must make their way out of a dungeon without dying.
* They will have to collect item and use clues in order to successfully beat the game.
* This program uses many functions to act as rooms with specific events. When a number is entered, some functions
* will be called in order to go to new rooms. It also uses if-else case structure depending on what the player chooses to do.
*
* Developers:
* - Ryan Moore - moore3r4@mail.uc.edu
* - Rachel Lindquist - lindqurm@mail.uc.edu
* - Anne Baldwin - baldwiak@mail.uc.edu
*
* Help Received:
* N/A
*
* Special Instructions:
* Quickest route:
* 3
* 1
* 1
* 2
* 1
* 1
* 7
* 1
* 1
* 3
* 1
* 1
* Action depends on poster found 2 moves ago
* 2
*
* Developer comments:
* Ryan:
* Wrote much of the code, and polished existing code. Learned that fixing and improving code is a long, but rewarding process.
* Rachel:
* Wrote much of the code, helped lay out concepts. Learned that play testing is longer and more thorough than originally thought.
* Anne:
* Created concept diagrams, and helped create code. Learned that thinking through the entire scope of projects is beneficial.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>

using namespace std;

/* Function Name: printStory
*
* Function Description:
* This function prints story text when the game is started.
*
* Parameters:
* N/A
*
* return value:
* N/A
*/

void printStory(){
        cout << "You have woken up in an unknown room." << endl;
        cout << "There is no exit behind you, and one door ahead of you." << endl;
        cout << "There are two drawers in the room, one to your left and one to your right." << endl;
        cout << "What do you wish to do?" << endl;
}

/* Function Name: printHelp
*
* Function Description:
* This function prints text intended to help guide the player when called for.
*
* Parameters:
* N/A
*
* return value:
* N/A
*/

void printHelp(){
        cout << "Weclome to Dungeon Escape" << endl;
        cout << "The numbers 1 to 7 will be used to play the game." << endl;
        cout << "You must advance to the rooms ahead in order to escape the dungeon." << endl;
        cout << "It is ideal to explore certain rooms and take any items you stumble upon." << endl;
        cout << "Be wise about the choices you make when in conflict." << endl;
        cout << "Also be sure to check your inventory to know what you have access to." << endl;
        cout << "Good luck!" << endl;
}

/* Function Name: printInventory
*
* Function Description:
* This function prints a list of items the player currently has.
*
* Parameters:
* inventory parameter is a vector of strings, with each item's name.
*
* return value:
* N/A
*/

void printInventory(vector<string> inventory){
        cout << "You currently own:" << endl;
        for (int i = 0; i < inventory.size(); i++){
                cout << inventory.at(i) << endl;
        }
}

/* Function Name: checkDeath
*
* Function Description:
* This function checks to see if the player has died, causing a game over.
*
* Parameters:
* inventory parameter is a vector of strings, containing "dead" as an item if the player died.
*
* return value:
* Returns boolean value of dead, determining if the player won or lost.
*/

bool checkDeath(vector<string> & inventory){
        bool dead = false;
        if (inventory.at(inventory.size() - 1).compare("dead") == 0){
                dead = true;
        }
        return dead;
}

/* Function Name: roomOne
*
* Function Description:
* Runs gameplay of the first room in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
*
* return value:
* N/A
*/

void roomOne(vector<string> & inventory){
        bool swordTaken = false;
        bool shieldTaken = false;
        int option;
        int sword;
        int shield;

        cout << "You are in the first room." << endl;
        for (int i = 0; i < inventory.size(); i++){
                if (inventory.at(i).compare("sword") == 0){
                        swordTaken = true;
                }
                if (inventory.at(i).compare("shield") == 0){
                        shieldTaken = true;
                }
        }

        while (true) {
                cout << "1. Move north" << endl;
                cout << "2. Move south" << endl;
                cout << "3. Move east" << endl;
                cout << "4. Move west" << endl;
                cout << "5. Help" << endl;
                cout << "6. Check inventory" << endl;
                cin >> option;
                cout << endl;

                if (option == 1){
                        // Go to next room.
                        break;
                }
                else if (option == 3 && !swordTaken){
                        cout << "You find a sword in a drawer." << endl;
                        cout << "1. Take it" << endl;
                        cout << "2. Leave it" << endl;
                        cin >> sword;
                        cout << endl;

                        if (sword == 1){
                                inventory.push_back("sword");
                                cout << "You have acquired a sword." << endl;
                                swordTaken = true;
                        }
                        else if (sword == 2){
                                cout << "You decide to leave the sword." << endl;
                        }
                        else{
                                cout << "This is not an option." << endl;
                        }
                }
                else if (option == 3 && swordTaken || option == 4 && shieldTaken){
                        cout << "There is nothing left in the drawer." << endl;
                }
                else if (option == 4){
                        cout << "You find a shield in a drawer." << endl;
                        cout << "1. Take it" << endl;
                        cout << "2. Leave it" << endl;
                        cin >> shield;
                        cout << endl;

                        if (shield == 1){
                                inventory.push_back("shield");
                                cout << "You have acquired a shield." << endl;
                                shieldTaken = true;
                        }
                        else if (shield == 2){
                                cout << "You decide to leave the shield." << endl;
                        }
                        else{
                                cout << "This is not an option." << endl;
                        }
                }
                else if (option == 2){
                        cout << "You cannot move south, there is a wall behind you." << endl;
                }
                else if (option == 5){
                        printHelp();
                }
                else if (option == 6){
                        printInventory(inventory);
                }
                else{
                        cout << "This is not an option." << endl;
                }
                if (option == 2 || option == 3 || option == 4){
                        cout << "You walk back to the middle of the room." << endl;
                }
        }
}

/* Function Name: roomTwo
*
* Function Description:
* Runs gameplay of the second room in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
*
* return value:
* N/A
*/

void roomTwo(vector<string>& inventory){
        bool monster = true;
        bool haveSword = false;
        bool haveShield = false;
        bool dead = false;
        int fight;
        int ball;
        int option;

        cout << "You enter the second room." << endl;

        for (int i = 0; i < inventory.size(); i++){
                if (inventory.at(i).compare("crystal ball") == 0){
                        monster = false;
                }
                if (inventory.at(i).compare("key") == 0){
                        monster = false;
                }
                if (inventory.at(i).compare("sword") == 0){
                        haveSword = true;
                }
                if (inventory.at(i).compare("shield") == 0){
                        haveShield = true;
                }
        }

        if (monster){
                cout << "A monster appeared in front of you." << endl;
                while (true){
                        cout << "1. Punch it" << endl;
                        cout << "2. Attack with a sword" << endl;
                        cout << "3. Block with a shield" << endl;
                        cin >> fight;
                        cout << endl;

                        if (fight == 1){
                                cout << "Attempting to punch it, the monster eats your arm." << endl;
                                cout << "You slowly bleed to death." << endl;
                                dead = true;
                                break;
                        }
                        else if (fight == 2 && haveSword){
                                cout << "You slay the monster with your sword." << endl;
                                cout << "It slowly bleeds to death." << endl;
                                cout << "After it breathes its last, you see it was holding a crystal ball." << endl;
                                cout << "Do you want to: " << endl;
                                cout << "1. Take the crystal ball" << endl;
                                cout << "2. Leave it" << endl;
                                cin >> ball;
                                cout << endl;

                                if (ball == 1){
                                        inventory.push_back("crystal ball");
                                        cout << "You have acquired a crystal ball." << endl;
                                }
                                else if (ball == 2){
                                        cout << "You left the crystal ball." << endl;
                                }
                                else {
                                        cout << "That is not an option, you have left the ball." << endl;
                                }
                                break;
                        }
                        else if (fight == 2){
                                cout << "You swing, just before realizing you don't have a sword." << endl;
                                cout << "The monster retaliates and eats your arm." << endl;
                                cout << "You slowly bleed to death." << endl;
                                dead = true;
                                break;
                        }
                        else if (fight == 3 && haveShield){
                                cout << "You raise your shield." << endl;
                                cout << "The monster hits the shield, both you and the monster are unharmed." << endl;
                        }
                        else if (fight == 3){
                                cout << "You raise your arm as defense, but your arm is eaten by the attacking monster." << endl;
                                cout << "You slowly bleed to death." << endl;
                                dead = true;
                                break;
                        }
                        else {
                                cout << "This is not an option." << endl;
                        }
                }
        }

        while (true) {
                if (dead){
                        inventory.push_back("dead");
                        break;
                }

                cout << "1. Move north" << endl;
                cout << "2. Move south" << endl;
                cout << "3. Move east" << endl;
                cout << "4. Move west" << endl;
                cout << "5. Help" << endl;
                cout << "6. Check inventory" << endl;
                cin >> option;
                cout << endl;

                if (option == 1){
                        // Go to next room.
                        break;
                }
                else if (option == 3){
                        cout << "There is nothing here." << endl;
                }
                else if (option == 4){
                        cout << "There is nothing here." << endl;
                }
                else if (option == 2){
                        roomOne(inventory);
                        cout << "You walk back to the second room." << endl;

                }
                else if (option == 5){
                        printHelp();
                }
                else if (option == 6){
                        printInventory(inventory);
                }
                else{
                        cout << "This is not an option." << endl;
                }
                if (option == 3 || option == 4){
                        cout << "You walk back to the middle of the room." << endl;
                }
        }
}

/* Function Name: roomThree
*
* Function Description:
* Runs gameplay of the third room in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
*
* return value:
* N/A
*/

void roomThree(vector<string> &inventory){
        bool crystal = false;
        bool key = false;
        bool dead = false;
        int cLocation;
        int option;
        int hand;

        cout << "You enter the third room." << endl;
        cout << "You see a fortune teller." << endl;

        for (int i = 0; i < inventory.size(); i++){
                if (inventory.at(i).compare("crystal ball") == 0){
                        crystal = true;
                        cLocation = i;
                }
                if (inventory.at(i).compare("key") == 0){
                        key = true;
                }
        }
        while (true){
                cout << "1. Move north" << endl;
                cout << "2. Move south" << endl;
                cout << "3. Move east" << endl;
                cout << "4. Move west" << endl;
                cout << "5. Help" << endl;
                cout << "6. Check inventory" << endl;
                cout << "7. Talk to the fortune teller" << endl;
                cin >> option;
                cout << endl;

                if (option == 1){
                        // Go to next room.
                        break;
                }
                else if (option == 3){
                        cout << "There is nothing here." << endl;
                }
                else if (option == 4){
                        cout << "There is nothing here." << endl;
                }
                else if (option == 2){
                        roomTwo(inventory);
                        if (checkDeath(inventory)){
                                break;
                        }
                        else {
                                cout << "You walk back to the third room." << endl;
                                for (int i = 0; i < inventory.size(); i++){
                                        if (inventory.at(i).compare("crystal ball") == 0){
                                                crystal = true;
                                                cLocation = i;
                                        }
                                        if (inventory.at(i).compare("key") == 0){
                                                key = true;
                                        }
                                }
                        }

                }
                else if (option == 5){
                        printHelp();
                }
                else if (option == 6){
                        printInventory(inventory);
                }
                else if (option == 7){
                        cout << "The fortune teller greets you and asks if you have a crystal ball." << endl;
                        cout << "1. 'I'll give it'" << endl;
                        cout << "2. 'No, it's mine'" << endl;
                        cin >> hand;
                        cout << endl;

                        while (true){
                                if (hand == 1 && crystal){
                                        cout << "'Thank you.'" << endl;
                                        cout << "'Allow me to tell your fortune in exchange.'" << endl;
                                        cout << "'In the fourth room, make sure to check the east.'" << endl;
                                        cout << "'Take this with you, you'll need it later on.'" << endl;
                                        cout << "The fortune teller hands you a key." << endl;
                                        inventory.at(cLocation) = "key";
                                        key = true;
                                        crystal = false;
                                        break;
                                }
                                else if (hand == 1){
                                        if (key){
                                                cout << "You've already obtained a key from the fortune teller." << endl;
                                                break;
                                        }
                                        else{
                                                cout << "'But you don't have one?'" << endl;
                                                cout << "The fortune teller laughs at you and hands you a key." << endl;
                                                inventory.push_back("key");
                                                key = true;
                                                break;
                                        }
                                }
                                else if (hand == 2 && crystal){
                                        cout << "The fortune teller becomes angry." << endl;
                                        cout << "You suddenly feel a sharp pain in your chest." << endl;
                                        cout << "As the light fades from your eyes, you see the fortune teller take the crystal ball from you." << endl;
                                        dead = true;
                                        inventory.push_back("dead");
                                        break;
                                }
                                else if (hand == 2){
                                        if (key){
                                                cout << "You've already obtained a key from the fortune teller." << endl;
                                                break;
                                        }
                                        else{
                                                cout << "'You can just admit you don't have one.'" << endl;
                                                cout << "The fortune teller looks disappointed in you." << endl;
                                                break;
                                        }
                                }
                                else{
                                        cout << "This is not an option." << endl;
                                        break;
                                }
                        }
                }
                else{
                        cout << "This is not an option." << endl;
                }
                if (dead){
                        break;
                }
                if (option == 3 || option == 4 || option == 7){
                        cout << "You walk back to the middle of the room." << endl;
                }
        }
}

/* Function Name: trapDoor
*
* Function Description:
* Runs gameplay of the trap door event in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
* wanted parameter is a string with the character that is to be targeted.
*
* return value:
* N/A
*/

void trapDoor(vector<string> & inventory, string wanted){

        cout << "You unlock the door with your key and open it." << endl;
        cout << "Inside you see a wanted poster." << endl;
        cout << "It has a picture of something." << endl;

        if (wanted.compare("dragon") == 0){
                cout << "The entity in the picture is very large and has two horns." << endl;
        }
        else if (wanted.compare("knight") == 0){
                cout << "The entity in the picture is tall and holding a weapon." << endl;
        }
        else{
                cout << "The entity looks very familiar." << endl;
        }

        if (inventory.at(inventory.size() - 1).compare("poster of criminal") == 0){
        }
        else if (inventory.at(inventory.size() - 2).compare("poster of criminal") == 0){
        }
        else{
                inventory.push_back("poster of criminal");
        }
}

/* Function Name: roomFour
*
* Function Description:
* Runs gameplay of the fourth room in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
* wanted parameter is a string with the character that is to be targeted.
*
* return value:
* N/A
*/

void roomFour(vector<string>& inventory, string wanted){
        int option;
        int door;
        bool key = false;
        for (int i = 0; i < inventory.size(); i++){
                if (inventory.at(i).compare("key") == 0){
                        key = true;
                }
        }

        cout << "You enter the fourth room." << endl;

        while (true) {
                cout << "1. Move north" << endl;
                cout << "2. Move south" << endl;
                cout << "3. Move east" << endl;
                cout << "4. Move west" << endl;
                cout << "5. Help" << endl;
                cout << "6. Check inventory" << endl;
                cin >> option;
                cout << endl;

                if (option == 1){
                        // Go to next room.
                        break;
                }
                else if (option == 3){
                        cout << "There is a small door here." << endl;
                        cout << "1. Open it" << endl;
                        cout << "2. Leave it" << endl;
                        cin >> door;
                        cout << endl;

                        if (door == 1 && key){
                                trapDoor(inventory, wanted);
                        }
                        else if (door == 1){
                                cout << "There's a lock on the door, but you don't have a key." << endl;
                        }
                        else {
                                cout << "You leave the door as is." << endl;
                        }
                }
                else if (option == 4){
                        cout << "There is nothing here." << endl;
                }
                else if (option == 2){
                        roomThree(inventory);
                        if (checkDeath(inventory)){
                                break;
                        }
                        else {
                                cout << "You walk back to the fourth room." << endl;
                                for (int i = 0; i < inventory.size(); i++){
                                        if (inventory.at(i).compare("key") == 0){
                                                key = true;
                                        }
                                }
                        }
                }
                else if (option == 5){
                        printHelp();
                }
                else if (option == 6){
                        printInventory(inventory);
                }
                else{
                        cout << "This is not an option." << endl;
                }
                if (option == 3 || option == 4){
                        cout << "You walk back to the middle of the room." << endl;
                }
        }
}

/* Function Name: roomFive
*
* Function Description:
* Runs gameplay of the fifth room in the game.
*
* Parameters:
* inventory parameter is used to store and check items the player has.
* wanted parameter is a string with the character that is to be targeted.
*
* return value:
* N/A
*/

void roomFive(vector<string>& inventory, string wanted){
        bool shield = false;
        bool dead = false;
        bool win = false;
        int fight;
        int action;

        cout << "You enter the final room." << endl;
        cout << "The door behind you slams shut, locking you inside." << endl;
        cout << "In front of you stands 3 individuals." << endl;
        cout << "There is a dragon, a knight, and the fortune teller." << endl;

        for (int i = 0; i < inventory.size(); i++){
                if (inventory.at(i).compare("shield") == 0){
                        shield = true;
                }
        }

        while (true){
                if (dead){
                        break;
                }

                if (win){
                        break;
                }

                cout << "What do you do:" << endl;
                cout << "1. Fight the dragon" << endl;
                cout << "2. Fight the knight" << endl;
                cout << "3. Fight the fortune teller" << endl;
                cout << "4. Do nothing" << endl;
                cin >> fight;
                cout << endl;

                if (fight == 1){
                        cout << "You have decided to fight the dragon." << endl;
                        cout << "What do you do:" << endl;
                        while (true){
                                cout << "1. Punch it" << endl;
                                cout << "2. Attack with your sword" << endl;
                                cout << "3. Defend with a shield" << endl;
                                cin >> action;
                                cout << endl;

                                if (action == 1){
                                        cout << "You punch as hard as you can, but it's a dragon." << endl;
                                        cout << "It hurts you a lot and the dragon doesn't flinch." << endl;
                                        cout << "The dragon is kind of mad, and decides to burn you to a crisp." << endl;
                                        dead = true;
                                        inventory.push_back("dead");
                                        break;
                                }
                                else if (action == 2){
                                        cout << "You immediately find its weak spot, slaying it instantly." << endl;

                                        if (wanted.compare("dragon") == 0){
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You safely escape the dungeon, successfully completing your journey!" << endl;
                                                win = true;
                                                break;
                                        }
                                        else {
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You escape the dungeon, only to find the authority waiting there." << endl;
                                                cout << "They stop you and place you under arrest for murder!" << endl;
                                                cout << "It turns out you killed the wrong offender." << endl;
                                                cout << "The " << wanted << " was supposed to be your target." << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else if (action == 3){
                                        if (shield){
                                                cout << "The dragon breathes a fiery breath, but you raise your shield." << endl;
                                                cout << "The flames were successfully blocked." << endl;
                                        }
                                        else {
                                                cout << "The dragon breathes a fiery breath, you believe you can defend against it." << endl;
                                                cout << "Without a shield, you're helplessly burned to a crisp." << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else{
                                        cout << "This is not an option." << endl;
                                }
                        }
                }
                else if (fight == 2){
                        cout << "You have decided to fight the knight." << endl;
                        cout << "What do you do:" << endl;
                        while (true){
                                cout << "1. Punch him" << endl;
                                cout << "2. Attack with your sword" << endl;
                                cout << "3. Defend with a shield" << endl;
                                cin >> action;
                                cout << endl;

                                if (action == 1){
                                        cout << "You punch the knight, but he is fully armored." << endl;
                                        cout << "The punch brings pain to your hand." << endl;
                                        cout << "The knight retaliates with a swing of his weapon, knocking you to the floor." << endl;
                                        dead = true;
                                        inventory.push_back("dead");
                                        break;
                                }
                                else if (action == 2){
                                        cout << "You both swing your weapons at each other, but only your attack connects." << endl;
                                        cout << "The knight falls defeated." << endl;

                                        if (wanted.compare("knight") == 0){
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You safely escape the dungeon, successfully completing your journey!" << endl;
                                                win = true;
                                                break;
                                        }
                                        else {
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You escape the dungeon, only to find the authority waiting there." << endl;
                                                cout << "They stop you and place you under arrest for murder!" << endl;
                                                cout << "It turns out you killed the wrong offender." << endl;
                                                cout << "The " << wanted << " was supposed to be your target." << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else if (action == 3){
                                        if (shield){
                                                cout << "The knight takes a swing, but your shield blocks the attack." << endl;
                                                cout << "You're left unharmed at the moment." << endl;
                                        }
                                        else{
                                                cout << "The knight takes a swing." << endl;
                                                cout << "You think you can defend against a powerful weapon," << endl;
                                                cout << "but you fail to endure the attack, falling to the ground." << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else{
                                        cout << "This is not an option." << endl;
                                }
                        }
                }
                else if (fight == 3){
                        cout << "You have decided to fight the fortune teller." << endl;
                        cout << "What do you do:" << endl;
                        while (true){
                                cout << "1. Punch him" << endl;
                                cout << "2. Attack with your sword" << endl;
                                cout << "3. Defend with a shield" << endl;
                                cin >> action;
                                cout << endl;

                                if (action == 1){
                                        cout << "You try to punch the fortune teller in the face," << endl;
                                        cout << "but he swiftly dodges and laughs." << endl;
                                        cout << "'How foolish of you to think you could challenge me.'" << endl;
                                        cout << "You suddenly feel a sharp pain in your chest." << endl;
                                        cout << "Light fades from your eyes as the fortune teller brings you to your death." << endl;
                                        dead = true;
                                        inventory.push_back("dead");
                                        break;
                                }
                                else if (action == 2){
                                        cout << "Bewildered by his apparent betrayal," << endl;
                                        cout << "you stab him right in the stomach." << endl;
                                        cout << "The fortune teller gasps for air." << endl;
                                        cout << "'Betrayal is a cold, but necessary evil...'" << endl;
                                        cout << "The fortune teller falls and lies on the ground dead." << endl;

                                        if (wanted.compare("fortune teller") == 0){
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You safely escape the dungeon, successfully completing your journey!" << endl;
                                                win = true;
                                                break;
                                        }
                                        else {
                                                cout << "You see a bright light at the wall." << endl;
                                                cout << "It's an exit from the dungeon!" << endl;
                                                cout << "You escape the dungeon, only to find the authority waiting there." << endl;
                                                cout << "They stop you and place you under arrest for murder!" << endl;
                                                cout << "It turns out you killed the wrong offender." << endl;
                                                cout << "The " << wanted << " was supposed to be your target." << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else if (action == 3){
                                        if (shield){
                                                cout << "You raise your shield up. The fortune teller casts a fire spell." << endl;
                                                cout << "The flames bounce off your shield, putting the spell in vain." << endl;
                                        }
                                        else{
                                                cout << "The fortune teller casts a fire spell." << endl;
                                                cout << "You prepare to endure the flames, but your effort was in vain." << endl;
                                                cout << "You take severe burns, unable to fight anymore." << endl;
                                                cout << "'How foolish of you to challenge me. Enjoy your permanent rest.'" << endl;
                                                dead = true;
                                                inventory.push_back("dead");
                                                break;
                                        }
                                }
                                else{
                                        cout << "This is not an option." << endl;
                                }
                        }
                }
                else if (fight == 4){
                        cout << "You have decided to do nothing." << endl;
                        cout << "You are a moron." << endl;
                        cout << "While standing idle, the " << wanted << " kills you." << endl;
                        dead = true;
                        inventory.push_back("dead");
                        break;
                }
                else{
                        cout << "This is not an option." << endl;
                }
        }
}

int main()
{
        srand(time(NULL));
        vector<string> inventory;
        string wanted;
        int w = rand() % 3;

        if (w == 0){
                wanted = "dragon";
        }
        else if (w == 1){
                wanted = "knight";
        }
        else{
                wanted = "fortune teller";
        }

        printStory();
        roomOne(inventory);
        roomTwo(inventory);
        if (!(checkDeath(inventory))){
                roomThree(inventory);
                if (!(checkDeath(inventory))){
                        roomFour(inventory, wanted);
                        if (!(checkDeath(inventory))){
                                roomFive(inventory, wanted);
                        }
                }
        }
        if (checkDeath(inventory)){
                cout << "Game Over" << endl;
        }
        else{
                cout << "You win" << endl;
        }
        return 0;
}
