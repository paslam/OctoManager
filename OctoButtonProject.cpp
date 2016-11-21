#include "OctoButtonProject.h"
#include "OctoProject.h"

//TODO REMOVE THESE DEPS
#include <OctoSettings.h>
#include "OctoClient.h"

#include <QDir>

OctoButtonProject::OctoButtonProject(OctoProject* project, QWidget* parent)
  : OctoButton(parent), m_project(project)
{
  setText(project->name());
  connect(this, SIGNAL(clicked()), SLOT(onClick()));
}

OctoButtonProject::~OctoButtonProject()
{

}

void OctoButtonProject::onClick()
{
  //TODO REMOVE THESE DEPS
  QString path = settings()->general()->workspaceDir();
  path += QDir::separator() + m_project->client()->name();
  path += QDir::separator() + m_project->name();
  emit showFolder(path);
}

