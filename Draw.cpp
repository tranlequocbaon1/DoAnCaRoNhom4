#pragma once
#include<Windows.h>
#include "Header.h"
#include <iostream>

using namespace std;

void SetColor(int mauchu, int mauBg) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (mauBg << 4) | mauchu);
}

void DrawWIN() {
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(LEFT + 81, TOP + 9);

	//dong 1/6
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄    ";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄ ";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄ ";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄▄   ";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";


	//dong 2/6
	GotoXY(LEFT + 81, TOP + 10);
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█    ";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█ ";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 14);//tren den duoi vang
	cout << u8"▄";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 14);//tren den duoi vang
	cout << u8"▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀ ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"████";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄ ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";

	//dong 3/6
	GotoXY(LEFT + 81, TOP + 11);
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█  ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█  ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"██";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";

	//dong 4/6
	GotoXY(LEFT + 81, TOP + 12);
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█  ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█  ";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█ ";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";

	//dong 5/6
	GotoXY(LEFT + 81, TOP + 13);
	SetColor(0, 15);//full den
	cout << u8"█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█ ";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vanag
	cout << u8"▄";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(14, 0);//tren den duoi vanag
	cout << u8"▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(0, 15);//full den
	cout << u8" █";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█   ▀█";
	SetColor(14, 0);//full vang
	cout << u8"██";
	SetColor(0, 15);//full den
	cout << u8"█";

	//dong 6/6
	GotoXY(LEFT + 81, TOP + 14);
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀    ▀";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀ ▀";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄▄▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀ ▀";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀    ▀";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(0, 15);//tren den duoi trang
	cout << u8"▀";


	SetColor(1, 15);
}


void DrawX(int x, int y) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 4);
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(LEFT + x, TOP + y);
	cout << u8"██▄   ▄██    ";
	GotoXY(LEFT + x, TOP + y + 1);
	cout << u8" ██▄ ▄██     ";
	GotoXY(LEFT + x, TOP + y + 2);
	cout << u8"  ▀█▄█▀      ";

	GotoXY(LEFT + x, TOP + y + 3);
	cout << u8"  ▄███▄      ";
	GotoXY(LEFT + x, TOP + y + 4);
	cout << u8" ██▀ ▀██     ";
	GotoXY(LEFT + x, TOP + y + 5);
	cout << u8"██▀   ▀██    ";
}
void DrawO(int x, int y) {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (15 << 4) | 0);
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(LEFT + x, TOP + y);
	cout << u8"  ▄█▀█▄      ";
	GotoXY(LEFT + x, TOP + y + 1);
	cout << u8"▄█▀   ▀█▄    ";
	GotoXY(LEFT + x, TOP + y + 2);
	cout << u8"█       █    ";
	GotoXY(LEFT + x, TOP + y + 3);
	cout << u8"█       █    ";
	GotoXY(LEFT + x, TOP + y + 4);
	cout << u8"▀█▄   ▄█▀   ";
	GotoXY(LEFT + x, TOP + y + 5);
	cout << u8"  ▀█▄█▀     ";

}
void DrawBlank() {
	for (int i = 0;i < 43;i++) {
		for (int j = 0;j < 6;j++) {
			GotoXY(LEFT + 70 + i, TOP + 9 + j);
			cout << " ";
		}
	}
}

void DrawTIE() {
	SetConsoleOutputCP(CP_UTF8);
	GotoXY(LEFT + 74, TOP + 9);

	//dong 1/6
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(10, 0);//tren den duoi xanh
	cout << u8"▄▄▄▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";

	cout << "  ";

	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(10, 0);//tren den duoi xanh
	cout << u8"▄▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";

	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";

	SetColor(15, 15);
	cout << "  ";

	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(10, 0);//tren den duoi xanh
	cout << u8"▄▄▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";

	cout << "    ";

	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(10, 0);//tren den duoi xanh
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";

	//dong 2/6
	GotoXY(LEFT + 74, TOP + 10);
	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(10, 10);//full xanhh
	cout << u8"███";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";

	SetColor(15, 15);
	cout << "  ";

	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";

	SetColor(15, 15);
	cout << "  ";


	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(10, 10);//full xanhh
	cout << u8"██";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";

	SetColor(15, 15);
	cout << "   ";

	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(0, 0);//tren den duoi den
	cout << u8"▄";

	//dong 3/6
	GotoXY(LEFT + 74, TOP + 11);
	SetColor(15, 15);//tren trang duoi trang
	cout << u8" ";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄▄";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄▄";

	SetColor(15, 15);
	cout << "    ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "   ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(10, 0);//tren den duoi xanh
	cout << u8"▄";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(0, 15);//tren xanh duoi vang
	cout << u8"▀";

	SetColor(15, 15);
	cout << "    ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(14, 14);//full vang
	cout << u8"█";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(10, 10);//full xanh
	cout << u8"██";
	SetColor(0, 0);//full den
	cout << u8"█";

	//dong 4/6
	GotoXY(LEFT + 74, TOP + 12);
	SetColor(15, 15);//tren trang duoi trang
	cout << u8"   ";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▄";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "      ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "   ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(14, 0);//tren vang duoi den
	cout << u8"▀";
	SetColor(10, 0);//tren vang duoi den
	cout << u8"▀▀";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(15, 0);//tren trang duoi den
	cout << u8"▀";

	SetColor(15, 15);
	cout << "    ";

	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 10);//tren xanh duoi den
	cout << u8"▄";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 0);//tren vang duoi den
	cout << u8"▀";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";

	//dong 5/6
	GotoXY(LEFT + 74, TOP + 13);
	SetColor(15, 15);//tren trang duoi trang
	cout << u8"   ";
	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 10);//full xanh
	cout << u8"█";
	SetColor(10, 14);//tren vang duoi xanh
	cout << u8"▀";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "     ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(14, 10);//tren vang duoi xanh
	cout << u8"▀";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "  ";

	SetColor(0, 0);//full den
	cout << u8"█";
	SetColor(14, 10);//tren vang duoi xanh
	cout << u8"▀";
	SetColor(10, 10);//full xanh
	cout << u8"███";
	SetColor(10, 14);//tren xanh duoi vang
	cout << u8"▀";
	SetColor(14, 14);//full vang
	cout << u8"██";
	SetColor(0, 0);//full den
	cout << u8"█";

	SetColor(15, 15);
	cout << "    ";

	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";
	SetColor(14, 0);//tren den duoi vang
	cout << u8"▄▄";
	SetColor(0, 15);//tren trang duoi den
	cout << u8"▄";

	GotoXY(LEFT + 74, TOP + 14);
	SetColor(15, 15);//tren trang duoi trang
	cout << u8"   ";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";

	SetColor(15, 15);
	cout << "     ";

	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄";
	SetColor(0, 10);//tren xanh duoi den
	cout << u8"▄▄";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";

	SetColor(15, 15);
	cout << "  ";

	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 10);//tren xanh duoi den
	cout << u8"▄▄▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄▄▄";
	SetColor(0, 10);//tren xanh duoi den
	cout << u8"▄";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";

	SetColor(15, 15);
	cout << "    ";

	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(0, 14);//tren vang duoi den
	cout << u8"▄";
	SetColor(0, 10);//tren xanh duoi den
	cout << u8"▄";
	SetColor(15, 0);//tren den duoi trang
	cout << u8"▄";
	SetColor(1, 15);
}

void DrawHeart(int x,int y) {
	int mang[8][9] = {
		{15,0,0,0,15,0,0,0,15},
		{0,12,12,12,0,12,12,12,0},
		{0,12,12,12,12,12,12,12,0},
		{0,12,12,12,12,12,12,12,0},
		{15,0,12,12,12,12,12,0,15},
		{15,15,0,12,12,12,0,15,15},
		{15,15,15,0,12,0,15,15,15},
		{15,15,15,15,0,15,15,15,15}
	};
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 8; i+=2)
	{
		GotoXY(x, y+i/2);
		for (int x = 0; x < 9; x++) {
			SetColor(mang[i+1][x], mang[i][x]);
			cout << u8"▄";
		}
		cout << endl;
	}
}

void DrawMinion1(int x, int y) {

	int mang[30][18] = {
		{15,15,15,14,14,14,14,14,15,15,15},
		{15,15,14,14,14,14,14,14,14,15,15},
		{15,14,14,8,8,14,8,8,14,14,15	},
		{15,8,8,15,15,8,15,15,8,8,15},
		{15,8,8,15,0,8,15,0,8,8,15},
		{15,14,14,8,8,14,8,8,14,14,15},
		{15,14,14,0,14,14,14,0,14,14,15},
		{15,14,14,14,0,0,0,14,14,14,15},
		{15,14,14,14,14,14,14,14,14,14,15},
		{15,3,14,14,14,14,14,14,14,3,15},
		{15,14,3,0,3,3,3,0,3,14,15},
		{15,14,14,3,3,3,3,3,14,14,15},
		{15,14,14,3,3,0,3,3,14,14,15},
		{15,14,14,3,3,3,3,3,14,14,15},
		{15,14,3,3,3,3,3,3,3,14,15},
		{0,0,3,3,3,3,3,3,3,0,0},
		{15,0,3,3,3,3,3,3,3,0,15},
		{15,15,15,0,0,15,0,0,15,15,15},
		{15,15,0,0,0,15,0,0,0,15,15},
		{15,15,15,15,15,15,15,15,15,15,15,15,}
	};
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 19; i+=2)
	{
		GotoXY(x,y+i/2);
		for (int x = 0; x < 11; x++) {
			SetColor(mang[i+1][x],mang[i][x]);

			cout << u8"▄";
		}
		std::cout << endl;

	}
}
void DrawMinion2(int x, int y) {
	int mang2[16][12] = {
		{15,15,14,14,14,14,14,14,15,15,15,15},
		{15,14,14,14,14,8 ,8 ,14,14,15,15,15},
		{15,0 ,0 , 0, 8,15,15, 8, 0,15,15,15},
		{15, 0, 0, 0, 8,15, 0, 8,0 ,15,15,15},
		{15,14,14,14,14, 8, 8,14,14,15,15,15},
		{15,14,14,14,0,14,14,14,14,15,15,15},
		{15,14,14,14,14, 0, 0,14,14,15,15,15},
		{15, 1,14,14,14,14,14,14,1 ,15,15,15},
		{15,14, 1, 1, 1, 1, 1, 1,14,15, 0,15},
		{15,14,14, 1, 1, 1, 1,14,14,14, 0, 0},
		{15,14, 1, 1, 1, 1, 1, 1,14,15,15,15},
		{15,14, 1, 1, 1, 1, 1, 1,14,14,15,15},
		{0 ,0 , 1, 1, 1, 1, 1, 1, 1,15,15,15},
		{15, 0,15, 0, 0,15, 0, 0,15,15,15,15},
		{15,15,0 , 0,0 ,15, 0, 0, 0,15,15,15},
		{15 ,15 , 15, 15, 15, 15, 15, 15, 15, 15,15 ,15,}

	};
	
	SetConsoleOutputCP(CP_UTF8);
	for (int i = 0; i < 15; i+=2)
	{
		GotoXY(x, y+i/2);
		for (int x = 0; x < 12; x++) {
			SetColor(mang2[i + 1][x], mang2[i][x]);

			cout << u8"▄";
		}
		std::cout << endl;

	}
}


