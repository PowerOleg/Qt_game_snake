#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QVector>
#include <QPoint>
#include <QKeyEvent>

class Game : public QWidget
{
    //Q_OBJECT
public:
    Game(/*QWidget* parent*/);

protected:
    void timerEvent(QTimerEvent*) override;
    void keyPressEvent(QKeyEvent* event) override;

private:
    static const int DOT_HEIGHT = 20;
    static const int DOT_WIDTH = 20;
    static const int FIELD_HEIGHT = 20;//quantity of dots
    static const int FIELD_WIDTH = 20;
    static const int DELAY = 150;

    int m_timer_id;

    bool m_in_game = false;
    QVector<QPoint> m_dots;

    void InitGame();
};

#endif // GAME_H
