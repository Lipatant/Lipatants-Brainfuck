/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** main.cpp
** File description:
** Main function
*/

#include <brainfuck.hpp>
#include <fstream>
#include <iostream>

int main(int const ac, char const *av[], char const *env[])
{
    char c = 0;
    char *program = NULL;
    unsigned int programLength = 0;
    std::streampos fileSize = 0;
    std::string authorizedCharacters = "<>+-.,[]#$";

    if (ac < 2)
        return 1;
    std::fstream file(av[1], std::fstream::in);
    if (!file.is_open())
        return 1;
    while (file >> std::noskipws >> c)
        fileSize += 1;
    file.clear();
    file.seekg(0, std::ios::beg);
    fileSize += 1;
    program = new char[fileSize];
    fileSize -= 1;
    if (program != NULL)
    {
        for (unsigned int i = 0; file >> std::noskipws >> c && i < fileSize; i++)
        {
            program[i] = '\0';
            program[i + 1] = '\0';
            if (authorizedCharacters.find(c) != std::string::npos) {
                program[programLength] = c;
                programLength++;
            }
        }
    }
    file.close();
    if (program == NULL)
        return 1;
    brainfuck::run(program);
    delete[] program;
    return 0;
}
