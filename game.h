#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>
#include <QPainter>
#include <QPaintEvent>
#include <QTime>
#include <QMessageBox>


enum class Directions
{
    left,
    right,
    up,
    down
};

class Game : public QWidget
{
    //Q_OBJECT
public:
    Game(/*QWidget* parent*/);

protected:
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;
    void paintEvent(QPaintEvent* event) override;

private:
    static const int DOT_HEIGHT = 20;
    static const int DOT_WIDTH = 20;
    static const int FIELD_HEIGHT = 20;//quantity of dots
    static const int FIELD_WIDTH = 20;
    static const int DELAY = 150;

    int m_timer_id;
    Directions m_dir;
    bool m_in_game = false;
    QVector<QPoint> m_dots;
    QPoint m_apple;

    void LocateApple();
    void InitGame();
    void GameOver();
    void DoDrawing();
    void Move();
    void CheckField();
    void CheckIsAppleBitten();
};

#endif // GAME_H
