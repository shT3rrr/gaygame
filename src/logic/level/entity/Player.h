#ifndef LB3_PLAYER_H
#define LB3_PLAYER_H


#include "src/util/Vector.h"

class Player {
private:
    int health;
    int score;
    Vector position;

public:
    Player(int health, int score, Vector position);
    Player();

    int get_health() const;
    int get_score() const;
    const Vector &get_position() const;
    void set_health(int new_health);
    void set_score(int new_score);
    void set_position(const Vector& new_position);
};

#endif