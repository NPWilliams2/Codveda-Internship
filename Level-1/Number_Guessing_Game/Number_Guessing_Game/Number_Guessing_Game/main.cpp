#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int main()
{
    int secretNumber;
    int guess;
    int attemps = 0;
    char playAgain;

    srand(static_cast<unsigned int>(time(0)));

    cout << "===== Number Guessing Game =====" << endl;

    do
    {
        secretNumber = rand() % 100 + 1;
        attemps = 0;

        cout << "\nI have chosen a number between 1 and 100" << endl;
        cout << "Try to guess it!" << endl;

        do
        {
            while (true)
            {
                cout << "\nEnter your guess (1-100): ";

                if (!(cin >> guess))
                {
                    cout << "Invalid input. Please enter a number" << endl;

                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    continue;
                }

                if (guess < 1 || guess > 100)
                {
                    cout << "Please enter a number between 1 and 100" << endl;
                    continue;
                }

                break;
            }

            attemps++;

            if (guess > secretNumber)
            {
                cout << "Too high! Try again" << endl;
            }
            else if (guess < secretNumber)
            {
                cout << "Too low! Try again" << endl;
            }
            else
            {
                cout << "\nCongratulations!" << endl;
                cout << "You guessed the number in "
                    << attemps
                    << " attempts" << endl;
            }

        } while (guess != secretNumber);

        cout << "\nWould you like to play again? (Y/N): ";
        cin >> playAgain;

    } while (guess != secretNumber);

    cout << "\nThank you for playing!" << endl;

    return 0;
    
}

