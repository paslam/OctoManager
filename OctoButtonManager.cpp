#include "OctoButtonManager.h"
#include "OctoButtonProject.h"
#include "OctoSettings.h"
#include "OctoItem.h"

#define _USE_MATH_DEFINES
#include <math.h>

OctoItem* OctoButtonManager::s_itemManager = new OctoItem;

OctoButtonManager::OctoButtonManager()
  : OctoButtonItem(s_itemManager, 75)
{
  //setText("OM");
  //connect(this, SIGNAL(clicked()), SIGNAL(showManager()));

  const QList<OctoProject*> & projects = settings()->workspace()->projects();
  OctoProject* activeProject = settings()->workspace()->activeProject();
  int offset = 0;
  if(activeProject)
  {
    offset = projects.indexOf(activeProject);
  }

  for(int i = 0; i < projects.count(); ++i)
  {
    int offsetId = (i + offset) % projects.count();
    OctoProject* project = projects[offsetId];
    OctoButtonProject* itemProject = new OctoButtonProject(project);
    connect(itemProject, SIGNAL(showFolder(QString)), SIGNAL(showFolder(QString)));

    double angle = (2*M_PI / projects.count()) * i - M_PI/2;
    double totalRadius = radius() + itemProject->radius() + 20;
    double x = cos(angle)*totalRadius;
    double y = sin(angle)*totalRadius;

    itemProject->moveBy(x, y);
    itemProject->setParentItem(this);
  }
}

OctoButtonManager::~OctoButtonManager()
{

}

