#include<SFML/Graphics.hpp>
#include<time.h>
#include"TurkishDraught.h"
#include<iostream>

using namespace std;
using namespace sf;
//constructor of Square Class
Square::Square()
{
	block = EMPTY;
	color = NONE;
}
Block Square::getBlock()
{
	return block;
}
Colourr Square::getColor()
{
	return color;
}
void Square::setEmpty()
{
	block = EMPTY;
	color = NONE;
}
void Square::setSpace(Square* space)
{
	color = space->getColor();
	block = space->getBlock();
}
void Square::setBlockAndColor(Block b, Colourr c)
{
	block = b;
	color = c;
}
void Board::printBoard( RenderWindow &window, Font &font1,RectangleShape &Photo, int &score1,int &score2, string Player1, string Player2)
{
	Texture board, black_p, white_p, black_k, white_k, head, scr_brd; // DECLARE THE IMAGES TO LOAD
	Sprite black, white; //DECLARE THE PIECES
	Text player1, player2, score_p1, score_p2;

	string score_of1, score_of2; //TO DISPLAY SCORES
	score_of1 = Player1 + ": " + to_string(score1);
	score_of2 = Player2 + ": " + to_string(score2);

	Vertex line1[] = { Vertex(Vector2f(0.f,165.f)),Vertex(Vector2f(1300.f,165.f)) }; ////TESTER
	Vertex line2[] = { Vertex(Vector2f(140.f,0.f)),Vertex(Vector2f(140.f,1100.f)) }; ///TESTER

	//LOAD ALL TEXTURES
	board.loadFromFile("images/board.png");
	head.loadFromFile("images/Heading.png");
	black_p.loadFromFile("images/black_king.png");
	white_p.loadFromFile("images/white_king.png");

	RectangleShape background, heading; //SET ALL BACKGROUND AND DETAILS
	background.setSize(Vector2f(700.f, 700.f));
	background.setTexture(&board);
	background.setPosition(Vector2f(100.f, 125.f));

	heading.setSize(Vector2f(500.f, 500.f));
	heading.setTexture(&head);
	heading.setPosition(Vector2f(800.f, 50.f));

	player1.setFont(font1);
	player1.setCharacterSize(50);
	player1.setString(Player1);
	player1.setPosition(Vector2f(350.f, 50.f));

	player2.setFont(font1);
	player2.setCharacterSize(50);
	player2.setString(Player2);
	player2.setPosition(Vector2f(350.f, 820.f));

	score_p1.setFont(font1);
	score_p1.setCharacterSize(30);
	score_p1.setString(score_of1);
	score_p1.setPosition(Vector2f(890.f, 500.f));
	score_p2.setFont(font1);
	score_p2.setCharacterSize(30);
	score_p2.setString(score_of2);
	score_p2.setPosition(Vector2f(890.f, 550.f));

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();

			if (event.KeyPressed && event.key.code == Keyboard::Escape)
				window.close();
		}
		//UPDATE

		

		//1-CLAER 2-DRAW 3-DISPLAY
		//CLEAR EVERYTHING
		window.clear();

		//DRAW
		window.draw(Photo);
		window.draw(background);
		window.draw(heading);
		window.draw(player1);
		window.draw(player2);
		window.draw(score_p1);
		window.draw(score_p2);

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{

				black.setScale(Vector2f(0.2f, 0.2f));
				white.setScale(Vector2f(0.2f, 0.2f));
				Block b = square[i][j].getBlock();
				Colourr c = square[i][j].getColor();
				//capitals is for white and small letters for black
				switch (b)
				{
				case STANDARD:
				{
					if (c == WHITE)
					{
						white.setTexture(white_p);
						white.setPosition(Vector2f(127.f + (j * 78), 150 + (i * 78)));
					}
					else
					{
						black.setPosition(Vector2f(127.f + (j * 78), 150 + (i * 78)));
						black.setTexture(black_p);
					}
					window.draw(black);
					window.draw(white);
					break;
				}
				case KING:
				{
					if (c == WHITE)
					{
						white.setTexture(white_p);
						white.setPosition(Vector2f(127.f + (j * 78), 150 + (i * 78)));
					}
					else
					{
						black.setPosition(Vector2f(127.f + (j * 78), 150 + (i * 78)));
						black.setTexture(black_p);
					}
					window.draw(black);
					window.draw(white);
					break;
				}
				}
			}

		}
		window.display();
	
	
}
bool Board::move_standard_block(RenderWindow &window, Square* thisStandard, Square* thatSpace, int& score1, int& score2)
{
	Texture white_wins, black_wins, unc, turk_dama;
	white_wins.loadFromFile("images/white wins.png");
	black_wins.loadFromFile("images/black wins.png");
	unc.loadFromFile("images/uncles.png");
	turk_dama.loadFromFile("images/Heading.png");

	RectangleShape back, board, head;
	head.setSize(Vector2f(500.f, 500.f));
	head.setTexture(&turk_dama);
	head.setPosition(Vector2f(800.f, 50.f));

	board.setSize(Vector2f(700.f, 700.f));
	board.setPosition(Vector2f(100.f, 125.f));

	back.setSize(Vector2f(1300.f, 1100.f));
	back.setPosition(Vector2f(0.f, 0.f));
	back.setTexture(&unc);

	

	if (score2 == 0)
	{
		
		RenderWindow whitewon(VideoMode(1300, 1100), "RESULTS", Style::Default);
		whitewon.setFramerateLimit(60);
		while (whitewon.isOpen())
		{
			Event e1;
			while (whitewon.pollEvent(e1))
			{
				if (e1.type == Event::Closed)
					whitewon.close();

				if (e1.KeyPressed && e1.key.code == Keyboard::Escape)
					whitewon.close();
			}
			whitewon.clear();
			board.setTexture(&white_wins);
			whitewon.draw(back);
			whitewon.draw(head);
			whitewon.draw(board);
			whitewon.display();
		}
		
	}
	else if (score1 == 0)
	{
		
		RenderWindow blackwon(VideoMode(1300, 1100), "RESULTS", Style::Default);
		blackwon.setFramerateLimit(60);
		while (blackwon.isOpen())
		{
			Event e2;
			while (blackwon.pollEvent(e2))
			{
				if (e2.type == Event::Closed)
					blackwon.close();

				if (e2.KeyPressed && e2.key.code == Keyboard::Escape)
					blackwon.close();
			}
			blackwon.clear();
			board.setTexture(&black_wins);
			blackwon.draw(back);
			blackwon.draw(head);
			blackwon.draw(board);
			blackwon.display();

		}
		
	}

	//thisStandard is the location on the square where the goti resides
	// thatSpace is the location in the the cheaker board where the goti has to move
	//off board inputs should be handled elsewhere (before this)
	//squares with same color should be handled elsewhere (before this)
	bool invalid = false;
	int standardX = thisStandard->getX();
	int standardY = thisStandard->getY();
	int thatX = thatSpace->getX();
	int thatY = thatSpace->getY();


	if (thisStandard->getColor() == WHITE)
	{
		if (thatSpace->getColor() == BLACK)
		{
			if (thatX == standardX + 1 && thatY == standardY)
			{
				thatX++;

			}
			else if (thatY == standardY + 1 && thatX == standardX)
			{
				thatY++;
			}
			else if (thatY == standardY - 1 && thatX == standardX)
			{
				thatY--;
			}
		
		}
		if (thatX == standardX + 1  || thatY == standardY + 1 || thatY == standardY - 1)
		{
			//leftward movement for one move left
			if (standardX == thatX && thatY == standardY - 1)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				return true;
			}
			//rightward movement for one move right
			else if (standardX == thatX && thatY == standardY + 1 /*&& thatSpace->getColor() == NONE*/)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				return true;
			}
			//forward  movement for one move forward
			else if (standardX + 1 == thatX && thatY == standardY)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();

				return true;
			}
			else
				return false;

		}
		else if (thatX == standardX + 2 || thatY == standardY + 2 || thatY == standardY - 2)
		{
			//leftward movement for two moves left
		 if (standardX == thatX && thatY == standardY - 2)
		 {
			 thatSpace->setSpace(thisStandard);
			thisStandard->setEmpty();
			turn = WHITE;
			cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
			score2--;
			doMove(window,score1,score2);
			return true;
		 }
		 //rightward movement for two moves
		 else if (standardX == thatX && thatY == standardY + 2 /*&& thatSpace->getColor() == NONE*/)
		 {
			 thatSpace->setSpace(thisStandard);
			 thisStandard->setEmpty();
			 turn = WHITE;
			 cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
			 score2--;
			 doMove(window, score1, score2);
			 return true;
		 }
		 //forward  movement for two moves
		 else if (standardX + 2 == thatX && thatY == standardY)
		 {
			 
			 thatSpace->setSpace(thisStandard);
			 thisStandard->setEmpty();
			 turn = WHITE;
			 cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
			 score2--;
			 doMove(window, score1, score2);
			 return true;
		 }
		 else
			 return false;
		}
	}
	else if (thisStandard->getColor() == BLACK)
	{

		if (thatSpace->getColor() == WHITE)
		{
			if (thatX == standardX -1 && thatY == standardY)
			{
				thatX--;

			}
			else if (thatY == standardY + 1 && thatX == standardX)
			{
				thatY++;
			}
			else if (thatY == standardY - 1 && thatX == standardX)
			{
				thatY--;
			}

		}
		if (thatX == standardX - 1 || thatY == standardY + 1 || thatY == standardY - 1)
		{
			//leftward movement for one move left
			if (standardX == thatX && thatY == standardY - 1)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				return true;
			}
			//rightward movement for one move
			else if (standardX == thatX && thatY == standardY + 1 /*&& thatSpace->getColor() == NONE*/)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				return true;
			}
			//forward  movement for one move
			else if (standardX - 1 == thatX && thatY == standardY)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				return true;
			}
			else
				return false;
		}
		else if (thatX == standardX - 2 || thatY == standardY + 2 || thatY == standardY - 2)
		{
			//leftward movement for two moves left
			if (standardX == thatX && thatY == standardY - 2)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				turn = BLACK;
				cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
				score1--;
				doMove(window, score1, score2);
				return true;
			}

			//rightward movement for two moves
			else if (standardX == thatX && thatY == standardY + 2 /*&& thatSpace->getColor() == NONE*/)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				turn = BLACK;
				cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
				score1--;
				doMove(window, score1, score2);
				return true;
			}

			//forward  movement for two moves
			else if (standardX - 2 == thatX && thatY == standardY)
			{
				thatSpace->setSpace(thisStandard);
				thisStandard->setEmpty();
				turn = BLACK;
				cout << "ENTER THE POSITION OF WHICH YOU WISH TO OVER-RIDE" << endl;
				score1--;
				doMove(window, score1, score2);
				return true;
			}
			else
				return false;
		}
	}
	else
		return false;
}
bool Board::move_king_block(Square* thisStandard, Square* thatSpace)
{
	return true;
}
void Board::setBoard()
{
	for (int i = 1; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setBlockAndColor(STANDARD, WHITE);
		}
	}
	for (int i = 6; i > 4; i--)
	{
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setBlockAndColor(STANDARD, BLACK);
		}
	}
	for (int i = 2; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			square[j][i].setBlockAndColor(EMPTY, NONE);
		}

	}
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
		{
			square[i][j].setX(i);
			square[i][j].setY(j);
		}

}
bool Board::playGame(RenderWindow &window, Font& font1, RectangleShape& Photo, int &score1, int &score2, string Player1, string Player2)
{
	printBoard(window,font1,Photo,score1,score2,Player1,Player2);
		return doMove(window,score1,score2);
}
bool Board::doMove(RenderWindow &window, int& score1, int& score2)
{
	
	string move;
	int x1, x2 = 0, y1, y2 = 0;
	bool stop = false;
	(turn == WHITE) ? cout << "WHITE'S TURN " << endl : cout << "BLACK'S TURN" << endl;
	cout << "POSITION: " << endl;
	cin >> move;

	x1 = move[0] - 48;
	y1 = move[1] - 48;
	
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			if (e.type == Event::Closed)
				window.close();
		}
		if (e.KeyPressed && e.key.code == Keyboard::S)
		{
			x2 = x1 + 1;
			y2 = y1;
			break;
		}
		else if (e.KeyPressed && e.key.code == Keyboard::W)
		{
			x2 = x1 - 1;
			y2 = y1;
			break;
		}
		else if (e.KeyPressed && e.key.code == Keyboard::D)
		{
			y2 = y1 + 1;
			x2 = x1;
			break;
		}
		else if(e.KeyPressed && e.key.code==Keyboard::A)
		{
			y2 = y1 - 1;
			x2 = x1;
			break;
		}
	}
		
	while (!stop)
		{
			if (getSquare(x1, y1)->getColor() == turn)
			{
				//the function of make move will tell
					//about the move to be taken is right or is it wrong
				if (makeMove(window, x1, y1, x2, y2, score1, score2) == false)
				{
					cout << "Invalid move, try again." << endl;
				}
				else
					stop = true;
			}
			else
				cout << "That's not your piece. Try again." << endl;
		}
		if (turn == BLACK)
			turn = WHITE;
		else
			turn = BLACK;

		return true;
		
	}

bool Board::makeMove(RenderWindow &window, int  x1, int y1, int x2, int y2, int& score1, int& score2) {
	//Checking for turns will be done previous to this
	if (x1 < 0 || x1>7 || y1 < 0 || y1>7 || x2 < 0 || x2>7 || y2 < 0 || y2>8)
		// this check will check the out of range input i.e out of range from 8*8 array or board
	{
		cout << "One of your inputs was our of bounds\n";
		return false;
	}
	//wowowowowwow
	// two pointers bny hen or wo ye dekhty hen k jo xy ke values likhi hen woh kya apky 
	//he block k uper to nhi aa rhi?
	//dusri cheez ye check krti hai k color bl
	Square* start = getSquare(x1, y1);//goti ke location
	Square* dest = getSquare(x2, y2);

	if (start->getColor() == dest->getColor() && dest->getColor() != NONE)
	{
		std::cout << "Invalid move: cannot land on your own piece" << std::endl;
		return false;
	}
	//idr jo get block ka function hai na usne ye btaana hai k block standard hai ya king?
	//usky baad jo case hoga wo wala case chly ga or block ke type k hisaab se functions ko call jaaye gee or phir block ke movement hogee
	//idr srs ka pointer hai, ye wala pointer us location ko point kr rha hai jidr goti pri hai
	switch (start->getBlock())
	{
	case STANDARD:
		return move_standard_block(window, start, dest, score1, score2);
		break;
	case KING:
		return move_king_block(start, dest);
		break;
	case EMPTY:
		cout << "You do not have a piece there\n";
		return false;
		break;
	default: cerr << "Something went wrong in the switch statement in makeMove() \n";
		break;
	}
	return false;
}
