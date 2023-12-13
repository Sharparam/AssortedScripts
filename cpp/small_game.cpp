#include <cstdlib>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <svtecken.h> //ALWAYS include svtecken.h when you use Swedish characters!
#include <cmath>
#include <iomanip>
#include <limits>
#include <stdlib.h>
#include <sstream>
#include <fmod.h>

using std::cout;
using std::cin;

FMUSIC_MODULE* music;
FSOUND_SAMPLE* sample;
FSOUND_SAMPLE* pl_atk;
FSOUND_SAMPLE* pl_hurt;
FSOUND_SAMPLE* npc_atk;
FSOUND_SAMPLE* npc_hurt;
FSOUND_SAMPLE* npc_die;
FSOUND_SAMPLE* thunder_1;
FSOUND_SAMPLE* thunder_2;
FSOUND_SAMPLE* thunder_3;
FSOUND_SAMPLE* thunder_4;
FSOUND_SAMPLE* thunder_5;
FSOUND_SAMPLE* thunder_6;
FSOUND_SAMPLE* thunder_7;
FSOUND_SAMPLE* thunder_8;
FSOUND_SAMPLE* thunder_9;
FSOUND_SAMPLE* thunder_10;
FSOUND_SAMPLE* boss_atk_1;
FSOUND_SAMPLE* boss_atk_2;
FSOUND_SAMPLE* boss_hurt;
FSOUND_SAMPLE* boss_die;
FSOUND_STREAM* stream;
FSOUND_STREAM* menumusic;
FSOUND_STREAM* bgmusic;
FSOUND_STREAM* battlemusic;
FSOUND_STREAM* bossmusic;
FSOUND_STREAM* endmusic;
FSOUND_STREAM* dark;
FSOUND_STREAM* daynormal;
FSOUND_STREAM* rain;
FSOUND_STREAM* thunder_loop;

int damage;

void PlayMusic (string filename)
{
	music=FMUSIC_LoadSong(filename.c_str());
	FMUSIC_SetMasterVolume (music, 255);
	FMUSIC_PlaySong(music);
	FMUSIC_SetLooping (music, true);
}

void PlayShort (string filename)
{
	sample=FSOUND_Sample_Load (0,filename.c_str(),0,0,0);
	FSOUND_PlaySound (1,sample);
}

void LoadGameMusic ()
{
	menumusic=FSOUND_Stream_Open("res\\music\\menumusic.ogg",FSOUND_LOOP_NORMAL, 0, 0);
	bgmusic=FSOUND_Stream_Open("res\\music\\bgmusic.ogg",FSOUND_LOOP_NORMAL, 0, 0);
	battlemusic=FSOUND_Stream_Open("res\\music\\battlemusic.ogg",FSOUND_LOOP_NORMAL, 0, 0);
	bossmusic=FSOUND_Stream_Open("res\\music\\bossmusic.mp3",FSOUND_LOOP_NORMAL, 0, 0);
	endmusic=FSOUND_Stream_Open("res\\music\\endmusic.ogg",FSOUND_LOOP_NORMAL, 0, 0);
	dark=FSOUND_Stream_Open("res\\sounds\\ambient\\dark.wav",FSOUND_LOOP_NORMAL, 0, 0);
	daynormal=FSOUND_Stream_Open("res\\sounds\\ambient\\daynormal.wav",FSOUND_LOOP_NORMAL, 0, 0);
	rain=FSOUND_Stream_Open("res\\sounds\\ambient\\rain.wav",FSOUND_LOOP_NORMAL, 0, 0);
	thunder_loop=FSOUND_Stream_Open("res\\sounds\\ambient\\thunder_loop.wav",FSOUND_LOOP_NORMAL, 0, 0);
}

void GameMusic (int index)
{
	if (index == 1){
		FSOUND_Stream_Play (20,menumusic);
	}else if (index == 2){
		FSOUND_Stream_Play (21,bgmusic);
	}else if (index == 3){
		FSOUND_Stream_Play (22,battlemusic);
	}else if (index == 4){
		FSOUND_Stream_Play (23,bossmusic);
		FSOUND_SetVolume(23,200);
	}else if (index == 5){
		FSOUND_Stream_Play (24,endmusic);
	}else if (index == 6){
		FSOUND_Stream_Play (10,dark);
	}else if (index == 7){
		FSOUND_Stream_Play (11,daynormal);
	}else if (index == 8){
		FSOUND_Stream_Play (12,rain);
		FSOUND_SetVolume(12,155);
	}else if (index == 9){
		FSOUND_Stream_Play (13,thunder_loop);
	}else{
		cout << "ERROR!";
	}
}

void StopGameMusic (int index)
{
	if (index == 1){
		FSOUND_Stream_Stop(menumusic);
	}else if (index == 2){
		FSOUND_Stream_Stop(bgmusic);
	}else if (index == 3){
		FSOUND_Stream_Stop(battlemusic);
	}else if (index == 4){
		FSOUND_Stream_Stop(bossmusic);
	}else if (index == 5){
		FSOUND_Stream_Stop(endmusic);
	}else if (index == 6){
		FSOUND_Stream_Stop(dark);
	}else if (index == 7){
		FSOUND_Stream_Stop(daynormal);
	}else if (index == 8){
		FSOUND_Stream_Stop(rain);
	}else if (index == 9){
		FSOUND_Stream_Stop(thunder_loop);
	}else{
		cout << "ERROR!";
	}
}

void LoadGameSounds ()
{
	pl_atk=FSOUND_Sample_Load (0,"res\\sounds\\pl_atk.wav",0,0,0);
	pl_hurt=FSOUND_Sample_Load (1,"res\\sounds\\pl_hurt.wav",0,0,0);
	npc_atk=FSOUND_Sample_Load (2,"res\\sounds\\npc_atk.wav",0,0,0);
	npc_hurt=FSOUND_Sample_Load (3,"res\\sounds\\npc_hurt.wav",0,0,0);
	npc_die=FSOUND_Sample_Load (4,"res\\sounds\\npc_die.wav",0,0,0);
	thunder_1=FSOUND_Sample_Load (5,"res\\sounds\\ambient\\thunder_1.wav",0,0,0);
	thunder_2=FSOUND_Sample_Load (6,"res\\sounds\\ambient\\thunder_2.wav",0,0,0);
	thunder_3=FSOUND_Sample_Load (7,"res\\sounds\\ambient\\thunder_3.wav",0,0,0);
	thunder_4=FSOUND_Sample_Load (8,"res\\sounds\\ambient\\thunder_4.wav",0,0,0);
	thunder_5=FSOUND_Sample_Load (9,"res\\sounds\\ambient\\thunder_5.wav",0,0,0);
	thunder_6=FSOUND_Sample_Load (10,"res\\sounds\\ambient\\thunder_6.wav",0,0,0);
	thunder_7=FSOUND_Sample_Load (11,"res\\sounds\\ambient\\thunder_7.wav",0,0,0);
	thunder_8=FSOUND_Sample_Load (12,"res\\sounds\\ambient\\thunder_8.wav",0,0,0);
	thunder_9=FSOUND_Sample_Load (13,"res\\sounds\\ambient\\thunder_9.wav",0,0,0);
	thunder_10=FSOUND_Sample_Load (14,"res\\sounds\\ambient\\thunder_10.wav",0,0,0);
	boss_atk_1=FSOUND_Sample_Load (15,"res\\sounds\\boss_atk_1.wav",0,0,0);
	boss_atk_2=FSOUND_Sample_Load (16,"res\\sounds\\boss_atk_2.wav",0,0,0);
	boss_hurt=FSOUND_Sample_Load (17,"res\\sounds\\boss_hurt.wav",0,0,0);
	boss_die=FSOUND_Sample_Load (18,"res\\sounds\\boss_die.wav",0,0,0);
}

void GameSound (int index)
{
	if (index == 1){
		FSOUND_PlaySound (29,pl_atk);
	}else if (index == 2){
		FSOUND_PlaySound (30,pl_hurt);
	}else if (index == 3){
		FSOUND_PlaySound (31,npc_atk);
	}else if (index == 4){
		FSOUND_PlaySound (32,npc_hurt);
	}else if (index == 5){
		FSOUND_PlaySound (13,npc_die);
	}else if (index == 6){
		FSOUND_PlaySound (14,thunder_1);
	}else if (index == 7){
		FSOUND_PlaySound (15,thunder_2);
	}else if (index == 8){
		FSOUND_PlaySound (16,thunder_3);
	}else if (index == 9){
		FSOUND_PlaySound (17,thunder_4);
	}else if (index == 10){
		FSOUND_PlaySound (18,thunder_5);
	}else if (index == 11){
		FSOUND_PlaySound (19,thunder_6);
	}else if (index == 12){
		FSOUND_PlaySound (20,thunder_7);
	}else if (index == 13){
		FSOUND_PlaySound (21,thunder_8);
	}else if (index == 14){
		FSOUND_PlaySound (22,thunder_9);
	}else if (index == 15){
		FSOUND_PlaySound (23,thunder_10);
	}else if (index == 16){
		FSOUND_PlaySound (24,boss_atk_1);
	}else if (index == 17){
		FSOUND_PlaySound (25,boss_atk_2);
	}else if (index == 18){
		FSOUND_PlaySound (26,boss_hurt);
	}else if (index == 19){
		FSOUND_PlaySound (27,boss_die);
	}else{
		cout << "ERROR!";
	}
}

void clear_screen ( void )
{
  DWORD n;                         /* Number of characters written */
  DWORD size;                      /* number of visible characters */
  COORD coord = {0};               /* Top left screen position */
  CONSOLE_SCREEN_BUFFER_INFO csbi;

  /* Get a handle to the console */
  HANDLE h = GetStdHandle ( STD_OUTPUT_HANDLE );

  GetConsoleScreenBufferInfo ( h, &csbi );

  /* Find the number of characters to overwrite */
  size = csbi.dwSize.X * csbi.dwSize.Y;

  /* Overwrite the screen buffer with whitespace */
  FillConsoleOutputCharacter ( h, TEXT ( ' ' ), size, coord, &n );
  GetConsoleScreenBufferInfo ( h, &csbi );
  FillConsoleOutputAttribute ( h, csbi.wAttributes, size, coord, &n );

  /* Reset the cursor to the top left position */
  SetConsoleCursorPosition ( h, coord );
}

void Color(string color)
{
	if (color == "green"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	}else if (color == "red"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_INTENSITY));
	}else if (color == "white"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	}else if (color == "gray"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN));
	}else if (color == "blue"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_BLUE | FOREGROUND_INTENSITY));
	}else if (color == "yellow"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY));
	}else if (color == "bgreen"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_GREEN | BACKGROUND_INTENSITY));
	}else if (color == "bred"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED | BACKGROUND_INTENSITY));
	}else if (color == "bwhite"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_INTENSITY));
	}else if (color == "bgray"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN));
	}else if (color == "bblue"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_BLUE | BACKGROUND_INTENSITY));
	}else if (color == "byellow"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY));
	}else if (color == "reset"){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE));
	}else{
		cout << "ERROR!";
	}
}

void StartUp ()
{
	SetConsoleTitleA("The Small Game - Starting Up");
	Color("yellow");
	cout << "Connecting...\n";
	PlayShort("res\\sounds\\dialup.wav");
	Color("blue");
	while (FSOUND_IsPlaying(1) == true)
	{
		Sleep(500);
		cout << char(219);
	}
	FSOUND_Sample_Free (sample);
	Sleep(1000);
	Color("green");
	cout << "\nConnected!\n\n";
	Sleep(2000);
	clear_screen();
	Color("yellow");
	cout << "Loading sounds...\n";
	Sleep(1000);
	LoadGameMusic();
	Sleep(250);
	GameMusic(1);
	Sleep(1000);
	Sleep(500);
	Color("green");
	cout << "Sounds loaded!\n";
	Color("white");
	Sleep(3000);
}

void PrintInfo (string name, int health, int mana, int gold)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_GREEN | BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE));
	cout << "  <" << name << ">" << "\tHP: " << health << "  MP: " << mana << "  Gold: " << gold << "  " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY));
}

int GetRand(int min, int max)
{
  static int Init = 0;
  int rc;
  
  if (Init == 0)
  {
    /*
     *  As Init is static, it will remember it's value between
     *  function calls.  We only want srand() run once, so this
     *  is a simple way to ensure that happens.
     */
    srand(time(NULL));
    Init = 1;
  }

  /*
   * Formula:  
   *    rand() % N   <- To get a number between 0 - N-1
   *    Then add the result to min, giving you 
   *    a random number between min - max.
   */  
  rc = (rand() % (max - min + 1) + min);
  
  damage = rc;
  return (rc);
}

void BossAttackSound ()
{
	int soundindex=GetRand(16, 17);
	GameSound(soundindex);
}

void BossBattleBattle (string& playername, int& playerhealth, int& playermana, int& gold, int& bosshealth, int& bossmana, int& bossgold, int& actionchoice)
{
	int bossAttackDamage;
	while (actionchoice == 5){
		cout << "What do you want to do?\n1. Attack\t2. Defend\t(Escape is not available in boss battles)\n";
		cin >> actionchoice;
		if (actionchoice == 1){
			clear_screen();
			bosshealth -= GetRand(30, 70);
			GameSound(1);
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo("ADDE", bosshealth, bossmana, bossgold);
			Sleep(500);
			GameSound(18);
			cout << "\nYou dealt " << damage << " damage to ADDE!\n";
			Sleep(1500);
			clear_screen();
			playerhealth -= GetRand(3, 7);
			bossAttackDamage = damage;
			BossAttackSound();
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo("ADDE", bosshealth, bossmana, bossgold);
			Sleep(500);
			GameSound(2);
			cout << "\nADDE dealt " << bossAttackDamage << " to you!\n\n";
			Sleep(1500);
		}else if (actionchoice == 2){
			clear_screen();
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo("ADDE", bosshealth, bossmana, bossgold);
			cout << "\nYou defend yourself, dealing no damage.\n";
			Sleep(1500);
			cout << "\nADDE dealt no damage to you.\n\n";
			Sleep(1500);
		}
	}
}

void Battle (string playername, int& playerhealth, int& playermana, int& gold, string mobname)
{
//Start&Stop music
StopGameMusic(2);
GameMusic(3);
//END: Start&Stop music

//!!LOCAL!!
int mobhealth=GetRand(70, 110), mobmana=GetRand(80, 100), mobgold=GetRand(1, 200), actionchoice=3;
bool battlestate=true;
//END: !!LOCAL!!

	while (mobhealth > 0 && battlestate == true){
		cout << "\nWhat do you want to do?\t1. Attack\t2. Defend\t3. Escape\n";
		cin >> actionchoice;
		if (actionchoice == 1){
			if (playerhealth < 200){
				mobhealth -= GetRand(1, 5);
			}else if (playerhealth > 200 && playerhealth < 500){
				mobhealth -= GetRand(10, 20);
			}else{
				mobhealth -= GetRand(50, 100);
			}
			GameSound(1);
			clear_screen();
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo(mobname, mobhealth, mobmana, mobgold);
			Sleep(500);
			GameSound(4);
			cout << "\nYou dealt " << damage << " damage to " << mobname << "!\n";
			Sleep(1500);
			playerhealth -= GetRand(1, 3);
			GameSound(3);
			clear_screen();
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo(mobname, mobhealth, mobmana, mobgold);
			Sleep(500);
			GameSound(2);
			cout << "\n" << mobname << " dealt " << damage << " damage to you!\n";
			Sleep(1500);
		}else if (actionchoice == 2){
			clear_screen();
			PrintInfo(playername, playerhealth, playermana, gold);
			PrintInfo(mobname, mobhealth, mobmana, mobgold);
			cout << "\nYou defend yourself, dealing no damage.\n";
			Sleep(1500);
			cout << "\n" << mobname << " dealt no damage to you.\n\n";
			Sleep(1500);
		}else if (actionchoice == 3){
			cout << "\nYou escaped the battle!\n";
			Sleep(1500);
			battlestate = false;
			break;
		}else{
			cout << "\nInvalid number, please input a valid number...\n";
			Sleep(1000);
		}
	}
	GameSound(5);
	Sleep(1000);
	clear_screen();
	PrintInfo(playername, playerhealth, playermana, gold);
	StopGameMusic(3);
	GameMusic(2);
	if (battlestate == true){
		cout << endl << mobname << " defeated!\n";
		gold += mobgold;
	}
	Sleep(2000);
}

void BossBattle (string& playername, int& playerhealth, int& playermana, int& gold)
{
//Start ambient sounds
GameMusic(6);
GameMusic(8);
GameMusic(9);
//END: Start bossmusic and ambient sounds

//Declare !!LOCAL!! variables
int bosshealth=1000, bossmana=1000, bossgold=9999999;
//END: Declare !!LOCAL!! variables

	clear_screen();
	PrintInfo(playername, playerhealth, playermana, gold);
	PrintInfo("ADDE", bosshealth, bossmana, bossgold);
	Sleep(1000);
	cout << endl << "ADDE appeared!\n\n";
	Sleep(1000);
	cout << "ADDE: Finally i get to meet the hero! I've been waiting for you for a long time. It will be a pleasure to kill you.\n\n";
	Sleep(2000);
	cout << playername << ": Hah, I'm well prepared for this battle. You have no chance against me!\n\n";
	Sleep(2000);
	cout << "ADDE: Oh, you think so? Well, we'll see about that!\n\n";
	Sleep(5000);
	GameMusic(4);
	int actionchoice;
	while (bosshealth > 0){
		actionchoice = 5;
		BossBattleBattle(playername, playerhealth, playermana, gold, bosshealth, bossmana, bossgold, actionchoice);
	}
	GameSound(19);
	cout << "\n\nDefeated!";
	Sleep(3000);
StopGameMusic(4);
StopGameMusic(6);
StopGameMusic(8);
StopGameMusic(9);
GameMusic(2);
}

void GameCredits ();

void Game ()
{
	//Declare !!LOCAL!! Variables
		int playerhealth=100, playermana=100, playerexp=0, enemyhealth=50, enemymana=25, gold=0, load=10, path=0;
		string playername, enemyname, npcname;
	//END: Declare Variables

	SetConsoleTitleA("The Small Game");
	clear_screen();


	/***************************************
	*****Welcome message and name input*****
	***************************************/
	cout << "Welcome to The Small Game! Please choose a name for your character:\n\n\t";
	getline(cin, playername);
	cout << "\n\nHi " + playername + "! Press any key to enter the game!";
	cin.get();


	/************************
	*****Load game stuff*****
	************************/
	clear_screen();
	Sleep(500);
	Color("yellow");
	cout << "Clearing sounds...\n";
	Sleep(500);
	StopGameMusic(1);
	Sleep(750);
	Color("green");
	cout << "Sounds cleared!\n";
	Sleep(750);
	Color("yellow");
	cout << "Loading game music...\n";
	GameMusic(2);
	Sleep(750);
	Color("green");
	cout << "Game music loaded!\n";
	Sleep(750);
	Color("yellow");
	cout << "Loading game sounds...\n";
	LoadGameSounds();
	Sleep(1250);
	Color("green");
	cout << "Game sounds loaded!\n";
	Sleep(750);
	Color("yellow");
	cout << "\nStarting game engine...\n";
	for (load=80;load > 0;load--){
		Color("blue");
		cout << char(219);
		Sleep(200);
		Color("white");
	}
	Sleep(1250);
	Color("green");
	cout << "Game loaded successfully!";
	Color("white");
	Sleep(1000);
	clear_screen();


	/*******************
	*****Start game*****
	********************/
	PrintInfo(playername, playerhealth, playermana, gold);

	Sleep(1000);
	cout << "You are in a small house.\nPress 1 to go out.\n";
	while (path != 1){
		cin >> path;
	}
	cout << "\n\nYou got out of the house. ";
	cout << "You are now in a small wood.\nPress 1 to go to the city, press 2 to go deeper into the woods, press 3 to go back into the house.\n";
	while (path != 2){
		cin >> path;
		if (path == 1){
			cout << "\nThe city gates are blocked by large stones, please choose another path.\n";
		}else if (path == 3){
			cout << "\nThere is no point in going back into the house, please choose another path.\n";
		}else if (path == 2){
			break;
		}else{
			cout << "\nInvalid path number, please try again.\n";
		}
	}
	cout << "\nEntering woods...";
	Sleep(3000);
	clear_screen();
	PrintInfo(playername, playerhealth, playermana, gold);
	Sleep(2000);
	cout << "Wolf appeared!\n";
	Sleep(1000);
	Battle(playername, playerhealth, playermana, gold, "Wolf");
	cout << "\nWell done! As a reward, your maximum health has now increased with 50!\n\nPress any key to continue...";
	playerhealth = 100;
	playerhealth += 50;
	cin.get();cin.get();
	clear_screen();
	PrintInfo(playername, playerhealth, playermana, gold);
	cout << "You are now in the wood.\nPress 1 to go to the dark tower, press 2 to go deeper into the woods.\n";
	while (path != 1){
		cin >> path;
		if (path == 1){
			break;
		}else if (path == 2){
			cout << "\nYou are too scared to go any further.\n";
		}else{
			cout << "\nInvalid path number, please try again.\n";
		}
	}
	Sleep(500);
	cout << "\nThe road is blocked by a wolf!\n";
	Sleep(1000);
	Battle(playername, playerhealth, playermana, gold, "Wolf");
	cout << "\nWell done! As a reward, your maximum health has now increased with 50!\n\nPress any key to continue...";
	playerhealth = 150;
	playerhealth += 50;
	cin.get();cin.get();
	Sleep(1000);
	clear_screen();
	PrintInfo(playername, playerhealth, playermana, gold);
	cout << "\nEntering the dark tower...\n";
	Sleep(2000);
	cout << "\n<BOSS> ADDE appeared!\n";
	Sleep(1000);
	StopGameMusic(2);
	BossBattle(playername, playerhealth, playermana, gold);
	Sleep(1000);
	clear_screen();
	cout << "ADDE: No, this can't be...\n\n";
	Sleep(1500);
	cout << playername << ": It's over ADDE.\n\n";
	Sleep(1500);
	cout << "ADDE: No, you may have won this battle. But I'll be back... You'll see.\n\n";
	Sleep(1000);
	cout << "*ADDE falls dead to the ground*\n\n";
	Sleep(1500);
	cout << "Congratulations! You have completed The Small Game!\n\n";
	Sleep(2000);
	GameCredits();
	Sleep(1000);
	StopGameMusic(5);
	GameMusic(1);
}

//Labels

void MenuLogo ()
{
	SetConsoleTitleA("The Small Game - Menu");
	cout << "=============================================\n";
	cout << "======The Small Game - By Adam Hellberg======\n";
	cout << "=============================================\n";
	cout << "==MENU==\n\n";
}

void InstLogo ()
{
	SetConsoleTitleA("title The Small Game - Instructions");
	cout << "=============================================\n";
	cout << "======The Small Game - By Adam Hellberg======\n";
	cout << "=============================================\n";
	cout << "==INSTRUCTIONS==\n\n";
}

//END: Labels

void Instructions ()
{
	clear_screen();
	InstLogo();
	cout << "\t- Moving around\nTo move around in the game you use 1, 2, 3 and 4. In-game information will tell you which ways you can choose.\n\n";
	cout << "\t- Picking up items\nSometimes you might find items in the game which may be useful to you. The game will tell you about this and you can shoose whether or not to pick the item up by writing Y (Yes) or N (No).\n\n";
	cout << "\t- Fighting\nBelieve it or not but there are actually monsters in this game. You can escape some battles, but not all. Boss fights for example. When the fight starts, you will have some options displayed: \"1. Attack 2. Defend 3. Escape\". If you choose \"Attack\" the character will attack the monster and deal some damage depending on your attack lvl. If you choose \"Defend\" your character will not take damage from the monster's attack, however, you won't deal any damage to the monster. Choosing \"Escape\" lets you escape from the fight. Note \"Escape\" is not available in boss fights.\n\n";
	cout << "Press any key to go back to the menu...";
	cin.get();
}

void MenuList (bool& exitnow)
{
	string choice;
	cout << "1. Play Game\n2. Instructions\n3. Source Code\n4. Exit Game\n\n";
	getline(cin, choice);
	if (choice == "1"){
		Game();
	}else if (choice == "2"){
		Instructions();
	}else if (choice == "3"){
		system("start %WINDIR%\\notepad.exe game.cpp");
	}else if (choice == "4"){
		exitnow = true;
	}else{
		cout << "Invalid number, please input a valid number and try again.\nPress any key to continue...\n";
		cin.get();
	}
}

void GameCredits ()
{
	clear_screen();
	StopGameMusic(2);
	GameMusic(5);
	Sleep(2000);
	cout << "Programming:";
	Sleep(1500);
	cout << "\n\t Adam Hellberg\n\n";
	Sleep(2000);
	cout << "Idea:";
	Sleep(1500);
	cout << "\n\tAdam Hellberg\n\n";
	Sleep(2000);
	cout << "Thanks to:";
	Sleep(1500);
	cout << "\n\t�N�ADDE";
	Sleep(1500);
	cout << "\n\t#c++ and #c++.se on QuakeNet IRC";
	Sleep(2000);
	cout << "\n\n\n\n\n\n\n\n\t\t\t\t    THE END";
	cin.get();cin.get();
}

int main ()
{
	//Declare variables
		bool exitnow=false;
	//END: Declare variables

	//Initialize FMOD
		FSOUND_Init (44100, 32, 0);
	//END: Initialize FMOD

	StartUp();

	while (exitnow == false)
	{
		clear_screen();
		MenuLogo();
		MenuList(exitnow);
	}

//Unload and close FMOD and the Game
FMUSIC_FreeSong (music);
FSOUND_Sample_Free (sample);
FSOUND_Sample_Free (pl_atk);
FSOUND_Sample_Free (pl_hurt);
FSOUND_Sample_Free (npc_atk);
FSOUND_Sample_Free (npc_hurt);
FSOUND_Sample_Free (npc_die);
FSOUND_Sample_Free (boss_atk_1);
FSOUND_Sample_Free (boss_atk_2);
FSOUND_Sample_Free (boss_hurt);
FSOUND_Sample_Free (boss_die);
FSOUND_Sample_Free (thunder_1);
FSOUND_Sample_Free (thunder_2);
FSOUND_Sample_Free (thunder_3);
FSOUND_Sample_Free (thunder_4);
FSOUND_Sample_Free (thunder_5);
FSOUND_Sample_Free (thunder_6);
FSOUND_Sample_Free (thunder_7);
FSOUND_Sample_Free (thunder_8);
FSOUND_Sample_Free (thunder_9);
FSOUND_Sample_Free (thunder_10);
FSOUND_Stream_Close(stream);
FSOUND_Stream_Close(menumusic);
FSOUND_Stream_Close(bgmusic);
FSOUND_Stream_Close(battlemusic);
FSOUND_Stream_Close(bossmusic);
FSOUND_Stream_Close(endmusic);
FSOUND_Stream_Close(dark);
FSOUND_Stream_Close(daynormal);
FSOUND_Stream_Close(rain);
FSOUND_Close();
return 0;
}
