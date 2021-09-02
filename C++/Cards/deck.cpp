#include"deck.h"


ostream& operator<<(ostream& os, const Deck& deck) {
        os << "Deck: ";
        for (int i = 0; i < deck.length; i++) {
                os << deck.cards[i] << ", ";
        }
        os << endl;

        os << "Discards: ";
        for (int i = 0; i < deck.numDiscards; i++) {
                os << deck.discard[i] << ", ";
        }
        return os;
}


int Deck::getLength(void) {
        return length;
}


Card Deck::takeCard(void) {
        return cards[--length];
}


Card Deck::flipCard(void) {
        discard[numDiscards++] = cards[length - 1];
        return cards[--length];
}


void Deck::wash(void) {
        for (int i = 0; i < length; i++) {
                int idx = rand() % (length - i);
                swap(cards[idx], cards[idx + i]);
        }
}


void Deck::riffleShuffle(void) {
        srand(time(NULL));

        // find approximate middle (middle ± 3%)
        int middle = (length / 2) + (rand() % 2 * 2 - 1) * (length * 0.05);

        // randomly take from top and bottom until one depletes, then add the rest of the other
        Card* newVals = (Card*)malloc(length * sizeof(Card));
        int numTop = 0;
        int numBottom = 0;

        // should eventually end but this could technically run forever if we get really unlucky? might be worth fixing
        while (numBottom + numTop < length) {
                int side = rand() % 2;
                if (side && (length - numTop - 1) >= middle) {
                        newVals[numBottom + numTop] = cards[middle + numTop];
                        numTop++;
                        //cout << cards[middle + numTop] << endl;
                }

                if (!side && numBottom < middle) {
                        newVals[numBottom + numTop] = cards[numBottom];
                        numBottom++;
                        //cout << cards[numBottom] << endl;
                }
        }
        free(cards);
        cards = newVals;
}


void Deck::nRiffleShuffle(int n) {
        for (int i = 0; i < n; i++) {
                riffleShuffle();
        }
}


void Deck::strip(void) {
        srand(time(NULL));
        int numTransferred = 0;

        Card* newCards = (Card*)malloc(length * sizeof(Card));

        for (int i = 0; i < 4; i++) {
                int cut = (int)(length * 0.2) + (rand() % 2 * 2 - 1) * (length * 0.03);
                for (int i = 0; i < cut; i++) {
                        newCards[numTransferred + cut - 1 - i] = cards[length - 1 - numTransferred - i];
                }
                numTransferred += cut;
        }

        while (numTransferred < length) {
                newCards[numTransferred] = cards[length - 1 - numTransferred];
                numTransferred++;
        }

        free(cards);
        cards = newCards;
}


Card Deck::cut(void) {
        int idx = rand() / RAND_MAX * (length *0.90 - length * 0.1) + (length * 0.1);
        
        Card cut = cards[idx];

        for (int i = idx; i < length; i++) {
                cards[i] = cards[i + 1];
        }

        length--;

        return cut;
}

void Deck::verify(void) {
        // check for duplicates
        for (int i = 0; i < length - 2; i++) {
                for (int j = i + 1; j < length - 1; j++) {
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
                        for (int idx = 0; idx < length; idx++) {
                                if (cards[idx] == card) {
                                        found = true;
                                }
                        }
                        if (!found) {
                                cout << "failed to find card: " << card << endl;
                        }
                }
        }
}


int main() {
        Deck deck = Deck(52);
        deck.nRiffleShuffle(3);
        deck.strip();
        deck.riffleShuffle();
        cout << deck << endl;
        deck.verify();
}
