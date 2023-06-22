#include "transaction_functionality.h"

User::User(std::string_view name) : m_name{ name }
{}

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


double User::calculate_expenses()
{
    double expenses;
    for (const auto& transaction : m_transactions)
    {
        if (transaction.m_amount < 0.0)
        {
            expenses += transaction.m_amount;
        }
    }
    return expenses;
}
double User::calculate_incomes()
{
    double incomes;
    for (const auto& transaction : m_transactions)
    {
        if (transaction.m_amount > 0.0)
        {
            incomes += transaction.m_amount;
        }
    }
    return incomes;
}
double User::calculate_balance()
{
    double balance;
    for (const auto& transaction : m_transactions)
    {
        balance += transaction.m_amount;  
    }
    return balance;
}
