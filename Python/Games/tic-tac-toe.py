class Game:
    def __init__(self):
        self.turn = 'x'
        self.board = ' ' * 9

    def __str__(self):
        return self.board[0] + '|' + self.board[1] + '|' + self.board[2] + '\n' + '-----\n' + self.board[3] + '|' + \
            self.board[4] + '|' + self.board[5] + '\n' + '-----\n' + self.board[6] + '|' + self.board[7] + '|' + self.board[8]

    def play(self, position):
        if self.board[position] != ' ':
            raise PositionError
        self.board = self.board[:position] + \
            self.turn + self.board[position + 1:]
        self.turn = 'x' if self.turn == 'o' else 'o'

    def has_winner(self):
        # check horizontals
        if self.board[0] == self.board[1] == self.board[2] != ' ':
            return True
        if self.board[3] == self.board[4] == self.board[5] != ' ':
            return True
        if self.board[6] == self.board[7] == self.board[8] != ' ':
            return True

        # check verticals
        if self.board[0] == self.board[3] == self.board[6] != ' ':
            return True
        if self.board[1] == self.board[4] == self.board[7] != ' ':
            return True
        if self.board[2] == self.board[5] == self.board[8] != ' ':
            return True

        # check diagonals
        if self.board[0] == self.board[4] == self.board[8] != ' ':
            return True
        if self.board[2] == self.board[4] == self.board[6] != ' ':
            return True


if __name__ == '__main__':
    while input("play a game of tic tac toe? (y/n): ") == 'y':
        ttt = Game()
        print(ttt)

        while not ttt.has_winner():
            pos = input("choose a position to play at: ")
            try:
                pos = int(pos)
            except:
                print(f"can't find a position \"{pos}\"")
            try:
                ttt.play(pos)
            except:
                print(f"You cannot play at position {pos}")
            print(ttt)
        print(f"Winner! {'x' if ttt.turn == 'o' else 'x'} has won the game!")
