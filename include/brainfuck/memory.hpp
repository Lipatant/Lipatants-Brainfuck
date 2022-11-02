/*
** LIPATANT'S BRAINFUCK - VIRGILE (LIPATANT) BERRIER, 2022
** brainfuck/memory.hpp
** File description:
** Class used to manage memory and pointers
*/

#pragma once
#include <brainfuck/namespace.hpp>
#include <iostream>
#include <memory>

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
        Memory_c(Tape::length_t const tapeLenght = Tape::DEFAULT_LENGTH)
        {
            setTapeLength(tapeLenght);
            tapeReset();
        }

        /// @return _tapeLenght
        Tape::length_t getTapeLength(void) { return _tapeLenght; };

        /// @return _tapePointer % getTapePointer( )
        Tape::length_t getTapePointer(void) { return _tapePointer % getTapeLength(); };

        /// @return _tape [ getTapePointer( ) ]
        char getTapePointerValue(void) { return _tape[getTapePointer()]; };

        /// @param tapeLenght New value of _tapeLenght
        void setTapeLength(Tape::length_t const tapeLenght) { _tapeLenght = tapeLenght; };

        /// @param tapePointer New value of _tapePointer
        void setTapePointer(Tape::length_t const tapePointer) { _tapePointer = tapePointer % getTapeLength(); };

        /// @param tapePointerValue New value of _tape [ getTapePointer( ) ]
        void setTapePointerValue(char const tapePointerValue) { _tape[getTapePointer()] = tapePointerValue; };

        /// @brief Reset the value of _tape.
        void tapeReset(char const value = 0)
        {
            Tape::length_t tapeLenght = getTapeLength();

            _tape.reset(new char[tapeLenght]);
            for (Tape::length_t i = 0; i < tapeLenght; i++)
                _tape[i] = value;
        }

    private:
        std::unique_ptr<char[]> _tape;
        Tape::length_t _tapeLenght = 0;
        Tape::length_t _tapePointer = 0;
    };
}
