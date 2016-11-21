#include "OctoDashLogic.h"
#include "OctoDash.h"
#include "OctoManagerView.h"
#include <QDesktopServices>
#include <QUrl>

OctoDashLogic::OctoDashLogic(OctoDash* dash) : QObject(dash)
{
  m_managerView = new OctoManagerView;
  connect(dash, SIGNAL(showManager()), SLOT(showManager()));
  connect(dash, SIGNAL(showFolder(QString)), SLOT(showFolder(QString)));
}

OctoDashLogic::~OctoDashLogic()
{

}

void OctoDashLogic::showManager()
{
  emit hideDashScreen();
  m_managerView->show();
}

void OctoDashLogic::showFolder(const QString &path)
{
  emit hideDashScreen();
  QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

