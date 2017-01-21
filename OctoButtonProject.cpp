#include "OctoButtonProject.h"
#include "OctoProject.h"

#include "OctoClient.h"

#include <QDir>

OctoButtonProject::OctoButtonProject(OctoProject* project)
  : OctoButtonItem(project, 50), m_project(project)
{
  connect(this, SIGNAL(clickedLeft()), SLOT(onLeftClick()));
  connect(this, SIGNAL(clickedRight()), SLOT(onRightClick()));
  setIconPath(project->client()->avatarPath());
}

OctoButtonProject::~OctoButtonProject()
{

}

void OctoButtonProject::onLeftClick()
{
  emit showFolder(m_project->path());
}

void OctoButtonProject::onRightClick()
{
  emit copyPath(m_project->path());
}

