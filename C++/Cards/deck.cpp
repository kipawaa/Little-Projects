#include"deck.hpp"


std::ostream& operator<<(std::ostream& os, const Deck& deck) {
        os << "Deck: ";
        for (auto card : deck.cards) {
                os << card << ", ";
        }
        os << std::endl;

        os << "Discards: ";
        for (auto card : deck.discards) {
                os << card << ", ";
        }
        return os;
}


int Deck::getLength(void) {
        return cards.size();
}


Card Deck::takeCard(void) {
        Card card = cards.front();
        cards.erase(cards.begin());
        return card;
}


void Deck::flipCard(void) {
        discards.push_back(cards.front());
        cards.erase(cards.begin());
}


void Deck::wash(void) {
        for (int i = 0; i < cards.size(); i++) {
                int idx = rand() % (cards.size() - i);
                swap(cards[idx], cards[idx + i]);
        }
}


void Deck::riffleShuffle(void) {
        std::default_random_engine generator;
        std::bernoulli_distribution distribution(0.5);
        auto random = std::bind(distribution, generator);

        // find approximate middle (middle ± 3%)
        int cut = (cards.size() / 2) + (random() % 2 * 2 - 1) * (cards.size() * 0.05);

        // randomly take from top and bottom until one depletes, then add the rest of the other
        std::vector<Card> newCards;
        int numTop = 0;
        int numBottom = 0;

        while (numBottom + numTop < cards.size()) {
                int side = random() % 2;
                if (side && (cards.size() - 1 - numTop) >= cut) {
                        newCards.push_back(cards[cut + numTop++]);
                }

                if (!side && numBottom < cut) {
                        newCards.push_back(cards[numBottom++]);
                }
        }
        cards = newCards;
}


void Deck::nRiffleShuffle(int n) {
        for (int i = 0; i < n; i++) {
                riffleShuffle();
        }
}


void Deck::strip(void) {
        std::default_random_engine generator;
        std::bernoulli_distribution distribution(0.5);
        auto random = std::bind(distribution, generator);

        int numTransferred = 0;

        std::vector<Card> newCards;;

        for (int i = 0; i < 4; i++) {
                // cut 20% ± 3%
                int cut = (int)(cards.size() * 0.2) + (random() % 2 * 2 - 1) * (cards.size()* 0.03);
                for (int i = 0; i < cut; i++) {
                        newCards.push_back(cards[cards.size() - 1 - numTransferred - i]);
                }
                numTransferred += cut;
        }

        while (numTransferred < cards.size()) {
                newCards.push_back(cards[cards.size() - 1 - numTransferred++]);
        }

        cards = newCards;
}


Card Deck::cut(void) {
        int idx = rand() / RAND_MAX * (cards.size() *0.90 - cards.size() * 0.1) + (cards.size() * 0.1);
        
        Card cut = cards[idx];

        cards.erase(cards.begin() + idx);

        return cut;
}

/*
void Deck::verify(void) {
        // check for duplicates
        for (int i = 0; i < cards.size() - 2; i++) {
                for (int j = i + 1; j < cards.size() - 1; j++) {
                        if (cards[i] == cards[j]) {
                                cout << "duplicate value in deck: " << cards[i] << endl;
                        }
                }
        }

        // check to make sure every card is there (inherently makes sure there are 52 cards)
        for (int suit = 0; suit < 4; suit++) {
                for (int num = 0; num < 13; num++) {
                        Card card = Card(suit * num);
                        bool found = false;
                        for (int idx = 0; idx < cards.size(); idx++) {
                                if (cards[idx] == card) {
                                        found = true;
                                }
                        }
                        if (!found) {
                                cout << "failed to find card: " << card << endl;
                        }
                }
        }
}*/
