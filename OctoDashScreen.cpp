#include "OctoDashScreen.h"
#include "OctoDash.h"
#include <QPainter>
#include <QDesktopWidget>
#include <OctoDashLogic.h>

OctoDashScreen::OctoDashScreen(QWidget *parent) : QMainWindow(parent)
{
  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_NoSystemBackground);
  setAttribute(Qt::WA_TranslucentBackground);

  m_dash = new OctoDash;
  setCentralWidget(m_dash);

  m_dashLogic = new OctoDashLogic(m_dash);
  connect(m_dashLogic, SIGNAL(hideDashScreen()), SLOT(hide()));

  showFullScreen();
}

OctoDashScreen::~OctoDashScreen()
{

}

void OctoDashScreen::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setOpacity(0.2);
  painter.setBrush(Qt::black);
  painter.drawRect(rect());
}

void OctoDashScreen::mousePressEvent(QMouseEvent *)
{
  close();
}

