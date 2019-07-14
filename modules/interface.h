#include "windows.h"

namespace Interface {

   // mengubah ukuran console
   void setWindowSize(int width, int height) {
      HWND console = GetConsoleWindow();
      RECT r;
      GetWindowRect(console, &r);

      // Move Window
      MoveWindow(console,  r.left, r.top, width, height, TRUE);
   }

   // mengubah arah cursor pada console
   void xy(int x, int y) {
      COORD coord;
      coord.X = x;
      coord.Y = y;

      SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
   }

   // untuk membuat garis
   void drawX(int positionX, int positionY, int width, int character) {
      for(int i{}; i <= width; i++) {
        xy(positionX + i,positionY); std::cout << char(character);
      }
   }

    void drawY(int positionX, int positionY, int height, int character) {
      for(int i{}; i <= height; i++) {
        xy(positionX,positionY + i); std::cout << char(character);
      }
    }

    void color(const short fcol, const short bcol) {
      const short fc = fcol < 0  ? 0 :
              fcol > 15 ? 15:
              fcol;
              
      const short bc = bcol < 0  ? 0 :
              bcol > 15 ? 15:
              bcol;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bc * 16 + fc);
	}
}