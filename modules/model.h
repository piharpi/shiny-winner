namespace Model
{
    struct Coffee
    {
        std::string Id;
        std::string Name;
        double Price;
    };

    struct Order
    {
        std::string Name;
        std::string Coffee;
        int Qty;
    };

    struct Payment
    {
        struct Order Order;
        double Total;
    };
} // namespace Model
