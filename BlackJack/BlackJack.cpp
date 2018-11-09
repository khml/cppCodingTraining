/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>

#include "BlackJack.hpp"

BlackJack::BlackJack () 
{
  clear ();
}

BlackJack::BlackJack (const BlackJack& orig) { }

BlackJack::~BlackJack () { }

void BlackJack::clear ()
{
  std::vector<int>().swap (randoms);
  cardSum = 0;
  
}

int BlackJack::checkSum ()
{
  return cardSum;
}

int BlackJack::randInt()
{
  int random_num = rand() % MAX_CARD_NUM + 1;
  return std::abs(random_num);
}

int BlackJack::drawCard ()
{
  int random_num = randInt();
  cardSum += random_num;
  randoms.push_back(random_num);
  return random_num;
}

int BlackJack::isOver ()
{
  if (cardSum > BLACK_JACK) return 1;
  else return 0;
}

int BlackJack::playDraw ()
{
  int draw_card = drawCard();
  if (isOver()) return -1;
  else return draw_card;
}

int BlackJack::autoGM ()
{
  int gm_card_sum(0);
  while(true)
    {
      gm_card_sum += randInt ();
      if (gm_card_sum > GM_THRESHOLD)
        break;
    }
  return gm_card_sum;
}

void BlackJack::show ()
{
  for(int value : randoms)
    {
      std::cout << value << std::endl;
    }
}
