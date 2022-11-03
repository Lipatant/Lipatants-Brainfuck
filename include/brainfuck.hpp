/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** brainfuck.hpp
** File description:
** Includes EVERYTHING from brainfuck
*/

#pragma once
#include <brainfuck/memory.hpp>
#include <brainfuck/namespace.hpp>

namespace LIPATANTS_BRAINFUCK_NAMESPACE
{
    bool optimize(char *program);
    void run(char const *program);
}
