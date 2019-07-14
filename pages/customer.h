void drawCustomerMenu() {
  Interface::xy(2,1); Interface::color(0,7); 
  std::cout << " PELANGGAN:     " << std::endl;
  Interface::color(7,0);
  Interface::xy(2,3); std::cout<<"[1] CARI KOPI"<<std::endl;
  Interface::xy(2,4); std::cout<<"[2] PESAN KOPI"<<std::endl;
  Interface::xy(2,5); std::cout<<"[0] KEMBALI"<<std::endl;

  // table
  Interface::xy(20,1); Interface::color(0,7);
  std::cout << " ID   ";
  Interface::xy(27,1); std::cout << " NAME                     ";
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
}

void Route::Customer(void){

  int opt;
  do{
    drawCustomerMenu();
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
      Route::search_coffees();
      std::system("cls");
    }else if(opt==2){
      std::system("cls");
      Route::order();
      std::system("cls");
    }
  }while(opt!=0);

}
