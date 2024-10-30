#include "Header.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>

using namespace std;

string player1, player2;
void InputPlayerNames() {

	system("cls");
	SetConsoleOutputCP(CP_UTF8);

	// Lấy chiều rộng của console
	int consoleWidth = GetConsoleWidth();
	int boxWidth = 41; // Chiều rộng của khung
	int centerX = (consoleWidth - boxWidth) / 2;

	// Hiển thị khung tiêu đề
	GotoXY(centerX, 1);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(centerX, 2);
	cout << u8R"(│            NHẬP TÊN NGƯỜI CHƠI          │)";
	GotoXY(centerX, 3);
	cout << u8R"(└─────────────────────────────────────────┘)";

	// Hiển thị và căn giữa phần nhập tên Player 1
	GotoXY(centerX, 5);
	cout << "Nhap ten player1";
	GotoXY(centerX, 6);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(centerX, 7);
	cout << u8R"(│                                         │)";
	GotoXY(centerX, 8);
	cout << u8R"(└─────────────────────────────────────────┘)";

	
	// Hiển thị và căn giữa phần nhập tên Player 2
	GotoXY(centerX, 10);
	cout << "Nhap ten player2";
	GotoXY(centerX, 11);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(centerX, 12);
	cout << u8R"(│                                         │)";
	GotoXY(centerX, 13);
	cout << u8R"(└─────────────────────────────────────────┘)";
	GotoXY(centerX + 5, 7); // Vị trí nhập tên player1
	getline(cin, player1);
	GotoXY(centerX + 5, 12); // Vị trí nhập tên player2
	getline(cin, player2);
}
