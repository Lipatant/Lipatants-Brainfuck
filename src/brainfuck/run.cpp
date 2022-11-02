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
        for (unsigned int i = 0; program[i] != '\0'; i++)
        {
            switch (program[i])
            {
            case '>':
                memory.setTapePointer(memory.getTapePointer() + 1);
                break;
            case '<':
                memory.setTapePointer(memory.getTapePointer() - 1);
                break;
            case '+':
                memory.setTapePointerValue(memory.getTapePointerValue() + 1);
                break;
            case '-':
                memory.setTapePointerValue(memory.getTapePointerValue() - 1);
                break;
            case '.':
                std::cout << memory.getTapePointerValue();
                break;
            case '[':
                if (memory.getTapePointerValue() == 0) {
                    while (i != '\0' && program[i] != ']')
                        i++;
                    if (i == '\0')
                        i++;
                }
                break;
            case ']':
                if (memory.getTapePointerValue() != 0) {
                    while (i != 0 && program[i] != '[')
                        i--;
                    if (i == 0)
                        i--;
                }
                break;
            }
        }
        std::cout << "End\n";
    }
}
