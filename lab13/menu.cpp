#include <iostream>
#include "PlayerModel.h"

void menu() {

    std::vector <PlayerModel> players;
    int choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create new player\n";
        std::cout << "2. Show player table\n";
        std::cout << "3. Overloaded operators\n";
        std::cout << "4. Save players to file\n";
        std::cout << "5. Load players from file\n";
        std::cout << "6. Save player by index\n";
        std::cout << "7. Load player by index\n";
        std::cout << "8. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >>
                 choice;

        switch (choice) {
            case 1: {
                std::string name;
                int score, place;

                std::cout << "Enter player name: ";
                std::cin >>
                         name;
                std::cout << "Enter player score: ";
                std::cin >>
                         score;
                std::cout << "Enter player place: ";
                std::cin >>
                         place;

                PlayerModel newPlayer(name, score, place);
                players.
                        push_back(newPlayer);

                std::cout << "Player created successfully!\n";
                break;
            }
            case 2: {
                std::cout << "Player table:\n";
                for (
                    auto &player
                        : players) {
                    player.

                            showPlayer();

                }
                break;
            }
            case 3: {
                std::cout << "Overloaded operators\n";
                PlayerModel player1("Balandin", 123, 2);
                PlayerModel player2("Shishkov", 79, 3);
                PlayerModel player3("Kravenko", 134, 1);

                do {
                    std::cout << "1. Overloaded + operator\n";
                    std::cout << "2. Overloaded = operator\n";
                    std::cout << "3. Overloaded == operator\n";
                    std::cout << "4. Overloaded << operator\n";
                    std::cout << "5. Overloaded >> operator\n";
                    std::cout << "6. Overloaded [] operator\n";
                    std::cout << "7. Overloaded () operator\n";
                    std::cout << "8. Exit\n";
                    std::cout << "Enter your choice: ";
                    std::cin >> choice;

                    int firstPlayer = 0, secondPlayer = 0;
                    int index;

                    switch (choice) {
                        case 1: {
                            std::cout << "Choose players to sum:\n";
                            for (int i = 0; i < players.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                players[i].showPlayer();
                                std::cout << std::endl;
                            }
                            std::cout << "First player: ";
                            std::cin >> firstPlayer;
                            std::cout << "Second player: ";
                            std::cin >> secondPlayer;
                            PlayerModel sumPlayer = players[firstPlayer - 1] + players[secondPlayer - 1];
                            std::cout << "Sum player: ";
                            sumPlayer.showPlayer();
                            break;
                        }
                        case 2: {
                            std::cout << "Choose player to copy:\n";
                            for (int i = 0; i < players.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                players[i].showPlayer();
                                std::cout << std::endl;
                            }
                            std::cout << "Player to copy: ";
                            std::cin >> firstPlayer;
                            std::cout << "Copied player: ";
                            std::cin >> secondPlayer;
                            players[firstPlayer - 1] = players[secondPlayer - 1];
                            std::cout << "Copy player: ";
                            players[firstPlayer - 1].showPlayer();
                            break;
                        }
                        case 3: {
                            std::cout << "Choose players to compare:\n";
                            std::cin >> firstPlayer >> secondPlayer;
                            for (int i = 0; i < players.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                players[i].showPlayer();
                                std::cout << std::endl;
                            }
                            bool isEqual = players[firstPlayer - 1] == players[secondPlayer - 1];
                            std::cout << players[firstPlayer - 1] << players[secondPlayer - 1];
                            std::cout << "Are player1 and player3 equal? " << (isEqual ? "Yes" : "No") <<
                                      std::endl;
                            break;
                        }
                        case 4: {
                            PlayerModel newPlayer;
                            std::cout << "Enter player details: ";
                            std::cin >> newPlayer;
                            players.push_back(newPlayer);
                            break;
                        }
                        case 5: {
                            std::cout << "Chose player: \n";
                            for (int i = 0; i < players.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                players[i].showPlayer();
                                std::cout << std::endl;
                            }
                            std::cin >> index;
                            std::cout << players[index - 1];
                            break;
                        }
                        case 6: {
                            std::cout << "Choose a player: \n";
                            for (int i = 0; i < players.size(); ++i) {
                                std::cout << i + 1 << ". ";
                                players[i].showPlayer();
                                std::cout << std::endl;
                            }

                            int playerIndex;
                            std::cout << "Enter the player number to access: ";
                            std::cin >> playerIndex;

                            if (playerIndex >= 1 && playerIndex <= players.size()) {
                                size_t length = players[playerIndex - 1][0];
                                std::cout << "Length of the first value of player " << playerIndex << "'s name: " << length << std::endl;
                            } else {
                                std::cout << "Invalid player number!" << std::endl;
                            }
                            break;
                        }
                        case 7: {
                            std::string newName;
                            int newScore, newPlace;
                            std::cout << "Enter new name, score, and place for the player: ";
                            std::cin >> newName >> newScore >> newPlace;
                            PlayerModel newPlayer(newName, newScore, newPlace);
                            players.push_back(newPlayer);
                            std::cout << "Player details updated." << std::endl;
                            std::cout << newPlayer;
                            break;
                        }
                    }
                } while (choice != 8);
                break;
            }
            case 4:
#ifdef SAVE_TYPE_BINARY
                dump(players);
#else
                dumpTxt(players);
#endif
                std::cout << "All players are saved.\n";
                break;
            case 5:
                loadFromFile();
                std::cout << "All players are loaded.\n";

                break;
            case 6:
                int index;
                std::cout << "Enter player`s number to save:\n";
                std::cin >> index;
#ifdef SAVE_TYPE_BINARY
                dumpByIndex(players, index - 1);
#else
                dumpByIndexTxt(players, index - 1);
#endif
                std::cout << "Player is saved.\n";
                break;
            case 7:
                std::cout << "Enter player`s number to load:\n";
                std::cin >> index;

                loadByIndex(players, index - 1);
                break;
            default:
                std::cout << "Invalid choice! Please enter a number from 1 to 4.\n";
                break;
        }
    } while (choice != 8);
}
