#define MAX 3

std::vector<Model::Coffee> goods;
std::vector<Model::Order> orders;
std::vector<Model::Payment> payments;

struct Queue
{
	struct Model::Payment payments[MAX];
	int head, tail;        
}queues;

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
    std::cout << " - " << good.Name << "\n";
    std::cout << "Harga : " << good.Price << "\n";
  }

  std::cout<<std::endl<<"Tekan apapun untuk kembali";
	getch();
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

bool full() 
{
	if (queues.tail == MAX - 1)
	{
		return true;
	} else {
		return false;
	}
}

bool empty() 
{
	if (queues.tail == -1)
	 {
	 	return true;
	 } else {
	 	return false;	
	 }
}

void Route::show_queues()
{
	int i;
	if (!empty())
	{
		for (int i = queues.head; i < queues.tail; i++)
		{
			std::cout <<  queues.payments[i].Order.Coffee<<" - ";
			std::cout <<  queues.payments[i].Order.Name<<" - ";
			std::cout <<  queues.payments[i].Order.Qty<<" - ";
			std::cout <<  queues.payments[i].Total<<"\n";
		}
	} 
	else 
	{
		std::cout << " Data kosong "; 
	}
	// for(auto pay : queues.payments)
	// {
	// 	std::cout << pay.Order.Coffee << " - "; 
	// 	std::cout << pay.Order.Name << " - "; 
	// 	std::cout << pay.Order.Qty << "-"; 
	// 	std::cout << pay.Total << "\n"; 
	// }
	
	std::cout<<std::endl<<"Tekan apapun untuk kembali";
	getch();
}

void Route::delete_queues(){
	int i;

	if (!empty())
	{
		std::cout << "\nMengambil data\" "<<queues.payments[queues.head].Order.Name<<" - "<<queues.payments[queues.head].Order.Coffee<<" \"..."<<std::endl;
		for (i = queues.head; i < queues.tail; i++)
		{
			// std::cout << "ini i" << i; 
			// std::cout << "\nini i+1" << i+1; 	
			queues.payments[i] = queues.payments[i+1];
		// getchar();

		}
		queues.tail--;
		// getchar();
	} else {
		std::cout << "Antrean kosong";
	}
}


void Route::order(void){ // fungsi inqueue
	// initqueues();

  char Y; 
	std::string name, coffee, qty;
	double total;	

	do{
		std::system("cls");
		bool found= false;
		double price = 0;
		if (!full())
		{
			std::cout<<"nama pemesan : ";std::cin>>name;
			std::cout<<"nama kopi : ";std::cin>>coffee;
			std::cout<<"jumlah : ";std::cin>>qty;
			// orders.push_back({name, coffee, stoi(qty)});
			// penjumlahan total pembayaran
			for (auto good : goods)
			{
				if (good.Name == coffee)
				{
					found=true;
					price= good.Price;
					// lists.push_back({{{name, coffee, stoi(qty)}, total}});
				} 
			}
			if(found == true){
				total = price * stoi(qty);
				queues.payments[queues.tail].Order.Coffee = coffee;
				queues.payments[queues.tail].Order.Name = name;
				queues.payments[queues.tail].Order.Qty = stoi(qty);

				queues.payments[queues.tail].Total = total;
				queues.tail++;
			} else {
				std::cout<<"Kopi tidak ada "; 
			}
			std::cout << queues.tail;
			getchar();
		} else { std::cout<<"Antrian penuh harap bersabar"; }

		std::cout<<std::endl;
		std::cout<<std::endl<<"apakah ingin memesan lagi? (y/n)";std::cin>>Y;
	}while(Y=='y');
}