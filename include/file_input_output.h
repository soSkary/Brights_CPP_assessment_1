#ifndef FILE_INPUT_OUTPUT_H
#define FILE_INPUT_OUTPUT_H

#include "transaction_functionality.h"

void write_user_to_file(const User& user);
void read_user_from_file(const std::string& user_name);


#endif
