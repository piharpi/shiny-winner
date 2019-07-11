void Route::Barista(void){
  int opt;
  do {
    std::cout<<"1. tambah daftar kopi"<<std::endl;
    std::cout<<"2. lihat pesanan"<<std::endl;
    std::cout<<"3. hapus pesanan"<<std::endl;
    std::cout<<"4. kembali"<<std::endl;

    std::cout<<std::endl<<"masukkan pilihan = ";std::cin>>opt;

    if (opt==1){
      // std::system("cls");
      // Route::add_coffee();
      // std::system("cls");
      // std::cout<<std::endl;
    }else if(opt ==2){
      std::system("cls");
      Route::show_queues();
      std::system("cls");
      std::cout<<std::endl;
    }else if(opt ==3){
      std::system("cls");
      Route::delete_queues();
      std::system("cls");
      std::cout<<std::endl;
    }
  }while(opt!=4);
}
