#include "file_input_output.h"

#include <filesystem>
#include <fstream>
#include <iostream>

namespace fs = std::filesystem;

void write_user_to_file(const User& user)
{


    fs::path path("users");

    //Check if directory exists
    if (!fs::exists(path) || !fs::is_directory(path))
    {
        fs::create_directory(path);
    }
    
    //Set path to users/user.m_name
    path /= user.m_name;

    //Open file for writing
    std::ofstream file_output;
    file_output.open(path, std::ios::trunc);

    if (!file_output.is_open())
    {
        throw std::runtime_error("Couldn't open file for writing");
    }

    //write to file
    file_output << "name, amount, time, transaction_id, receiver/sender\n";
    for (const auto& transaction : user.m_transactions)
    {
        file_output << user.m_name << ", " << transaction << '\n';
    }

    //close file
    file_output.close();
}
void read_user_from_file(const std::string& user_name)
{
    fs::path path("users");
    path /= user_name;

    if (!fs::exists(path))
    {
        throw std::runtime_error("Couldn't find the file of user " + user_name);
    }
    //Open file
    std::ifstream file_input(path, std::ios::in);

    if (!file_input.is_open())
    {
        throw std::runtime_error("Couldn't open file for reading");
    }
    std::string print;
    while (std::getline(file_input, print))
    {
        std::cout << print << '\n';
    }

    file_input.close();

    //Didn't have the time to implement reading in users to the program from file
}

