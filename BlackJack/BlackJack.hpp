/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#define BLACK_JACK 21

#include <random>
#include <vector>

class BlackJack {
public:
    BlackJack();
    BlackJack(const BlackJack& orig);
    virtual ~BlackJack();
    void clear();
    int playDraw();
    int checkSum();
    int randInt();
    int autoGM();
    void show();
private:
    int drawCard();
    int isOver();
    std::random_device rand;
    std::vector<int> randoms;
    int cardSum;
    int const MAX_CARD_NUM = 13;
    int const GM_THRESHOLD = 16;
};

void draw(BlackJack&);
void stop(BlackJack&);
void playBlackJack();

#endif /* BLACKJACK_HPP */

