/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** brainfuck/memory.hpp
** File description:
** Class used to manage memory and pointers
*/

#pragma once
#include <brainfuck/namespace.hpp>
#include <iostream>

namespace LIPATANTS_BRAINFUCK_NAMESPACE
{
    namespace Tape
    {
        typedef unsigned int length_t;
        /// @brief Default tape lenght for a Brainfuck program (30000 bytes)
        static const length_t DEFAULT_LENGTH = 30000;
    }

    class Memory_c
    {
    public:
        /// @param tapeLenght Lenght of _tape
        Memory_c(Tape::length_t tapeLenght = Tape::DEFAULT_LENGTH)
        {
            setTapeLength(tapeLenght);
        }

        /// @return _tapeLenght
        Tape::length_t getTapeLength(void) { return _tapeLenght; };

        /// @return _tapePointer
        Tape::length_t getTapePointer(void) { return _tapePointer; };

        /// @param tapeLenght New value of _tapeLenght
        void setTapeLength(Tape::length_t tapeLenght) { _tapeLenght = tapeLenght; };

        /// @param tapePointer New value of _tapePointer
        void setTapePointer(Tape::length_t tapePointer) { _tapePointer = tapePointer; };

    private:
        std::unique_ptr<char> _tape;
        Tape::length_t _tapeLenght = 0;
        Tape::length_t _tapePointer = 0;
    };
}
