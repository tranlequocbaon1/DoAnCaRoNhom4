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
			else {
				cout << ch; // Hiển thị ký tự vừa nhập
				input += ch;
			}
		}
	}
	return input;
}

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
	cout << u8R"(╔═════════════════════════════════════════╗)";
	GotoXY(centerX, 2);
	cout << u8R"(║            ENTER NICKNAME               ║)";
	GotoXY(centerX, 3);
	cout << u8R"(╚═════════════════════════════════════════╝)";

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

	bool validInput = false;
	while (!validInput) {
		GotoXY(centerX + 5, 7);
		player1 = getInputWithEscCheck();
		if (player1.empty())  player1 = "Player1";
		if (player1.length() > 10) {
			GotoXY(centerX, 15);
			cout << "                                        " << endl;
			Sleep(200);
			GotoXY(centerX, 15);
			cout << "Ten phai nho hon hoac bang 10 ky tu.     " << endl;
			Sleep(800);
			GotoXY(centerX + 5, 7);
			cout << "                                     ";
			GotoXY(centerX + 5, 7);
		}
		else validInput = true;
	}
	validInput = false;
	while (!validInput) {
		GotoXY(centerX + 5, 12);
		player2 = getInputWithEscCheck(); // Sử dụng hàm để nhập tên Player 2

		if (player2.empty()) { // Nếu người dùng nhấn Esc
			player2 = "Player2"; // Đặt tên mặc định
			return; // Quay lại menu
		}

		if (player2.length() > 10) {
			GotoXY(centerX, 15);
			cout << "Ten phai nho hon hoac bang 10 ky tu.      " << endl;
			Sleep(500); // Tạm dừng 0.5 giây
			GotoXY(centerX + 5, 12);
			cout << "                                    "; // Xóa tên đã nhập
			GotoXY(centerX + 5, 12); // Đưa con trỏ về vị trí nhập tên
		}
		else if (player1 == player2) {
			GotoXY(centerX, 15);
			cout << "                                         ";
			Sleep(200);
			GotoXY(centerX, 15);
			cout << "Ten phai khac nhau. Vui long nhap lai.    " << endl;
			Sleep(1000); // Tạm dừng 0.5 giây
			GotoXY(centerX + 5, 12);
			cout << "                                    "; // Xóa tên đã nhập
			GotoXY(centerX + 5, 12); // Đưa con trỏ về vị trí nhập tên
		}
		else {
			validInput = true; // Thoát khỏi vòng lặp nếu nhập tên hợp lệ
		}
	}
}