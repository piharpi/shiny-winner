void Route::Barista(void){
  int opt;
  do {
    std::cout<<"1. tambah daftar kopi"<<std::endl;
    std::cout<<"2. edit kopi"<<std::endl;
    std::cout<<"3. hapus kopi"<<std::endl;
    std::cout<<"4. lihat pesanan"<<std::endl;
    std::cout<<"5. hapus pesanan"<<std::endl;
    std::cout<<"6. kembali"<<std::endl;

    std::cout<<std::endl<<"masukkan pilihan = ";std::cin>>opt;

    if (opt==1){
      std::system("cls");
      Route::add_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==2){
      std::system("cls");
      // Route::edit_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==3){
      std::system("cls");
      Route::delete_coffees();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==4){
      std::system("cls");
      Route::show_queues();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==5){
      std::system("cls");
      Route::delete_queues();
      std::system("cls");
      std::cout<<std::endl;
    }
  }while(opt!=6);
}
