#define MAX 3

std::vector<Model::Coffee> goods;
std::vector<Model::Order> orders;
std::vector<Model::Payment> payments;

int lastid{};

struct Queue
{
	struct Model::Payment payments[MAX];
	int head, tail;        
}queues;

void Route::initialize(void)
{
	goods.clear();

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
		lastid = stoi(id);
	}
	
	is.close();
}

void Route::show_coffees(void)
{
	struct Model::Coffee temp;
  // temp dibuat untuk menyimpan perubahan sementara,
  // dimana perubahan diambil dari objek coffee
  // sebelumnya (cf[]), karna kembalian data berupa string name & int price 

  auto len = goods.size();
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
			std::cout<<"payrmasi kopi\n";
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

bool full(void) 
{
	if (queues.tail == MAX - 1)
	{
		return true;
	} else {
		return false;
	}
}

bool empty(void) 
{
	if (queues.tail == 0)
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
			std::cout <<  queues.payments[i].Id<<" - ";
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
	
	std::cout<<std::endl<<"Tekan apapun untuk kembali";
	getch();
}

void Route::delete_queues()
{
	int i;

	if (!empty())
	{
		if(queues.payments[queues.head].Status == false){
			std::cout << "Belum lunas";
			getch();
		}else {
			std::cout << "\nMengambil data\" "<<queues.payments[queues.head].Order.Name<<" - "<<queues.payments[queues.head].Order.Coffee<<" \"..."<<std::endl;
			for (i = queues.head; i < queues.tail; i++)
			{	
				queues.payments[i] = queues.payments[i+1];
			}
			queues.tail--;
		}
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
				queues.payments[queues.tail].Id = "ORD"+std::to_string(queues.tail);
				queues.payments[queues.tail].Order.Coffee = coffee;
				queues.payments[queues.tail].Order.Name = name;
				queues.payments[queues.tail].Order.Qty = stoi(qty);

				queues.payments[queues.tail].Total = total;
				queues.payments[queues.tail].Status = false;
				queues.tail++;

				std::ofstream odb("collection/log.csv", std::ios::app);
				odb	<< name << " Telah memesan " 
						<< qty << " Kopi " 
						<< coffee << " dengan total harga Rp." 
						<< total << '\n';

				odb.close();
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

void Route::paid(void)
{
	std::string id;
  int money;
	if (!empty())
	{
  	std::cout<<"masukkan id pesanan : ";std::cin>>id;
  	std::system("cls");
		for (int i = queues.head; i < queues.tail; i++)
		{
			if (queues.payments[i].Id == id)
			{
				std::cout<<"kode pemesanan        = "<<queues.payments[i].Id<<std::endl;
				std::cout<<"nama pemesan          = "<<queues.payments[i].Order.Name<<std::endl;
				std::cout<<"kopi yang dipesan     = "<<queues.payments[i].Order.Coffee<<std::endl;
				std::cout<<"jumlah pesanan        = "<<queues.payments[i].Order.Qty<<std::endl;
				std::cout<<"total pembayaran      = "<<queues.payments[i].Total<<std::endl;

				std::cout<<"uang yang dibayarkan  = ";std::cin>>money;

				//validasi apakah uang lebih atau kurang
				if (money >= queues.payments[i].Total){
					queues.payments[i].Status = true;

					std::cout<<"jumlah uang kembalian = "<<money - queues.payments[i].Total<<std::endl;
				}else{ std::cout<<"uang anda kurang"<<std::endl; }	
			} 
		}

		char Y;
		std::cout<<"ingin transaksi lagi?(y)";std::cin>>Y;
		std::system("cls");
	} 
	else 
	{
		std::cout << " Data kosong "; 
	}
}

void store_coffees(Model::Coffee cof)
{
	std::ofstream odb("collection/coffees.csv", std::ios::app);
	odb	<< cof.Id << "," 
			<< cof.Name << "," 
			<< cof.Price << '\n';

	odb.close();

	Route::initialize();
}

void Route::add_coffees()
{
	lastid++;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::string name;

	std::string id = std::to_string(lastid);
	double price;

	std::cout << "Name :"; std::getline(std::cin, name);
	std::cout << "Price :"; std::cin >> price;

	store_coffees({id, name, price});
}

void Route::delete_coffees()
{
	std::string id{};

	std::ofstream temp;
	temp.open("collection/coffees_temp.csv");

	std::cout << "Masukkan id kopi = "; std::cin>>id;

	for(auto c:goods) {
		if(c.Id != id) {
			temp << c.Id << ',';
			temp << c.Name << ',';
			temp << c.Price << std::endl;
		}
	}
	
	temp.close();
	remove("collection/coffees.csv");
	rename("collection/coffees_temp.csv", "collection/coffees.csv");

	Route::initialize();
}

void Route::edit_coffees()
{
	std::string id{};

	std::ofstream temp;
	temp.open("collection/coffees_temp.csv");

	std::cout << "Masukkan id kopi = "; std::cin>>id;

	for(auto c:goods) {
		if(c.Id != id) {
			temp << c.Id << ',';
			temp << c.Name << ',';
			temp << c.Price << '\n';
		}
	}
	
	temp.close();
	remove("collection/coffees.csv");
	rename("collection/coffees_temp.csv", "collection/coffees.csv");

	Route::initialize();

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
	std::string name;
	double price;

	std::cout << "Name :"; std::getline(std::cin, name);
	std::cout << "Price :"; std::cin >> price;

	store_coffees({id, name, price});
}

