#include "OctoDashView.h"
#include <QPainter>
#include <QDesktopWidget>
#include <OctoDashScene.h>
#include <OctoButtonManager.h>
#include <QGraphicsScene>
#include <QDebug>
#include <QMouseEvent>
#include <QApplication>

#include "qxtglobalshortcut.h"

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

  QxtGlobalShortcut* showShortcut = new QxtGlobalShortcut(this);
  showShortcut->setShortcut(QKeySequence(Qt::CTRL + Qt::ALT + Qt::Key_Z));
  connect(showShortcut, SIGNAL(activated()), SLOT(showFullScreen()));
}

OctoDashView::~OctoDashView()
{
  delete m_dashScene;
}


