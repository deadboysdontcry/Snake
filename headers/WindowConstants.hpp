#ifndef HEADERS_WINDOWCONSTANTS_HPP_
#define HEADERS_WINDOWCONSTANTS_HPP_

#include <QImage>

namespace WindowConstants {

const static QImage APPLE_IMG = QImage("../pics/apple big.png");
const static QImage BACKGROUND_IMG = QImage("../pics/background.png");
const static QImage SNAKE_HEAD_IMG = QImage("../pics/snake head big.png");
const static QImage SNAKE_TAIL_IMG = QImage("../pics/snake tail big.png");

const static int window_height = 640, window_width = 640;
const static int cell_size = 64;
const static int cells_x_cnt = window_width / cell_size, cells_y_cnt = window_height / cell_size;

}

#endif //HEADERS_WINDOWCONSTANTS_HPP_
