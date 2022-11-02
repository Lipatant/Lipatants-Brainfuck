/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** brainfuck/run.cpp
** File description:
** Allows the user to run a brainfuck program
*/

#include <brainfuck/memory.hpp>
#include <brainfuck/namespace.hpp>
#include <iostream>

namespace LIPATANTS_BRAINFUCK_NAMESPACE
{
    void run(char const *program)
    {
        Memory_c memory;

        std::cout << "Running '" << program << "'\n";
        std::cout << "SHEEEEESH\n";
    }
}
