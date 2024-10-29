#pragma once
#include <iostream>
#include <conio.h> // Để sử dụng _getch()
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <sys/stat.h>
#ifdef _WIN32
#include <direct.h>  // Thư viện cho Windows
#define CreateDir _mkdir  // Đổi tên cho hàm Windows
#else
#endif
#include <cstdlib>  // Để sử dụng system()
#include <string>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")
using namespace std;


#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1

void about();
void Setting();

void clearScreen();
void FixConsoleWindow();
void GotoXY(int x, int y);
void ResetKetqua(int a[BOARD_SIZE][BOARD_SIZE]);
void ResetData();
void DrawBoard(int pSize);
void StartGame();
void ExitGame();

int ProcessFinish(int pWhoWin);
int AskContinue();
int checkHoa(int a[BOARD_SIZE][BOARD_SIZE]);
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
void DrawX(int, int);
void DrawO(int, int);
void DrawWIN();
void DrawBlank();
void DrawTIE();

void displayMenu(int selected);
void startGame();
void showInstructions();

void SaveToFile(const string& filename, const string& content);
void CreateSaveDirectory();
void SaveGameWithFileName();
void LoadGameWithFileName();
void showSavedFiles();
void restartGame();
void reStartGame();
char AskLoadGame();
void resetData();
void countXO(int& countX, int& countO);
void reStartGame();
int checkWinCondition();
void printXO();
void Playmusic();