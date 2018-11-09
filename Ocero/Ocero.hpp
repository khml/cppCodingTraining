/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#ifndef OCERO_HPP
#define OCERO_HPP

#define PAD 1

#define WALL -1
#define EMPTY 0
#define BLACK 1
#define WHITE 2

#define LEFT_UP 0
#define UP 1
#define RIGHT_UP 2
#define LEFT 3
#define RIGHT 4
#define LEFT_DOWN 5
#define DOWN 6
#define RIGHT_DOWN 7
#define DIRECTION_NUM 8

#include <vector>
#include <string>

using namespace std;

class Ocero {
public:
    Ocero();
    Ocero(const Ocero& orig);
    virtual ~Ocero();
    void play(int const x, int const y, int const color);
    int isLegal(int const x, int const y, int const color);
    void show();
private:
    int const boardSize = 6;
    int const realBoardSize = boardSize + PAD * 2;
    std::vector<int> board;
    int const eightNeighbour[DIRECTION_NUM] ={-1 * realBoardSize - 1, -1 * realBoardSize, -1 * realBoardSize + 1, -1, 1,
        realBoardSize - 1, realBoardSize, realBoardSize + 1};
    
    void initializeBoard();
    int getOpositColor(int const color);
    int getPos(int const x, int const y, int const space=PAD);
    int getEightNeibourPos(int const pos, int const direction);
    int isLegalPos(int const pos, int const color);
    int seekColorForOneDirection(int const pos, int const direction, int const color);
    void put(int const pos, int const color);
    void move(int const pos, int const color);
    void turn(int const pos, int const color);
    int isFullBoard();
    
    std::string toSymbol(int color);
    
    
};

#endif /* OCERO_HPP */

