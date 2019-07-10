void Route::order(void){
    int opt;
    do{
    std::cout<<"====pelanggan====="<<std::endl;
    std::cout<<"1. lihat daftar kopi"<<std::endl;
    std::cout<<"2. search nama kopi"<<std::endl;
    std::cout<<"3. pesan"<<std::endl;
    std::cout<<"4. kembali"<<std::endl;
    std::cout<<std::endl<<"masukkan pilihan ";std::cin>>opt;

    if (opt==1){
      std::system("cls");
      std::cout << "DAFTAR KOPI\n";
      Route::show_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt==2){
      std::system("cls");
      Route::search_coffees();
    }else if(opt==3){
      std::system("cls");
      Route::order();
      std::system("cls");
      std::cout<<std::endl;
    }
  }while(opt!=4);

}
