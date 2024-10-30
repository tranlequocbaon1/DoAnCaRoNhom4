#pragma once

#ifndef HEADER_H
#define HEADER_H

#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1

  struct _POINT { int x, y, c; };
 extern _POINT _A[BOARD_SIZE + 1][BOARD_SIZE + 1];
 extern _POINT pastcoord;
 
extern int _B[BOARD_SIZE + 1][BOARD_SIZE + 1];
extern bool _TURN;
extern int _COMMAND;
extern int _X;
extern int _Y;
extern int scoreP1;
extern int scoreP2;

void about();
void Setting();
int mainmenu();
void showloadgame();
void drawcaro();

void clearScreen();
void FixConsoleWindow();
void GotoXY(int x, int y);
void ResetKetqua(int _B[BOARD_SIZE+ 1][BOARD_SIZE + 1]);
void ResetData();
void DrawBoard(int pSize);
void StartGame();
void ExitGame();

int ProcessFinish(int pWhoWin);
int AskContinue();
int checkHoa(int _B[BOARD_SIZE + 1][BOARD_SIZE + 1]);
int TestBoard();
int CheckBoard(int pX, int pY);

void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();

void Box1();
void Box2();
void Score2Player();
void Box3();

void displayMenu(int selected);
void startGame();
void showInstructions();
void displaysetting(int selected);



void InputPlayerNames();

#endif