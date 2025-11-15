#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

//#define DEBUG //<---- Uncomment to see debug information (such as the squares a piece is moving through)

//----------------------- Constants -----------------------
//Constants for board array
const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

//Constants for rendering board
const string SQUARE0 = "\033[100m";
const string SQUARE1 = "\033[107m";
const string RESET = "\033[49m";
const string RED_TEXT = "\u001b[31m";
const string BLUE_TEXT = "\u001b[96m";
const string WHITE_TEXT = "\u001b[37m";
const string BOLD = "\u001b[1m";
const string NO_BOLD = "\u001b[22m";

//Constants for messages
const string GET_PIECE_MSG = "Please enter the coordinate of the piece to move (column, row)";
const string MOVE_PIECE_MSG = "Please enter the coordinate to move the piece to";
const string NO_PIECE_MSG = "There is no piece at that coordinate";
const string WRONG_COLOR_MSG = "That piece does not belong to you!";
const string SPACE_OCCUPIED_MSG = "That space has a piece of the same color";
const string WRONG_MOVE_MSG = "That piece cannot move in that way";
const string PATH_NOT_FREE_MSG = "There are pieces blocking the path";

//----------------------- Function Prototypes -----------------------
/*(used to tell the compiler that functions exist, their return value, and inputs)*/

void initializeBoard(string board[BOARD_HEIGHT][BOARD_WIDTH]);
void printBoard(string board[BOARD_HEIGHT][BOARD_WIDTH]);
bool hasWon(string board[BOARD_HEIGHT][BOARD_WIDTH]);
void movePiece(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y);
char getPieceType(string piece);
char getPieceType(string board[BOARD_HEIGHT][BOARD_WIDTH], int x_pos, int y_pos);
bool isPieceRed(string); //Example of another way to do prototypes. Optional to specify parameter names, just types are needed by compiler @ prototype.
bool isPieceRed(string board[BOARD_HEIGHT][BOARD_WIDTH], int x_pos, int y_pos);
bool isFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y);
bool isPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int step_x, int step_y, int distance);
bool isHorizontalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x);
bool isVerticalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_y);
bool isDiagonalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y);
void readPosition(int& pos_x, int& pos_y);
bool canPieceMoveLikeThat(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y);
void playTurn(string board[BOARD_HEIGHT][BOARD_WIDTH], bool is_red_turn, int turn_number);
/* TODO: Write the prototypes for readInteger and readChar here */
int readInteger(int min, int max);
char readChar(char min, char max);

int main() {

	string board[BOARD_HEIGHT][BOARD_WIDTH]; //Board for the game
	initializeBoard(board); //Setup the board for a game of Chess++

	//Play the game until someone has won
	cout << "Start the game!\n";
	bool isRedTurn = true; //Red goes first
	int turn = 1; //Counter for turns played
	while (!hasWon(board)) //Keep playing until someone has won
	{
		playTurn(board, isRedTurn, turn); //Play the turn
		isRedTurn = !isRedTurn; //Flip from red to blue or vice versa
		++turn; //Go to the next turn
	}

	cout << "Done! Finished in " << turn - 1 << " turns\n";
	return 0;
}

//----------------------- Function Definitions -----------------------

//Initializes the board to start the game
void initializeBoard(string board[BOARD_HEIGHT][BOARD_WIDTH])
{
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_HEIGHT; j++)
			board[i][j] = " ";

	//Blue pieces
	board[7][0] = board[7][7] = BLUE_TEXT + BOLD + "^"; //Blue Pointer (Rook)
	board[6][0] = board[6][7] = BLUE_TEXT + BOLD + "/"; //Blue Slash (Bishop)
	board[7][2] = BLUE_TEXT + BOLD + "C"; //Blue C (King)
	board[7][3] = board[7][4] = BLUE_TEXT + BOLD + "+"; //Blue + (Queen)

	//Red pieces
	board[0][0] = board[0][7] = RED_TEXT + BOLD + "^"; //Red Pointer (Rook)
	board[1][0] = board[1][7] = RED_TEXT + BOLD + "/"; //Red Slash (Bishop)
	board[0][2] = RED_TEXT + BOLD + "C"; //Red C (King)
	board[0][3] = board[0][4] = RED_TEXT + BOLD + "+"; //Red + (Queen)
}

//Prints the board to the screen
void printBoard(string board[BOARD_HEIGHT][BOARD_WIDTH])
{
	cout << NO_BOLD << "  ABCDEFGH" << endl;
	cout << ' ' << '+' << setw(BOARD_WIDTH) << setfill('=') << "" << '+' << endl; //Print top
	for (int i = 0; i < BOARD_HEIGHT; i++)
	{
		cout << BOARD_HEIGHT - i << '|'; //Print left edge
		for (int j = 0; j < BOARD_WIDTH; j++) //Print row
			cout << (i % 2 == j % 2 ? SQUARE0 : SQUARE1) << board[i][j]; //Print checkerboard pattern
		cout << RESET << WHITE_TEXT << NO_BOLD << '|'; //Print right edge
		cout << endl;
	}

	cout << WHITE_TEXT << ' ' << '+' << setw(BOARD_WIDTH) << "" << setfill(' ') << '+' << endl; //Print bottom
}

//Indicates if someone has won
bool hasWon(string board[BOARD_HEIGHT][BOARD_WIDTH])
{
	//Check if two (or more) kings exist on the board
	int kingCount = 0;
	for (int i = 0; i < BOARD_HEIGHT; i++)
		for (int j = 0; j < BOARD_WIDTH; j++)
			if (getPieceType(board[i][j]) == 'C') { kingCount++; if (kingCount >= 2) return false; }	

	return true;
}

//Moves a piece from the start position to the end position. Assumes this is a valid move
void movePiece(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y)
{
	board[end_y][end_x] = board[start_y][start_x]; //Move piece to destination
	board[start_y][start_x] = " "; //Mark original spot as now empty
}

//Returns the piece's type (C = C, + = Plus, / = Slash, ^ = Pointer)
char getPieceType(string piece)
{
	return piece[piece.length() - 1];
}

//Returns the type of the piece at the given position (C = C, + = Plus, / = Slash, ^ = Pointer)
char getPieceType(string board[BOARD_HEIGHT][BOARD_WIDTH], int x_pos, int y_pos)
{
	return getPieceType(board[y_pos][x_pos]);
}

//Indicates the color of the piece at the given position
bool isPieceRed(string piece)
{
	return !piece.substr(0, 5).compare(RED_TEXT);
}

//Indicates the color of the piece at the given position. This is an example of a function overload, overloading the function above to also take a position
bool isPieceRed(string board[BOARD_HEIGHT][BOARD_WIDTH], int x_pos, int y_pos)
{
	return isPieceRed(board[y_pos][x_pos]);
}

//Indicates whether a position on the board is "free" (i.e. is there no piece there?)
bool isFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int pos_x, int pos_y)
{
	return !board[pos_y][pos_x].compare(" ");
}

//Indicates whether the path is "free" (i.e. there are no pieces in the way)
bool isPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int step_x, int step_y, int distance)
{
	//Go through the path. If a piece is encountered, the path is not free
	for (int i = 1; i < distance; i++)
	{
		#ifdef DEBUG
		cout << "Checking square (" << (start_x + step_x * i) << ", " << start_y + step_y * i << ")" << endl;
		#endif
		if (board[start_y + step_y * i][start_x + step_x * i] != " ") return false;
	}

	return true; //Else if the entire path was traversed, it is free
}

/* ============================== TODO: Finish the functions below ============================== */

/* Describe the function here. Please do the same for all other definitions */
bool isHorizontalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x)
{
	//Go through the x path. If a piece is encountered, the path is not free
	// calculate distance
	int distance = abs(end_x - start_x);

	// see if we are going to the right of the left
	int step_x = 1;
	if (end_x < start_x) {
		step_x = -1;
	}

	// we call the isPathFree function with the calculated variables
	bool isFree = isPathFree(board, start_x, start_y, step_x, 0, distance);
	return isFree;

}

bool isVerticalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_y)
{
	//Go through the y path. If a piece is encountered, the path is not free
	// calculate distance
	int distance = abs(end_y - start_y);

	// see if we are going to up or down
	int step_y = 1;
	if (end_y < start_y) {
		step_y = -1;
	}

	// we call the isPathFree function with the calculated variables
	bool isFree = isPathFree(board, start_x, start_y, 0, step_y, distance);
	return isFree;
}

bool isDiagonalPathFree(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y)
{
	// calculate distance
	int distance = abs(end_x - start_x);

	// see if we are going to the right of the left
	int step_x = 1;
	if (end_x < start_x) {
		step_x = -1;
	}

	// see if we are going to up or down
	int step_y = 1;
	if (end_y < start_y) {
		step_y = -1;
	}

	// we call the isPathFree function with the calculated variables
	bool isFree = isPathFree(board, start_x, start_y, step_x, step_y, distance);
	return isFree;
}

int readInteger(int min, int max)
{
	// user input
	int userInput = 0;
	// bool check
	bool isValid = false;
	while (!isValid){
		// user input
		cin >> userInput;

		// error checking
		if (cin.fail() || userInput < min || userInput > max){
			cout << "Error, please enter an integer between " << min << " and " << max << ", inclusive" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
		} else {
			isValid = true;
		}
	}
	return userInput;

}

char readChar(char min, char max)
{
	// TODO: Write the function
	// variable needed
	char userInput = ' ';
	bool isValid = false;

	// changing functions to uppercase
	char upMin = toupper(min);
	char upMax = toupper(max);

	// loop until the input is valid
	while (!isValid){
		// user input
		cin >> userInput;

		// change userinput to uppercase
		userInput = toupper(userInput);

		// checking if the input is between the min and the max
		if (userInput < upMin || userInput > upMax) {
			cout << "Error, please enter a char between " << min << " and " << max << ", inclusive" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
		} else {
			isValid = true;
		}
	}
	return userInput;

}

void readPosition(int& pos_x, int& pos_y)
{
	//variables needed
	char colChar = readChar('A', 'K');
	int rowNum = readInteger(1, 8);

	// converting the char to integers of the poostion using ASSICC
	pos_x = colChar - 'A';
	// converting the char to integers of the poostion using ASSICC
	pos_y = 8 - rowNum;

}

bool canPieceMoveLikeThat(string board[BOARD_HEIGHT][BOARD_WIDTH], int start_x, int start_y, int end_x, int end_y)
{
	//TODO: Write the function
	// getting the type of the item
	char Piece = getPieceType(board, start_x, start_y);

	// calculate the distance
	int xDistance = abs(end_x - start_x);
	int yDistance = abs(end_y - start_y);

	// switch for the piece tuypes
	switch (Piece) {
		// when C
		case 'C':
			return (xDistance <= 1 && yDistance <= 1);

		// when ^
		case '^':
			return (xDistance > 0 && yDistance == 0) || (xDistance == 0 && yDistance > 0);
		
		// when /
		case '/':
			return (xDistance == yDistance && xDistance > 0);

		// when +
		case '+': {
            bool isHorizontal = (xDistance > 0 && yDistance == 0);
            bool isVertical = (xDistance == 0 && yDistance > 0);
            bool isDiagonal = (xDistance == yDistance && xDistance > 0);
            return (isHorizontal || isVertical || isDiagonal);
		}
		// otherwise return false
		default:
			return false;
	}
}

void playTurn(string board[BOARD_HEIGHT][BOARD_WIDTH], bool is_red_turn, int turn_number) 
{
	// print the turn based on the color
	if (is_red_turn){
		cout << "Turn " << turn_number << ": " << "Red Turn" << endl;
	} else {
		cout << "Turn " << turn_number << ": " << "Blue Turn" << endl;
	}

	// printing the board
	printBoard(board);

	// moving the piece

	// variables needed
	int start_x = 0;
	int start_y = 0;
	bool isValid = false;

	while (!isValid) {
		// ask the user
		cout << GET_PIECE_MSG << endl;

		// getting the position to user
		readPosition(start_x, start_y);

		// checking system
		if (isFree(board, start_x, start_y)) {
			cout << NO_PIECE_MSG << endl;
		} else if (isPieceRed(board, start_x, start_y) != is_red_turn) {
			cout << WRONG_COLOR_MSG << endl;
		} else {
			isValid = true;
		}
	}

	// ask user where to move it
	// variables needed
	int end_x = 0;
	int end_y = 0;
	bool isValidEnd = false;

	// loop untile valid
	while (!isValidEnd) {
		cout << MOVE_PIECE_MSG << endl;
		readPosition(end_x, end_y);

		// check if the position is valid and if the piece can move there
		if (!isFree(board, end_x, end_y) && (isPieceRed(board, end_x, end_y) == is_red_turn)) {
			cout << SPACE_OCCUPIED_MSG << endl;
		} else if (!canPieceMoveLikeThat(board, start_x, start_y, end_x, end_y)) {
			cout << WRONG_MOVE_MSG << endl;
		} else {
			// get the distance
			// variables needed
			int xDistance = abs(end_x - start_x);
			int yDistance = abs(end_y - start_y);
			bool pathBlocked = false;

			// check is path is blocked
			if (xDistance > 0 && yDistance == 0) {
				// horizontal
				if (!isHorizontalPathFree(board, start_x, start_y, end_x)) {
					pathBlocked = true;
				}
			} else if (yDistance > 0 && xDistance == 0) {
				// vertical
				if (!isVerticalPathFree(board, start_x, start_y, end_y)){
					pathBlocked = true;
				}
			} else if (xDistance > 0 && xDistance == yDistance) {
				// diagonal
				if (!isDiagonalPathFree(board, start_x, start_y, end_x, end_y)) {
					pathBlocked = true;
				}
			}

			// switch the boolean based on the status of the path
			if (pathBlocked) {
				cout << PATH_NOT_FREE_MSG << endl;
			} else {
				isValidEnd = true;
			}
		}
	}

	// move the piece
	movePiece(board, start_x, start_y, end_x, end_y);


}

//TODO: Write the playTurn function definition here
	//Print whose turn it is (red or blue)
	//Read the position of the piece that is going to be moved until it is correct
		//If there is no piece at the correct position, print the NO_PIECE_MSG
		//If the piece is not the same color as the player whose turn it is, print the WRONG_COLOR_MSG
	//Read the position to move the piece to until its correct
		//If the position has a piece already in it that belongs to that player, they cannot move there. SPACE_OCCUPIED_MSG
		//If the position is not one reachable because of the way the piece moves, print WRONG_MOVE_MSG
		//If there are pieces blocking the path of the piece, print PATH_NOT_FREE_MSG
	//Move the piece to where it needs to go