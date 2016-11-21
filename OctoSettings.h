#ifndef OCTOSETTINGS_H
#define OCTOSETTINGS_H

#include <QObject>
#include "OctoSettingsGeneral.h"
#include "OctoSettingsWorkspace.h"

class OctoSettings : public QObject
{
  Q_OBJECT
private:
  OctoSettings();

public:
  ~OctoSettings();

  static OctoSettings* instance();

  inline OctoSettingsGeneral* general() { return m_general;}
  inline OctoSettingsWorkspace* workspace() { return m_workspace;}

signals:
  void workspaceChanged();

private slots:
  void workspaceDirChanged(const QString&);

private:
  static OctoSettings* s_instance;
  OctoSettingsGeneral* m_general;
  OctoSettingsWorkspace* m_workspace;
};

OctoSettings* settings();

#endif // OCTOSETTINGS_H
