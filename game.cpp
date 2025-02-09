#include "game.h"
//#include <QDebug>

Game::Game()
{
     this->resize(DOT_WIDTH * FIELD_WIDTH, DOT_HEIGHT * FIELD_HEIGHT);
     this->setWindowTitle("Snake game");
    InitGame();
}

void Game::timerEvent(QTimerEvent *event)//main gameplay
{
    Q_UNUSED(event);

    if (m_in_game)
    {
        CheckIsAppleBitten();
        Move();
        CheckField();
    }
    this->repaint();
}

void Game::keyPressEvent(QKeyEvent *event)
{
    int key = event->key();
    if (key == Qt::Key_Left && m_dir != Directions::right)
    {
        m_dir = Directions::left;
    }
    if (key == Qt::Key_Right && m_dir != Directions::left)
    {
        m_dir = Directions::right;
    }
    if (key == Qt::Key_Up && m_dir != Directions::down)
    {
        m_dir = Directions::up;
    }
    if (key == Qt::Key_Down && m_dir != Directions::up)
    {
        m_dir = Directions::down;
    }
}

void Game::paintEvent(QPaintEvent *event)//draw all when init the Window and when this->repaint()
{
    Q_UNUSED(event);
    DoDrawing();
}

void Game::LocateApple()
{
    QTime time = QTime::currentTime();
    srand((uint) time.msec());
    m_apple.rx() = rand() % DOT_WIDTH;
    m_apple.ry() = rand() % DOT_HEIGHT;
}

void Game::InitGame()
{
    m_in_game = true;
    m_dir = Directions::right;
    m_dots.resize(3);
    for (int i = 0; i < m_dots.size(); ++i) {
        m_dots[i].rx() = m_dots.size() - i - 1;
        m_dots[i].ry() = 0;
    }

    LocateApple();
    m_timer_id = startTimer(DELAY);//start the slot timerEvent() with DELAY
}

void Game::GameOver()
{
    QMessageBox msg;
    msg.setText("Game Over");
    msg.exec();
    InitGame();
}

void Game::DoDrawing()
{
    QPainter qp(this);
    if (m_in_game)
    {
        qp.setBrush(Qt::red);
        qp.drawEllipse(m_apple.x() * DOT_WIDTH, m_apple.y() * DOT_HEIGHT, FIELD_WIDTH, FIELD_HEIGHT);

        for (int i = 0; i < m_dots.size(); ++i) {
            if (i == 0)
            {
                qp.setBrush(Qt::white);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, FIELD_WIDTH, FIELD_HEIGHT);
            } else
            {
                qp.setBrush(Qt::green);
                qp.drawEllipse(m_dots[i].x() * DOT_WIDTH, m_dots[i].y() * DOT_HEIGHT, FIELD_WIDTH, FIELD_HEIGHT);
            }
        }


    } else
    {
        GameOver();
    }

}

void Game::Move()
{
    for (int i = m_dots.size() - 1; i > 0; --i) {
        m_dots[i] = m_dots[i - 1];
    }

    switch (m_dir) {
    case Directions::left:
        m_dots[0].rx() -= 1;
        break;
    case Directions::right:
        m_dots[0].rx() += 1;
        break;
    case Directions::up:
        m_dots[0].ry() -= 1;
        break;
    case Directions::down:
        m_dots[0].ry() += 1;
        break;
    }
}

void Game::CheckField()
{
    if (m_dots.size() > 4)//check if snake bites himself
    {
        for (int i = 1; i < m_dots.size(); ++i) {
            if (m_dots[0] == m_dots[i])
            {
                m_in_game = false;
            }
        }
    }

    if (m_dots[0].x() >= FIELD_WIDTH)//check if snake out of field
    {
        m_in_game = false;
    }
    if (m_dots[0].x() < 0)
    {
        m_in_game = false;
    }
    if (m_dots[0].y() >= FIELD_HEIGHT)
    {
        m_in_game = false;
    }
    if (m_dots[0].y() < 0)
    {
        m_in_game = false;
    }
    if (!m_in_game)
    {
        killTimer(m_timer_id);
    }
}

void Game::CheckIsAppleBitten()
{
    if (m_apple == m_dots[0])
    {
        m_dots.emplaceBack(QPoint(0,0));//in method Move() last QPoint relocates
        LocateApple();
    }
}
