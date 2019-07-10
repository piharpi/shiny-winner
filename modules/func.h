std::vector<Model::Coffee> goods;
std::vector<Model::Order> orders;

void Route::initialize(void)
{
  std::ifstream is("./collection/coffees.csv");
	
	std::string item;
	while(std::getline(is, item))
	{
		int begin = 0;
		int pos = item.find(",");
		std::string id = item.substr(begin, pos);
		
		begin = pos + 1;
		pos = item.find(",", begin);
		std::string name = item.substr(begin, pos - begin);
		
		begin = pos + 1;
		std::string price = item.substr(begin);
		
		goods.push_back({id, name, stod(price)});
	}
	
	is.close();
}

void Route::show_coffees(void)
{
	struct Model::Coffee temp;
  // temp dibuat untuk menyimpan perubahan sementara,
  // dimana perubahan diambil dari objek coffee
  // sebelumnya (cf[]), karna kembalian data berupa string name & int price 
  auto len = sizeof(goods);
  //len => panjang array struct coffee
	// std::cout << len << " buah";
  for(auto i=1;i<=len;i++){ // melakukan sorting bubble sort secara ascending
    for(auto j=0;j<len-i;j++){
      if(goods[j].Price > goods[j+1].Price){
        temp = goods[j+1];
        goods[j+1] = goods[j];
        goods[j] = temp;
      }
    }
  }

  for (auto good : goods)
  {
    std::cout << good.Id;
    std::cout << "- " << good.Name << "\n";
    std::cout << "Harga : " << good.Price << "\n";
  }

  char Y;
  std::cout<<std::endl<<"Tekan apapun untuk kembali"; std::cin >>Y;
}

void Route::search_coffees(void) // squential searching
{
	Model::Coffee coffee;
  bool found = false;
  std::string name;
  char Y;
	do 
	{
		std::cout << "Cari nama kopi : ";std::cin>>name;

		for (auto good : goods)
		{
			if (good.Name == name)
			{
				found = true;
				coffee = good;
			}
		}

		if (found){
			std::cout<<"Informasi kopi\n";
			std::cout<<"ID : "<< coffee.Id << "\nNama : "<< coffee.Name <<"\nHarga : "<<coffee.Price<<std::endl;
			std::cout<<"\ningin melakukan pencarian kembali?(y) ";std::cin>>Y;
			std::system("cls");
		}
		else
		{
			std::cout<<"Kopi \"" << name << "\" yang anda cari tidak ditemukan"<<std::endl;
			std::cout<<"\ningin melakukan pencarian kembali?(y) ";std::cin>>Y;
			std::system("cls");
		}
	} while (Y == 'y');
}

void Route::order(){
  char Y; 
  do{
    std::cout<<"nama pemesan : ";std::cin>>orders[k].py.od.name;
    std::cout<<"nama kopi : ";std::cin>>orders[k].py.od.kopi;
    std::cout<<"jumlah : ";std::cin>>orders[k].py.od.totalOrder;
    Payment();
    std::cout<<std::endl;
    enQueue();
    std::cout<<std::endl<<"apakah ingin memesan lagi? (y/n)";std::cin>>plh;
  }while(Y=='y');
}