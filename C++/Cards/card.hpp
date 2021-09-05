#pragma once

#include<iostream>

const std::string SUITS[4] = {"\u2660", "\u2665", "\u2666", "\u2663"};

const std::string NUMBERS[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};

struct Card : std::pair<int, int> {
        Card(int suit, int number) {
                first = suit;
                second = number;
        }
        
        friend std::ostream& operator<<(std::ostream& os, const Card& card);
};
