#include "modules/libs.h"

int main(){
  Route::initialize();

  mainMenu:
    std::system("cls");
    std::cout<<"1. barista"<<std::endl;
    std::cout<<"2. kasir"<<std::endl;
    std::cout<<"3. order"<<std::endl;
    std::cout<<"4. exit"<<std::endl;
    
    int opt;
    std::cin>>opt;
  
    if (opt == 1)
    {
      std::system("cls");
      // Route::Barista();
      goto mainMenu;
      
    }
    else if(opt==2)
    {
      std::system("cls");
      // Route::Kasir();
      goto mainMenu;

    }
    else if(opt==3)
    {
      std::system("cls");
      Route::order();
      goto mainMenu;
    }

    std::system("cls");
}