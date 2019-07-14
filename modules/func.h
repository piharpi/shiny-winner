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
		
		if(lastid < stoi(id))
		{
			lastid = stoi(id);
		}
	}
	
	is.close();

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
}

void Route::show_coffees(void)
{
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
	  Interface::xy(60,15); Interface::color(0,7); 
  	std::cout << " PENCARIAN KOPI ";
		Interface::color(7,0); 
    Interface::xy(60,17); std::cout << char(175) << " ";
		
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, name);

		for (auto good : goods)
		{
			if (good.Name == name)
			{
				found = true;
				coffee = good;
			}
		}

		if (found){
			std::system("cls");
			
			Interface::xy(60,15); Interface::color(0,7); 
  		std::cout << " PENCARIAN KOPI ";
			Interface::color(7,0); 
			Interface::xy(60,17); std::cout<<"ID\t\t: "<< coffee.Id;
			Interface::xy(60,18); std::cout<<"NAMA\t: "<< coffee.Name;
			Interface::xy(60,19); std::cout<<"HARGA\t: "<<coffee.Price<<'\n';
			Interface::xy(60,21); std::cout<<"Ingin melakukan pencarian kembali?(y/n) ";std::cin>>Y;
			std::system("cls");
		}
		else
		{
			Interface::xy(60,19); Interface::color(7,4); 
			std::cout<< "INFO:"; 
			Interface::color(7,0); Interface::xy(66,19); 
			std::cout<<"Kopi \"" << name << "\" yang anda cari tidak ditemukan"<<std::endl;
			Interface::xy(60,20); std::cout<<"Ingin melakukan pencarian kembali?(y/n) ";std::cin>>Y;
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
			std::cout << queues.payments[i].Id<<" - ";
			std::cout << queues.payments[i].Order.Coffee<<" - ";
			std::cout << queues.payments[i].Order.Name<<" - ";
			std::cout << queues.payments[i].Order.Qty<<" - ";
			std::cout << queues.payments[i].Total<<"\n";
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
			Interface::xy(60,19); Interface::color(7,4); 
			std::cout<< "INFO:"; 
			Interface::color(7,0); Interface::xy(66,19); 
			std::cout<<"Antrian ini belum melunasi"; 
			
			getch();
		}else {
			std::cout << "\nMengambil data\" "<<queues.payments[queues.head].Order.Name<<" - "<<queues.payments[queues.head].Order.Coffee<<" \"..."<<std::endl;
			for (i = queues.head; i < queues.tail; i++)
			{	
				queues.payments[i] = queues.payments[i+1];
			}
			queues.tail--; // dectement / atau nilai sekarang dikurang dengan 1
		}
	} else {
		std::cout << "Antrean kosong";
	}
}


void Route::order(void){ // fungsi inqueue

  char Y; 
	std::string name, coffee, qty;
	double total;	

	do{
		std::system("cls");
		bool found= false;
		double price = 0;
		if (!full())
		{
			std::system("cls");
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
			
			Interface::xy(60,15); Interface::color(0,7); 
  		std::cout << " PEMESANAN KOPI ";
			Interface::color(7,0); 
			Interface::xy(60,17); std::cout<<"NAMA\t: "; std::getline(std::cin, name);
			Interface::xy(60,18); std::cout<<"KOPI\t: "; std::getline(std::cin, coffee);
			Interface::xy(60,19); std::cout<<"JUMLAH\t: "; std::cin>>qty;

			// penjumlahan total pembayaran
			for (auto good : goods)
			{
				if (good.Name == coffee)
				{
					found=true;
					price= good.Price;
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
				Interface::xy(60,19); Interface::color(7,4); 
				std::cout<< "INFO:"; 
				Interface::color(7,0); Interface::xy(66,19); 
				std::cout<<"Kopi \"" << name << "\" yang anda cari tidak ditemukan";
			}
			getchar();
		} else { 
			Interface::xy(60,19); Interface::color(7,4); 
			std::cout<< "INFO:"; 
			Interface::color(7,0); Interface::xy(66,19); 
			std::cout<<"Antrian penuh harap bersabar"; 
		
		}

		Interface::xy(60,21); std::cout<<"Apakah ingin memesan lagi? (y/n)";std::cin>>Y;
	}while(Y=='y');
}

void Route::paid(void)
{
	std::string id;
	double price;
  int money;
	
	if (!empty())
	{
  	// std::cout<<"masukkan id pesanan : ";std::cin>>id;
		
		Interface::xy(60,15); Interface::color(0,7); 
  	std::cout << " PEMBAYARAN (MASUKKAN KODE PEMESANAN) ";
		Interface::color(7,0); 
    Interface::xy(60,17); std::cout << char(175) << " ";
    std::cin >> id;

		for (int i = queues.head; i < queues.tail; i++)
		{
			if (queues.payments[i].Id == id)
			{
				for (auto good : goods)
				{
					if (good.Name == queues.payments[i].Order.Coffee)
					{
						price = good.Price;
					} 
				}

				Interface::xy(60,17); std::cout<<"KODE \t: "<< queues.payments[i].Id;
				Interface::xy(60,18); std::cout<<"NAMA\t: "<< queues.payments[i].Order.Name;
				Interface::xy(60,19); std::cout<<"KOPI\t: "<< queues.payments[i].Order.Coffee;
				Interface::xy(60,20); std::cout<<"JUMLAH\t: "<< queues.payments[i].Order.Qty;
				Interface::xy(60,21); std::cout<<"TOTAL\t: "<< queues.payments[i].Total;
				Interface::xy(60,22); std::cout<<"DIBAYAR\t: "; std::cin>>money;

				// std::cout<<"kode pemesanan        = "<<queues.payments[i].Id<<std::endl;
				// std::cout<<"nama pemesan          = "<<queues.payments[i].Order.Name<<std::endl;
				// std::cout<<"kopi yang dipesan     = "<<queues.payments[i].Order.Coffee<<std::endl;
				// std::cout<<"jumlah pesanan        = "<<queues.payments[i].Order.Qty<<std::endl;
				// std::cout<<"total pembayaran      = "<<queues.payments[i].Total<<std::endl;

				// std::cout<<"uang yang dibayarkan  = ";std::cin>>money;

				//validasi apakah uang lebih atau kurang
				if (money >= queues.payments[i].Total){
					
					queues.payments[i].Status = true;				
			
					std::ofstream os("notta.txt");

					os << "------------------------------------------------" << std::endl;
					os << "|              KEDAI KOPI JAMILLAH             |" << std::endl;
					os << "| JLN. NUSA INDAH NO.32, CONDONG CATUR, SLEMAN |" << std::endl;
					os << "------------------------------------------------" << std::endl;	
					double total = 0;
					os << std::setw(5) << "Nama";
					os << std::setw(10) << "Kopi";
					os << std::setw(10) << "Jumlah";
					os << std::setw(20) << "Harga" << std::endl; 

					os << std::setw(5) << queues.payments[i].Order.Name;
					os << std::setw(10) << queues.payments[i].Order.Coffee;
					os << std::setw(7) << queues.payments[i].Order.Qty;
					os << std::setw(21) << price;
					os << std::endl;

					os << "------------------------------------------------" << std::endl;
					os << std::setw(35) << "Total";
					os << std::setw(10) << queues.payments[i].Total << std::endl;
					os << std::setw(35) << "Pay";
					os << std::setw(10) << money << std::endl;	
					os << std::setw(35) << "Change";
					os << std::setw(10) << money - queues.payments[i].Total << std::endl;
					os.close();

					Interface::xy(60,23); std::cout<<"KEMBALIAN\t: "<<money - queues.payments[i].Total;
				}else{ 
						Interface::xy(60,19); Interface::color(7,4); 
						std::cout<< "INFO:"; 
						Interface::color(7,0); Interface::xy(66,19); 
						std::cout<<"Uang anda kurang";
					}	
			} 
		}

		char Y;
		Interface::xy(60,25); std::cout<<"Ingin melakukan transaksi kembali?(y/n) ";std::cin>>Y;
		std::system("cls");
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

	Interface::xy(60,15); Interface::color(0,7); 
	std::cout << " TAMBAH DAFTAR KOPI ";
	Interface::color(7,0); 
	Interface::xy(60,17); std::cout<<"NAMA  : "; std::getline(std::cin, name);
	Interface::xy(60,18); std::cout<<"HARGA : "; std::cin >> price;

	std::system("cls");

	// std::cout << "Name :"; std::getline(std::cin, name);
	// std::cout << "Price :"; std::cin >> price;

	store_coffees({id, name, price});
}

void Route::delete_coffees()
{
	std::string id{};

	std::ofstream temp;
	temp.open("collection/coffees_temp.csv");

	Interface::xy(60,15); Interface::color(0,7); 
	std::cout << " HAPUS DAFTAR KOPI ";
	Interface::color(7,0); 
	Interface::xy(60,17); std::cout<<"ID KOPI  : "; std::cin>>id;


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

	Interface::xy(60,15); Interface::color(0,7); 
	std::cout << " EDIT DAFTAR KOPI(MASUKKAN ID KOPI)";
	Interface::color(7,0); 
	Interface::xy(60,16); std::cout << "ID KOPI : "; std::cin>>id;

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

	Interface::xy(60,17); std::cout<<"NAMA  : "; std::getline(std::cin, name);
	Interface::xy(60,18); std::cout<<"HARGA : "; std::cin >> price;

	store_coffees({id, name, price});
}

