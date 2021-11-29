//
// Created by pe2ch on 11.11.21.
//

#include "../headers/SnakeWindow.hpp"

SnakeWindow::SnakeWindow(QWidget *parent) : collisions_(snake_, apple_),
                                            painter_(snake_, apple_) {
  setStyleSheet("background-color:black;");
  setFixedSize(WindowConstants::window_width, WindowConstants::window_height);
  update();
  timer_id = startTimer(DELAY);
  cur_time_ = 0;
  last_time_ = -1;
}

void SnakeWindow::timerEvent(QTimerEvent *) {

  cur_time_++;
  event_ = collisions_.CheckCollisions();
  switch (event_) {
    case Event::kGrow: {
      auto st = snake_.GetSnakeCells();
      while(st.count(apple_.GetCell())) apple_.SetNewApple();
      snake_.Grow();
      snake_.Move();
    }
      break;
    case Event::kMove : {
      snake_.Move();
    }
      break;
    case Event::kNothing : {
      return;
    }
  }
  update();
}

void SnakeWindow::keyPressEvent(QKeyEvent *event) {
  if (last_time_ == cur_time_) return;
  int key = event->key();
  Direction dir = snake_.GetDirection();
  if ((key == Qt::Key_Left) && dir != Direction::kRight) {
    snake_.SetDirection(Direction::kLeft);
    cur_time_ = last_time_;
  }

  if ((key == Qt::Key_Right) && dir != Direction::kLeft) {
    snake_.SetDirection(Direction::kRight);
    cur_time_ = last_time_;
  }

  if ((key == Qt::Key_Up) && dir != Direction::kDown) {
    snake_.SetDirection(Direction::kUp);
    cur_time_ = last_time_;
  }

  if ((key == Qt::Key_Down) && dir != Direction::kUp) {
    snake_.SetDirection(Direction::kDown);
    cur_time_ = last_time_;
  }

  QWidget::keyPressEvent(event);
}


void SnakeWindow::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  using namespace WindowConstants;
  QPainter qp(this);
  switch (event_) {
    case Event::kLose: {
      GameOver(qp);
    }
      break;
    default : {
      painter_.FillBackGround(qp);
      painter_.DrawApple(qp);
      painter_.DrawSnake(qp);
    }

  }
}

void SnakeWindow::GameOver(QPainter &qp) {

  QFont font("Courier", 10, QFont::ExtraBold);
  int textWidth = WindowConstants::window_width/2;

  qp.setFont(font);
  int h = height();
  int w = width();


  record_ = snake_.GetSize() - 1;
  QString message2;
  std::ifstream istream("../data/record.txt");
  int cur_record;
  istream >> cur_record;
  if(cur_record < record_) {
    cur_record = record_;
    message2 = QString("New record!!! \n") + QString("Your points: ") +
        QString::number(record_);
    istream.close();
    std::ofstream ostream("../data/record.txt");
    ostream << cur_record;
    qp.translate(QPoint(w / 2 - 10, h / 2));
    qp.drawText(-textWidth / 2, 0, message2);
  }  else {

    QString message1 = QString("Game over!  ") + QString("Your points: ") +
        QString::number(record_);
    QString message2 = QString("Record is: ") + QString::number(cur_record);
    qp.translate(QPoint(w / 2, h / 2));
    qp.drawText(-textWidth / 2 - 10, 0, message1);
    qp.drawText(-textWidth / 2 + 40, 15, message2);

  }

}
