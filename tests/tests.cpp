#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "transaction.h"
#include "transaction_functionality.h"



TEST_CASE("Testing transaction.cpp")
{
    Transaction transaction1{ 1000.0, "Receiver" };
    CHECK(transaction1.m_amount == 1000.0);
    
    CHECK(transaction1.m_receiver == "Receiver");
  
    User user;
    user.make_transaction( transaction1 );

    Transaction transaction2{ -500.25, "Receiver1" };
    user.make_transaction(transaction2);
    user.make_transaction(-499.75, "Receiver2");

    CHECK(user.m_transactions.at(2).m_amount == -499.75);
    CHECK(user.m_transactions.at(1).m_id == 1);
    CHECK(user.m_transactions.at(0).m_receiver == "Receiver");

    user.view_transactions();
};
