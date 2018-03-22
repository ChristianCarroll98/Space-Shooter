#include <Level.h>
#include <vector>
#include <cstdlib>

#include "Enemy.h"

Level::Level(int pickupC, std::vector<std::string> enemyT){
    enemyTypes = enemyT;
    pickupChance = pickupC;
    std::vector<std::string> tempEnemyT;
    
    int basicEnemyWeight = 3;
    int advancedEnemyWeight = 2;
    int smallEnemyWeight = 3;
    int mineWeight = 2;
    
    for(int i = 0; i<enemyTypes.size(); i++){
        if(enemyTypes.at(i) == "basicEnemy"){
            for(int j = 0; j<basicEnemyWeight; j++){
                tempEnemyT.push_back("basicEnemy");
            }
        }else if(enemyTypes.at(i) == "advancedEnemy"){
            for(int j = 0; j<advancedEnemyWeight; j++){
                tempEnemyT.push_back("advancedEnemy");
            }
        }else if(enemyTypes.at(i) == "smallEnemy"){
            for(int j = 0; j<smallEnemyWeight; j++){
                tempEnemyT.push_back("smallEnemy");
            }
        }else if(enemyTypes.at(i) == "mine"){
            for(int j = 0; j<mineWeight; j++){
                tempEnemyT.push_back("mine");
            }
        }
    }
    /*enemyTypes.clear();
    for(int i = 0; i<tempEnemyT.size(); i++){
        enemyTypes.push_back(tempEnemyT.at(i));
    }*/
    enemyTypes = tempEnemyT;
}

std::string Level::getRandomEnemy(){
    return enemyTypes.at((int)(std::rand() % enemyTypes.size()));
}

std::string Level::getPickup(){
    
}