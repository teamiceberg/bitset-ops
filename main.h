#ifndef MAIN_H
#define MAIN_H

#endif // MAIN_H
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <vector>
#include <string.h>
#include <string>
#include <iomanip>
#include <ctype.h>

using namespace std;

enum class OrdType : char {little, big, mixed};
const unsigned char * print_mem_layout(const void *object, size_t size);
constexpr short int N = sizeof(unsigned int) << 3;
unsigned long get_input();
