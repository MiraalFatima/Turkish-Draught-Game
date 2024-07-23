#include<SFML/Graphics.hpp>
#include<time.h>
#include <iostream>
#include <cmath>
#include <string>
using namespace sf;
using namespace std;
//enumeration of blocks typess and the color on the board has been done
//for the purpose of taking only one value(one block) at a time and considering one color at a time
//by the means of creating enum type object where it is being used
//for example in the class of square the piece is made of type Piece here by doing so we can
//easily access one piece at a time considering it as a numerical value or a variable
enum Block { STANDARD, KING, EMPTY };
enum Colourr { WHITE, BLACK, NONE };
class Square
{
private:
	Block block;
	Colourr color;
	int x, y;
	//x represents rows
	//y represents coloums
public:
	void setSpace(Square*);//isne eik space me eik block ka color or us block ke type set krni hai
	void setEmpty();//ye empty kry ga sb kch bs
	void setBlockAndColor(Block, Colourr);
	Block getBlock();
	Colourr getColor();
	void setX(int ex) { x = ex; }
	void setY(int why) { y = why; }
	int getX() { return x; }
	int getY() { return y; }
	Square();
};
class Board
{
private:
	Square square[8][8];//2-d array for the visualization of board
	Colourr turn = WHITE;//enumeration.....variable of name turn is being made and WHITE
	//has been assigned to it so it considers only variable WhIte from the set of color
	//defined earlier
	bool move_standard_block(RenderWindow &window, Square* thisStandard, Square* thatSpace, int& score1, int& score2);
	bool move_king_block(Square* thisKing, Square* thatSpace);
	bool makeMove(RenderWindow& window, int x1, int y1, int x2, int y2, int& score1, int& score2);
	void printBoard(RenderWindow &window, Font& font1, RectangleShape& Photo, int &score1, int &score2, string Player1, string Player2);
public:
	Square* getSquare(int x, int y) {
		return &square[x][y];
	}
	void setSquare(Square* s, int x, int y) {
		square[x][y] = *s;
	}
	bool doMove(RenderWindow &window, int& score1, int& score2);

	void setBoard();
	bool playGame(RenderWindow& window, Font& font1, RectangleShape& Photo, int &score1, int &score2, string Player1, string Player2);
	
};
