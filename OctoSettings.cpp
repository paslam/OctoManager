#include "OctoSettings.h"

OctoSettings* OctoSettings::s_instance = 0;

OctoSettings::OctoSettings()
{
  m_general = new OctoSettingsGeneral(this);
  connect(m_general, SIGNAL(workspaceDirChanged(QString)),
          SLOT(workspaceDirChanged(QString)));
  m_workspace = new OctoSettingsWorkspace(m_general);
}

OctoSettings::~OctoSettings()
{
  delete m_workspace;
  delete m_general;
}

OctoSettings *OctoSettings::instance()
{
  if(s_instance == 0)
  {
    s_instance = new OctoSettings();
  }
  return s_instance;
}

void OctoSettings::workspaceDirChanged(const QString &)
{
  delete m_workspace;
  m_workspace = new OctoSettingsWorkspace(m_general);
  emit workspaceChanged();
}

OctoSettings *settings()
{
  return OctoSettings::instance();
}
