/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Ocero.hpp"
#include <iostream>

#define Debug 0

Ocero::Ocero ()
{
  initializeBoard ();
}

Ocero::Ocero (const Ocero& orig) : boardSize (orig.boardSize), board (orig.board), realBoardSize (orig.realBoardSize) { }

Ocero::~Ocero () { }

void Ocero::initializeBoard ()
{
  // clear board and fill with EMPTY
  std::vector<int>().swap (board);
  board.resize (realBoardSize * realBoardSize, EMPTY);

  // making Wall
  for (int i = 0; i < realBoardSize; i++)
    {
      board[getPos (0, i, 0)] = WALL;
      board[getPos (realBoardSize - 1, i, 0)] = WALL;
      board[getPos (i, 0, 0)] = WALL;
      board[getPos (i, realBoardSize - 1, 0)] = WALL;
    }

  // deploy first stones;
  int mid_pos = getPos (boardSize / 2 - 1, boardSize / 2 - 1);
  put (mid_pos, BLACK);
  put (getEightNeibourPos (mid_pos, RIGHT_DOWN), BLACK);
  put (getEightNeibourPos (mid_pos, RIGHT), WHITE);
  put (getEightNeibourPos (mid_pos, DOWN), WHITE);

  std::cout << "initilize Board OK" << std::endl;
  show ();
#if Debug > 0
  std::cout << "NumberBoard" << std::endl;
  std::vector<int> numberBoard(realBoardSize * realBoardSize, EMPTY);
  for(int i=0; i < realBoardSize * realBoardSize; i++)
    numberBoard[i] = i;
    for (int y = 0; y < realBoardSize; y++)
    {
      for (int x = 0; x < realBoardSize; x++)
        {
          std::cout << numberBoard[getPos (x, y, 0)] << ", ";
        }
      std::cout << std::endl;
    }
  std::cout << std::endl;
#endif
}

int Ocero::getOpositColor (int const color)
{
  return 3 - color;
}

int inline Ocero::getEightNeibourPos (const int pos, const int direction)
{
  return pos + eightNeighbour[direction];
}

int Ocero::getPos (int const x, int const y, int const space)
{
  return (x + space) +realBoardSize * (y + space);
}

/*
 * from pos, to one direction, seek color
 * return found pos
 * (color of pos is ignored)
 * 
 * direction
 * 1 2 3
 * 4 * 5
 * 6 7 8
 */
int Ocero::seekColorForOneDirection (int const pos, int const direction, int const colorLookingFor)
{
  int flag = 0;
  int seekPos = pos;
  for (int i = 0; i < realBoardSize; i++)
    {
      seekPos += eightNeighbour[direction];
      if (board[seekPos] == colorLookingFor)
        {
          flag = seekPos;
          break;
        }

      if (board[seekPos] == WALL || board[seekPos] == EMPTY)
        break;
    }
  return flag;
}

void Ocero::turn (int const pos, int const color)
{
  int const opositColor = getOpositColor (color);
  int foundPos;
  int turnPos;
  
  for(int direction=0; direction < DIRECTION_NUM; direction++)
    {
      // seek turnable direction
      if (board[getEightNeibourPos (pos, direction)] != opositColor)
        continue;
      // seek same color pos
      foundPos = seekColorForOneDirection (pos, direction, color);
      if (foundPos)
        {
          // init turn position
          turnPos = getEightNeibourPos (pos, direction);
          for(int i=0; i < boardSize; i++)
            {
              put (turnPos, color);
              turnPos = getEightNeibourPos (turnPos, direction);
              if (turnPos == foundPos)
                break;
            }
        }
    }
}

int Ocero::isLegalPos (int const pos, int const color)
{ 
  int neibourFlag = 0;
  
  if (board[pos] != EMPTY)
    return neibourFlag;
  
  int const oposit_color = getOpositColor (color);
  // explorer 8 neibour
  for (int i = 0; i < DIRECTION_NUM; i++)
    {
      if (board[getEightNeibourPos (pos, i)] == oposit_color && seekColorForOneDirection (pos, i, color))
        {
          neibourFlag = 1;
          break;
        }
    }
  return neibourFlag;
}

int Ocero::isLegal (const int x, const int y, const int color)
{
  if (x < 0 || boardSize < x || y < 0 || boardSize < y)
    return 0;
  
  return isLegalPos (getPos (x, y), color);
}

int Ocero::isFullBoard ()
{
  int y, x = 0;
  int flag = 1;
  
  for (y=0; y < boardSize; y++)
    {
      for (x=0; x < boardSize; x++)
        {
          if (board[getPos (y, x)] == EMPTY)
            {
              flag = 0;
              break;
            }
        }
    }
  return flag;
}

void Ocero::put (int const pos, int const color)
{
  board[pos] = color;
}

void Ocero::move (const int pos, const int color)
{
  put(pos, color);
  turn(pos, color);
}

void Ocero::play (int const x, int const y, int const color)
{
  if (isLegal (x, y, color))
    {
      move (getPos (x, y), color);
    }
  else
    {
      std::cout << "Error Ilegal Position: x = " << x << ", y = " << y << std::endl;
      int origColor = board[getPos (x, y)];
      put (getPos (x, y), color);
      show();
      put (getPos (x, y), origColor);
        
    }
  
  show();
}

std::string Ocero::toSymbol (int color)
{
  if (color == BLACK)
    return "B";
  else if (color == WHITE)
    return "W";
  else if (color == WALL)
    return "#";
  else if (color == EMPTY)
    return " ";
  else
    return "*";
}

void Ocero::show ()
{
  for (int y = 0; y < realBoardSize; y++)
    {
      for (int x = 0; x < realBoardSize; x++)
        {
          std::cout << toSymbol(board[getPos (x, y, 0)]) << ", ";
        }
      std::cout << std::endl;
    }
  std::cout << std::endl;
}

