#ifndef PLAYERMODEL_H
#define PLAYERMODEL_H

#include <string>
#include <iostream>
#include <fstream>

#define SAVE_TYPE BINARY

class PlayerModel {
public:
    std::string name;
    int place;
    int score;
public:
    PlayerModel();
    PlayerModel(const std::string& newName, int newScore, int newPlace);
    std::string getName() const;
    int getScore() const;
    int getPlace() const;

    void setName(const std::string& newName) ;
    void setScore(int newScore) ;
    void setPlace(int newPlace);
    void showPlayer();

    PlayerModel operator+(const PlayerModel& player);
    PlayerModel & operator=(const PlayerModel& player1);
    bool operator==(const PlayerModel& player) const;
//    char operator[](int index) const;
    size_t operator[](int index) const;
    void operator()(const std::string& newName, int newScore, int newPlace);

//    friend bool operator==(const PlayerModel& player1, const PlayerModel& player2);
//    friend PlayerModel operator+(const PlayerModel& player1, const PlayerModel& player2);

};

std::ostream& operator<<(std::ostream& out, const PlayerModel& player);
std::istream& operator>>(std::istream& in, PlayerModel& player);

void dump(const std::vector<PlayerModel>& players);
void loadFromFile();
void dumpByIndex(const std::vector<PlayerModel>& players, int index);
void loadByIndex(const std::vector<PlayerModel>& players, int index);
void loadByIndexTxt(const std::vector<PlayerModel> &players, int index);
void dumpTxt(const std::vector<PlayerModel>& players);
void dumpByIndexTxt(const std::vector<PlayerModel> &players, int index);


void menu();

#endif // PLAYERMODEL_H
