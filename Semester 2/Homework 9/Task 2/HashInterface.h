#pragma once

#include <iostream>
#include <stdio.h>

#include "HashFunctionFirst.h"
#include "HashFunctionSecond.h"

/**
@brief amount elements witch can be keep in the range of HashTable
*/
int const amountElements = 1000;
/**
@brief max length of words which can be keeped
*/
int const maxLengthWord = 30;


/**
@brief general class for user using
*/
class HashInterface
{
public:
    HashInterface();
    ~HashInterface();
    /**
    @brief calc hash
    */
    int calcHash(char *text);
    /**
    @brief add to hash table word from keyboard
    */
    void addHT();
    /**
    @brief search this word in HashTable
    @param text from keyboar during general cycle in main.cpp
    @return index of range cell of hash Table ( index of ArrayWords)
    **/
    int searchHT(char *buffer);
    /**
    @brief delete this word from HashTable
    @detailed unsig searchHT and consider result
    @param text from keyboar during general cycle in main.cpp
    */
    void deleteHT(char *buffer);
    /**
    @brief print static of hash Table
    @detailed amount elements, clashes, loadfactor, ...
    */
    void staticHT();

    /**
    @brief current number of hash fucntion
    */
    int numberHF;

private:
    /**
    @brief for keeping words
    */
    struct Words
    {
        char word[maxLengthWord];
        Words *next;
    };

    /**
    @brief range of lists of words
    */
    Words *arrayWords[amountElements];
    /**
    @brief support for searchHT
    @detailed moving along list of one cell of arrayWords and search this word from keyboard
    */
    bool itWasHere(Words *slot, char *text);

    /**
    @brief variable of First Hash Funtion class
    */
    HashFunctionFirst firstHF;
    /**
    @brief variable of Second Hash Funtion class
    */
    HashFunctionSecond secondHF;
    /**
    @brief keep result of searching
    */
    Words *slotWords;
};
