#include "OctoDashScene.h"
#include "OctoManagerView.h"
#include <QDesktopServices>
#include "OctoButtonManager.h"
#include <QUrl>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QApplication>
#include <QClipboard>

OctoDashScene::OctoDashScene()
{
  m_managerView = new OctoManagerView;

  OctoButtonManager* managerItem = new OctoButtonManager;
  connect(managerItem, SIGNAL(showManager()), SLOT(showManager()));
  connect(managerItem, SIGNAL(showFolder(QString)), SLOT(showFolder(QString)));
  connect(managerItem, SIGNAL(copyPath(QString)), SLOT(copyPath(QString)));
  addItem(managerItem);
}

OctoDashScene::~OctoDashScene()
{
  delete m_managerView;
}

void OctoDashScene::showManager()
{
  emit hideDashScreen();
  m_managerView->show();
}

void OctoDashScene::showFolder(const QString &path)
{
  emit hideDashScreen();
  QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void OctoDashScene::copyPath(const QString &path)
{
  emit hideDashScreen();
  QApplication::clipboard()->setText(path);
}

void OctoDashScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsScene::mousePressEvent(event);

  if (itemAt(event->scenePos(), QTransform()) == NULL)
  {
    emit hideDashScreen();
    //exit(0); //TEMP
  }
}
