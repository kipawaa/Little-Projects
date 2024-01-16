SPADE = '\u2660'
CLUB = '\u2663'
HEART = '\u2665'
DIAMOND = '\u2666'

class Card:
    def __init__(self, value, suit):
        self.value = value
        self.suit = suit

    def __str__(self):
        return self.value + self.suit

if __name__ == "__main__":
    AH = Card('A', HEART)
    print(AH)
