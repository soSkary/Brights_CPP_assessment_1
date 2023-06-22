#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "transaction.h"
#include "transaction_functionality.h"
#include "file_input_output.h"



TEST_CASE("Testing transaction.cpp")
{
    Transaction transaction1{ 1000.00, "Receiver" };
    CHECK(transaction1.m_amount == 1000.00);
    
    CHECK(transaction1.m_receiver == "Receiver");
  
    User user{"User1"};
    user.make_transaction( transaction1 );

    Transaction transaction2{ -500.25, "Receiver1" };
    user.make_transaction(transaction2);
    user.make_transaction(-999.75, "Receiver2");

    CHECK(user.m_transactions.at(2).m_amount == -999.75);
    CHECK(user.m_transactions.at(1).m_id == 1);
    CHECK(user.m_transactions.at(0).m_receiver == "Receiver");

    CHECK(user.calculate_balance() == -500.0);
    CHECK(user.calculate_expenses() == -1500.00);
    CHECK(user.calculate_incomes() == 1000.00);

    user.view_transactions();
    try
    {
        write_user_to_file(user);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        read_user_from_file("User1");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
};
