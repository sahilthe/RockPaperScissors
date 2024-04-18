
#include <iostream>
using namespace std;
#include <random>
#include <math.h>
#include <string>
#include <stdexcept>
#include <cstdlib>


//Determining who wins

int determineWhoWins(int playerMove, int computerMove, string playerName) {
    

    // Rock (1) beats Scissor (3) 
    // Paper (2) beats Rock (1)
    // Scissor (3) beats Paper (2)

    // player wins
    if (playerMove == computerMove)
    {
        if (playerMove == 1)
        {
        cout << playerName << " Move: Rock" << endl;
        cout << "Computer Move: Rock" << endl;
        cout << "Player and Computer Tie" << endl;
        }

        else if (playerMove == 2)
        {
        cout << playerName << " Move: Paper" << endl;
        cout << "Computer Move: Paper" << endl;
        cout << "Player and Computer Tie" << endl;
        }
        
        if (playerMove == 3)
        {
        cout << playerName << " Move: Scissor" << endl;
        cout << "Computer Move: Scissor" << endl;
        cout << "Player and Computer Tie" << endl;
        }

    return 0;

    }
    
    // player wins
    else if ((playerMove == 1) && (computerMove == 3))
    {
        cout << playerName << "'s Move: Rock" << endl;
        cout << "Computer Move: Scissor" << endl;
        cout << "Player Wins" << endl;
    }
    else if ((playerMove == 2) && (computerMove == 1))
    {
        cout << playerName << "'s Move: Paper" << endl;
        cout << "Computer Move: Rock" << endl;
        cout << "Player Wins" << endl;

    }

    else if ((playerMove == 3) && (computerMove == 2))
    {
        cout << playerName << "'s Move: Scissor" << endl;
        cout << "Computer Move: Paper" << endl;
        cout << "Player Wins" << endl;

    }
    else
    {
        if (computerMove == 2)
        {
             cout << playerName << "'s Move: Rock" << endl;
             cout << "Computer Move: Paper" << endl;
             cout << "Computer Wins" << endl;
        }

        else if (computerMove == 1)
        {
            cout << playerName << "'s Move: Scissor" << endl;
            cout << "Computer Move: Rock" << endl;
            cout << "Computer Wins" << endl;
        }
        else
        {
            cout << playerName << "'s Move: Paper" << endl;
            cout << "Computer Move: Scissor" << endl;
            cout << "Computer Wins" << endl;
        }
        
        
        return 2;
    }

    return 1;

}


// Showing input to put there name and amount of rounds to play , program rand 
// the rock paper  and it will show  player wins and it will keep a score. out puts overall winner

int main () {

    string playerName;
    int roundsToPlay, playerScore = 0, computerScore = 0, scoreTracker = 0, playerMove = 0, computerMove = 0, ties = 0;

    cout << "Welcome to the Rock, Paper, Scissors Mini Game" << endl;
    cout << "Please enter your username: ";   
    cin >> playerName; 


    
    cout << "How many rounds do you want to play: ";
    cin >> roundsToPlay;
    // Create a error case for negative numbers

    while (roundsToPlay <= 0)
    {
        cout << "You enterd in a invalid number of rounds. Try again: ";
        cin >> roundsToPlay;
    }
    
    

    do
    {
        cout << "Enter 1 for Rock, 2 For Scissor, 3 for Paper: ";
        cin >> playerMove;

        while ((playerMove < 1) || playerMove > 3)
    {
        cout << "You enterd in a invalid move. Try again: ";
        cin >> playerMove;
    }

        // Create an error case for number not 1-3
        srand(time(NULL));
        computerMove = rand() % 3 + 1;

        // compare the numbers and determine who wins
        // determineWhoWins return value int: 0 is tie, 1 is playerWins, 2 is computerWins
        
        scoreTracker = determineWhoWins(playerMove, computerMove, playerName); 

        if (scoreTracker == 1)
        {
            playerScore++;
        }

        else if (scoreTracker == 2)
        {
            computerScore++;
        }

        else
        {
            ties++;
        }
        
        roundsToPlay--;
    } while (roundsToPlay > 0);

    cout << playerName << "'s score: " << playerScore << endl;
    cout << "Computer's score: " << computerScore << endl;
    cout << "Ties: " << ties << endl;

    if (playerScore > computerScore) 
    {
        cout << playerName << " is the winner";
    }
    else if (computerScore > playerScore)
    {
        cout << "Computer is the winner";
    }
    else
    {
        cout << "Game ends in a Tie";
    }
    

    return 0;
}

