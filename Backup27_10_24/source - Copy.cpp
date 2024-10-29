#pragma once
#include "header.h"
#include"Draw.h"
//menu
struct _POINT { int x, y, c; };
_POINT _A[BOARD_SIZE + 1][BOARD_SIZE + 1];
int _B[BOARD_SIZE][BOARD_SIZE];
bool _TURN;
int _COMMAND;
int _X, _Y;
int scoreP1 = 0;
int scoreP2 = 0;



void clearScreen() {
	system("cls");
}
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void ResetKetqua(int a[BOARD_SIZE][BOARD_SIZE]) {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			a[LEFT + 2 + i * 5][TOP + 1 + 2 * j] = 0;
		}
	}
}
void ResetData() {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			_A[i][j].x = 5 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0;
		}
	}
	_TURN = true;_COMMAND = -1;
	_X = _A[0][0].x;_Y = _A[0][0].y;
}

void DrawBoard(int pSize) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0;i <= pSize - 1;i++) {
		for (int j = 0;j <= pSize - 1;j++) {
			GotoXY(LEFT, TOP + 2 * j);
			cout << u8"╠";

			//
			GotoXY(LEFT + 5 * i, TOP + 2 * j);
			cout << u8"╬════";
			GotoXY(LEFT + 5 * i, TOP);
			cout << u8"╦════";
			GotoXY(LEFT + 5 * i + 5, TOP + 2 * j);
			cout << u8"╣";
			//
			GotoXY(LEFT + 5 * (i)+5, TOP + 2 * j + 1);
			cout << u8"║ ";
			GotoXY(LEFT + 5 * (i), TOP + 2 * j + 1);
			cout << u8"║ ";
			//dong cuoi
			GotoXY(LEFT + 5 * i, TOP + 2 * j + 2);
			cout << u8"╬════";
			GotoXY(LEFT + 5 * i + 5, TOP + 2 * j + 2);
			cout << u8"╣";
			GotoXY(LEFT + 5 * pSize, TOP);
			cout << u8"╗";
			GotoXY(LEFT + 5 * i, TOP + 2 * pSize);
			cout << u8"╩════";
			//goc tren
			GotoXY(LEFT, TOP);
			cout << u8"╔";
			//goc duoi
			GotoXY(LEFT + 5 * pSize, TOP + 2 * pSize);
			cout << u8"╝";
			GotoXY(LEFT, TOP + 2 * pSize);
			cout << u8"╚";

		}
	}
}

void StartGame() {
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);

}

void GabageCollect() {

}

void ExitGame() {
	system("cls");
	GabageCollect();
}

int ProcessFinish(int pWhoWin) {
	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	switch (pWhoWin) {
	case -1: {
		scoreP1 += 1;
		int demnguoc = 7;
		while (demnguoc > 0) {
			DrawX(71, 9);
			DrawWIN();
			Sleep(150);
			DrawBlank();
			Sleep(150);
			DrawX(71, 9);
			DrawWIN();

			demnguoc--;

		}
		break;
	}
	case 1: {
		scoreP2 += 1;
		int demnguoc = 7;
		while (demnguoc > 0) {
			DrawO(71, 9);
			DrawWIN();
			Sleep(150);
			DrawBlank();
			Sleep(150);
			DrawO(71, 9);
			DrawWIN();

			demnguoc--;

		}
		break;
	}
	case 0: {
		int demnguoc = 7;
		while (demnguoc > 0) {

			DrawTIE();
			Sleep(150);
			DrawBlank();
			Sleep(150);

			DrawTIE();

			demnguoc--;

		}

		break;
	}
	case 2:
		_TURN = !_TURN;

	}
	GotoXY(_X, _Y);
	return pWhoWin;
}
int AskContinue() {
	GotoXY(15, _A[BOARD_SIZE][BOARD_SIZE - 1].y);
	cout << "    nhap y/n de tiep tuc/dung     ";
	return toupper(_getch());
}
int checkHoa(int a[BOARD_SIZE][BOARD_SIZE]) {
	int countSL = 0;
	for (int i = 0; i <= BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE; j++) {
			if (a[LEFT + 2 + i * 5][TOP + 1 + 2 * j] == 1 || a[LEFT + 2 + i * 5][TOP + 1 + 2 * j] == -1) {
				countSL += 1;
				GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 5);//test vitri
				cout << countSL;
				if (countSL == BOARD_SIZE * BOARD_SIZE - 1) return 0;
			}
			else break;
		}
	}
	return 2;
}

int TestBoard() {
	int countX = 0;
	int countY = 0;
	int countCC = 0;
	int countCP = 0;

	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 2);
	cout << "x:" << _B[_X - 20][_Y] << " " << _B[_X - 15][_Y] << " " << _B[_X - 10][_Y]
		<< " " << _B[_X - 5][_Y] << " _" << _B[_X][_Y] << "_ " << _B[_X + 5][_Y] << " "
		<< _B[_X + 10][_Y] << " " << _B[_X + 15][_Y] << " " << _B[_X + 20][_Y] << "                 ";

	GotoXY(0, _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y + 4);
	cout << "y:" << _B[_X][_Y - 8] << " " << _B[_X][_Y - 6] << " " << _B[_X][_Y - 4]
		<< " " << _B[_X][_Y - 2] << " _" << _B[_X][_Y] << "_ " << _B[_X][_Y + 2] << " "
		<< _B[_X][_Y + 4] << " " << _B[_X][_Y + 6] << " " << _B[_X][_Y + 8] << "                 "; //check ket qua
	if (checkHoa(_B) == 0) return 0;

	//cheo phu
	for (int i = 0;i <= 9;i++) {
		if (_B[_X + 20 - i * 5][_Y - 8 + i * 2] == -1) {
			countCP += 1;
			if (countCP == 5) return -1;
		}
		else countCP = 0;
	}
	for (int i = 0;i <= 9;i++) {
		if (_B[_X + 20 - i * 5][_Y - 8 + i * 2] == 1) {
			countCP += 1;
			if (countCP == 5) return 1;
		}
		else countCP = 0;
	}
	//cheo chinh
	for (int i = 0;i <= 9;i++) {
		if (_B[_X - 20 + i * 5][_Y - 8 + i * 2] == -1) {
			countCC += 1;
			if (countCC == 5) return -1;
		}
		else countCC = 0;
	}

	for (int i = 0;i <= 9;i++) {
		if (_B[_X - 20 + i * 5][_Y - 8 + i * 2] == 1) {
			countCC += 1;
			if (countCC == 5) return 1;
		}
		else countCC = 0;

	}
	//thang
	for (int i = 0;i <= 9;i++) {
		if (_B[_X][_Y - 8 + i * 2] == -1) {
			countY += 1;
			if (countY == 5) return -1;
		}
		else countY = 0;
	}
	for (int i = 0;i <= 9;i++) {
		if (_B[_X][_Y - 8 + i * 2] == 1) {
			countY += 1;
			if (countY == 5) return 1;
		}
		else countY = 0;
	}
	//ngang
	for (int i = 0;i <= 9;i++) {
		if (_B[_X - 20 + i * 5][_Y] == -1) {
			countX += 1;
			if (countX == 5) return -1;
		}
		else countX = 0;
	}

	for (int i = 0;i <= 9;i++) {
		if (_B[_X - 20 + i * 5][_Y] == 1) {
			countX += 1;
			if (countX == 5) return 1;
		}
		else countX = 0;
	}

	return 2;
}

int CheckBoard(int pX, int pY) {
	for (int i = 0;i <= BOARD_SIZE;i++) {
		for (int j = 0;j <= BOARD_SIZE;j++) {
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
				if (_TURN == true) _A[i][j].c = -1;
				else _A[i][j].c = 1;
				return _A[i][j].c;
			}
		}
	}
	return 0;
}



void MoveRight() {
	if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
		_X += 5;
		GotoXY(_X, _Y);
	}
}

void MoveLeft() {
	if (_X > _A[0][0].x) {
		_X -= 5;
		GotoXY(_X, _Y);
	}
}

void MoveDown() {
	if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
		_Y += 2;
		GotoXY(_X, _Y);
	}
}

void MoveUp() {
	if (_Y > _A[0][0].y) {
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}

void Box1() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 6);
	SetConsoleOutputCP(CP_UTF8);
	//box p1
	GotoXY(LEFT + 70, TOP + 2);
	for (int i = 0;i < 20;i++) cout << u8"─";
	//cot doc trai
	GotoXY(LEFT + 69, TOP + 3);
	cout << u8"│ ";// cot giua

	GotoXY(LEFT + 69, TOP + 2);
	cout << u8"┌";
	GotoXY(LEFT + 69, TOP + 4);
	cout << u8"└";
	//cot doc phai
	GotoXY(LEFT + 90, TOP + 3);
	cout << u8"│ ";
	GotoXY(LEFT + 90, TOP + 2);
	cout << u8"┐";
	GotoXY(LEFT + 90, TOP + 4);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 4);
	for (int i = 0;i < 20;i++) cout << u8"─";

	//box p2
	GotoXY(LEFT + 70, TOP + 5);
	for (int i = 0;i < 20;i++) cout << u8"─";
	//cot doc trai
	GotoXY(LEFT + 69, TOP + 6);
	cout << u8"│";//cot giua

	GotoXY(LEFT + 69, TOP + 5);
	cout << u8"┌";
	GotoXY(LEFT + 69, TOP + 7);
	cout << u8"└";
	//cot doc phai
	GotoXY(LEFT + 90, TOP + 6);
	cout << u8"│";
	GotoXY(LEFT + 90, TOP + 5);
	cout << u8"┐";
	GotoXY(LEFT + 90, TOP + 7);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 7);
	for (int i = 0;i < 20;i++) cout << u8"─";

	SetConsoleTextAttribute(hStdOut, (15 << 4) | 0);
	GotoXY(LEFT + 70, TOP + 6);
	cout << "player 2";
	GotoXY(LEFT + 70, TOP + 3);
	cout << "player 1";
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
}


void Score2Player() {
	GotoXY(LEFT + 88, TOP + 3);
	cout << scoreP1;
	GotoXY(LEFT + 88, TOP + 6);
	cout << scoreP2;
}

void Box2() {
	SetConsoleOutputCP(CP_UTF8);
	//box p1
	GotoXY(LEFT + 70, TOP + 2 + 6);
	for (int i = 0;i < 45;i++) cout << u8"═";
	//cot doc trai
	for (int i = 0;i <= 6;i++) {
		GotoXY(LEFT + 69, TOP + 8);
		cout << u8"╔";
		GotoXY(LEFT + 115, TOP + 2 + 6);
		cout << u8"╗";
		GotoXY(LEFT + 69, TOP + 3 + i + 6);
		cout << u8"║ ";// cot giua
		GotoXY(LEFT + 115, TOP + 3 + i + 6);
		cout << u8"║ ";// cot giua
	}

	GotoXY(LEFT + 69, TOP + 14 + 1);
	cout << u8"╚";
	GotoXY(LEFT + 115, TOP + 14 + 1);
	cout << u8"╝";
	/*//cot doc phai
	GotoXY(LEFT + 115, TOP + 2 +6 );
	cout << u8"┐";
	*/
	//duoi cung
	GotoXY(LEFT + 70, TOP + 14 + 1);
	for (int i = 0;i < 45;i++) cout << u8"═";

}


void Box3() {
	SetConsoleOutputCP(CP_UTF8);
	//box p1
	GotoXY(LEFT + 70, TOP + 2 + 6 + 8);
	for (int i = 0;i < 35;i++) cout << u8"─";
	//cot doc trai
	for (int i = 0;i <= 5;i++) {
		GotoXY(LEFT + 69, TOP + 8 + 8);
		cout << u8"┌";
		GotoXY(LEFT + 105, TOP + 2 + 6 + 8);
		cout << u8"┐";
		GotoXY(LEFT + 69, TOP + 3 + i + 6 + 8);
		cout << u8"│ ";// cot giua
		GotoXY(LEFT + 105, TOP + 3 + i + 6 + 8);
		cout << u8"│ ";// cot giua
	}
	GotoXY(LEFT + 69, TOP + 14 + 8 + 1);
	cout << u8"└";
	//cot doc phai

	GotoXY(LEFT + 105, TOP + 14 + 8 + 1);
	cout << u8"┘";
	//duoi cung
	GotoXY(LEFT + 70, TOP + 14 + 8 + 1);
	for (int i = 0;i < 35;i++) cout << u8"─";
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 4);

	GotoXY(LEFT + 70, TOP + 17);//nhap noi dung
	cout << " --HOW TO PLAY-- ";
	GotoXY(LEFT + 70, TOP + 18);
	cout << "RIGHT: D | LEFT: A ";
	GotoXY(LEFT + 70, TOP + 19);
	cout << "UP:    W | DOWN: S ";
	GotoXY(LEFT + 70, TOP + 20);
	cout << "QUIT: ESC| SAVE: L";
	GotoXY(LEFT + 70, TOP + 21);
	cout << "CHOOSE:ENTER";
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 1);
	for (int i = 0;i < 6;i++) {
		GotoXY(LEFT + 88, TOP + 16);
		cout << u8"┬";
		GotoXY(LEFT + 88, TOP + 17 + i);
		cout << u8"│";
		GotoXY(LEFT + 88, TOP + 17 + 6);
		cout << u8"┴";
	}

}








void displayMenu(int selected) {
	const string options[] = { "Bat dau tro choi", "Huong dan","About","Load game","Setting","Thoat" };
	const int numOptions = sizeof(options) / sizeof(options[0]);
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));
	clearScreen();
	cout << u8R"(     
                              ╔═█████████    ╔═█████████     ╔═█████████     ╔═█████████	
                             ╔╝██           ╔╝██═════╗ ██    ║ ██    ║ ██   ╔╝██    ╚╗ ██
                             ║ ██           ║ ██     ║ ██    ║ ██    ║ ██   ║ ██     ║ ██
                             ║ ██           ║ ███████████    ║ █████████    ║ ██     ║ ██
                             ║ ██           ║ ██═════╗ ██    ║ ██════╗ ██   ║ ██     ║ ██
                             ║ ██           ║ ██     ║ ██    ║ ██    ║ ██   ║ ██     ║ ██
                             ╚╦ █████████   ║ ██     ║ ██    ║ ██    ║ ██   ╚╦ █████████ 
                              ╚════════╝    ╚══╝     ╚══╝    ╚═╝     ╚═╝     ╚══════╝
)" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
	SetConsoleOutputCP(CP_UTF8);
	cout << u8"                                              ┌────────────────────────┐" << endl;
	for (int i = 0; i < numOptions; i++) {

		if (i == selected) {
			// Mục đang chọn với màu chữ đỏ
			SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4)); // Màu chữ xanh lam, nền trắng // Màu chữ đỏ
			SetConsoleOutputCP(CP_UTF8);
			cout << u8"                                              │   >> " << options[i];
			if (options[i] == "Bat dau tro choi") cout << u8"  │ " << "\n";
			else if (options[i] == "Huong dan") cout << u8"         │ " << "\n";
			else if (options[i] == "About") cout << u8"             │ " << "\n";
			else if (options[i] == "Load game") cout << u8"         │ " << "\n";
			else if (options[i] == "Setting") cout << u8"           │ " << "\n";
			else if (options[i] == "Thoat") cout << u8"             │ " << "\n";
		}
		else {
			// Mục không chọn với màu mặc định (trắng)
			SetConsoleTextAttribute(hConsole, FOREGROUND_INTENSITY | (15 << 4));
			// Màu mặc định
			cout << u8"                                              │      " << options[i];
			if (options[i] == "Bat dau tro choi") cout << u8"  │ " << "\n";
			else if (options[i] == "Huong dan") cout << u8"         │ " << "\n";
			else if (options[i] == "About") cout << u8"             │ " << "\n";
			else if (options[i] == "Load game") cout << u8"         │ " << "\n";
			else if (options[i] == "Setting") cout << u8"           │ " << "\n";
			else if (options[i] == "Thoat") cout << u8"             │ " << "\n";
		}
	}
	cout << u8"                                              └────────────────────────┘" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (15 << 4));

	std::cout << u8R"(
                    ...

)" << std::endl;
}
void startGame() {

	SetConsoleOutputCP(1251);
	cout << "Bat dau tro choi...\n";

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | (15 << 4));

	FixConsoleWindow();

	int a, b;
	bool ValidEnter = true;

	StartGame();
	Box1();
	Box2();
	Box3();
	DrawX(89 + 2, 17);
	Score2Player();
	GotoXY(LEFT + 2, TOP + 1);//dua con tro ve o dau tien

	while (1) {

		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) {
			Sleep(500);
			scoreP1 = 0;
			scoreP2 = 0;
			ExitGame();
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'L') {
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo(hStdOut, &csbi);
				int bottomRow = csbi.srWindow.Bottom;  // Get the bottom row of the current console window

				GotoXY(0, bottomRow);

				SaveGameWithFileName();  // Gọi hàm để lưu game với tên file người chơi nhập

			}
			else if (_COMMAND == 13) {
				switch (CheckBoard(_X, _Y)) {
				case -1:
					SetConsoleTextAttribute(hStdOut, 12 | (15 << 4));
					cout << "X";

					_B[_X][_Y] = -1;
					GotoXY(0, 0);
					DrawO(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));
					

					break;
				case 1:
					SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));
					cout << "O";
					_B[_X][_Y] = 1;
					GotoXY(0, 0);
					DrawX(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 1 | (15 << 4));
					
					break;
				case 0:
					ValidEnter = false;
				}
				if (ValidEnter == true) {
					switch (ProcessFinish(TestBoard())) {
					case-1:
					case 1:
					case 0:
						SetConsoleOutputCP(CP_UTF8);

						// Đường dẫn đến file âm thanh
						LPCWSTR filePath = L"Music\\victory.wav"; // Sử dụng đường dẫn đến file âm thanh

						// Phát âm thanh
						PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);

						// Giữ console mở trong một khoảng thời gian

						if (AskContinue() != 'Y') {
							//system("pause");
							Sleep(500);
							ResetKetqua(_B);
							system("cls");
							scoreP1 = 0;
							scoreP2 = 0;
							_COMMAND == 27;
							return;

						}
						else {
							ResetKetqua(_B);
							startGame();
						}

					}
				}
				ValidEnter = true;
			}
		}
	}

}



void showInstructions() {
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15 << 4));

	clearScreen();
	cout << u8R"(

            █  ██    █  ██████   █████████ █████████  █   █   ██████  █████████  █   ███████   ██    █   ██████
            █  █ █   █ █      █      █     █       █  █   █  █      █     █      █  █       █  █ █   █  █      █
            █  █  █  █  █████        █     █████████  █   █  █            █      █  █       █  █  █  █   █████
            █  █   █ █       ██      █     █ ████     █   █  █      █     █      █  █       █  █   █ █        ██
            █  █    ██  ██████       █     █      ██   ███    ██████      █      █   ███████   █    ██   ██████
)" << endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (15 << 4));
	cout << "A : Move Left\n";
	cout << "D : Move Right\n";
	cout << "W : Move Up.\n";
	cout << "S : Move Down\n";
	cout << "Press Q to return Menu";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	do {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (toupper(key) == 'Q') {
			break;

			// Quay về menu
		}
	} while (true);
}
void about() {
	clearScreen();
	SetConsoleOutputCP(CP_UTF8);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);

	clearScreen();
	std::cout << u8R"(
                           ╔═█████████     ╔═█████████    ╔═█████████	 ╔═██ 	  ╔═██   ╔═██████████
                          ╔╝██═════╗ ██    ║ ██    ║ ██  ╔╝██    ╚╗ ██   ║ ██     ║ ██   ╚═══╗ ██
                          ║ ██     ║ ██    ╠═██════╣ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██ 
                          ║ ███████████    ║ █████████   ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██═════╗ ██    ║ ██    ║ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██     ║ ██    ║ ██    ║ ██  ║ ██     ║ ██   ║ ██     ║ ██       ║ ██
                          ║ ██     ║ ██    ║ █████████   ╚╦ █████████    ╚╦ █████████        ║ ██ 
                          ╚══╝     ╚══╝    ╚══════╝       ╚══════╝        ╚════════╝         ╚══╝ 
)" << std::endl;
	SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
	SetConsoleOutputCP(CP_UTF8);
	cout << u8"                               ┌────────────────────────────────────────────┐" << "\n";
	cout << u8"                               │    Teacher_Instructors:Truong Toan Thinh   │" << "\n";
	cout << u8"                               │ GROUP 04:                                  │" << "\n";
	cout << u8"                               │   +Do Ngoc Gia Bao - Leader(24120263)      │" << "\n";
	cout << u8"                               │   +Huynh Thanh Tu          (24120235)      │" << "\n";
	cout << u8"                               │   +Tran Le Quoc Bao        (24120268)      │" << "\n";
	cout << u8"                               │   +Nguyen Van Toan         (24120232)      │" << "\n";
	cout << u8"                               │   +Tran Thien An           (24120255)      │" << "\n";
	cout << u8"                               │ Press Q to return Menu                     │" << "\n";
	cout << u8"                               └────────────────────────────────────────────┘" << "\n";

	// Chờ người dùng nhấn 'Q' để quay lại menu
	while (true) {
		char key = _getch(); // Nhận đầu vào từ bàn phím
		if (key == 'q' || key == 'Q') {
			break; // Quay về menu
		}
	}
}

void Setting() {

}
void SaveGameWithFileName() {
	// Đếm số lượng file .txt trong thư mục Saves
	system("dir /b Saves\\*.txt > file_count.txt");  // Lưu danh sách file vào file_count.txt
	ifstream countFile("file_count.txt");
	int fileCount = 0;
	string temp;
	while (getline(countFile, temp)) {
		fileCount++;
	}
	countFile.close();
	remove("file_count.txt");  // Xóa file tạm sau khi sử dụng

	// Kiểm tra nếu số lượng file đạt giới hạn 8
	if (fileCount >= 9) {
		cout << "Thu muc 'Saves' da dat gioi han 8 file. Khong the luu them." << endl;
		return;
	}

	string fileName;
	do {
		GotoXY(LEFT + 20, TOP + 2 * BOARD_SIZE + 2);
		cout << "Nhap ten file de luu game (toi da 8 ky tu): ";
		cin >> fileName;

		if (fileName.length() > 8) {
			// Xóa dòng nhập tên file
			GotoXY(LEFT + 30, TOP + 2 * BOARD_SIZE + 2);  // Di chuyển đến vị trí nhập tên file
			cout << string(fileName.length(), ' ');  // Ghi đè tên file sai bằng khoảng trắng

			// Thông báo lỗi
			GotoXY(LEFT, TOP + 2 * BOARD_SIZE + 3);
			cout << "Ten file qua dai, vui long nhap lai (toi da 8 ky tu).";
			Sleep(1000); // Tạm dừng để hiển thị thông báo lỗi

			// Xóa dòng thông báo lỗi sau khi hiển thị
			GotoXY(LEFT + 20, TOP + 2 * BOARD_SIZE + 2);

			cout << "                                                                                  ";

			// Xóa bộ đệm nhập và đặt lại con trỏ
			cin.clear();  // Xóa trạng thái lỗi của cin
			cin.ignore(INT_MAX, '\n');  // Xóa bộ đệm nhập
		}
	} while (fileName.length() > 8); // Lặp lại nếu tên file quá dài

	fileName += ".txt";  // Thêm phần mở rộng cho file

	// Thêm đường dẫn vào thư mục "Saves"
	string filePath = "Saves/" + fileName;

	// Mở file để lưu vào đường dẫn
	ofstream saveFile(filePath.c_str());

	if (!saveFile) {
		cout << "ERROR, khong the tao file luu game" << endl;
		return;
	}

	// Lưu trạng thái bàn cờ
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			saveFile << _A[i][j].c << " ";  // Lưu giá trị của từng ô cờ
		}
		saveFile << endl;
	}


	// Lưu lượt chơi hiện tại
	saveFile << (_TURN ? 1 : 0) << endl;

	// Lưu vị trí con trỏ hiện tại
	saveFile << _X << " " << _Y << endl;
	saveFile << scoreP1 << " " << scoreP2 << endl;  // Lưu điểm số của người chơi 1 và 2
	saveFile << _B[45][4];
	saveFile.close();

	GotoXY(LEFT + 20, TOP + 2 * BOARD_SIZE + 3);
	cout << "Ban co muon quay ve menu chinh? (Nhan ESC de thoat hoac bat ky phim nao khac de tiep tuc choi)";

	char choice = _getch();  // Nhận phím từ người dùng
	if (choice == 27) {  // ESC có mã ASCII là 27
		// Quay lại menu chính
	}
	else {
		GotoXY(LEFT, TOP + 2 * BOARD_SIZE + 3);
		cout << "                                                                                                                                                     ";
	}
}

void showSavedFiles() {
	cout << "Danh sach cac file save:\n";

	// Chạy lệnh dir và ghi đầu ra vào file temp.txt
	system("dir Saves > temp.txt");

	ifstream file("temp.txt");
	string line;

	// Đọc từng dòng trong file temp.txt
	while (getline(file, line)) {
		// Kiểm tra xem dòng có chứa .txt hay không và in ra
		if (line.find(".txt") != string::npos) {
			// Cắt tên file từ dòng
			size_t pos = line.find_last_of(" ");
			cout << line.substr(pos + 1) << endl; // In ra tên file
		}
	}

	file.close();
	remove("temp.txt");  // Xóa file tạm sau khi sử dụng
}
void LoadGameWithFileName() {
	clearScreen();  // Xóa màn hình trước khi tải game

	showSavedFiles();  // Hiện danh sách các file save

	cout << endl << "Press Q to return Menu" << endl;  // Thêm thông báo hướng dẫn

	string fileName;
	cout << "Ban co muon Load File khong? (Y/N)";
	char choice = _getch();
	if (choice == 'n')
	{
	}
	else if (choice == 'q')
	{
	}
	else
	{// Yêu cầu người chơi nhập tên file save
		cout << endl << "Nhap ten file save de load (khong can phan mo rong .txt): ";
		cin >> fileName;

		// Kiểm tra nếu người chơi muốn quay về menu
		if (fileName == "q") {
			cout << "Da ve menu." << endl;
			return;  // Quay về menu
		}

		// Thêm đường dẫn và phần mở rộng .txt
		string fullFileName = "Saves/" + fileName + ".txt";

		// In ra đường dẫn file để kiểm tra
		cout << "Trying to open: " << fullFileName << endl;

		// Mở file save
		ifstream loadFile(fullFileName.c_str());

		// Kiểm tra nếu không thể mở file
		if (!loadFile.is_open()) {
			cout << "Loi: Khong the mo file save! Kiem tra lai ten file va thu muc 'Saves/'." << endl;
			return;
		}

		// Kiểm tra nếu file đang rỗng hoặc không đúng định dạng
		if (loadFile.peek() == ifstream::traits_type::eof()) {
			cout << "Loi: File save rong hoac khong dung dinh dang!" << endl;
			return;
		}

		// Đọc trạng thái bàn cờ từ file
		for (int i = 0; i < BOARD_SIZE; i++) {
			for (int j = 0; j < BOARD_SIZE; j++) {
				loadFile >> _A[i][j].c;  // Load dữ liệu từng ô cờ
				cout << "Loading [" << i << "][" << j << "] = " << _A[i][j].c << endl;  // Debug thông tin
			}
		}

		// Đọc lượt chơi hiện tại
		int turn;
		loadFile >> turn;
		_TURN = (turn == 1);  // 1 tương đương với lượt chơi thứ nhất
		cout << "Luat choi hien tai: " << (turn == 1 ? "Nguoi choi 1" : "Nguoi choi 2") << endl;


		// Đọc vị trí con trỏ hiện tại
		loadFile >> _X >> _Y;
		cout << "Vi tri con tro: (" << _X << ", " << _Y << ")" << endl;

		// Đóng file sau khi load xong
		loadFile >> scoreP1 >> scoreP2;
		loadFile.close();

		clearScreen();
		restartGame();






		GotoXY(_X, _Y);  // Di chuyển con trỏ đến vị trí hiện tại
		cout << "Game da duoc load thanh cong tu file: " << fullFileName << endl;

	}

}


void CreateSaveDirectory() {
	int result = CreateDir("Saves");

	if (result == 0) {
		cout << "Created directory 'Saves'." << endl;
	}
	else if (errno == EEXIST) {
		cout << "'Saves' directory already exists." << endl;

	}
	else {
		cout << "Error creating 'Saves' directory." << endl;
	}
}
void SaveToFile(const string& filename, const string& content) {
	string filepath = "Saves/" + filename;  // Lưu vào thư mục Saves
	ofstream file(filepath);

	if (file.is_open()) {
		file << content;
		file.close();
		cout << "File saved to: " << filepath << endl;
	}
	else {
		cout << "Unable to open file for writing." << endl;
	}
}
int checkWinCondition() {
	// Kiểm tra hàng
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j <= BOARD_SIZE - 5; j++) {
			if (_A[i][j].c == -1 && _A[i][j + 1].c == -1 && _A[i][j + 2].c == -1 &&
				_A[i][j + 3].c == -1 && _A[i][j + 4].c == -1) {
				return -1; // X thắng
			}
			if (_A[i][j].c == 1 && _A[i][j + 1].c == 1 && _A[i][j + 2].c == 1 &&
				_A[i][j + 3].c == 1 && _A[i][j + 4].c == 1) {
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra cột
	for (int j = 0; j < BOARD_SIZE; j++) {
		for (int i = 0; i <= BOARD_SIZE - 5; i++) {
			if (_A[i][j].c == -1 && _A[i + 1][j].c == -1 && _A[i + 2][j].c == -1 &&
				_A[i + 3][j].c == -1 && _A[i + 4][j].c == -1) {
				return -1; // X thắng
			}
			if (_A[i][j].c == 1 && _A[i + 1][j].c == 1 && _A[i + 2][j].c == 1 &&
				_A[i + 3][j].c == 1 && _A[i + 4][j].c == 1) {
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra đường chéo chính
	for (int i = 0; i <= BOARD_SIZE - 5; i++) {
		for (int j = 0; j <= BOARD_SIZE - 5; j++) {
			if (_A[i][j].c == -1 && _A[i + 1][j + 1].c == -1 && _A[i + 2][j + 2].c == -1 &&
				_A[i + 3][j + 3].c == -1 && _A[i + 4][j + 4].c == -1) {
				return -1; // X thắng
			}
			if (_A[i][j].c == 1 && _A[i + 1][j + 1].c == 1 && _A[i + 2][j + 2].c == 1 &&
				_A[i + 3][j + 3].c == 1 && _A[i + 4][j + 4].c == 1) {
				return 1; // O thắng
			}
		}
	}

	// Kiểm tra đường chéo phụ
	for (int i = 0; i <= BOARD_SIZE - 5; i++) {
		for (int j = 4; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == -1 && _A[i + 1][j - 1].c == -1 && _A[i + 2][j - 2].c == -1 &&
				_A[i + 3][j - 3].c == -1 && _A[i + 4][j - 4].c == -1) {
				return -1; // X thắng
			}
			if (_A[i][j].c == 1 && _A[i + 1][j - 1].c == 1 && _A[i + 2][j - 2].c == 1 &&
				_A[i + 3][j - 3].c == 1 && _A[i + 4][j - 4].c == 1) {
				return 1; // O thắng
			}
		}
	}
	// Kiểm tra hòa
	int countX = 0, countO = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) countO++;
			else if (_A[i][j].c == -1) countX++;
		}
	}

	// Nếu bàn cờ đầy mà không có ai thắng, trả về 2 (hòa)
	if (countX + countO == BOARD_SIZE * BOARD_SIZE) {
		return 2;
	}
	return 0; // Không có ai thắng
}
void countXO(int& countX, int& countO) {
	countX = 0;
	countO = 0;
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) {
				countO++; // Đếm O
			}
			else if (_A[i][j].c == -1) {
				countX++; // Đếm X
			}
		}
	}
}
void restartGame() {//chay trong load game
	SetConsoleOutputCP(1251);
	cout << "Bat dau tro choi...\n";

	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, FOREGROUND_BLUE | (15 << 4));

	FixConsoleWindow();

	int a, b;
	bool ValidEnter = true;

	reStartGame();
	Box1();
	Box2();
	Box3();
	Score2Player();
	GotoXY(LEFT + 2, TOP + 1); // Đưa con trỏ về ô đầu tiên
	for (int i = 0; i < BOARD_SIZE; i++) {
		for (int j = 0; j < BOARD_SIZE; j++) {
			if (_A[i][j].c == 1) {
				GotoXY((j + 1) * 5, (i + 1) * 2);
				cout << "O";
			}
			else if (_A[i][j].c == -1) {
				GotoXY((j + 1) * 5, (i + 1) * 2);
				cout << "X";
			}
		}
	}
	resetData();

	// Đếm X và O để xác định lượt chơi tiếp theo
	int countX, countO;
	countXO(countX, countO);
	_TURN = (countX <= countO); // Nếu số lượng X <= O, thì lượt chơi là của X
	if (_TURN == 1) DrawX(89 + 2, 17);
	else DrawO(89 + 2, 17);
	while (1) {
		_COMMAND = toupper(_getch());
		if (_COMMAND == 27) { // Nếu người chơi bấm Esc
			Sleep(500);
			//system("pause");
			Sleep(500);scoreP1 = 0;
			scoreP2 = 0;
			system("cls");
			_COMMAND == 27;
			return;
		}
		else {
			if (_COMMAND == 'A') MoveLeft();
			else if (_COMMAND == 'W') MoveUp();
			else if (_COMMAND == 'S') MoveDown();
			else if (_COMMAND == 'D') MoveRight();
			else if (_COMMAND == 'L') {
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo(hStdOut, &csbi);
				int bottomRow = csbi.srWindow.Bottom;  // Lấy hàng cuối cùng của cửa sổ console
				GotoXY(0, bottomRow);
				SaveGameWithFileName();  // Gọi hàm để lưu game với tên file người chơi nhập
			}
			else if (_COMMAND == 13) { // Nếu người chơi bấm Enter
				switch (CheckBoard(_X, _Y)) {
				case -1: // Nếu ô có người chơi O
					SetConsoleTextAttribute(hStdOut, 12 | (15 << 4));
					cout << "X";
					_B[_X][_Y] = -1; // Cập nhật bàn cờ
					GotoXY(0, 0);
					DrawO(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));

					cout << "den O  "; SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));

					break;
				case 1: // Nếu ô có người chơi X
					SetConsoleTextAttribute(hStdOut, 0 | (15 << 4));
					cout << "O";
					_B[_X][_Y] = 1; // Cập nhật bàn cờ
					GotoXY(0, 0);
					DrawX(89 + 2, 17);SetConsoleTextAttribute(hStdOut, 1 | (15 << 4));
					cout << "den X "; SetConsoleTextAttribute(hStdOut, 1 | (15 << 4));
					break;
				case 0: // Nếu ô trống
					ValidEnter = false; // Không làm gì, ô đã có X hoặc O
				}
				if (ValidEnter == true) {
					int winStatus = checkWinCondition(); // Hàm kiểm tra thắng
					if (winStatus != 0)
					{
						SetConsoleOutputCP(CP_UTF8);

						// Đường dẫn đến file âm thanh
						LPCWSTR filePath = L"Music\\victory.wav"; // Sử dụng đường dẫn đến file âm thanh

						// Phát âm thanh
						PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);
						if (winStatus == -1) {
							scoreP1 += 1;
							int demnguoc = 7;
							while (demnguoc > 0) {
								DrawX(71, 9);
								DrawWIN();
								Sleep(150);
								DrawBlank();
								Sleep(150);
								DrawX(71, 9);
								DrawWIN();

								demnguoc--;

							}

						}
						else if (winStatus == 1)
						{
							scoreP2 += 1;
							int demnguoc = 7;
							while (demnguoc > 0) {
								DrawO(71, 9);
								DrawWIN();
								Sleep(150);
								DrawBlank();
								Sleep(150);
								DrawO(71, 9);
								DrawWIN();

								demnguoc--;

							}

						}
						else if (winStatus == 2)
						{
							int demnguoc = 7;
							while (demnguoc > 0) {

								DrawTIE();
								Sleep(150);
								DrawBlank();
								Sleep(150);

								DrawTIE();

								demnguoc--;

							}
						}
						if (AskContinue() != 'Y') {
							//system("pause");
							Sleep(500);
							ResetKetqua(_B);
							system("cls");
							_COMMAND == 27;
							return;
						}
						else {
							ResetKetqua(_B);
							startGame(); // Khởi động lại trò chơi
						}
					}

					switch (ProcessFinish(TestBoard())) {
					case -1:
					case 1:
					case 0:
						SetConsoleOutputCP(CP_UTF8);

						// Đường dẫn đến file âm thanh
						LPCWSTR filePath = L"Music\\victory.wav"; // Sử dụng đường dẫn đến file âm thanh

						// Phát âm thanh
						PlaySound(filePath, NULL, SND_FILENAME | SND_ASYNC);

						// Giữ console mở trong một khoảng thời gian

						if (AskContinue() != 'Y') {
							//system("pause");
							Sleep(500);
							ResetKetqua(_B);
							system("cls");
							_COMMAND == 27;
							return;
						}
						else {
							ResetKetqua(_B);
							startGame(); // Khởi động lại trò chơi
						}
					}
				}
				ValidEnter = true; // Reset biến ValidEnter cho lượt tiếp theo
			}
		}
	}
}
void reStartGame() {
	system("cls");
	DrawBoard(BOARD_SIZE);

}
void resetData() {
	for (int i = 0;i < BOARD_SIZE;i++) {
		for (int j = 0;j < BOARD_SIZE;j++) {
			_A[i][j].x = 5 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;

		}
	}
	_TURN = true;_COMMAND = -1;
	_X = _A[0][0].x;_Y = _A[0][0].y;
}

//final