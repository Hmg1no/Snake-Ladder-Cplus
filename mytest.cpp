/***********************************************************
 ** // UMBC - CMSC 341 - Fall 2024 - Proj1
 ** File:    Snakes.h
 ** Project: Fall 2024 - Proj1
 ** Author:  Hazael Magino
 ** Date:     9/15/2024
 ** This file contains the tester file of the snake class
 **********************************************************/
#include "snakes.h"
using namespace std;
class Tester {
public:

  //Useful tests made for this implementation
  bool testSnakesAlNormal();                              
  bool testSnakesAlError();                              
  bool testSnakesAlEdge();                                
  bool testSnakesRestartNormal();                         
  bool testSnakesRestartError();                          
  bool testSnakesClearNormal();                         
  bool testSnakesClearError();                            
  bool testSnakesMakeDefaultNormal(int size);             
  bool testSnakesMakeDefaultEdge(int size);             
  bool testSnakesMakeDefaultError(int size);             
  bool testSnakesMakeRandomNormal(int size, int numObst); 
  bool testSnakesMakeRandomEdge(int size, int numObst); 
  bool testSnakesMakeRandomError(int size, int numObst); 
  bool testSnakesOverloadAsNormal(const Snakes &orig);
  bool testSnakesOverloadAsEdge(const Snakes &orig);
  bool testSnakesPlayNormal();
  bool testSnakesPlayRandomNormal();
  bool testSnakesPlayEdge();
  bool testSnakesPlayRandomEdge();
  bool testSnakesPlayError();
  bool testSnakesPlayRandomError();
  bool testMoveOnSnake();
  bool testMoveOnLadder();
};

// Function: Snakes(int);
// Case(Normal): Function will attempt to create a valid perfect square size
// board
// Expected result: All member variables should be populated with valid values
//  and board should be present
bool Tester::testSnakesAlNormal() {

  Snakes aSnake(1000);

  if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
      (aSnake.m_player1 == aSnake.m_start) &&
      (aSnake.m_player2 == aSnake.m_start) &&
      (aSnake.findSize(aSnake.m_start) == 961)) {
    return true;
  } else {
    return false;
  }
}

// Function: Snakes(int);
// Case(Edge): Function will attempt to create a valid board using non perfect
// square
// Expected result: All member variables should be populated with valid values
//  and board should be present
bool Tester::testSnakesAlEdge() {

  Snakes aSnake(150);

  if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
      (aSnake.m_player1 == aSnake.m_start) &&
      (aSnake.m_player2 == aSnake.m_start) &&
      (aSnake.findSize(aSnake.m_start) == 144)) {
    return true;
  } else {
    return false;
  }
}

// Function: Snakes(int);
// Case(Error): Function will attempt to create an invalid perfect square size
// board aka less than 9
// Expected result: All member variables should be populated with default values
//  and board should not be present
bool Tester::testSnakesAlError() {

  Snakes aSnake(5);

  if ((aSnake.m_start == nullptr) && (aSnake.m_playerTurn == 0) &&
      (aSnake.m_player1 == nullptr) && (aSnake.m_player2 == nullptr) &&
      (aSnake.findSize(aSnake.m_start) == 0)) {
    return true;
  } else {
    return false;
  }
}

// Function: reStart(int);
// Case(Normal): Function will attempt to clear a playable board
// Expected result: All member variables should be populated with default values
//  and board should be present as a new game
bool Tester::testSnakesRestartNormal() {

  Snakes aSnake(100);

  Cell *start = aSnake.m_start;
  Cell *player1 = aSnake.m_player1;
  Cell *player2 = aSnake.m_player2;
  int turn = aSnake.m_playerTurn;
  int size = aSnake.findSize(aSnake.m_start);

  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.reStart();

  if ((aSnake.m_start == start) && (aSnake.m_playerTurn == turn) &&
      (aSnake.m_player1 == player1) && (aSnake.m_player2 == player2) &&
      (aSnake.findSize(aSnake.m_start) == size)) {
    return true;
  } else {
    return false;
  }
}

// Function: reStart(int);
// Case(Error): Function will attempt to clear a non playable board
// Expected result: All member variables should remain defaulted with default
// values
// and board should not be present as a new game
bool Tester::testSnakesRestartError() {

  Snakes aSnake(0);

  Cell *start = aSnake.m_start;
  Cell *player1 = aSnake.m_player1;
  Cell *player2 = aSnake.m_player2;
  int turn = aSnake.m_playerTurn;
  int size = aSnake.findSize(aSnake.m_start);

  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.reStart();

  if ((aSnake.m_start == start) && (aSnake.m_playerTurn == turn) &&
      (aSnake.m_player1 == player1) && (aSnake.m_player2 == player2) &&
      (aSnake.findSize(aSnake.m_start) == size)) {
    return true;
  } else {
    return false;
  }
}

// Function: clear();
// Case(Normal): Function will attempt to clear game board
// Expected result: All member variables should go back default values as if
// there was no game
bool Tester::testSnakesClearNormal() {

  Snakes aSnake(81);

  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());
  aSnake.play(aSnake.rollDice());

  aSnake.clear();

  if ((aSnake.m_start == nullptr) && (aSnake.m_playerTurn == 0) &&
      (aSnake.m_player1 == nullptr) && (aSnake.m_player2 == nullptr) &&
      (aSnake.findSize(aSnake.m_start) == 0)) {
    return true;
  } else {
    return false;
  }
}

// Function: clear();
// Case(Error): Function will attempt to clear an empty game baord
// Expected result: All member variables should remain as default values because
// there was no game
bool Tester::testSnakesClearError() {

  Snakes aSnake(0);

  Cell *start = aSnake.m_start;
  int turn = aSnake.m_playerTurn;
  Cell *player1 = aSnake.m_player1;
  Cell *player2 = aSnake.m_player2;
  int size = aSnake.findSize(aSnake.m_start);

  aSnake.play(aSnake.rollDice());

  aSnake.clear();

  if ((aSnake.m_start == start) && (aSnake.m_playerTurn == turn) &&
      (aSnake.m_player1 == player1) && (aSnake.m_player2 == player2) &&
      (aSnake.findSize(aSnake.m_start) == size)) {
    return true;
  } else {
    return false;
  }
}

// Function: makeDeafultBoard();
// Case(Normal): Function will attempt to create a perfect square board
// with valid snakes and ladders amounts.
// Expected result: All game variables should be present, valid snakes and
// ladder amount should
// on board
bool Tester::testSnakesMakeDefaultNormal(int size) {

  Snakes aSnake(size);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  int obst = floor((size / 4) - 1);

  int numOfLadders = obst / 2;
  int numOfSnakes = obst - numOfLadders;

  for (int i = 0; i < aSnake.findSize(aSnake.m_start); i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    } else if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
      (aSnake.m_player1 == aSnake.m_start) &&
      (aSnake.m_player2 == aSnake.m_start) &&
      (aSnake.findSize(aSnake.m_start) == size) && (snakes == numOfSnakes) &&
      (ladders == numOfLadders)) {
    return true;
  } else {
    return false;
  }
}

// Function: makeDeafultBoard();
// Case(Edge): Function will attempt to create a non perfect square board
// with valid snakes and ladders amounts
// Expected result: All game variables should be present, valid snakes and
// ladder amount should
// on board
bool Tester::testSnakesMakeDefaultEdge(int size) {

  Snakes aSnake(size);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  // must keep consistency in detirmining algorithm of snakes/ladders
  //  to judge accuracy and correctness

  int brdSize = sqrt(size);

  int boardSize = brdSize * brdSize;

  int obst = floor((boardSize / 4) - 1);

  int numOfLadders = floor(obst / 2);
  int numOfSnakes = obst - numOfLadders;

  for (int i = 0; i < aSnake.findSize(aSnake.m_start); i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    } else if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
      (aSnake.m_player1 == aSnake.m_start) &&
      (aSnake.m_player2 == aSnake.m_start) &&
      (aSnake.findSize(aSnake.m_start) == boardSize) &&
      (snakes == numOfSnakes) && (ladders == numOfLadders)) {
    return true;
  } else {
    return false;
  }
}

// Function: makeDeafultBoard();
// Case(Error): Function will attempt to create a non valid board
// Expected result: All game variables should be default values
bool Tester::testSnakesMakeDefaultError(int size) {

  Snakes aSnake(7);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  for (int i = 0; i < aSnake.findSize(aSnake.m_start); i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    } else if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  if ((aSnake.m_start == nullptr) && (aSnake.m_playerTurn == 0) &&
      (aSnake.m_player1 == nullptr) && (aSnake.m_player2 == nullptr) &&
      (aSnake.findSize(aSnake.m_start) == 0) && (snakes == 0) &&
      (ladders == 0)) {
    return true;
  } else {
    return false;
  }
}

// Function: makeDeafultRandomBoard();
// Case(Normal): Function will attempt to create a  valid board
// Expected result: All game variables should be populated and accurate
// and game board should be present with snakes/ladders
bool Tester::testSnakesMakeRandomNormal(int size, int numObst) {

  Snakes aSnake;
  aSnake.makeRandomBoard(size, numObst);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  int brdSize = sqrt(size);

  int boardSize = brdSize * brdSize;

  for (int i = 0; i < aSnake.findSize(aSnake.m_start); i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    }

    if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
      (aSnake.m_player1 == aSnake.m_start) &&
      (aSnake.m_player2 == aSnake.m_start) &&
      (aSnake.findSize(aSnake.m_start) == boardSize) &&
      ((snakes + ladders) == numObst)) {
    return true;
  } else {
    return false;
  }
}

// Function: makeDeafultRandomBoard();
// Case(Edge): Function will attempt to create a non perfect square valid board
// Size
// with a greater than max obstacles input size of numSnakesLadders
// Expected result: All game variables should be populated and accurate
// and game board should be present with snakes/ladders
bool Tester::testSnakesMakeRandomEdge(int size, int numObst) {

  Snakes aSnake;

  aSnake.makeRandomBoard(size, numObst);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  int brdSize = sqrt(size);

  int boardSize = brdSize * brdSize;

  for (int i = 0; i < boardSize; i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    } else if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  int maxObs = (boardSize / 2) - 2; // get the max number of obstacles incase

  if ((numObst < 2) || (numObst > maxObs)) {

    if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
        (aSnake.m_player1 == aSnake.m_start) &&
        (aSnake.m_player2 == aSnake.m_start) &&
        (aSnake.findSize(aSnake.m_start) == boardSize) &&
        ((snakes + ladders) == 2)) {
      return true;
    } else {
      return false;
    }

  } else {

    if ((aSnake.m_start != nullptr) && (aSnake.m_playerTurn == 1) &&
        (aSnake.m_player1 == aSnake.m_start) &&
        (aSnake.m_player2 == aSnake.m_start) &&
        (aSnake.findSize(aSnake.m_start) == boardSize) &&
        ((snakes + ladders) == numObst)) {
      return true;
    } else {
      return false;
    }
  }
}

// Function: makeDeafultRandomBoard();
// Case(Error): Function will attempt to create a non valid board Size
// with a non valid max obstacles input size of numSnakesLadders
// Expected result: All game variables should be populated and accurate
// and game board should be present with snakes/ladders
bool Tester::testSnakesMakeRandomError(int size, int numObst) {

  Snakes aSnake;

  aSnake.makeRandomBoard(size, numObst);

  Cell *temp = aSnake.m_start;

  int snakes = 0;
  int ladders = 0;

  for (int i = 0; i < aSnake.findSize(aSnake.m_start); i++) {

    if (temp->getNorth() != nullptr) {
      ladders++;
    } else if (temp->getSouth() != nullptr) {
      snakes++;
    }
    temp = temp->m_next;
  }

  if ((aSnake.m_start == nullptr) && (aSnake.m_playerTurn == 0) &&
      (aSnake.m_player1 == nullptr) && (aSnake.m_player2 == nullptr) &&
      (aSnake.findSize(aSnake.m_start) == 0) && ((snakes + ladders) == 0)) {
    return true;
  } else {
    return false;
  }
}

// Function: operator=();
// Case(Normal): Function will attempt to create a deep copy of
// a valid board size and replicate board obstacles and postions
// Expected result: All game variables should be populated and accurate
// and game board should be present with snakes/ladders in same positions
bool Tester::testSnakesOverloadAsNormal(const Snakes &orig) {

  Snakes newGame;
  newGame = orig;

  bool correctCopy = true; // Assume that original and newCopy are the same

  Cell *tempCopy = newGame.m_start;
  Cell *tempOrig = orig.m_start;
  int size = 0;

  // Determine size of board being copied
  while (tempOrig != nullptr) {
    tempOrig = tempOrig->m_next;
    size++;
  }

  // Reset tempOrig to the start of the original list
  tempOrig = orig.m_start;

  if ((size == newGame.findSize(tempCopy)) &&
      (newGame.m_playerTurn == orig.m_playerTurn) &&
      (newGame.m_player1 == orig.m_player1) &&
      (newGame.m_player2 == orig.m_player2)) {
    for (int i = 0; i < size; i++) {

      // Check if ladders are going to the same place on copied board
      if ((tempOrig != nullptr) && (tempOrig->getNorth() != nullptr) &&
          (tempCopy != nullptr) && (tempCopy->getNorth() != nullptr)) {
        if (tempOrig->getNorth()->getID() != tempCopy->getNorth()->getID()) {
          correctCopy = false;
        }
      }

      // Check if snakes are going to the same place on copied board
      if (tempOrig != nullptr && tempCopy != nullptr) {
        if (tempOrig->getID() != tempCopy->getID()) {
          correctCopy = false;
        }
      }

      tempCopy = tempCopy->m_next;
      tempOrig = tempOrig->m_next;
    }
  }

  return correctCopy;
}

// Function: operator=();
// Case(Edge): Function will not attempt to create a deep copy
// of an empty object.
// Expected result: All game variables should be the same as original.
// all values should be defaulted to 0 or nullptr
bool Tester::testSnakesOverloadAsEdge(const Snakes &orig) {

  Snakes newGame;
  newGame = orig;

  bool correctCopy = true; // Assume that original and newCopy are the same

  Cell *tempCopy = newGame.m_start;
  Cell *tempOrig = orig.m_start;
  int size = 0;

  // Determine size of board being copied
  while (tempOrig != nullptr) {
    tempOrig = tempOrig->m_next;
    size++;
  }

  // Reset tempOrig to the start of the original list
  tempOrig = orig.m_start;

  if ((size == newGame.findSize(tempCopy)) &&
      newGame.m_playerTurn == orig.m_playerTurn) {
    for (int i = 0; i < size; i++) {

      // Check if ladders are going to the same place on copied board
      if ((tempOrig != nullptr) && (tempOrig->getNorth() != nullptr) &&
          (tempCopy != nullptr) && (tempCopy->getNorth() != nullptr)) {
        if (tempOrig->getNorth()->getID() != tempCopy->getNorth()->getID()) {
          correctCopy = false;
        }
      }

      // Check if snakes are going to the same place on copied board
      if (tempOrig != nullptr && tempCopy != nullptr) {
        if (tempOrig->getID() != tempCopy->getID()) {
          correctCopy = false;
        }
      }

      tempCopy = tempCopy->m_next;
      tempOrig = tempOrig->m_next;
    }
  }
  tempCopy = newGame.m_start;
  if ((size != newGame.findSize(tempCopy)) && (tempCopy != nullptr) &&
      (newGame.m_player1 != nullptr) && (newGame.m_player2 != nullptr) &&
      (newGame.m_start != nullptr) && (newGame.m_playerTurn != 0)) {
    correctCopy = false;
  }

  return correctCopy;
}

// Function: play();
// Case(Normal): Function will attempt to make plays on a defaultboard
// Expected result: player move on board and utilizes game elements
bool Tester::testSnakesPlayNormal() {

  Snakes aGame;
  aGame.makeDefaultBoard(25); // create size board
  bool state = true;          // value to hold the return of the play
  bool gameplay = true;  // value to detirmine the validity of final state play
  bool invalidP = false; // value to hold if any invalid plays were made
  int plays = 10;        // play value
  Cell *locatePlayer =
      nullptr; // value to hold location detirmine if snake was in use

  while ((plays != 0) && (state != false) && (gameplay == true)) {

    bool snakeTravel = false; // assume no snake is in use
    int turn = aGame.m_playerTurn;
    int positionBefore = 0;
    int positionAfter = 0;

    if (turn == PLAYER1TURN) {
      locatePlayer = aGame.m_player1;
      positionBefore = aGame.m_player1->getID(); // store position
    } else {
      locatePlayer = aGame.m_player2;
      positionBefore = aGame.m_player2->getID(); // store position
    }

    int roll = aGame.m_dice.getRandNum(); // hold roll for use in snakeTravel
    state = aGame.play(roll);

    // Update positionAfter after the play function call
    if (turn == PLAYER1TURN) {
      positionAfter = aGame.m_player1->getID();
    } else {
      positionAfter = aGame.m_player2->getID();
    }

    int turnAfter = aGame.m_playerTurn; // use for check on validity of play
    snakeTravel = aGame.snakeTravel(
        roll, locatePlayer); // detirmine if snake travel was in play

    // Validate the move
    if ((turn != turnAfter) && (snakeTravel == false)) {

      if (aGame.findSize(aGame.m_start) > (positionBefore + roll)) {

        if (positionAfter == positionBefore) {
          invalidP = true;
        }
      }
    }

    // subtract play count
    plays--;

    // detirmine if game has finished
    if (state == false) {
      gameplay = false;
    }
  }

  // if any invalid move was present then return false;
  if (invalidP == true) {
    return false;
  } else {
    return true;
  }
}

// Function: play();
// Case(Normal): Function will attempt to make plays on a random board
// Expected result: player move on board and utilizes game elements
bool Tester::testSnakesPlayRandomNormal() {

  Snakes aGame;
  aGame.makeRandomBoard(64, 13);
  bool state = true;     // value to hold the return of the play
  bool gameplay = true;  // value to detirmine the validity of final state play
  bool invalidP = false; // value to hold if any invalid plays were made
  int plays = 20;        // play value
  Cell *locatePlayer =
      nullptr; // value to hold location detirmine if snake was in use

  while ((plays != 0) && (state != false) && (gameplay == true)) {
    bool snakeTravel = false;
    int turn = aGame.m_playerTurn;
    int positionBefore = 0;
    int positionAfter = 0;

    if (turn == PLAYER1TURN) {
      locatePlayer = aGame.m_player1;
      positionBefore = aGame.m_player1->getID(); // store postion
    } else {
      locatePlayer = aGame.m_player2;
      positionBefore = aGame.m_player2->getID(); // store position
    }

    int roll = aGame.m_dice.getRandNum();
    state = aGame.play(roll);

    // Update positionAfter after the play function call
    if (turn == PLAYER1TURN) {
      positionAfter = aGame.m_player1->getID();
    } else {
      positionAfter = aGame.m_player2->getID();
    }

    int turnAfter = aGame.m_playerTurn; // store turn

    snakeTravel = aGame.snakeTravel(
        roll, locatePlayer); // check if snake travel was possible

    // Validate the move
    if ((turn != turnAfter) && (snakeTravel == false)) {

      if (aGame.findSize(aGame.m_start) > (positionBefore + roll)) {

        if (positionAfter == positionBefore) {
          invalidP = true;
        }
      }
    }

    // subtract play count
    plays--;

    // detirmine state of game
    if (state == false) {
      gameplay = false;
    }
  }

  // if invalid plays were made, play did not execute correctly
  if (invalidP == true) {
    return false;
  } else {
    return true;
  }
}

// Function: play();
// Case(Edge): Function will attempt to make plays on a default board
// until the end of the game is reached
// Expected result: player move on board and utilizes game elements and reaches
// end
bool Tester::testSnakesPlayEdge() {

  Snakes aGame;
  aGame.makeDefaultBoard(55);
  bool state = true;     // value to hold the return of the play
  bool gameplay = true;  // value to detirmine the validity of final state play
  bool invalidP = false; // value to hold if any invalid plays were made
  Cell *locatePlayer =
      nullptr; // value to hold location detirmine if snake was in use

  while ((state != false) && (gameplay == true)) {
    bool snakeTravel = false; // assume false for until true
    int turn = aGame.m_playerTurn;
    int positionBefore = 0;
    int positionAfter = 0;

    if (turn == PLAYER1TURN) {
      locatePlayer = aGame.m_player1;
      positionBefore = aGame.m_player1->getID();
    } else {
      locatePlayer = aGame.m_player2;
      positionBefore = aGame.m_player2->getID();
    }

    int roll = aGame.m_dice.getRandNum();
    state = aGame.play(roll);

    // Update positionAfter after the play function call
    if (turn == PLAYER1TURN) {
      positionAfter = aGame.m_player1->getID();
    } else {
      positionAfter = aGame.m_player2->getID();
    }

    int turnAfter = aGame.m_playerTurn;

    snakeTravel = aGame.snakeTravel(roll, locatePlayer);

    // Validate the move
    if ((turn != turnAfter) && (snakeTravel == false)) {

      if (aGame.findSize(aGame.m_start) > (positionBefore + roll)) {

        if (positionAfter == positionBefore) {
          invalidP = true;
        }
      }
    }

    // check if at the end of the game
    if (aGame.findSize(aGame.m_start) == aGame.m_player1->getID() ||
        aGame.findSize(aGame.m_start) == aGame.m_player2->getID()) {
      gameplay = false;
    }
  }

  // detirmine if all conditions for final game met
  if (((aGame.m_player1->getID() == aGame.findSize(aGame.m_start)) ||
       (aGame.m_player2->getID() == aGame.findSize(aGame.m_start))) &&
      (invalidP == false) && (state == false) && (gameplay == false)) {
    return true;
  } else {
    return false;
  }
}
// Function: play();
// Case(Edge): Function will attempt to make plays on a random board
// until the end of the game is reached
// Expected result: player move on board and utilizes game elements and reaches
// end
bool Tester::testSnakesPlayRandomEdge() {

  Snakes aGame;
  aGame.makeRandomBoard(73, 100);
  bool state = true;     // value to hold the return of the play
  bool gameplay = true;  // value to detirmine the validity of final state play
  bool invalidP = false; // value to hold if any invalid plays were made
  Cell *locatePlayer =
      nullptr; // value to hold location detirmine if snake was in use

  while ((state != false) && (gameplay == true)) {
    bool snakeTravel = false;
    int turn = aGame.m_playerTurn;
    int positionBefore = 0;
    int positionAfter = 0;

    if (turn == PLAYER1TURN) {
      locatePlayer = aGame.m_player1;
      positionBefore = aGame.m_player1->getID();
    } else {
      locatePlayer = aGame.m_player2;
      positionBefore = aGame.m_player2->getID();
    }

    int roll = aGame.m_dice.getRandNum();
    state = aGame.play(roll); // store return of play

    // Update positionAfter after the play function call
    if (turn == PLAYER1TURN) {
      positionAfter = aGame.m_player1->getID();
    } else {
      positionAfter = aGame.m_player2->getID();
    }

    int turnAfter = aGame.m_playerTurn;

    snakeTravel = aGame.snakeTravel(roll, locatePlayer);

    // Validate the move
    if ((turn != turnAfter) && (snakeTravel == false)) {

      if (aGame.findSize(aGame.m_start) > (positionBefore + roll)) {

        if (positionAfter == positionBefore) {
          invalidP = true;
        }
      }
    }
  }

  // check if at the end of the game
  if (aGame.findSize(aGame.m_start) == aGame.m_player1->getID() ||
      aGame.findSize(aGame.m_start) == aGame.m_player2->getID()) {
    gameplay = false;
  }

  // detirmine if all conditions met for final gameplay
  if (((aGame.m_player1->getID() == aGame.findSize(aGame.m_start)) ||
       (aGame.m_player2->getID() == aGame.findSize(aGame.m_start))) &&
      (invalidP == false) && (state == false) && (gameplay == false)) {

    return true;
  } else {
    return false;
  }
}

// Function: play();
// Case(Error): Function will attempt to make an invalid makeDefaultboard game
// on
// Expected result: Board is never created and game is not played
// all member variables should be null or 0
bool Tester::testSnakesPlayError() {

  Snakes aGame;
  aGame.makeDefaultBoard(-9);

  // hold min values for expected invalid play
  int min = aGame.m_dice.getMin();
  int max = aGame.m_dice.getMax();

  // hold state of game play
  bool state = aGame.play(aGame.m_dice.getRandNum());

  // Detirmine validity of a non playable state
  if ((aGame.m_start == nullptr) && (aGame.m_playerTurn == NOGAME) &&
      (aGame.m_player1 == nullptr) && (aGame.m_player2 == nullptr) &&
      (aGame.findSize(aGame.m_start) == 0) && (min == max) &&
      (state == false)) {
    return true;
  } else {
    return false;
  }
}

// Function: play();
// Case(Error): Function will attempt to make an invalid makeRandomboard game on
// Expected result: Board is never created and game is not played
// all member variables should be null or 0
bool Tester::testSnakesPlayRandomError() {

  Snakes aGame;
  aGame.makeRandomBoard(-1, 1);

  int min = aGame.m_dice.getMin();
  int max = aGame.m_dice.getMax();

  // hold state of game play
  bool state = aGame.play(aGame.m_dice.getRandNum());

  // Detirmine validity of a non playable state
  if ((aGame.m_start == nullptr) && (aGame.m_playerTurn == NOGAME) &&
      (aGame.m_player1 == nullptr) && (aGame.m_player2 == nullptr) &&
      (aGame.findSize(aGame.m_start) == 0) && (min == max) &&
      (state == false)) {
    return true;
  } else {
    return false;
  }
}

// Function: play();
// Case(Normal): Function will attempt to check if player can move on a snake
// Expected output: Players postion should be less than before move
bool Tester::testMoveOnSnake() {

  Snakes originGame3(25);
  originGame3.play(5); // player 1 move on cell 6
  originGame3.play(4);
  originGame3.play(3); // player 1 move on cell 10
  originGame3.play(2);
  bool state1 = false; // first condition for snake move
  bool state2 = false; // second condition for snake move

  int positionBefore = originGame3.m_player1->getID();
  if (originGame3.snakeTravel(2, originGame3.m_player1) == true) {
    state1 = true;
  }

  originGame3.play(2); // player 1 move on cell 11 where snake is located

  int positionAfter = originGame3.m_player1->getID();

  if (positionBefore > positionAfter) {
    state2 = true;
  }

  if ((originGame3.m_player1->getID() == 3) && (state1 == true) &&
      (state2 == true)) {
    return true;
  } else {
    return false;
  }
}

// Function: play();
// Case(Normal): Function will attempt to check if player can move on a ladder
// Expected output: Players postion should be greater than position before
bool Tester::testMoveOnLadder() {

  Snakes originGame3(25);
  originGame3.play(1);
  originGame3.play(6); // player 2 move on cell 6
  originGame3.play(2);
  bool state1 = false;
  bool state2 = false;

  int positionBefore = originGame3.m_player2->getID();
  if (originGame3.snakeTravel(1, originGame3.m_player2) == true) {
    state1 = true;
  }

  originGame3.play(1);
  ; // player 2 move on cell 7  where ladder is located

  int positionAfter = originGame3.m_player2->getID();

  if (positionBefore < positionAfter) {
    state2 = true;
  }

  if ((originGame3.m_player2->getID() == 12) && (state1 == true) &&
      (state2 == true)) {
    return true;
  } else {
    return false;
  }
}

int main() {
  Snakes agame;
  Tester aTester;

  cout << "\tTesting Alternative Snakes Constructor Normal" << endl;
  if (aTester.testSnakesAlNormal() == true) {
    cout << "Testing Alternative Snakes Constructor test normal case passed!: "
            "Board elements fully created"
         << endl;
  } else {
    cout << "Testing Alternative Snakes Constructor test normal case failed!: ";
    cout << " Board elements missing " << endl;
  }

  cout << "\tTesting Alternative Snakes Constructor Edge" << endl;
  if (aTester.testSnakesAlEdge() == true) {
    cout << "Testing Alternative Snakes Constructor test edge case passed!: "
         << endl;
    cout << " Board elements fully created" << endl;
  } else {
    cout << "Testing Alternative Snakes Constructor test edge case failed!:";
    cout << "Board elements missing " << endl;
  }

  cout << "\tTesting Alternative Snakes Constructor Error" << endl;
  if (aTester.testSnakesAlError() == true) {
    cout << "Testing Alternative Snakes Constructor test Error case passed! "
         << endl;
    cout << "Board elements not created" << endl;
  } else {
    cout << "Testing Alternative Snakes Constructor test Error case failed!:";
    cout << "Board elements were created" << endl;
  }

  cout << "\tTesting Snakes Restart Function Normal case" << endl;
  if (aTester.testSnakesRestartNormal() == true) {
    cout << "Testing Snakes Restart Function test Normal case passed!: "
         << endl;
    cout << " Board elements have been moved to start" << endl;
  } else {
    cout << "Testing  Snakes Restart Function test Normal case failed!:";
    cout << "Board have not been changed" << endl;
  }

  cout << "\tTesting Snakes Restart Function Error case" << endl;
  if (aTester.testSnakesRestartError() == true) {
    cout << "Testing Snakes Restart Function test Error case passed!:" << endl;
    cout << "Board elements were already defaulted, nothing to clear" << endl;
  } else {
    cout << "Testing Snakes Restart Function test Error case failed!" << endl;
  }

  cout << "\tTesting Snakes Restart Function Error case" << endl;
  if (aTester.testSnakesRestartError() == true) {
    cout << "Testing Snakes Restart Function test Error case passed!: ";
    cout << "Board elements were already defaulted, nothing to clear" << endl;
  } else {
    cout << "Testing Snakes Restart Function test Error case failed!" << endl;
  }

  cout << "\tTesting Snakes Clear Function Normal case" << endl;
  if (aTester.testSnakesClearNormal() == true) {
    cout << "Testing Snakes Restart Function test Error case passed!: " << endl;
    cout << "Board elements have been cleared, default values used" << endl;
  } else {
    cout << "Testing Snakes Restart Function test Error case failed!" << endl;
    cout << "Board elements have not cleared." << endl;
  }

  cout << "\tTesting Snakes Clear Function Error case" << endl;
  if (aTester.testSnakesClearError() == true) {
    cout << "Testing Snakes Clear Function test Error case passed!: ";
    cout << "There is nothing to clear, board previously empty " << endl;
  } else {
    cout << "Testing Snakes Clear Function test Error case failed!" << endl;
  }

  cout << "\tTesting Snakes makeDefaultBoard Function Normal case: Size(100)"
       << endl;
  if (aTester.testSnakesMakeDefaultNormal(100) == true) {
    cout << "Testing Snakes makeDefaultBoardFunction test Normal case passed!: "
         << endl;
    cout << "Board created, all ladders and snakes on board" << endl;
  } else {
    cout << "Testing Snakes MakeDefaultNormal Function test Normal case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeDefaultBoard Function Edge case: Size(9)"
       << endl;
  if (aTester.testSnakesMakeDefaultEdge(9) == true) {
    cout << "Testing Snakes makeDefaultBoardFunction test Edge case passed!: "
         << endl;
    cout << "Board created a size of 9, all ladders and snakes on board"
         << endl;
  } else {
    cout << "Testing Snakes MakeDefaultEdge Function test Edge case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeDefaultBoard Function Error case: Size(72)"
       << endl;
  if (aTester.testSnakesMakeDefaultError(72) == true) {
    cout << "Testing Snakes makeDefaultBoardFunction test Error case passed!: "
         << endl;
    cout << "Board created a size of 64, all ladders and snakes on board"
         << endl;
  } else {
    cout << "Testing Snakes MakeDefaultEdge Function test Error case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeDefaultBoard Function Error case: Size(-1)"
       << endl;
  if (aTester.testSnakesMakeDefaultError(-1) == true) {
    cout << "Testing Snakes makeDefaultBoardFunction test Error case passed!: "
         << endl;
    cout << "Board not created" << endl;
  } else {
    cout << "Testing Snakes MakeDefaultError Function test Error case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Normal case: " << endl;
  cout << "(Size: 62, Obst: 10)" << endl;
  if (aTester.testSnakesMakeRandomNormal(64, 10) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Normal case passed!: "
         << endl;
    cout << "Random board created" << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Normal case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Normal case: " << endl;
  cout << "(Size: 625, Obst: 60)" << endl;
  if (aTester.testSnakesMakeRandomNormal(625, 60) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Normal case passed!: "
         << endl;
    cout << "Random board created" << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Normal case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Edge case: " << endl;
  cout << "(Size: 55, Obst: 2)" << endl;
  if (aTester.testSnakesMakeRandomEdge(55, 2) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Edge case passed!: "
         << endl;
    cout
        << "Random board created with low numSnakesLadders and non square value"
        << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Edge case failed!" << endl;
  }
  cout << "\tTesting Snakes makeRandomBoard Function Edge case: " << endl;
  cout << "(Size: 55, Obst: 30)" << endl;
  if (aTester.testSnakesMakeRandomEdge(55, 30) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Edge case passed!: "
         << endl;
    cout << "Random board created with non square value and beyond max "
            "numSnakesLadders"
         << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Edge case failed!" << endl;
  }

  if (aTester.testSnakesMakeRandomEdge(9, 1) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Edge case passed!: "
         << endl;
    cout << "Random board created with non square value and beyond max "
            "numSnakesLadders"
         << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Edge case failed!" << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Edge case:" << endl;
  cout << "(Size: 9, Obst: -2)" << endl;
  if (aTester.testSnakesMakeRandomEdge(9, -2) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Edge case passed!: "
         << endl;
    cout << "Random board created with min board size and non valid "
            "numOfsnakes/ladders"
         << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Edge case failed!" << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Error case: ";
  cout << " (Size: -2, Obst: -2)" << endl;
  if (aTester.testSnakesMakeRandomError(-2, -2) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Error case passed!: "
         << endl;
    cout << "Random board not created with non valid snakes/ladders and size "
            "given"
         << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Error case failed!"
         << endl;
  }

  cout << "\tTesting Snakes makeRandomBoard Function Error case:";
  cout << "(size 0,Obst: 100 )" << endl;
  if (aTester.testSnakesMakeRandomError(0, 100) == true) {
    cout << "Testing Snakes makeRandomBoardFunction test Error case passed!: "
         << endl;
    cout << "Random board not created when non valid snakes/ladders and size "
            "given"
         << endl;
  } else {
    cout << "Testing Snakes MakeRandom Function test Error case failed!"
         << endl;
  }

  Snakes originGame;
  originGame.makeDefaultBoard(256);
  cout << "\tTesting Snakes overLoadedAssign Function Normal case: " << endl;
  cout << "Using makeDefaultboard Size of 49" << endl;
  if (aTester.testSnakesOverloadAsNormal(originGame) == true) {
    cout << "Testing Snakes overLoadedAssign test Normal case passed!: ";
    cout << "Board contents have been fully copied" << endl;
  } else {
    cout << "Testing Snakes overLoadedAssign Function test Normal case failed!"
         << endl;
  }

  Snakes originGame1;
  originGame1.makeRandomBoard(36, 10);
  cout << "\tTesting Snakes overLoadedAssign Function Normal case: " << endl;
  cout << "Using makeRandomBoard Size of 36" << endl;
  if (aTester.testSnakesOverloadAsNormal(originGame1) == true) {
    cout << "Testing Snakes overLoadedAssign test Normal case passed!: ";
    cout << "Board contents have been fully copied" << endl;
  } else {
    cout << "Testing Snakes overLoadedAssign Function test Normal case failed!"
         << endl;
  }

  Snakes originGame2;
  originGame2.makeDefaultBoard(0);
  cout << "\tTesting Snakes overLoadedAssign Function Edge case: " << endl;
  cout << "Using makeDefaultBoard Size of 0" << endl;
  if (aTester.testSnakesOverloadAsEdge(originGame2) == true) {
    cout << "Testing Snakes overLoadedAssign test Edge case passed!: ";
    cout << "Board contents have not been copied" << endl;
  } else {
    cout << "Testing Snakes overLoadedAssign Function test Edge case failed!"
         << endl;
  }

  cout << "\tTesting Snakes Play Function Normal case: Size(25)" << endl;
  if (aTester.testSnakesPlayNormal() == true) {
    cout << "Testing Snakes Play test Play case passed!: ";
    cout << "Valid movements can be made" << endl;
  } else {
    cout << "Testing Snakes Play Function test Normal case failed!" << endl;
  }

  cout << "\tTesting Snakes Play Function Edge case: ";
  cout << " random(size 64, ladders/snakes:13) " << endl;
  if (aTester.testSnakesPlayRandomNormal() == true) {
    cout << "Testing Snakes Play test Normal case passed!: ";
    cout << "Valid movements can be made on random board" << endl;
  } else {
    cout << "Testing Snakes Play Function test Normal case failed!" << endl;
  }

  cout << "\tTesting Snakes Play Function Edge case: ";
  cout << "Playing till endgame: size(55)" << endl;
  if (aTester.testSnakesPlayEdge() == true) {
    cout << "Testing Snakes Play test Normal case passed!: ";
    cout << "Played until endgame on non square board" << endl;
  } else {
    cout << "Testing Snakes Play Function test Edge case failed!" << endl;
  }

  cout << "\tTesting Snakes Play Function Edge case: ";
  cout << "Playing till endgame: random(size:73 ,elements:100)" << endl;
  if (aTester.testSnakesPlayRandomEdge() == true) {
    cout << "Testing Snakes Play test Edge case passed!: ";
    cout << "Played until endgame" << endl;
  } else {
    cout << "Testing Snakes Play Function test Edge case failed!" << endl;
  }

  cout << "\tTesting Snakes Play Function Error case: ";
  cout << "Playing till endgame: size(-9)" << endl;
  if (aTester.testSnakesPlayError() == true) {
    cout << "Testing Snakes Play test Error case passed!: ";
    cout << "Board not playable" << endl;
  } else {
    cout << "Testing Snakes Play Function test Edge case failed!" << endl;
  }
  cout << "\tTesting Snakes Play Function Error case: ";
  cout << "Playing till endgame: random(size:-1 ,elements:1)" << endl;
  if (aTester.testSnakesPlayRandomError() == true) {
    cout << "Testing Snakes Play test Error case passed!: ";
    cout << "Board not playable" << endl;
  } else {
    cout << "Testing Snakes Play Function test Error case failed!" << endl;
  }

  cout << "\tTesting Play Function Normal case: ";
  cout << "Making a valid move on snake" << endl;
  if (aTester.testMoveOnSnake() == true) {
    cout << "Testing valid move on snake case passed!: ";
    cout << "Player is able to play on a snake element" << endl;
  } else {
    cout << "Test failed! Valid move not possible" << endl;
  }

  cout << "\tTesting Play Function Normal case: ";
  cout << "Making a valid move on ladder" << endl;
  if (aTester.testMoveOnSnake() == true) {
    cout << "Testing valid move on ladder case passed!: ";
    cout << "Player is able to play on a ladder element" << endl;
  } else {
    cout << "Test failed! Valid move not possible" << endl;
  }

  return 0;
}