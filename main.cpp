#include <iostream>
using namespace std;
int main()
{
    int health = 100;
    bool hasTorch = false;
    bool gameWon = false;
    int moves = 0;
    const int MAX_MOVES = 5;
    char direction;

    cout << "===== Welcome to The Citadel =====" << endl;
    cout << "Starting Health: " << health << endl;

    while (moves < MAX_MOVES && health > 0 && !gameWon)
    {
        cout << "\nMove " << (moves + 1) << "/" << MAX_MOVES << endl;
        cout << "Choose a direction (N / S / E / W): ";
        cin >> direction;

        switch (direction)
        {
            case 'N':
            case 'n':
            {
                cout << "\n[Alchemy Lab]" << endl;
                cout << "Choose a potion: Red (R) or Blue (B): ";
                char potion;
                cin >> potion;
                switch (potion)
                {
                    case 'R':
                    case 'r':
                        health = 150;
                        cout << "You drank the Red Potion!" << endl;
                        cout << "Health boosted to: " << health << endl;
                        break;

                    case 'B':
                    case 'b':
                        hasTorch = true;
                        cout << "You drank the Blue Potion!" << endl;
                        cout << "You obtained a torch!" << endl;
                        break;

                    default:
                        cout << "Invalid choice. No effect." << endl;
                }
                break;
            }

            case 'W':
            case 'w':
            {
                cout << "\n[Dark Library]" << endl;

                if (hasTorch)
                {
                    cout << "With the torch, you discover a hidden map!" << endl;
                    cout << "You found the escape route!" << endl;
                    gameWon = true;
                }
                else
                {
                    health -= 20;
                    cout << "It's too dark! You lost 20 health." << endl;
                    cout << "Current Health: " << health << endl;
                }
                break;
            }

            case 'E':
            case 'e':
            {
                cout << "\n[Collapsed Corridor]" << endl;
                if (health > 100)
                {
                    cout << "Your strong health helps you survive!" << endl;
                    cout << "You escape successfully!" << endl;
                    gameWon = true;
                }
                else
                {
                    cout << "You could not survive the collapse..." << endl;
                    health = 0;
                }
                break;
            }

            case 'S':
            case 's':
            {
                cout << "\n[Southern Gate]" << endl;
                cout << "The gate is locked. You need a key." << endl;
                break;
            }

            default:
                cout << "\nInvalid direction! Use N, S, E, or W." << endl;
                continue;
        }

        moves++;
    }


    if (gameWon)
    {
        cout << "Status: You Escaped the Citadel!" << endl;
    }
    else if (health <= 0)
    {
        cout << "Status: You Died!" << endl;
    }
    else
    {
        cout << "Status: Out of moves!" << endl;
        cout << "\n===== Game Over =====" << endl;
    }

    cout << "Final Health: " << health << endl;
    cout << "Moves Used: " << moves << "/" << MAX_MOVES << endl;

    return 0;
}
