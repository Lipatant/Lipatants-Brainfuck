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
        int depth = 0;
        unsigned long steps = 0;
        Memory_c memory;

        std::cout << "Running '" << program << "'\n";
        for (unsigned int i = 0; program[i] != '\0'; i++)
        {
            steps++;
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
                depth = 0;
                if (memory.getTapePointerValue() == 0)
                {
                    do
                    {
                        if (program[i] == '[')
                            depth -= 1;
                        if (program[i] == ']')
                            depth += 1;
                        i++;
                    } while (i != '\0' && depth != 0);
                    if (i == '\0')
                        i++;
                }
                break;
            case ']':
                depth = 0;
                if (memory.getTapePointerValue() != 0)
                {
                    do
                    {
                        if (program[i] == ']')
                            depth -= 1;
                        if (program[i] == '[')
                            depth += 1;
                        i--;
                    } while (i != 0 && depth != 0);
                    if (i == 0)
                        i--;
                }
                break;
            case '#':
                memory.displayTape();
                break;
            case '$':
                goto END_OF_PROGRAM;
                break;
            default:
                steps--;
                break;
            }
        }
    END_OF_PROGRAM: ;
    std::cout << "Code exectued in " << steps << " steps.\n";
    }
}
