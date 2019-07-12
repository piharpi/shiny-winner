namespace Route
{
  // Mengisi data vector dari file coffees.csv
  void initialize(void);

  // fungsi untuk mengarahkan menu
  void Barista(void);  
  void Cashier(void);
  void Customer(void);

  // fungsi untuk customer
  void order(void);
  void show_coffees(void);
  void search_coffees(void);
  void logging(void); // progress

  // fungsi untuk barista
  void add_coffees(void); // progress
  void edit_coffees(void); // progress
  void delete_coffees(void); // progress
  void show_queues(void);
  void delete_queues(void);

  // fungsi untuk cashier
  void paid(void);
  void print(void); // progress

} // namespace Route
