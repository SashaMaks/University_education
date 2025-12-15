#ifndef MODULE_H
#define MODULE_H

#include <iostream>
#include <string>
#include <windows.h>
#include <limits>

class CaesarCipher {
public:
    static std::string encrypt(const std::string &text, int key);
    static std::string decrypt(const std::string &text, int key);
};

#endif