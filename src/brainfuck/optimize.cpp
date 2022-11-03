/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** brainfuck/optimize.cpp
** File description:
** Allows the user to optimize their program, by remove things like +- or <>...
*/

#include <brainfuck/memory.hpp>
#include <brainfuck/namespace.hpp>
#include <iostream>

static void cutFromString(char *str, unsigned int const start, unsigned int const end)
{
    unsigned int i = 0;

    if (str == NULL || end - start <= 0)
        return;
    for (i = start; str[i] != '\0'; i++)
    {
        str[i] = str[i + (end + 1 - start)];
    }
    str[i] = '\0';
}

namespace LIPATANTS_BRAINFUCK_NAMESPACE
{
    bool optimize(char *program)
    {
        int index = 0;
        unsigned int modifs = 0;

        if (program == NULL)
            return false;
        for (index = 0; program[index] != '\0'; index++)
        {
            if (index >= 0 && (program[index] == '+' && program[index + 1] == '-') || (program[index] == '-' && program[index + 1] == '+')) {
                cutFromString(program, index, index + 1);
                index -= 1;
                modifs++;
            }
            if (index >= 0 && (program[index] == '<' && program[index + 1] == '>') || (program[index] == '>' && program[index + 1] == '<')) {
                cutFromString(program, index, index + 1);
                index -= 1;
                modifs++;
            }
            if (index >= 0 && (program[index] == '[' && program[index + 1] == ']')) {
                cutFromString(program, index, index + 1);
                index -= 1;
                modifs++;
            }
        }
        if (modifs > 0) {
            optimize(program);
            return true;
        }
        return false;
    }
}
