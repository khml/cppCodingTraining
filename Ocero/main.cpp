/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include "Ocero.hpp"

void ci(Ocero& game)
{
  std::string command;
  std::cout << "input as x,y,color = ";
  std::cin >> command;
  game.play (std::stoi (command.substr (0, 1)), std::stoi (command.substr (2, 1)), std::stoi (command.substr (4, 1)));
}

void playOcero ()
{
  Ocero game;
  ci(game);
}


/*
 * 
 */
int main (int argc, char** argv)
{
  playOcero ();
  return 0;
}

