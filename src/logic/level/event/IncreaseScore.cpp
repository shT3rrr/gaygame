#include "IncreaseScore.h"

bool IncreaseScore::game_event(Player &player) {
    int score = player.get_score();
    if (score + 100 > 1300){
        score = 1300;
    }
    else{
        score += 100;
    }
    player.set_score(score);
    return true;
}
