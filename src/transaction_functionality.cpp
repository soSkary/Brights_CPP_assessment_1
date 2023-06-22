#include "transaction_functionality.h"


void User::make_transaction(const double amount, std::string_view receiver)
{
    m_transactions.push_back(Transaction{ amount, receiver });
}

void User::make_transaction(const Transaction& transaction)
{
    m_transactions.push_back(transaction);
}


void User::view_transactions()
{
    for (const auto& transaction : m_transactions)
    {
        std::cout << m_name << ": " << transaction << '\n';
    }
}
