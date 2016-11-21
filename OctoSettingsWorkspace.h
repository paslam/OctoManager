#ifndef OCTOWORKSPACESETTINGS_H
#define OCTOWORKSPACESETTINGS_H

#include <QSettings>
#include <QList>
#include <QMap>

class OctoProject;
class OctoSettingsGeneral;
class OctoSettingsWorkspace : protected QSettings
{
  Q_OBJECT
public:
  explicit OctoSettingsWorkspace(OctoSettingsGeneral* generalSettings);
  ~OctoSettingsWorkspace();

  void setActiveProject(OctoProject* project);
  OctoProject* activeProject();

  void saveProject(OctoProject* project);
  OctoProject* project(const QString& uuid);
  const QList<OctoProject*>& projects() const;

private:
  void loadProjects();
  void createFolder(OctoProject *project);

  OctoSettingsGeneral* m_generalSettings;
  QList<OctoProject*> m_projects;
  QMap<QString, OctoProject*> m_projectsMap;
};

#endif // OCTOWORKSPACESETTINGS_H
