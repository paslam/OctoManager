#include "OctoDashScene.h"
#include "OctoManagerView.h"
#include <QDesktopServices>
#include "OctoButtonManager.h"
#include <QUrl>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>

OctoDashScene::OctoDashScene()
{
  m_managerView = new OctoManagerView;

  OctoButtonManager* managerItem = new OctoButtonManager;
  connect(managerItem, SIGNAL(showManager()), SLOT(showManager()));
  connect(managerItem, SIGNAL(showFolder(QString)), SLOT(showFolder(QString)));
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
