from card import *

class Hand:
    def __init__(self, cards):
        self.cards = cards
        self.sort()

    def sort(self):
        self.cards.sort(key=lambda x : x.value[1])

    def append(self, card):
        self.cards.append(card)

    def __str__(self):
        return ', '.join([str(card) for card in self.cards])

if __name__ == "__main__":
    hand = Hand([])
    print(hand)
