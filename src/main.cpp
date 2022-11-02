/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** main.cpp
** File description:
** Main function
*/

#include <brainfuck.hpp>
#include <iostream>

int main(int const ac, char *av[], char *env[])
{
    char program[] = ">+++++++++[<++++++++>-]<.>+++++++[<++++>-]<+.+++++++..+++.>>>++++++++[<++++>-]<.>>> ++ ++ ++ ++ ++[<++ ++ ++ ++ +> - ] < -- -.< <<<.++ +.-- -- --.-- -- -- --.>> +.> ++ ++ ++ ++ ++.";

    brainfuck::run(program);
    return 0;
}
