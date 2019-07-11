void Route::Cashier(){
  int opt;
  do{
    std::cout<<"===kasir==="<<std::endl;
    std::cout<<"1. pembayaran"<<std::endl;
    std::cout<<"2. kembali"<<std::endl;
    std::cout<<std::endl<<"masukkan pilihan";std::cin>>opt;
    if (opt==1){
      std::system("cls");
      Route::paid();
      std::cout<<std::endl;
    }
  }while(opt!=2);
}