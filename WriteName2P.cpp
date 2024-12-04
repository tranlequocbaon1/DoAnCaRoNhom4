#include "Header.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include "Draw.h"
#include <conio.h>
#include"Sound.h"


using namespace std;

string getInputWithEscCheck() {
	string input = "";
	char ch;

	while (true) {
		// Kiểm tra nếu có phím nhấn
		if (_kbhit()) {
			ch = _getch(); // Lấy ký tự nhập vào

			if (ch == 27) { // Kiểm tra nếu là phím Esc
				click();
				ExitGame();
				mainmenu();
				return ""; // Quay lại menu
			}
			else if (ch == '\r') { // Kiểm tra nếu là phím Enter
				cout << endl;
				break;
			}
			else if (ch == '\b') { // Xóa ký tự nếu nhấn phím Backspace
				if (!input.empty()) {
					cout << "\b \b"; // Xóa ký tự khỏi màn hình
					input.pop_back();
				}
			}
			else if (input.length() < 32) {
				cout << ch; // Hiển thị ký tự vừa nhập
				input += ch;
			}
		}
	}
	return input;
}

string player1, player2;
void InputPlayerNames() {

	int consoleWidth = GetConsoleWidth();
	int boxWidth = 41; // Chiều rộng của khung
	int centerX = (consoleWidth - boxWidth) / 2;
	SetName_View();
	bool validInput = false;
	while (!validInput) {
		GotoXY(3, 11);
		player1 = getInputWithEscCheck();
		if (player1.empty())  player1 = "Player 1";
		if (player1.length() > 10) {
			Sleep(200);
			GotoXY(3, 11);
			cout << "                                       ";
			int count = 3;
			while (count > 0) {
				Box_Error_SetName(2, 13);
				Sleep(500);
				GotoXY(3, 15);
				cout << "                                         ";
				Sleep(500);
				count--;
			}
			Box_Error_SetName(2, 13);
			Sleep(1500);
			SetName_View();
			GotoXY(3, 11);
			validInput = false;
		}
		else validInput = true;
	}
	validInput = false;
	while (!validInput) {
		//DrawBG();
		GotoXY(76, 11);
		player2 = getInputWithEscCheck(); // Sử dụng hàm để nhập tên Player 2

		if (player2.empty()) { // Nếu người dùng nhấn Esc
			player2 = "Player 2"; // Đặt tên mặc định
			return; // Quay lại menu
		}

		if (player2.length() > 10) {
			Sleep(200);
			//Box_Error_SetName(75,13);
			//Sleep(800);
			//SetName_View();
			GotoXY(76, 11);
			cout << "                                       ";
			int count = 3;
			while (count > 0) {
				Box_Error_SetName(75, 13);
				Sleep(500);
				GotoXY(76, 15);
				cout << "                                         ";
				Sleep(500);
				count--;
			}
			Box_Error_SetName(75, 13);
			Sleep(1500);
			SetName_View();
			GotoXY(4, 11);
			cout << player1;
			GotoXY(centerX + 5, 12); // Đưa con trỏ về vị trí nhập tên
			validInput = false;
		}
		else if (player1 == player2) {
			int count = 3;
			while (count > 0) {
				Box_Error_Duplicate_SetName();
				Sleep(500);
				GotoXY(43, 16);
				cout << "                                       ";
				Sleep(500);
				count--;
			}
			Box_Error_Duplicate_SetName();
			Sleep(1500);
			SetName_View();
			GotoXY(4, 11);
			cout << player1;
			GotoXY(76, 11); // Đưa con trỏ về vị trí nhập tên
			validInput = false;
		}
		else {
			validInput = true; // Thoát khỏi vòng lặp nếu nhập tên hợp lệ
		}
	}
}

void SetName_View() {
	system("cls");
	DrawBG();
	SetConsoleOutputCP(CP_UTF8);

	// Lấy chiều rộng của console
	int consoleWidth = GetConsoleWidth();
	int boxWidth = 41; // Chiều rộng của khung
	int centerX = (consoleWidth - boxWidth) / 2;

	// Hiển thị khung tiêu đề
	SetColor(12, 15);

	drawName(10, 1);

	// Hiển thị và căn giữa phần nhập tên Player 1
	SetColor(0, 15);
	GotoXY(2, 9);
	cout << ">>Nhap ten player1";
	GotoXY(2, 10);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(2, 11);
	cout << u8R"(│                                         │)";
	GotoXY(2, 12);
	cout << u8R"(└─────────────────────────────────────────┘)";


	// Hiển thị và căn giữa phần nhập tên Player 2
	GotoXY(75, 9);
	cout << ">>Nhap ten player2";
	GotoXY(75, 10);
	cout << u8R"(┌─────────────────────────────────────────┐)";
	GotoXY(75, 11);
	cout << u8R"(│                                         │)";
	GotoXY(75, 12);
	cout << u8R"(└─────────────────────────────────────────┘)";
}