from random import randint

from card import *
from hand import *

suits = [SPADE, CLUB, HEART, DIAMOND]
values = [str(char) for char in range(2,11)] + ['J', 'Q', 'K', 'A']
joker = 'JJ'

class Deck:
    def __init__(self, jokers=False):
        self.shuffled = False
        self.has_jokers = jokers
        self.cards = [Card(value, suit) for suit in suits for value in values]
        if jokers:
            self.cards += [joker, joker]

        self.hands = []

    def __str__(self):
        return ', '.join(str(card) for card in self.cards)


    def shuffle(self):
        n = len(self.cards)-1
        for i in range(n):
            j = randint(i, n)
            self.cards[i], self.cards[j] = self.cards[j], self.cards[i]
        self.shuffled = True

    def deal(self, numHands, size):
        self.hands = [Hand([]) for _ in range(numHands)]
        for _ in range(size):
            for i in range(numHands):
                self.hands[i].append(self.cards.pop(0))


if __name__ == "__main__":
    deck = Deck(jokers=True)
    print(deck)
    deck.shuffle()
    print(deck)
    deck.deal(2, 8)
    [print(hand) for hand in deck.hands]
    print(len(deck.cards))
