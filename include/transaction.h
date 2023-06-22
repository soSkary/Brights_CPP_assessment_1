#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <iostream>
#include <string>
#include <string_view>

struct Transaction
{
    double m_amount;
    std::time_t m_date_and_time;
    unsigned int m_id;
    std::string m_receiver;

    Transaction(const double amount, std::string_view receiver);

    friend std::ostream& operator<<(std::ostream& out, Transaction transaction);
};


#endif
