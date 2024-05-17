#include "PlayerModel.h"

PlayerModel::PlayerModel() : name(" "), score(0), place(0) {}

PlayerModel::PlayerModel(const std::string &newName, int newScore, int newPlace)
        : name(newName), score(newScore), place(newPlace) {}

std::string PlayerModel::getName() const {
    return name;
}

int PlayerModel::getScore() const {
    return score;
}

int PlayerModel::getPlace() const {
    return place;
}

void PlayerModel::setName(const std::string &newName) {
    name = newName;
}

void PlayerModel::setScore(int newScore) {
    score = newScore;
}

void PlayerModel::setPlace(int newPlace) {
    place = newPlace;
}

void PlayerModel::showPlayer() {
    std::cout << "Name: " << name << ", Score: " << score << ", Place: " << place << std::endl;
}


PlayerModel PlayerModel::operator+(const PlayerModel &player) {
    PlayerModel newPlayer;
    newPlayer.setName(this->getName() + " " + player.getName());
    newPlayer.setScore(this->getScore() + player.getScore());
    newPlayer.setPlace(this->getPlace() + player.getPlace());
    return newPlayer;
}

PlayerModel& PlayerModel::operator=(const PlayerModel &player1) {
    this->setName(player1.getName());
    this->setPlace(player1.getPlace());
    this->setScore(player1.getScore());
    return *this;
}

bool PlayerModel::operator==(const PlayerModel& player) const {
    return name == player.name && score == player.score && place == player.place;
}

bool operator==(const PlayerModel& player1, const PlayerModel& player2) {
    return player1.getName() == player2.getName() && player1.getScore() == player2.getScore() && player1.getPlace() == player2.getPlace();
}

PlayerModel operator+(const PlayerModel& player1, const PlayerModel& player2) {
    PlayerModel newPlayer;
    newPlayer.name = player1.name + " " + player2.name;
    newPlayer.score = player1.score + player2.score;
    newPlayer.place = player1.place + player2.place;
    return newPlayer;
}

//char PlayerModel::operator[](int index) const {
//    if (index >= 0 && index < name.length()) {
//        return name[index];
//    } else {
//        return '\0';
//    }
//}

size_t PlayerModel::operator[](int index) const {
    if (index >= 0 && name != "") {
        return name.length();
    }
    return 0;
}

void PlayerModel::operator()(const std::string& newName, int newScore, int newPlace) {
    name = newName;
    score = newScore;
    place = newPlace;
}

void dump(const std::vector<PlayerModel>& players) {
    std::ofstream file("players.txt", std::ios::binary | std::ios::app);

    if (file.is_open()) {
        for (const auto& player : players) {
            file.write(reinterpret_cast<const char*>(&player), sizeof(PlayerModel));
        }
        file.close();
        std::cout << "Vector saved to file." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void dumpTxt(const std::vector<PlayerModel>& players) {
    std::ofstream file("players.txt", std::ios::app);

    if (file.is_open()) {
        for (const auto& player : players) {
            file << player.getName() << " " << player.getScore() << " " << player.getPlace() << std::endl;
        }
        file.close();
        std::cout << "Vector saved to file." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void loadFromFile(std::vector<PlayerModel> &players) {
    std::ifstream file("players.txt", std::ios::binary);

    if (file.is_open()) {
        players.clear();
        PlayerModel player;
        while (file.read(reinterpret_cast<char*>(&player), sizeof(PlayerModel))) {
            players.push_back(player);
        }
        file.close();
        std::cout << "File loaded successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void loadFromFileTxt(std::vector<PlayerModel> &players) {
    std::ifstream file("players.txt");

    if (file.is_open()) {
        players.clear();
        std::string name;
        int score, place;
        while (file >> name >> score >> place) {
            PlayerModel player(name, score, place);
            players.push_back(player);
        }
        file.close();
        std::cout << "File loaded successfully." << std::endl;
    } else {
        std::cerr << "Unable to open file." << std::endl;
    }
}

void loadByIndex(std::vector<PlayerModel> &players, int index) {

    std::ifstream file("players.txt", std::ios::binary);

    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }

    for (int i = 0; i < index; i++) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string name;
    int score, place;

    file >> name >> score >> place;

    file.close();

    std::cout << "Player loaded: " << name << " " << score << " " << place << std::endl;
    PlayerModel newPlayer(name, score, place);
    players.push_back(newPlayer);
}

void loadByIndexTxt( std::vector<PlayerModel> &players, int index) {
    std::ifstream file("players.txt");

    if (!file.is_open()) {
        std::cout << "File not found" << std::endl;
        return;
    }

    for (int i = 0; i < index; i++) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::string name;
    int score, place;

    file >> name >> score >> place;

    file.close();

    std::cout << "Player loaded: " << name << " " << score << " " << place << std::endl;
    PlayerModel newPlayer(name, score, place);
    players.push_back(newPlayer);
}

void dumpByIndex(std::vector<PlayerModel> &players, int index) {

    std::ofstream file("players.txt", std::ios::binary | std::ios::app);

    if (file.is_open()) {
        file.write(reinterpret_cast<const char*>(&players[index]), sizeof(PlayerModel));
        file.close();
        std::cout << "Player saved" << std::endl;
    } else {
        std::cout << "File not found" << std::endl;
    }
}

void dumpByIndexTxt(const std::vector<PlayerModel> &players, int index) {
    std::ofstream file("players.txt", std::ios::app);

    if (file.is_open()) {
        file << players[index].getName() << " " << players[index].getScore() << " " << players[index].getPlace() << std::endl;
        file.close();
        std::cout << "Player saved" << std::endl;
    } else {
        std::cout << "File not found" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const PlayerModel& player) {
    out << player.getName() << " " << player.getScore() << " " << player.getPlace() << " " << std::endl;
    return out;

}

std::istream& operator>>(std::istream &in, PlayerModel& player) {
    std::string name;
    int score, place;

    in >> name >> score >> place;

    player.setName(name);
    player.setScore(score);
    player.setPlace(place);

    return in;
}


