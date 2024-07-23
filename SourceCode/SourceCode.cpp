#include<SFML/Graphics.hpp>
#include"TurkishDraught.h"
#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<cstring>
#include<iomanip>

using namespace sf;
using namespace std;

void display()
{
	cout << "--------------Welcome to TURKISH DRAUGHT ----------------" << endl;
	cout << "                                 A Game Powered by MLM's ;)" << endl;
	cout << "A Game Powered by MLM's " << endl;
	

	string row1 = "O  .  O  .  O  .  O  .  ";
	string row2 = ".  O  .  O  .  O  .  O  ";
	string row3 = "O  .  O  .  O  .  O  .  ";
	string row4 = ".  .  .  .  .  .  .  .  ";
	string row5 = ".  .  .  .  .  .  .  .  ";
	string row6 = ".  X  .  X  .  X  .  X  ";
	string row7 = "X  .  X  .  X  .  X  .  ";
	string row8 = ".  X  .  X  .  X  .  X  ";

	cout << "  1  2  3  4  5  6  7  8  " << endl;
	cout << "1 " << row1 << " 1" << endl;
	cout << "2 " << row2 << " 2" << endl;
	cout << "3 " << row3 << " 3" << endl;
	cout << "4 " << row4 << " 4" << endl;
	cout << "5 " << row5 << " 5" << endl;
	cout << "6 " << row6 << " 6" << endl;
	cout << "7 " << row7 << " 7" << endl;
	cout << "8 " << row8 << " 8" << endl;
	cout << "  1  2  3  4  5  6  7  8  " << endl;
}
bool Register(void)
{
	string username, password;
	char read[30];
	int d = 1;
	do
	{
		switch (d)
		{
		case 1:
		{

			fstream file1;
			file1.open("REGISTER.txt ", ios::in);
			cout << "ENTER YOUR USERNAME.\n";
			cin >> username;
			cout << "ENTER YOUR PASSWORD\n";
			cin >> password;
			if (file1.is_open())
			{
				while (!file1.eof())
				{
					file1 >> read;
					if (read == username || read == password)
					{
						cout << "THIS USER ALREADY EXISTS. PLEASE ENTER A NEW USERNAME AND PASSWORD\n";
						d = 1;
						break;
					}
					else
					{
						d = 2;
					}
				}
				file1.close();
			}
			break;
		}
		case 2:
		{
			fstream file;
			file.open("REGISTER.txt", ios::app);
			if (file.is_open())
			{
				file << username;
				file << endl;
				file << password;
				file << endl;
				file.close();
				return 1;
			}
			d = 3;
			break;
		}
		}
	} while (d == 1 || d == 2);
}

Board bb;
string s;
bool newgame = true;
int score1 = 2, score2 = 2; //SCORE COUNT 
string Player1, Player2; //PLAYER NAMES

int main()
{

	display();
	//cout << "Enter 1 to login, 2 to register" << endl;

	//int tu, b, f = 0;
	//ofstream file1;
	//file1.open("REGISTER.txt ", ios::app);
	//if (file1.is_open())
	//{
	//}
	//file1.close();
	//cin >> b;
	//system("CLS");
	//do
	//{
	//	switch (b)
	//	{
	//	case 1:
	//	{
	//		f = Register();
	//		if (f == 1)
	//		{
	//			cout << "ENTER 2 IF YOU WANT TO LOG-IN NOW : \n";
	//			cin >> b;
	//			break;
	//		}
	//	}
	//	case 2:
	//	{
	//		string username, password;
	//		char read[30], pass[30];
	//		int c = 0, n = 1, m = 1;
	//		cout << "ENTER YOUR USERNAME : \n";
	//		cin >> username;
	//		cout << "ENTER YOUR PASSWORD : \n";
	//		cin >> password;
	//		ifstream file;
	//		file.open("REGISTER.txt");
	//		if (file.is_open())
	//		{
	//			while (!file.eof())
	//			{
	//				file >> read;
	//				if (read == username)
	//				{
	//					cout << "ENTERED USER NAME IS CORRECT\n";
	//					c++;
	//					ifstream file;
	//					file.open("REGISTER.txt");
	//					if (file.is_open())
	//					{
	//						while (!file.eof())
	//						{
	//							file >> pass;
	//							if ((n + 1) == m)
	//							{
	//								if (pass == password)
	//								{
	//									cout << "ENTERED PASSWORD IS CORRECT\n";
	//									c++;
	//								}
	//							}
	//							m++;
	//						}
	//						file.close();
	//					}
	//				}
	//				else
	//				{
	//					n++;
	//				}
	//			}
	//			if (c == 2)
	//			{
	//				cout << "YOU HAVE SUCCESSFULLY LOGGED IN\n";
	//				b = 3;

	//			}
	//			else
	//			{
	//				cout << "YOU HAVE ENTERED WRONG LOG-IN INFORMATION. \nIF YOU WANT TO REGISTER PRESS 1 : \nIF YOU WANT TO RETRY FOR LOGGING IN PRESS 2 : \n";
	//				cin >> b;
	//				if (b == 1)
	//				{
	//					cout << "FOR REGISTERATION PLEASE \n";
	//				}
	//			}
	//			file.close();
	//		}
	//		break;
	//	}
	//	}
	//} while (b == 2 || b == 1);

	//system("CLS");

	cout << "ENTER PLAYER NAMES" << endl;
	cout << "PLAYER 1: ";

	cin >> Player1;
	cout << "PLAYER 2: ";
	cin>> Player2;

	Texture photo;
	Font font1;
	RectangleShape Photo;
	font1.loadFromFile("fonts/invasion2000.TTF");
	photo.loadFromFile("images/uncles.png");
	Photo.setSize(Vector2f(1300.f, 1100.f));
	Photo.setTexture(&photo);
	Photo.setPosition(Vector2f(0.f, 0.f));

	//RULES WINDOW
	RenderWindow rules(VideoMode(1300, 1100), "GAME RULES", Style::Default);
	rules.setFramerateLimit(60);
	Texture rules_image;
	Text text;
	rules_image.loadFromFile("images/Rules.png");
	RectangleShape Rules;
	Rules.setSize(Vector2f(800.f, 700.f));
	Rules.setTexture(&rules_image);
	Rules.setPosition(Vector2f(230.f, 200.f));
	text.setFont(font1);
	text.setCharacterSize(85);
	text.setFillColor(Color::Color(235, 225, 200, 150));
	text.setOutlineColor(Color::White);
	text.setPosition(Vector2f(315.f, 60.f));
	text.setString("GAME RULES");
	while (rules.isOpen())
	{
		Event event;
		while (rules.pollEvent(event))
		{
			if (event.type == Event::Closed)
				rules.close();

			if (event.KeyPressed && event.key.code == Keyboard::Enter)
				rules.close();
		}
		rules.clear();
		rules.draw(Photo);
		rules.draw(Rules);
		rules.draw(text);

		rules.display();
	}

	//GAME DISPLAY WINDOW
	
	RenderWindow window(VideoMode(1300, 1100), "THE TURKISH DRAUGHT", Style::Default);
	window.setFramerateLimit(60);


	
	while (window.isOpen())
	{
		while (newgame) {
			bb.setBoard();
			while (bb.playGame(window, font1, Photo, score1, score2, Player1, Player2));
			cout << "Do you want to play again? (y for yes, anything else for no) ";
			cin >> s;
			if (s != "y")
				newgame = false;
		}
	}
	return 0;
}

