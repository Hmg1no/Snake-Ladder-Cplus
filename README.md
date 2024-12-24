# Snake-Ladder-Cplus
This project includes a design and implementation of the game engine for a Snakes and Ladders board. The grid in this engine is a linked list, and the players can traverse the list to advance. This implementation was developed utilizing C++. 
Objectives:  

  -Practice analyzing a project's requirements.
  -Implementing a linked list data structure.
  -Practice C++ dynamic memory management, i.e. avoiding memory leaks, avoiding double free, protection against wrong accesses in memory (segmentation fault), etc.
  -Practice writing test cases for a project.

Introduction:  

Snakes and Ladders is a dice board game that multiple players can compete with each other. The board can be of any size and it must be a square grid. Players make moves based on dice rolling and depending on what cell they land they might receive a reward or a punishment. If a player lands on a cell that has a ladder, the player can climb the ladder. If a player lands on a cell that has a snake, the player needs to fall down to the other cell containing the tail of the snake. 

Specifications:

snakes.h - Interface for the Snakes class.
snakes.cpp - Implementation of Snake class
mytest.cpp - A test file to test different methods of the snake class
driver.txt - sample output from driver.cpp.
driver.cpp - A sample program to test program functionality

Snake Class:

The Snakes class has a pointer to an object of type Cell. The pointer is stored in the member variable m_start. This variable is the head to a singly linked list. The linked list represents the game board. The two players m_player1 and m_player2 start the game at cell number 1 in the list. They play in turn by rolling dice and perform the required moves. The game continues until one of the players reaches the last cell of the board.

Snakes::Snakes():

The default constructor creates an empty object.

Snakes::~Snakes():

The destructor deallocates all memory in the object and reinitializes all member variables.

void Snakes::clear():

This function deallocates all memory in the object and reinitializes all member variables.

Snakes::Snakes(int boardSize):

The alternative constructor creates a default game board. The parameter boardSize specifies the number of cells on the square board. If a user provides a size which does not have an integer square root, the constructor converts the size to the largest possible value less than boardSize which has an integer square root. For the requirements of a default board please refer to The Rules section on this page. If the requested size is not valid the constructor creates an empty object.

bool Snakes::makeDefaultBoard(int boardSize):

This function creates a default board. The parameter boardSize specifies the number of cells on the square board. If a user provides a size which does not have an integer square root, the constructor converts the size to the largest possible value less than boardSize which has an integer square root. For the requirements of a default board please refer to The Rules section on this page. If the requested size is not valid the function does not modify the object and returns false. If the object has already a board this function does not modify the object and returns false. If everything is in order and the new board is created the function returns true.

void Snakes::makeRandomBoard(int boardSize, int numSnakesLadders):

This function creates a board using random values. It clears the current board and creates a new board with the requested values. The user can specify two parameters. The parameter boardSize specifies the number of cells on the square board. If a user provides a size which does not have an integer square root, the function converts the size to the largest possible value less than boardSize which has an integer square root. Also, the user specifies the total number of snakes and ladders by passing the parameter numSnakesLadders. The function uses this parameter to create the snakes and ladders and it places them on the board in random locations. If the requested numSnakesLadders is an invalid value the function adjusts it to the min or max valid values. For the random board requirements please refer to The Rules section on this page. If the requested board size is invalid the function creates an empty object.

bool Snakes::play(int dice):

This function performs the requested move, the parameter dice indicates the number of cells a player can advance. Every time a move is complete the function changes the player turn. If a move is complete the function returns true. If a player lands on a cell with a snake or a ladder the corresponding action must be taken to complete the move. If a player lands on the last cell the game ends, in such a case the play function returns false. If a player is near the end the player must continue rolling dice until the player receives the required dice value to move to the last cell. Such a case is considered a valid play, then the function returns true.

int Snakes::rollDice():

This function returns a random number between 1 and 6.

void Snakes::reStart():

This function reinitializes the game without any changes to the board. The players can start the game again on the same board.

const Snakes & Snakes::operator=(const Snakes & rhs):
The assignment operator, creates a deep copy of rhs.

void Snakes::dumpBoard():
This function prints out the game board to the standard output.
