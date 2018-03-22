#ifndef LEVEL_H
#define LEVEL_H

#include <vector>
#include <string>

class Level {
private:
    int spawnFrequency;
    int pickupChance;
public:
    Level(int pickupC, std::vector<std::string> enemyT);
    
    std::vector<std::string> enemyTypes;
    
    std::string getRandomEnemy();
    std::string getPickup();
};

#endif
