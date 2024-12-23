/***********************************************************
 ** // UMBC - CMSC 341 - Fall 2024 - Proj1
 ** File:    Snakes.cpp
 ** Project: Fall 2024 - Proj0
 ** Author:  Hazael Magino
 ** Date:     9/15/2024
 ** This file contains the proper implementations for snakes.cpp
 **********************************************************/
#include "snakes.h"

// Name: Snakes() - Default Constructor
// Desc: Used to build a new empty snake object (for invalid parameters)
// parameters not assigned.
// Preconditions: None
// Postconditions: Creates a new empty snake object with a default name and
// values of nullptrs and no turns since there is no game.
Snakes::Snakes() {

  // default values assigned to member variables;
  // nullptrs for pointers 0 for integers.
  m_start = nullptr;
  m_player1 = nullptr;
  m_player2 = nullptr;
  m_playerTurn = 0;
  m_playerTurn = 0;
  m_dice.init(0, 0);
  m_dice.setSeed(time(0));
}

// Name: Snakes(int boardSize) - Alternative Overloaded Constructor
// Desc: Used to build a creates a default game board.
// Preconditions: Size must be passed in and identified
// Postconditions: Builds a default game board with member variables populated
// and game ready to start.
Snakes::Snakes(int boardSize) {

  m_start = nullptr;
  m_player1 = nullptr;
  m_player2 = nullptr;
  m_playerTurn = 0;
  int newSize = 0;
  m_playerTurn = 1;
  m_dice.init(1, 6);
  m_dice.setSeed(time(0));

  if (boardSize >= 9) {

    int brdSize = sqrt(boardSize);

    // If the sqrt root size is not a valid size then
    // next best possible square needs to be found
    if (boardSize % brdSize != 0) {

      // use truncated value of the sqrt value to get newSize
      newSize = brdSize * brdSize;
      makeDefaultBoard(newSize);
    } else {

      makeDefaultBoard(boardSize);
    }

  } else {
    m_start = nullptr;
    m_player1 = nullptr;
    m_player2 = nullptr;
    m_playerTurn = 0;
    m_dice.init(0, 0);
  }
}

// Name: ~Snakes() - Destructor
// Desc: Used to destroy all dynamic memory used
// Preconditions: Board must exist
// Postconditions: Removes all dynamic memory and set default values
// to member variables
Snakes::~Snakes() {

  if (m_start != nullptr) {
    // First check if the board exists
    Cell *curr = m_start;
    Cell *prev = nullptr;

    // delete pointer
    while (curr != nullptr) {
      prev = curr;
      curr = curr->m_next;
      delete prev;
    }

    // reset values to null or 0
    m_start = nullptr;
    m_player1 = nullptr;
    m_player2 = nullptr;
    m_playerTurn = 0;
    m_dice.init(0, 0);
  }
}

// Name: findSize() - Helper function
// Desc: Used to detirmine size of LL
// Preconditions: Board must exist
// Postconditions: returns integer size of LL
int Snakes::findSize(Cell *start) {
  // start is usually the beginning of the LL

  // if LL exist count from start
  if (m_start != nullptr) {
    int size = 0;
    Cell *temp = start;

    while (temp != nullptr) {
      temp = temp->m_next;
      size++;
    }

    // return size
    return size;
  } else {
    return 0;
  }
}

// Name: setObs()
// Desc: Helper function meant to help with setting ladder/snakes
// Preconditions: Board must exist
// Postconditions: Board is populated with snakes and ladder
void Snakes::setObs(int placement, int boardSize, int obst, bool type) {

  int check = 0; // Meant to help to check if all obstacles are on board
  int j = 1;     // start of m_start

  bool findDest = false; // Determine if we found a valid start setpoint
  bool setObst = false;  // Detirmine if we have set obstacles

  if (type == false) {

    // Handling ladders

    Cell *temp = m_start;    // Placeholder for setting north
    Cell *placeOb = m_start; // Iterator node to move across nodes

    do {

      if ((j != 1) && (j != boardSize) && (setObst != true)) {
        // Ensure we are not placing at start or end of board

        if ((j % placement == 0) && (findDest == true)) {

          // found the end of a valid placement, place object
          temp->m_next->setNorth(placeOb);
          findDest = false; // Reset findDest after placing
          check++;
        } else {

          if ((j % placement == 0) && (findDest == false)) {
            // If we have found the start of a valid placement
            temp = placeOb;
            findDest = true;
          }
        }
      }

      if (check == obst) {
        setObst = true;
      } else {

        if (placeOb->m_next != nullptr) {
          j++;
          placeOb = placeOb->m_next;
        } else {
          placeOb = m_start;
          temp = m_start;
          j = 1;
        }
      }
    } while (setObst == false);
  }

  if (type == true) {
    // Handling snakes

    Cell *temp = m_start;
    Cell *placeOb = m_start;

    do {

      if ((j != 1) && (j != boardSize) && (setObst != true)) {
        // Ensure we are not placing at start or end of board

        if ((placeOb != nullptr) && (placeOb->m_next != nullptr) &&
            (j % placement == 0) && (findDest == true) &&
            (placeOb->m_next->getSouth() != temp) &&
            (placeOb->m_next->getNorth() ==
             nullptr)) { // detect if there is a snake or ladder in cell

          if (temp != m_start) {
            // found the end of a valid placement, place object
            placeOb->m_next->setSouth(temp);
            findDest = false;
            check++;
          }

        } else {

          if ((placeOb != nullptr) && (placeOb->m_next != nullptr)) {

            if (placeOb->m_next->getSouth() == temp) {

              if (temp->m_next != nullptr) {
                // if ladder occupies the cell
                temp = temp->m_next;
              }

            } else if (placeOb->m_next->getNorth() != nullptr) {

              if (placeOb->m_next != nullptr) {
                // if ladder occupies the cell
                placeOb = placeOb->m_next;
              }

            } else {

              if ((j % placement == 0) && (findDest == false)) {

                // If we have found the start of a valid placement
                temp = placeOb;
                findDest = true;
              }
            }
          }
        }
      }

      if (check == obst) {
        setObst = true;
      } else {

        if (placeOb->m_next != nullptr) {
          j++;
          placeOb = placeOb->m_next;
        } else {
          placeOb = m_start;
          temp = m_start;
          j = 1;
        }
      }
    } while (setObst == false);
  }
}

// Name: makeDefaultBoard()
// Desc: Meant to allocate memory for a new board and obstacles
// Preconditions: Board must have a valid board size
// Postconditions: Board is populated with snakes and ladder
bool Snakes::makeDefaultBoard(int boardSize) {

  if (boardSize >= 9) {

    // initalize values
    m_start = nullptr;
    m_player1 = nullptr;
    m_player2 = nullptr;
    m_playerTurn = 0;
    m_playerTurn = 1;
    m_dice.init(1, 6);
    m_dice.setSeed(time(0));

    // object of board does not exist, must create board
    int brdSize = sqrt(boardSize);

    // If the sqrt root size is not valid size then
    // next best possible square needs to be found

    boardSize = brdSize * brdSize;
    // if conditions from regular board size were met

    // create start of board
    m_start = new Cell;
    Cell *curr = m_start;
    m_start->setID(1);
    m_playerTurn = 1;
    m_player1 = m_start;
    m_player2 = m_start;

    // create cells the remainder of the board
    for (int i = 1; i < boardSize; i++) {
      Cell *newCell = new Cell;
      newCell->m_next = nullptr;
      newCell->setID(i + 1); // set ID of cell
      curr->m_next = newCell;
      curr = newCell;
    }

    curr = nullptr;

    // detirmine the the amount of snakes or ladders to create
    int obst = floor((boardSize / 4) - 1);

    // detirmine the amount of obstacles based on given board size
    int ladder = floor(obst / 2);
    int snake = obst - ladder;

    // algorithm to place snakes and ladders. Minus two, to account for board
    // spaces not used for  ladders
    int placement1 = ceil((boardSize + 5) / obst);

    bool type = false; // type tells signifies if working with ladder(false)

    setObs(placement1, boardSize, ladder,
           type); // helper function to help place snake/ladder

    type = true; // working with snakes
    int placement2 = floor((boardSize - 6) /
                           obst); // Needs to be for the base case of 9 to work

    if (placement1 == placement2) {

      placement2 = placement2 - 1; // incase placement is the same for both
                                   // change placement for snake by one
    }

    setObs(placement2, boardSize, snake, type);
    return true;

  } else {

    // valid board size not provided, default values for member variables used

    m_start = nullptr;
    m_player1 = nullptr;
    m_player2 = nullptr;
    m_playerTurn = NOGAME;
    m_dice.init(0, 0);

    return false;
  }
}

// Name: setRandObs(int boardSize, int obst, bool type)
// Desc: Helper function meant to help with setting ladder/snakes
// Preconditions: Board must exist
// Postconditions: Board is populated with snakes and ladder
void Snakes::setRandObs(int boardSize, int obst, bool type) {

  int check = 0; // help detirmine the amount of obstacles left to place
  int j = 1;     // iterator for while loop

  bool findDest = false; // bool value to find valid placement
  bool setObst =
      false; // bool value to detirmine if all snakes/ladders are placed

  if (type == false) {
    // placing random ladders

    Cell *temp = m_start;    // help as a placeholder for setting m_north
    Cell *placeOb = m_start; // iterator node to move across board

    do {

      // make sure that we are not placing at ends of boards
      // and ensure all objects are placed
      if ((j != 1) && (j != boardSize) && (setObst != true)) {

        // generate random value for placement indicies
        int random = m_dice.getRandNum();

        if ((j % random == 0) && (findDest == true)) {

          // found the end of a valid placement, place object
          temp->m_next->setNorth(placeOb);
          findDest = false; // Reset findDest after placing
          check++;

        } else {

          if ((j % random == 0) && (findDest == false)) {

            // If we have found the start of a valid placement
            temp = placeOb;
            findDest = true;
          }
        }
      }

      // check if all obstacles have been placed
      if (check == obst) {
        setObst = true;
      } else {

        // if not iterate or go back to m_start
        if (placeOb->m_next != nullptr) {
          j++;
          placeOb = placeOb->m_next;
        } else {
          placeOb = m_start;
          temp = m_start;
          j = 1;
        }
      }
    } while (setObst == false);
  }

  if (type == true) {

    Cell *temp = m_start;    // help as a placeholder for setting m_north
    Cell *placeOb = m_start; // iterator node to move across board

    do {
      // Same procedures as ladders
      // make sure that we are not placing at ends of boards
      // and ensure all objects are placed
      if ((j != 1) && (j != boardSize) && (setObst != true)) {

        int random = m_dice.getRandNum();

        while (j % random != 0) {
          random = m_dice.getRandNum();
        }

        if ((j % random == 0) && (findDest == true) &&
            (placeOb->m_next->getSouth() != temp) &&
            (placeOb->m_next->getNorth() ==
             nullptr)) { // detect if there is a snake or ladder in cell

          // found the end of a valid placement, place object
          placeOb->m_next->setSouth(temp);
          findDest = false;
          check++;

        } else {

          if (placeOb->m_next->getSouth() == temp) {

            // if snakes already been placed in a location
            //  go to next cell
            if (temp->m_next != nullptr) {
              temp = temp->m_next;
            }

          } else if (placeOb->m_next->getNorth() != nullptr) {

            // if ladder occupies the cell already
            // go to next cell

            if (placeOb->m_next != nullptr) {
              placeOb = placeOb->m_next;
            }

          } else {

            if ((j % random == 0) && (findDest == false)) {

              // If we have found the start of a valid placement
              temp = placeOb;
              findDest = true;
            }
          }
        }
      }

      // check if all obstacles have been placed
      if (check == obst) {
        setObst = true;
      } else {

        // if not iterate or go back to m_start
        if (placeOb->m_next != nullptr) {
          j++;
          placeOb = placeOb->m_next;
        } else {
          placeOb = m_start;
          temp = m_start;
          j = 1;
        }
      }
    } while (setObst == false);
  }
}

// Name: makeRandomBoard()
// Desc: This function creates a board using random values.
// Preconditions: Board must have a valid board size and given number of
// snakes/ladders Postconditions: Board is populated with snakes and ladder in
// random places
void Snakes::makeRandomBoard(int boardSize, int numSnakesLadders) {

  if (m_start != nullptr) {
    // if m_start already exists, board exists which
    // must be cleard to create a new board.

    clear();
  }

  if (boardSize >= 9) {

    // should be initilized once clear is called

    // first detirmine size of grid
    int brdSize = sqrt(boardSize);

    // if conditions from regular board size were met
    boardSize = brdSize * brdSize;

    // initailize member variables
    m_start = new Cell;
    Cell *curr = m_start;
    m_start->setID(1);
    m_player1 = m_start;
    m_player2 = m_start;
    m_playerTurn = 1;
    m_dice.init(1, 6);
    m_dice.setSeed(time(0));

    // create cells for random board
    for (int i = 1; i < boardSize; i++) {
      Cell *newCell = new Cell;
      newCell->m_next = nullptr;
      newCell->setID(i + 1); // set ID of cell
      curr->m_next = newCell;
      curr = newCell;
    }

    curr = nullptr;
    int snakes = 0; // help set min snake number if numSnakesLadders not valid
    int ladder = 0; // help set min Ladder number if numSnakesLadders not valid

    int maxObs = (boardSize / 2) - 2; // get the max number of obstacles incase

    if ((numSnakesLadders < 2) || (numSnakesLadders > maxObs)) {

      // set number of ladders and snakes
      snakes = m_dice.getMin();
      ladder = m_dice.getMin();

    } else {

      // set number of ladders and snakes
      // based off given values
      ladder = numSnakesLadders / 2;
      snakes = numSnakesLadders - ladder;
    }

    bool type = false; // type tells signifies if working with ladder(false)

    setRandObs(boardSize, ladder, type);

    type = true; // signify we are placing snakes

    setRandObs(boardSize, snakes, type);

  } else {

    // valid board size not provided, default values for member variables used
    m_start = nullptr;
    m_player1 = nullptr;
    m_player2 = nullptr;
    m_playerTurn = 0;
    m_playerTurn = NOGAME;
    m_dice.init(0, 0);
  }
}

// Name: Clear()
// Desc: Used to destroy all dynamic memory used
// Preconditions: Board must exist
// Postconditions: Removes all dynamic memory and set default values
// to member variables
void Snakes::clear() {

  if (m_start != nullptr) {
    Cell *curr = m_start;
    Cell *prev = nullptr;

    // Move curr to delete respective nodes
    while (curr != nullptr) {
      prev = curr;
      curr = curr->m_next;
      delete prev;
    }

    // Set m_start to null to indicate the board is cleared
    m_start = nullptr;
  }

  // reinitilize all member variables to base values
  m_start = nullptr;
  m_player1 = nullptr;
  m_player2 = nullptr;
  m_playerTurn = 0;
  m_playerTurn = NOGAME;
  m_dice.init(0, 0);
}

// Name: Overloaded Assignment Operator
// Desc: Used to create a deep copy of original board
// Preconditions: Board must exist
// Postconditions: Create a deep copy of board if board exists,
// otherwise sets m_start to nullptr and returns with copied object
const Snakes &Snakes::operator=(const Snakes &rhs) {

  if (this == &rhs) {
    // Protect self against assignment
    return *this;
  }

  // Delete the current board
  Cell *curr = m_start;
  Cell *temp = nullptr;

  while (curr != nullptr) {
    temp = curr;
    curr = curr->m_next;
    delete temp;
  }

  // reinitilize values of member variables
  m_start = nullptr;
  m_player1 = nullptr;
  m_player2 = nullptr;
  m_playerTurn = 0;
  m_dice.init(0, 0);

  // Copy board
  if (rhs.m_start != nullptr) {
    m_start = new Cell;
    m_start->setID(rhs.m_start->getID());
    m_playerTurn = rhs.m_playerTurn;
    m_dice.init(1, 6);
    m_dice.setSeed(time(0));

    Cell *original = rhs.m_start;
    Cell *currCopy = m_start;

    while (original->m_next != nullptr) {
      Cell *copy = new Cell;
      copy->setID(original->m_next->getID());
      currCopy->m_next = copy;
      currCopy = copy;
      original = original->m_next;
    }

    // Copy obstacles and players
    original = rhs.m_start;
    currCopy = m_start;

    while (original != nullptr) {

      // if ladder found iterate to location of ladder (start and end)
      if (original->getNorth() != nullptr) {
        Cell *tempOrig = rhs.m_start; // iterator for original board
        Cell *tempCopy = m_start;     // iterator for copy board

        while (tempOrig != original->getNorth() && tempOrig != nullptr) {
          // iterate pointers to location of ladder
          tempOrig = tempOrig->m_next;
          tempCopy = tempCopy->m_next;
        }

        // set copy of original ladder on copy board once location found
        if (tempOrig != nullptr && tempCopy != nullptr) {
          currCopy->setNorth(tempCopy);
        }
      }

      // if snake found iterate to location of snake (start and end)
      if (original->getSouth() != nullptr) {
        Cell *tempOrig = rhs.m_start;
        Cell *tempCopy = m_start;

        while (tempOrig != original->getSouth() && tempOrig != nullptr) {

          // iterate pointers to location of ladder
          tempOrig = tempOrig->m_next;
          tempCopy = tempCopy->m_next;
        }

        if (tempOrig != nullptr && tempCopy != nullptr) {

          // set location of snake (this was changed to see if test would still
          // pass)
          tempCopy->setSouth(currCopy);
        }
      }

      if (original == rhs.m_player1) {
        m_player1 = currCopy; // copy location of player 1
      }

      if (original == rhs.m_player2) {
        m_player2 = currCopy; // copy location of player 2
      }

      original = original->m_next; // iterate pointers
      currCopy = currCopy->m_next; // iterate pointers
    }
  } else {
    m_start = nullptr;
  }

  return *this;
}

// Name: rollDice();
// Desc: Used to get a random number
// Preconditions: Board must exist
// Postconditions: Will return a random number from initilized value from 1-6
int Snakes::rollDice() {

  return m_dice.getRandNum(); // return random umber
}

// Name: play();
// Desc: Performs requested move and returns true or false based on validity of
// movement Preconditions: Board must exist and dice roll must be valid
// Postconditions: Will return true or false if player movement is valid
// and will move corresponding pointer player to the spot
bool Snakes::play(int dice) {

  int roll = dice;

  // Check if board exists and game is in progress
  if (m_start == nullptr || m_playerTurn == NOGAME) {
    return false;
  }

  Cell *player = nullptr; // iterator pointer to move players on board

  // assign player based on whos turn it is
  if (m_playerTurn == PLAYER1TURN) {
    player = m_player1;
  } else if (m_playerTurn == PLAYER2TURN) {
    player = m_player2;
  }

  // detirmine if player pointer is valid
  if ((player != nullptr)) {

    // Move player based on dice roll number
    for (int i = 0; i < dice; i++) {
      player = player->m_next;
    }

    // Check if player is at ladder or snake
    if (player->getNorth() != nullptr) {
      player = player->getNorth();
    } else if (player->getSouth() != nullptr) {
      player = player->getSouth();
    }

    // Update player's position
    if (m_playerTurn == PLAYER1TURN) {
      m_player1 = player;
    } else if (m_playerTurn == PLAYER2TURN) {
      m_player2 = player;
    }

    // Check if player is on the last cell to determine if game is done
    if (player->getID() == findSize(m_start)) {
      return false;
    }

    if ((findSize(m_start) - player->getID()) <= m_dice.getMax()) {

      do {
        roll = m_dice.getRandNum();
      } while ((player->getID() + roll) != findSize(m_start));

      for (int i = 0; i < roll; i++) {
        player = player->m_next;
      }

      // Update player's position
      if (m_playerTurn == PLAYER1TURN) {
        m_player1 = player;
      } else if (m_playerTurn == PLAYER2TURN) {
        m_player2 = player;
      }

      // Check if player is on the last cell to determine if game is done
      if (player->getID() == findSize(m_start)) {
        return false;
      }
    }

    // End of current player's turn
    if (m_playerTurn == PLAYER1TURN) {
      m_playerTurn = PLAYER2TURN;
    } else {
      m_playerTurn = PLAYER1TURN;
    }

    return true;
  }

  return false;
}

// Name: reStart();
// Desc: Reinitlizes board contents to original preconditions of game
// Preconditions: Board must exist and dice roll must be valid
// Postconditions: Member variables reinitialized
void Snakes::reStart() {

  // check if board exists
  if (m_start != nullptr) {
    m_player1 = m_start;
    m_player2 = m_start;
    m_playerTurn = 1;
    m_dice.init(1, 6);
    m_dice.setSeed(time(0));
  }
}

// Name: snakeTravel();
// Desc: Returns true or false if the indicate placement after roll has a snake
// Preconditions: Board must exist and dice roll must be valid
// Postconditions: Return true for snake present false for snake not present
bool Snakes::snakeTravel(int roll, Cell *position) {

  Cell *temp = position; // set the postition of where the player is

  int count = 0;

  while ((temp->m_next != nullptr) && (count < roll)) {
    temp = temp->m_next;
    count++;
  }

  // if the cell has snake and player is able to move on snake return true else
  // false
  if (temp->getSouth() != nullptr) {
    return true;
  } else {
    return false;
  }
}

void Snakes::dumpBoard() {

  if (m_start != nullptr) {

    int ladderCode, snakeCode;
    Cell *temp = m_start;
    cout << "START => ";
    while (temp != nullptr) {

      cout << temp->m_cellID;
      cout << "temp ID" << temp->m_cellID << endl;
      if (temp == m_player1)
        cout << " (Player 1)";
      if (temp == m_player2)
        cout << " (Player 2)";
      if (temp->m_north != nullptr)
        ladderCode = temp->m_north->m_cellID;
      else
        ladderCode = -1;
      if (temp->m_south != nullptr)
        snakeCode = temp->m_south->m_cellID;
      else
        snakeCode = -1;
      if (ladderCode != -1 || snakeCode != -1) {
        cout << " (";
        if (ladderCode != -1)
          cout << "\033[1;32mLadder to: " << ladderCode
               << "\033[0m"; // green text
        if (snakeCode != -1)
          cout << "\033[1;31mSnake to: " << snakeCode << "\033[0m"; // red text
        cout << ")";
      }
      cout << " => ";
      temp = temp->m_next;
    }
    cout << "END" << endl;
  }
}