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
#include <vector>
#include <cstdio>

using namespace std;


#define BOARD_SIZE 12
#define LEFT 3
#define TOP 1

void about();
void Setting();
int mainmenu();
void showloadgame();
void drawcaro();

void clearScreen();
void FixConsoleWindow();
void GotoXY(int x, int y);
void ResetKetqua(int _B[BOARD_SIZE + 1][BOARD_SIZE + 1]);
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
void DrawX(int, int);
void DrawO(int, int);
void DrawWIN();
void DrawBlank();
void DrawTIE();

void displayMenu(int selected);
void startGame();
void showInstructions();
void displaysetting(int selected);

void SaveToFile(const string& filename, const string& content);
void CreateSaveDirectory();
void SaveGameWithFileName();
void LoadGameWithFileName();
void showSavedFiles(vector<string>& savedFiles);
void restartGame();
void reStartGame();
void resetData();
void countXO(int& countX, int& countO);
void reStartGame();
int checkWinCondition();
void deleteSavedFile(const std::string& fileName);

void click();
void victory();
void toggleSFX();

void InputPlayerNames();