#include "modules/libs.h"

void drawMainMenu() {
  Interface::xy(2,1); Interface::color(0,7); 
  std::cout << " MAIN MENU:     " << std::endl;
  Interface::color(7,0);
  Interface::xy(2,3); std::cout<<"[1] BARISTA"<<std::endl;
  Interface::xy(2,4); std::cout<<"[2] KASIR"<<std::endl;
  Interface::xy(2,5); std::cout<<"[3] PELANGGAN"<<std::endl;
  Interface::xy(2,6); std::cout<<"[0] KELUAR"<<std::endl;

  // table kopi
  Interface::xy(20,1); Interface::color(0,7);
  std::cout << " ID   ";
  Interface::xy(27,1); std::cout << " NAMA                     ";
  Interface::xy(50,1); std::cout << " HARGA    ";
  Interface::color(7,0);
  Interface::drawX(20,2, 39, 205);
  Interface::drawY(26, 3, 20, 186);
  Interface::drawY(50, 3, 20, 186);
  Interface::drawY(20,3,20,186);
  Interface::drawY(59,3,20,186);
  Interface::xy(20,2); std::cout << char(201);
  Interface::xy(26,2); std::cout << char(203);
  Interface::xy(50,2); std::cout << char(203);
  Interface::xy(59,2); std::cout << char(187);
  
  Interface::drawX(20,23, 39, 205);
  Interface::xy(20,23); std::cout << char(200);
  Interface::xy(26,23); std::cout << char(202);
  Interface::xy(50,23); std::cout << char(202);
  Interface::xy(59,23); std::cout << char(188);
  auto s = goods.size();
  for(int i=0; i<s; i++)
  {
    Interface::xy(22,3 + i); std::cout << goods[i].Id;
    Interface::xy(28,3 + i); std::cout << goods[i].Name;
    Interface::xy(52,3 + i); std::cout << goods[i].Price;
  }

  // table order
  Interface::xy(65,1); Interface::color(0,7); std::cout << " ID   ";
  Interface::xy(70,1); std::cout << " KOPI                     ";
  Interface::xy(90,1); std::cout << " PELANGGAN          ";
  Interface::xy(110,1); std::cout << " QTY ";
  Interface::xy(115,1); std::cout << " TOTAL     ";
  Interface::color(7,0);
  
  Interface::drawX(65, 2, 60, 205);
  Interface::drawY(65, 3, 20, 186);
  Interface::drawY(70, 3, 20, 186);
  Interface::drawY(90, 3, 20, 186);
  Interface::drawY(110,3, 20,186);
  Interface::drawY(115,3,20,186);
  Interface::drawY(125,3,20,186);
  Interface::xy(65,2); std::cout << char(201);
  Interface::xy(70,2); std::cout << char(203);
  Interface::xy(90,2); std::cout << char(203);
  Interface::xy(110,2); std::cout << char(203);
  Interface::xy(115,2); std::cout << char(203);
  Interface::xy(125,2); std::cout << char(187);
  
  Interface::drawX(65, 23, 60, 205);
  Interface::xy(65,23); std::cout << char(200);
  Interface::xy(70,23); std::cout << char(202);
  Interface::xy(90,23); std::cout << char(202);
  Interface::xy(110,23); std::cout << char(202);
  Interface::xy(115,23); std::cout << char(202);
  Interface::xy(125,23); std::cout << char(188);
	int i;
	if (!empty())
	{
		for (int i = queues.head; i < queues.tail; i++)
		{
			Interface::xy(65,1); std::cout << queues.payments[i].Id;
			Interface::xy(70,1); std::cout << queues.payments[i].Order.Coffee;
			Interface::xy(90,1); std::cout << queues.payments[i].Order.Name;
			Interface::xy(110,1); std::cout << queues.payments[i].Order.Qty;
			Interface::xy(115,1); std::cout << queues.payments[i].Total;
    }
	} 
	else 
	{
    Interface::color(7,4);
		Interface::xy(85,12); std::cout << " DATA KOSONG "; 
    Interface::color(7,0);
	}
}

int main(){
  Interface::setWindowSize(1060, 700);
  Route::initialize();

  mainMenu:
    std::system("cls");
    drawMainMenu();
    
    // INPUT SELECTION
    int opt;
    Interface::drawX(2,8, 12, 205);
    Interface::xy(1,8); std::cout << char(201);
    Interface::xy(1,9); std::cout << char(186);
    Interface::xy(1,10); std::cout << char(200);
    Interface::xy(14,8); std::cout << char(187);
    Interface::xy(14,9); std::cout << char(186);
    Interface::drawX(2,10, 12, 205);
    Interface::xy(14,10); std::cout << char(188);
    Interface::xy(3,9); std::cout << char(175) << " ";
    std::cin >> opt;

    if (opt == 1)
    {
      std::system("cls");
      Route::Barista();
      goto mainMenu;
      
    }
    else if(opt==2)
    {
      std::system("cls");
      Route::Cashier();
      goto mainMenu;

    }
    else if(opt==3)
    {
      std::system("cls");
      Route::Customer();
      goto mainMenu;
    }

    std::system("cls");
}