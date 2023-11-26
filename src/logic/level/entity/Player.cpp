#include <algorithm>
#include "Player.h"

Player::Player(int new_health, int new_score, Vector new_position):
        health(std::clamp(new_health, 0, 100)),
        score(std::clamp(new_score, 0, 1300)),
        position(new_position){
}

Player::Player(){
        health = 100;
        score = 0;
        Vector a;
        position = a;
}

int Player::get_health() const {
    return health;
}

int Player::get_score() const {
    return score;
}

const Vector & Player::get_position() const {
    return position;
}

void Player::set_health(int new_health) {
    health = std::clamp(new_health, 0, 100);
}

void Player::set_score(int new_score){
    score = std::clamp(new_score, 0, 1000);
}

void Player::set_position(const Vector &new_position) {
    position = new_position;
}




