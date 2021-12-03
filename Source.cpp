#include <iostream>
#include <cctype>
#include <chrono>
#include <thread>
#include <string>
#include <algorithm>
#include <conio.h>
using namespace std;

class Stats
{
protected:
  string name = "";
  int      hp = 0;
  int  attack = 0;
  int   level = 0;
  int     exp = 0;
public:
  string getname() { return   name; }  virtual void setname(string n) { name = n; }
  int      gethp() { return     hp; }  virtual void sethp(int h) { hp = h; }
  int  getattack() { return attack; }  virtual void setattack(int a) { attack = a; }
  int   getlevel() { return  level; }  virtual void setlevel(int l) { level = l; }
  int     getexp() { return    exp; }  virtual void setexp(int e) { exp = e; }
};
class Character : public Stats
{
private:
  string gender;
  string age;
public:
  Character(string g) { gender = g; age = 16; } // 
  Character() { gender = "male"; age = 16; } // default constructor 
  string getgender() { return gender; }
  void setgender(string g)
  {
    transform(g.begin(), g.end(), g.begin(), ::tolower); // makes it lowercase
    if (g == "male" || g == "female")
    {
      gender = g;
    }
    else while (g != "male" && g != "female")
    {
      cout << "Enter male or female: "; cin >> g;
      transform(g.begin(), g.end(), g.begin(), ::tolower); // makes it lowercase
    }
  }

  void initiatestats()
  {
    if (gender == "male")
    {
      sethp(35); setattack(8); setlevel(5);setexp(500);
    }
    else
    {
      sethp(35); setattack(8); setlevel(5); setexp(500);
    }
  }
};
class Monster : public Stats
{
public:
  string name;
  Monster() { name = "bandit"; }
  Monster(string n) { name = n; }
  void initiatestats(string n)
  {
    if ((name == "bandit")) { setname("Bandit"); sethp(12); setattack(1); setlevel(1); setexp(4); } // lvl 1
    else if ((name == "wolf")){ setname("Wolf"); sethp(15); setattack(2); setlevel(2); setexp(7); } // lvl 2 
    else if ((name == "knight")){ setname("Knight"); sethp(19); setattack(3); setlevel(3); setexp(11); } // lvl 3
    else if ((name == "elk")){ setname("Elk"); sethp(32); setattack(2); setlevel(4); setexp(17); } // lvl 4
    else if ((name == "elemental")) { setname("Elemental"); sethp(35); setattack(5); setlevel(5); setexp(28); } // lvl 5
  }
  string getname() { return name; } void setname(string s) { name = s; }
  int gethp() { return hp; }
  int getattack() { return attack; }
  int getlevel() { return level; }
  int getexp() { return exp; }
};
void printfunction(string, int);
void sleepforms(int);
void printstats(Character);
void AvailableMonsters(int);
void Encounter(Character, Monster, int);
void attack(Character&, Monster&);
void printfunction(string string_length, int delay)
{
  int length = string_length.length();
  for (int i = 0; i < string_length.length(); i++)
  {
    this_thread::sleep_for(chrono::milliseconds(delay));
    cout << string_length[i];
  }
  this_thread::sleep_for(chrono::milliseconds(750));
}
void sleepforms(int delay)
{
  this_thread::sleep_for(chrono::milliseconds(delay));
}
void printstats(Character Player)
{
  int i = 0;
  printfunction("Level: ", 50);   cout << Player.getlevel(); sleepforms(100);
  printfunction("\nHealth: ", 50);     cout << Player.gethp(); sleepforms(100);
  printfunction("\nAttack: ", 50); cout << Player.getattack(); sleepforms(100);
  printfunction("\nExp: ", 50);       cout << Player.getexp(); sleepforms(100);
  cin.ignore(); printfunction("\npress ENTER to continue... \n", 20); cin.get();

}
void AvailableMonsters(int level)
{
  printfunction("At this level Monster's you can currently fight are: \n", 50);
  if (level > 0)
  {
    printfunction("1. Bandit\n", 50);
  }
  if (level > 1)
  {
    printfunction("2. Wolf\n", 50);
  }
  if (level > 2)
  {
    printfunction("3. Knight\n", 50);
  }
  if (level > 3)
  {
    printfunction("4. Elk\n", 50);;
  }
  if (level > 4)
  {
    printfunction("5. Elemental\n", 50);
  }
}
void Encounter(Character Player, Monster Enemy, int level)
{
  AvailableMonsters(Player.getlevel());
  string pick;
  string monster_name;
  printfunction("Which monster would you like to fight: ", 50);
  cin >> pick; transform(pick.begin(), pick.end(), pick.begin(), ::tolower);
  system("CLS");
  bool Found = 0;
  if ((pick == "1" || pick == "bandit") && Player.getlevel() >= 1) { Enemy.initiatestats("bandit");      monster_name = "bandit";   Found = 1; }
  else if ((pick == "2" || pick == "wolf") && Player.getlevel() >= 2) { Enemy.initiatestats("wolf");      monster_name = "wolf";     Found = 1; }
  else if ((pick == "3" || pick == "knight") && Player.getlevel() >= 3) { Enemy.initiatestats("knight");     monster_name = "knight";   Found = 1; }
  else if ((pick == "4" || pick == "elk") && Player.getlevel() >= 4) { Enemy.initiatestats("elk");      monster_name = "elk";      Found = 1; }
  else if ((pick == "5" || pick == "elemental") && Player.getlevel() >= 5) { Enemy.initiatestats("elemental");     monster_name = "elemental"; Found = 1; }
  while (Found == 0)
  {
    printfunction("You Cannot fight that monster. \n", 50); AvailableMonsters(Player.getlevel());
    printfunction("Which monster would you like to fight: ", 50);
    cin >> pick;
    if ((pick == "1" || pick == "bandit") && Player.getlevel() >= 1) { Enemy.initiatestats("bandit"); monster_name = "Bandit"; Found = 1; }
    else if ((pick == "2" || pick == "wolf") && Player.getlevel() >= 2) { Enemy.initiatestats("wolf"); monster_name = "Wolf"; Found = 1; }
    else if ((pick == "3" || pick == "Knight") && Player.getlevel() >= 3) { Enemy.initiatestats("knight"); monster_name = "Knight"; Found = 1; }
    else if ((pick == "4" || pick == "Elk") && Player.getlevel() >= 4) { Enemy.initiatestats("elk"); monster_name = "Elk"; Found = 1; }
    else if ((pick == "5" || pick == "Elemental") && Player.getlevel() >= 5) { Enemy.initiatestats("elemental"); monster_name = "Elemental"; Found = 1; }
    system("CLS");
  }
  printfunction("Monster Found.", 5); sleepforms(1500); system("CLS");
  Enemy.setname(monster_name);
  Enemy.initiatestats(monster_name);
  cout << Enemy.getname() << " Health "; cout << Enemy.gethp(); sleepforms(1000); printfunction("     ", 50);
  cout << "Player Health " << Player.gethp() << endl; sleepforms(1000);
  while (Player.gethp() > 0 && Enemy.gethp() > 0)
  {
    printfunction("\n1. Attack \n", 25); printfunction("2. Run \n", 25);
    cin >> pick; while (pick != "1" && pick != "2") { cin >> pick; }
    if (pick == "2")
    {
      printfunction("The player has successfully fled. ", 50);
      break;
    }
    if (pick == "1")
    {
      attack(Player, Enemy); // I think I need a pointer. 
    }
  }
}
void attack(Character& Player, Monster& Enemy)
{
  string monster_attack_string = Enemy.getname(); monster_attack_string += " attacks. \n The ";
  monster_attack_string += Enemy.getname(); monster_attack_string += " inflicts "; monster_attack_string += to_string(Enemy.getattack());
  monster_attack_string += " damage \n";
  system("CLS");
  //printfunction("Player attacks. \n The player inflcits ", 5);
  //cout << Player.getattack(); printfunction(" damage \n", 5);
  //printfunction(monster_attack_string, 5);
  //system("CLS");
  Player.sethp(Player.gethp() - Enemy.getattack()); if (Player.gethp() < 0) { Player.sethp(0); }
  if (Enemy.gethp() - Player.getattack() > 0)
  {
    printfunction("Player attacks. \n The player inflcits ", 5);//
    cout << Player.getattack(); printfunction(" damage \n", 5);//
    printfunction(monster_attack_string, 5);
    system("CLS");
    Enemy.sethp(Enemy.gethp() - Player.getattack()); if (Enemy.gethp() < 0) { Enemy.sethp(0); }
    cout << Enemy.getname() << " Health "; cout << Enemy.gethp(); sleepforms(1000); printfunction("     ", 50);
    cout << "Player Health " << Player.gethp() << endl; sleepforms(1000);
  }
  else
  {
    printfunction("Player attacks. \n The player inflcits ", 5);//
    cout << Player.getattack(); printfunction(" damage \n", 5);//
    printfunction("The Monster has fainted \n", 50);
    system("CLS");
    // put the rewards we received.
    printfunction("We will now return to the hub. ", 50);
    cin.ignore(); printfunction("\npress ENTER to continue... \n", 20); cin.get();
    Enemy.sethp(0);
    system("CLS");
  }
}

int main()
{
  Character Player;
  string player_gender;
  Monster Enemy;
  printfunction("Welcome to kevin's world. \n", 0);
  printfunction("In this world, there are many evil creatures and powerful fighters. \n", 0); system("CLS");
  printfunction("To start, are you male or female?\nI am: ", 0);
  cin >> player_gender; Player.setgender(player_gender); Player.initiatestats(); system("CLS");
  printfunction("Your starting stats are: \n", 50); printstats(Player);
  system("CLS");
  while (int i = 1) // infite loop.
  {
    int pick = 0;
    printfunction("Would you like to \n 1. Train\n 2. check Stat \n ", 0);
    cin >> pick;
    system("CLS");
    if (pick == 2)
    {
      printstats(Player);
    }
    if (pick == 1)
    {
      Encounter(Player, Enemy, Player.getlevel());
    }
  } 
}
