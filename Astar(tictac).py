import math


class TicTacToe:
    def __init__(self):
        self.board = [' '] * 9
        self.player = 'X'
        self.ai = 'O'
        self.num_moves = 0

    def print_board(self):
        print('---------')
        print('|', self.board[0], self.board[1], self.board[2], '|')
        print('|', self.board[3], self.board[4], self.board[5], '|')
        print('|', self.board[6], self.board[7], self.board[8], '|')
        print('---------')

    def make_move(self, move, player):
        self.board[move] = player
        self.num_moves += 1

    def get_empty_cells(self):
        return [i for i in range(9) if self.board[i] == ' ']

    def is_winner(self, player):
        winning_positions = [
            (0, 1, 2), (3, 4, 5), (6, 7, 8),  # rows
            (0, 3, 6), (1, 4, 7), (2, 5, 8),  # columns
            (0, 4, 8), (2, 4, 6)  # diagonals
        ]
        for pos in winning_positions:
            if self.board[pos[0]] == self.board[pos[1]] == self.board[pos[2]] == player:
                return True
        return False

    def is_game_over(self):
        return self.is_winner(self.player) or self.is_winner(self.ai) or self.num_moves == 9

    def evaluate_state(self):
        if self.is_winner(self.player):
            return -1
        elif self.is_winner(self.ai):
            return 1
        else:
            return 0


class AIPlayer:
    def __init__(self, game):
        self.game = game

    def get_best_move(self):
        best_move = None
        best_score = -math.inf
        for move in self.game.get_empty_cells():
            self.game.make_move(move, self.game.ai)
            score = self.minimax(self.game, 0, False)
            self.game.board[move] = ' '
            if score > best_score:
                best_score = score
                best_move = move
        return best_move

    def minimax(self, game, depth, is_maximizing):
        if game.is_game_over():
            return game.evaluate_state()

        if is_maximizing:
            best_score = -math.inf
            for move in game.get_empty_cells():
                game.make_move(move, game.ai)
                score = self.minimax(game, depth + 1, False)
                game.board[move] = ' '
                best_score = max(score, best_score)
            return best_score
        else:
            best_score = math.inf
            for move in game.get_empty_cells():
                game.make_move(move, game.player)
                score = self.minimax(game, depth + 1, True)
                game.board[move] = ' '
                best_score = min(score, best_score)
            return best_score


def play_tic_tac_toe():
    game = TicTacToe()
    ai_player = AIPlayer(game)

    print("Welcome to Tic Tac Toe!")
    game.print_board()

    while not game.is_game_over():
        if game.player == 'X':
            move = int(input("Enter your move (0-8): "))
            if move not in game.get_empty_cells():
                print("Invalid move! Try again.")
                continue
        else:
            print("AI player is making a move...")
            move = ai_player.get_best_move()
            print(f"AI player chooses {move}")

        game.make_move(move, game.player)
        game.print_board()
        game.player, game.ai = game.ai, game.player

    if game.is_winner(game.player):
        print("AI player wins!")
    elif game.is_winner(game.ai):
        print("Congratulations! You win!")
    else:
        print("It's a draw!")


# Start the game
play_tic_tac_toe()
