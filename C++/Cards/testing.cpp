#include"card.hpp"
#include"deck.hpp"

int main() {
        Deck deck = Deck();
        std::cout << deck << std::endl;

        deck.nRiffleShuffle(1);
        std::cout << deck << std::endl;
}
