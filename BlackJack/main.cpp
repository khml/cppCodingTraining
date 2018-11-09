/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "BlackJack.hpp"

void draw (BlackJack& game)
{
  int card_num(game.playDraw ());
  if (card_num == -1)
    {
      std::cout << "Game Over! sum = " << game.checkSum () << std::endl;
      game.clear ();
    }
  else if (game.checkSum () == BLACK_JACK)
    {
      std::cout << "Congratulations! BLACK JACK!!" << std::endl;
      game.clear ();
    }
  else
    {
      std::cout << "draw card = " << card_num << ", sum = " << game.checkSum () << std::endl;
    }
}

void stop (BlackJack& game)
{
  int gm_num(game.autoGM ());
  std::cout << "Stop Game. card sum = " << game.checkSum () << std::endl;
  std::cout << "GM card sum = " << gm_num << std::endl;
  
  if (gm_num > BLACK_JACK)
    std::cout << "GM sum over, You Win!" << std::endl;
  else if (game.checkSum () > gm_num)
    std::cout << "YOU WIN!" << std::endl;
  else if (game.checkSum () == gm_num)
    std::cout << "DROW" << std::endl;
  else
    std::cout << "YOU LOSE" << std::endl;
  
  game.clear ();
}

void playBlackJack (void)
{
  BlackJack game;
  std::string cmd;

  while (true)
    {
      std::cout << "please input command (d:draw, s:stop) = ";
      std::cin >> cmd;
      if (cmd == "d") draw (game);
      else if (cmd == "s") stop (game);
      else break;
    }
}

int main (int argc, char** argv)
{
  playBlackJack ();
  return 0;
}

