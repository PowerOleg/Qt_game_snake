#include "game.h"
#include <QDebug>

Game::Game()
{
     this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
     this->setWindowTitle("Snake game");
    InitGame();
}

void Game::timerEvent(QTimerEvent *)
{
    //qDebug() << 1;
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    qDebug() << key;
}

void Game::InitGame()
{
    m_in_game = true;

    m_dots.resize(3);
    for (int i = 0; i < m_dots.size(); ++i) {
        m_dots[i].rx() = m_dots.size() - i;
        m_dots[i].ry() = 0;
    }

    //LocateApple();

    m_timer_id = startTimer(DELAY);
}
