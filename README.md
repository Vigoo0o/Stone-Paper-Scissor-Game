# Stone, Paper, Scissors Game

This is a simple console-based implementation of the classic game Stone, Paper, Scissors using C++. The game allows the player to play multiple rounds against the computer.

## Game Rules

1. Stone beats Scissors.
2. Scissors beats Paper.
3. Paper beats Stone.
4. If both the player and the computer choose the same option, it is a draw.

## Features

- The player can choose the number of rounds (between 1 and 10).
- Each round, the player chooses Stone, Paper, or Scissors.
- The computer randomly selects Stone, Paper, or Scissors.
- The game keeps track of wins, losses, and draws.
- After all rounds are completed, the final winner is displayed.
- Option to play the game again after it ends.

## Getting Started

## Executable Files

Executable versions of the project are available for different operating systems in the `bin/` directory.

### Prerequisites

- A C++ compiler (e.g., g++)

### Compiling and Running the Game

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/stone-paper-scissors.git
    cd stone-paper-scissors
    ```

2. Compile the program:
    ```bash
    g++ -o stone-paper-scissors stone-paper-scissors.cpp
    ```

3. Run the executable:
    ```bash
    ./stone-paper-scissors
    ```

## Code Overview

### Enum Definitions

- `enWinner`: Defines the possible winners (`Player`, `Computer`, `Draw`).
- `enChoise`: Defines the possible choices (`Stone`, `Paper`, `Scissors`).

### Struct Definitions

- `stGameResult`: Holds the overall game results, including the number of rounds, win counts, and final winner.
- `stRoundInfo`: Holds information for each round, including round number, player and computer choices, and round winner.

### Functions

- `Tabs(int NumberOfTaps)`: Generates a string of tabs for formatting.
- `ShowGameResults(stGameResult GameResults)`: Displays the final game results.
- `GameOverScreen()`: Displays the game over screen.
- `WhoWinTheGame(short PlayerWinTimes, short ComputerWinTimes, short DrawTime)`: Determines the overall game winner.
- `WinnerName(enWinner Winner)`: Returns the name of the winner.
- `FillGameResult(short GameRound, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)`: Fills and returns the game result structure.
- `ChoisesName(enChoise Choise)`: Returns the name of a choice.
- `RoundResults(stRoundInfo RoundResults)`: Displays the results of a round.
- `WhoRoundWin(enChoise PlayerChoise, enChoise ComputerChois)`: Determines the winner of a round.
- `RandomNumber(int From, int To)`: Generates a random number between `From` and `To`.
- `GetComputrChoise()`: Generates a random choice for the computer.
- `ReadPlayerChoise()`: Reads the player's choice from input.
- `HowManyRounds()`: Asks the player for the number of rounds.
- `PlayGame(short HowManyRounds)`: Plays the specified number of rounds and returns the game results.
- `StartGame()`: Manages the game loop, including playing again.

### Main Function

- `main()`: Starts the game by calling `StartGame()`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- Inspired by the classic game Stone, Paper, Scissors.

