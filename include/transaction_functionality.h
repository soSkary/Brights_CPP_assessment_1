#ifndef TRANSACTION_FUNCTIONALITY_H
#define TRANSACTION_FUNCTIONALITY_H

#include "transaction.h"
#include <vector>

struct User
{
    std::string m_name;
    std::vector<Transaction> m_transactions;

void make_transaction(const double amount, std::string_view receiver);
void make_transaction(const Transaction& transaction);
void view_transactions();
    
};



#endif
