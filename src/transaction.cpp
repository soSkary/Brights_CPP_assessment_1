#include "transaction.h"

#include <chrono>
#include <iomanip>




Transaction::Transaction(const double amount, std::string_view receiver)
    : m_amount{ amount }, m_receiver{ receiver }
{
    static unsigned int id{0};
    m_id = id++;
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    m_date_and_time = std::chrono::system_clock::to_time_t(now);
}

std::ostream& operator<<(std::ostream& out, Transaction transaction)
{
    out << transaction.m_amount << "€, " << std::put_time(std::localtime(&transaction.m_date_and_time), "%F - %T, ")
        << transaction.m_id << " -> " << transaction.m_receiver;
    return out;
}
