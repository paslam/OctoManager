#include "OctoSettingsWorkspace.h"
#include "OctoProject.h"
#include "OctoSettingsGeneral.h"
#include "OctoClient.h"
#include <QDir>

OctoSettingsWorkspace::OctoSettingsWorkspace(OctoSettingsGeneral* generalSettings)
  : QSettings(generalSettings->workspaceDir() + "/.octoworkspace", QSettings::IniFormat),
    m_generalSettings(generalSettings)
{
  beginGroup("Workspace");

  loadProjects();
}

OctoSettingsWorkspace::~OctoSettingsWorkspace()
{
  endGroup();
}

void OctoSettingsWorkspace::setActiveProject(OctoProject *project)
{
  setValue("ActiveProjectUuid", project->uuid());
}

OctoProject *OctoSettingsWorkspace::activeProject()
{
  return project(value("ActiveProjectUuid").toString());
}

void OctoSettingsWorkspace::createFolder(OctoProject *project)
{
  QDir projectDir(m_generalSettings->workspaceDir() +
                  QDir::separator() +
                  project->client()->name() +
                  QDir::separator() +
                  project->name());
  projectDir.mkpath(".");
}

void OctoSettingsWorkspace::saveProject(OctoProject *project)
{
  if(m_projectsMap.find(project->uuid()) == m_projectsMap.end())
  {
    m_projects << project;
    m_projectsMap[project->uuid()] = project;
    createFolder(project);
  }

  beginWriteArray("Projects");
  for(int i = 0; i < m_projects.size(); ++i)
  {
    OctoProject* p = m_projects[i];
    setArrayIndex(i);
    setValue("Name", p->name());
    setValue("Uuid", p->uuid());
    setValue("ClientUuid", p->client()->uuid());
  }
  endArray();
}

OctoProject* OctoSettingsWorkspace::project(const QString &uuid)
{
  return m_projectsMap.value(uuid);
}

const QList<OctoProject*> &OctoSettingsWorkspace::projects() const
{
  return m_projects;
}

void OctoSettingsWorkspace::loadProjects()
{
  m_projects.clear();
  m_projectsMap.clear();
  int size = beginReadArray("Projects");
  for(int i = 0; i < size; ++i)
  {
    setArrayIndex(i);
    OctoClient* client = m_generalSettings->client(value("ClientUuid").toString());
    OctoProject* project = new OctoProject(client);
    project->setName(value("Name").toString());
    project->setUuid(value("Uuid").toString());
    m_projects << project;
    m_projectsMap[project->uuid()] = project;
    createFolder(project);
  }
  endArray();
}

