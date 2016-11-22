#include "OctoDashView.h"
#include <QPainter>
#include <QDesktopWidget>
#include <OctoDashScene.h>
#include <OctoButtonManager.h>
#include <QGraphicsScene>
#include <QDebug>
#include <QMouseEvent>

OctoDashView::OctoDashView(QWidget *parent) : QGraphicsView(parent)
{
  setWindowFlags(Qt::FramelessWindowHint);
  setAttribute(Qt::WA_NoSystemBackground);
  setAttribute(Qt::WA_TranslucentBackground);
  setStyleSheet("background: transparent");

  m_dashScene = new OctoDashScene;
  setScene(m_dashScene);

  connect(m_dashScene, SIGNAL(hideDashScreen()), SLOT(hide()));

  showFullScreen();
}

OctoDashView::~OctoDashView()
{
  delete m_dashScene;
}

void OctoDashView::mousePressEvent(QMouseEvent *event)
{
  if (scene()->itemAt(event->pos(), transform()) == NULL)
  {
    close();
  }
}
