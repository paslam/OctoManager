#include "OctoSettingsGeneral.h"
#include "OctoClient.h"
#include <QApplication>
#include <QDir>

OctoSettingsGeneral::OctoSettingsGeneral() :
  QSettings(QSettings::IniFormat, QSettings::UserScope,
            QApplication::organizationName(),
            QApplication::applicationName())
{
  beginGroup("General");

  loadClients();
}

OctoSettingsGeneral::~OctoSettingsGeneral()
{
  endGroup();
}

void OctoSettingsGeneral::setWorkspaceDir(const QString &path)
{
  if(path != workspaceDir())
  {
    setValue("WorkspaceDir", path);
    emit workspaceDirChanged(path);
  }
}

QString OctoSettingsGeneral::workspaceDir() const
{
  return value("WorkspaceDir").toString();
}

void OctoSettingsGeneral::saveClient(OctoClient *client)
{
  if(m_clientsMap.find(client->uuid()) == m_clientsMap.end())
  {
    m_clients << client;
    m_clientsMap[client->uuid()] = client;
  }

  beginWriteArray("Clients");
  for(int i = 0; i < m_clients.size(); ++i)
  {
    const OctoClient* c = m_clients[i];
    setArrayIndex(i);
    setValue("Name", c->name());
    setValue("Uuid", c->uuid());
  }
  endArray();
}

OctoClient* OctoSettingsGeneral::client(const QString &uuid)
{
  return m_clientsMap.value(uuid);
}

const QList<OctoClient*> &OctoSettingsGeneral::clients() const
{
  return m_clients;
}

void OctoSettingsGeneral::loadClients()
{
  m_clients.clear();
  m_clientsMap.clear();
  int size = beginReadArray("Clients");
  for(int i = 0; i < size; ++i)
  {
    setArrayIndex(i);
    OctoClient* client = new OctoClient(this);
    client->setName(value("Name").toString());
    client->setUuid(value("Uuid").toString());
    m_clients << client;
    m_clientsMap[client->uuid()] = client;
  }
  endArray();
}
