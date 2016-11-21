#include "OctoDash.h"
#include "OctoButtonProject.h"
#include "OctoButtonManager.h"
#include "OctoSettings.h"
#include <cmath>

OctoDash::OctoDash(QWidget *parent)
  : QWidget(parent)
{
  setFixedSize(800, 800);

  OctoButtonManager* managerBtn = new OctoButtonManager(this);
  connect(managerBtn, SIGNAL(showManager()), SIGNAL(showManager()));

  const QList<OctoProject*> & projects = settings()->workspace()->projects();
  double radius = 200;
  for(int i = 0; i < projects.count(); ++i)
  {
    OctoProject* project = projects[i];
    OctoButtonProject* projectBtn = new OctoButtonProject(project, this);
    connect(projectBtn, SIGNAL(showFolder(QString)), SIGNAL(showFolder(QString)));

    double angle = (2*M_PI / projects.count()) * i - M_PI/2;
    double x = cos(angle)*radius;
    double y = sin(angle)*radius;

    projectBtn->centerAt(QPoint((int)x, (int)y));
  }
}

OctoDash::~OctoDash()
{

}