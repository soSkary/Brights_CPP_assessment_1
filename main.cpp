#include "file_input_output.h"
#include "transaction_functionality.h"
#include "transaction.h"

#include <iostream>
#include <limits>

int get_user_int()
{
    int value;
    while (true)
    {
        std::cout << "Input integer value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

double get_user_double()
{
    double value;
    while (true)
    {
        std::cout << "Input integer value: ";
        std::cin >> value;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (!std::cin)
        {
            std::cin.clear()
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return value;
    }
}

std::string get_user_string()
{
    std::string value;
    while (true)
    {
        std::cout << "Input integer value: ";
        std::getline(std::cin >> std::ws, value);
        return value;
    }
}

void user_loop(User& user)
{
    std::cout << "Please choose what you want to do:\n"
        << "1) View transactions\n"
        << "2) Make transaction\n"
        << "3) Calculate incomes, expenses and balance\n"
        << "4) Exit\n";

    int choice{ get_user_int() };
    switch (choice)
    {
    case 1:
        user.view_transactions();
        break;
    case 2:
        std::cout << "Please input amount for transaction: ";
        double amount{ get_user_double() };
        std::cout << "\nPlease input name of receiver: ";
        std::string receiver{get_user_string()};
        user.make_transaction(amount, receiver);
        break;
    case 3:
        std::cout << "Balance: " << user.calculate_balance() ", Expenses: " << user.calculate_expenses()
            << ", Incomes: " << user.calculate_incomes() << '\n';
        break;
    case 4:
        return;

    }

}
int main()
{
    Transaction transaction1{ 1000.00, "Receiver" };
     User user{"User1"};
    user.make_transaction( transaction1 );

    Transaction transaction2{ -500.25, "Receiver1" };
    user.make_transaction(transaction2);
    user.make_transaction(-999.75, "Receiver2");

    user_loop(user);
}
