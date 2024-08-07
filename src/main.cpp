#include <iostream>
using namespace std;

// stone, paper, scissors, Game

enum enWinner {Player = 1, Computer = 2, Draw = 3};

enum enChoise {Stone = 1, Paper = 2, Scissors = 3};

struct stGameResult
{
    short GameRound;
    short PlayerWinTimes;
    short ComputerWinTimes;
    short DrawTimes;
    enWinner Winner;
    string WinnerName;
    string PlayerChoises[10];
    string ComputerChoises[10];
};

struct stRoundInfo
{
    short RoundNumber;
    enChoise PlayerChoise;
    enChoise ComputerChoise;
    enWinner Winner;
    string WinnerName;
};

void PrintChoises(string Choises[], int Length)
{
    for(int i = 0; i < Length; i++)
    {
        cout << Choises[i];

        if(i != Length - 1)
            cout << ", ";
        
    }
}

string Tabs(int NumberOfTaps)
{
    string T = "";

    for(int i = 0; i < NumberOfTaps; i++)
    {
        T += "\t";
    }

    return T;
}

void ShowGameResults(stGameResult GameResults)
{
    cout << Tabs(5) << "_________________[Game Results]_______________\n\n";
    cout << Tabs(5) << "Game Rounds        :" << GameResults.GameRound << endl;
    cout << Tabs(5) << "Player Choises     :";
    PrintChoises(GameResults.PlayerChoises, GameResults.GameRound);
    cout << endl;
    cout << Tabs(5) << "Computer Choises   :";
    PrintChoises(GameResults.ComputerChoises, GameResults.GameRound);
    cout << endl;
    cout << Tabs(5) << "Player Won Times   :" << GameResults.PlayerWinTimes << endl;
    cout << Tabs(5) << "Computer Won Times :" << GameResults.ComputerWinTimes << endl;
    cout << Tabs(5) << "Draw Won Times     :" << GameResults.DrawTimes << endl;
    cout << Tabs(5) << "Final Winner       :" << GameResults.WinnerName << endl;
    cout << Tabs(5) << "______________________________________________\n\n";
}

void GameOverScreen()
{
    cout << Tabs(5) << "______________________________________________\n\n";
    cout << Tabs(5) << "               +++ Game Over +++                  \n";
    cout << Tabs(5) << "______________________________________________\n\n";
}

enWinner WhoWinTheGame(short PlayerWinTimes, short ComputerWinTimes, short DrawTime)
{
    if(PlayerWinTimes > ComputerWinTimes)
        return enWinner::Player;
    else if(ComputerWinTimes > PlayerWinTimes)
        return enWinner::Computer;
    else
        return enWinner::Draw;
}

string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] {"Player", "Computer", "No Winner"};
    return arrWinnerName[Winner - 1];
}

stGameResult FillGameResult(short GameRound, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes, string PlayerChoises[], string ComputerChoises[])
{
    stGameResult GameResult;

    GameResult.GameRound = GameRound;
    GameResult.PlayerWinTimes = PlayerWinTimes;
    GameResult.ComputerWinTimes = ComputerWinTimes;
    GameResult.DrawTimes = DrawTimes;
    GameResult.Winner = WhoWinTheGame(PlayerWinTimes, ComputerWinTimes, DrawTimes);
    GameResult.WinnerName = WinnerName(GameResult.Winner);

    for(int i = 0; i < GameRound; i++)
    {
        GameResult.PlayerChoises[i] = PlayerChoises[i];
        GameResult.ComputerChoises[i] = ComputerChoises[i];
    }

    return GameResult;
}

string ChoisesName(enChoise Choise)
{
    string ArrChoises[] {"Stone", "Paper", "Scissors"};
    return ArrChoises[Choise - 1];
}

void RoundResults(stRoundInfo RoundResults)
{
    cout << "\n____________________Round[" << RoundResults.RoundNumber << "]____________________\n";
    cout << "\nPlayer Choise  : " << ChoisesName(RoundResults.PlayerChoise) << endl;
    cout << "Computer Choise: " << ChoisesName(RoundResults.ComputerChoise) << endl;
    cout << "Round Winner   : " << RoundResults.WinnerName << endl;
    cout << "\n________________________________________________\n";
}

enWinner WhoRoundWin(enChoise PlayerChoise, enChoise ComputerChois)
{
    if(PlayerChoise == ComputerChois)
        return enWinner::Draw;

    switch (PlayerChoise)
    {
    case enChoise::Stone:
        if(ComputerChois == enChoise::Paper)
            return enWinner::Computer;
        break;
    case enChoise::Scissors:
        if(ComputerChois == enChoise::Stone)
            return enWinner::Computer;
        break;
    case enChoise::Paper:
        if(ComputerChois == enChoise::Scissors)
            return enWinner::Computer;
        break;
    }

    return enWinner::Player;
}

int RandomNumber(int From, int To)
{
    int RandomNumber = rand() % (To - From + 1) + From;
    return RandomNumber;
}

enChoise GetComputrChoise()
{
    return (enChoise)RandomNumber(1, 3);
}

enChoise ReadPlayerChoise()
{
    short Choise;

    do
    {
        cout << "\nYour Choise: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choise;
    } while (Choise > 3 || Choise < 1);

    return (enChoise)Choise;   
}

short HowManyRounds()
{
    short Rounds = 0;

    do
    {
        cout << "How Many Rounds From 1 To 10 ? ";
        cin >> Rounds;
    } while (Rounds > 10 || Rounds < 1);
    
    return Rounds;
}

stGameResult PlayGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short PlayerWinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;
    string PlayerChoises[HowManyRounds];
    string ComputerChoises[HowManyRounds];
    for(int GameRound = 1; GameRound <= HowManyRounds; GameRound++)
    {
        cout << "\nRound ["<< GameRound << "] Begin:\n";
        RoundInfo.RoundNumber = GameRound;
        RoundInfo.PlayerChoise = ReadPlayerChoise();
        PlayerChoises[GameRound - 1] = ChoisesName(RoundInfo.PlayerChoise);
        RoundInfo.ComputerChoise = GetComputrChoise();
        ComputerChoises[GameRound - 1] = ChoisesName(RoundInfo.ComputerChoise);
        RoundInfo.Winner = WhoRoundWin(RoundInfo.PlayerChoise, RoundInfo.ComputerChoise);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        RoundResults(RoundInfo);

        if(RoundInfo.Winner == enWinner::Player)
            PlayerWinTimes++;
        else if(RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else
            DrawTimes++;
    }

    return FillGameResult(HowManyRounds, PlayerWinTimes, ComputerWinTimes, DrawTimes, PlayerChoises, ComputerChoises);
}

void StartGame()
{
    char PlayAgain = 'N';

    do
    {
        system("clear");
        stGameResult GameResult = PlayGame(HowManyRounds());
        GameOverScreen();
        ShowGameResults(GameResult);
        cout << "Do You Want To Play Again? [Y]:Yes, [N]:No? ";
        cin >> PlayAgain;
    } while (PlayAgain == 'Y' || PlayAgain == 'y');
    
}

int main()
{
    StartGame();
    return 0;
}