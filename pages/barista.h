void drawBaristaMenu() {
  Interface::xy(2,1); Interface::color(0,7); 
  std::cout << " MENU BARISTA: " << std::endl;
  Interface::color(7,0);

  Interface::xy(2,3); std::cout<<"[1] TBH DFTR KOPI"<<std::endl;
  Interface::xy(2,4); std::cout<<"[2] EDIT KOPI"<<std::endl;
  Interface::xy(2,5); std::cout<<"[3] HPS KOPI"<<std::endl;
  // Interface::xy(2,5); std::cout<<"[4] LHT PESANAN"<<std::endl;
  Interface::xy(2,6); std::cout<<"[4] HPS ANTRIAN"<<std::endl;
  Interface::xy(2,7); std::cout<<"[0] KEMBALI"<<std::endl;

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
  Interface::xy(70,1); std::cout << "      KOPI                ";
  Interface::xy(90,1); std::cout << "   PELANGGAN        ";
  Interface::xy(110,1); std::cout << " QTY ";
  Interface::xy(115,1); std::cout << "   TOTAL      ";
  Interface::xy(125,1); std::cout << "   STATUS      ";
  Interface::color(7,0);
  
  Interface::drawX(65, 2, 74, 205);
  Interface::drawY(65, 3, 20, 186);
  Interface::drawY(73, 3, 20, 186);
  Interface::drawY(90, 3, 20, 186);
  Interface::drawY(110,3, 20,186);
  Interface::drawY(115,3,20,186);
  Interface::drawY(125,3,20,186);
  Interface::drawY(139,3,20,186);
  Interface::xy(65,2); std::cout << char(201);
  Interface::xy(73,2); std::cout << char(203);
  Interface::xy(90,2); std::cout << char(203);
  Interface::xy(110,2); std::cout << char(203);
  Interface::xy(115,2); std::cout << char(203);
  Interface::xy(125,2); std::cout << char(203);
  Interface::xy(139,2); std::cout << char(187);
  
  Interface::drawX(65, 23, 74, 205);
  Interface::xy(65,23); std::cout << char(200);
  Interface::xy(73,23); std::cout << char(202);
  Interface::xy(90,23); std::cout << char(202);
  Interface::xy(110,23); std::cout << char(202);
  Interface::xy(115,23); std::cout << char(202);
  Interface::xy(125,23); std::cout << char(202);
  Interface::xy(139,23); std::cout << char(188);

	int i;
	if (!empty())
	{
		for (int i = queues.head; i < queues.tail; i++)
		{
			Interface::xy(67,3+i); std::cout << queues.payments[i].Id;
			Interface::xy(75,3+i); std::cout << queues.payments[i].Order.Coffee;
			Interface::xy(92,3+i); std::cout << queues.payments[i].Order.Name;
			Interface::xy(112,3+i); std::cout << queues.payments[i].Order.Qty;
			Interface::xy(117,3+i); std::cout << queues.payments[i].Total;
      if(queues.payments[i].Status)
      {
        Interface::color(0,2);
			  Interface::xy(127,3+i); std::cout << "   LUNAS   ";
        Interface::color(7,0);
      } else {
        Interface::color(0,4);
			  Interface::xy(127,3+i); std::cout << " BLM LUNAS ";
        Interface::color(7,0);
      }
    }
	} 
	else 
	{
    Interface::color(7,4);
		Interface::xy(85,12); std::cout << " DATA KOSONG "; 
    Interface::color(7,0);
	}
}

void Route::Barista(void){
  int opt;
  do {

    drawBaristaMenu();
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

    if (opt==1){
      std::system("cls");
      Route::add_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==2){
      std::system("cls");
      Route::edit_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==3){
      std::system("cls");
      Route::delete_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }
    // else if(opt ==4){
    //   std::system("cls");
    //   Route::show_queues();
    //   std::system("cls");
    //   std::cout<<std::endl;
    // }
    else if(opt ==4){
      std::system("cls");
      Route::delete_queues();
      std::system("cls");
      std::cout<<std::endl;
    }
  }while(opt!=0);
}
