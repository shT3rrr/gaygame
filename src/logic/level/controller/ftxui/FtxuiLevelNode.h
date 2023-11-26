
#ifndef GAME_FTXUILEVELNODE_H
#define GAME_FTXUILEVELNODE_H


#include "FtxuiRenderModel.h"
#include "src/logic/level/event/IncreaseHealth.h"
#include "src/logic/level/event/IncreaseScore.h"
#include "src/logic/level/event/ReduceHealth.h"
#include "src/logic/level/event/TeleportPlayer.h"

class FtxuiLevelNode : public ftxui::Node {
private:
    std::unique_ptr<FtxuiRenderModel> &_model;

public:

    explicit FtxuiLevelNode(std::unique_ptr<FtxuiRenderModel> &model) : _model(model) {
    }

    void Render(ftxui::Screen &screen) override {
        if (_model == nullptr) {
            return;
        }

        requirement_.min_x = _model->field->get_width();
        requirement_.min_y = _model->field->get_heigth();

        auto field = _model->field;
        auto playerPosition = _model->player.get_position();

        for (int i = 0; i < field->get_heigth(); ++i) {
            for (int j = 0; j < field->get_width(); ++j) {
                ftxui::Pixel pixel;
                pixel.foreground_color = ftxui::Color::Default;
                pixel.background_color = ftxui::Color::Default;
                pixel.bold = false;
                pixel.blink = false;

                Vector act_pos(i, j);
                Cell &actual_cell = field->get_cell_for_index(act_pos);
                if (actual_cell.get_is_passable()) {
                    if (i == playerPosition.x && j == playerPosition.y) {
                        pixel.character = 'P';
                        pixel.foreground_color = ftxui::Color::Red;
                        pixel.bold = true;
                    } else if (i == field->get_finish().x && j == field->get_finish().y) {
                        pixel.character = 'F';
                        pixel.foreground_color = ftxui::Color::Green;
                        pixel.blink = true;
                        pixel.bold = true;
                    } else {
                        IGameEvent *event = actual_cell.get_gameEvent();
                        if (event == nullptr) {
                            pixel.character = ' ';
                        } else {
                            if (dynamic_cast<IncreaseHealth *>(event)) {
                                pixel.background_color = ftxui::Color::White;
                                pixel.foreground_color = ftxui::Color::Red;
                                pixel.bold = true;
                                pixel.character = '+';
                            } else if (dynamic_cast<IncreaseScore *>(event)) {
                                pixel.foreground_color = ftxui::Color::Gold1;
                                pixel.bold = true;
                                pixel.character = '*';
                            } else if (dynamic_cast<ReduceHealth *>(event)) {
                                pixel.foreground_color = ftxui::Color::Red;
                                pixel.bold = true;
                                pixel.character = '%';
                            } else if (dynamic_cast<TeleportPlayer *>(event)) {
                                pixel.foreground_color = ftxui::Color::Purple;
                                pixel.bold = true;
                                pixel.character = '@';
                            }

                        };
                    }
                } else {
                    pixel.character = "⣿";
                }

                screen.PixelAt(box_.x_min + j, box_.y_min + i) = pixel;
            }
        }
    }
};


#endif //GAME_FTXUILEVELNODE_H
