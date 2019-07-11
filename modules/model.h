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
        std::string Id;
        struct Order Order;
        double Total;
        bool Status;
    };
} // namespace Model
