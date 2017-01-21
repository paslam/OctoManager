#ifndef OCTOGENERALSETTINGS_H
#define OCTOGENERALSETTINGS_H

#include <QSettings>

class OctoClient;
class OctoItem;
class OctoSettingsGeneral : public QSettings
{
  Q_OBJECT
public:
  explicit OctoSettingsGeneral();
  virtual ~OctoSettingsGeneral();

  void setWorkspaceDir(const QString& path);
  QString workspaceDir() const;

  void saveClient(OctoClient* client);
  OctoClient* client(const QString& uuid);
  const QList<OctoClient*>& clients() const;

signals:
  void workspaceDirChanged(const QString& path);

private:
  void loadClients();
  QList<OctoClient*> m_clients;
  QMap<QString, OctoClient*> m_clientsMap;
  OctoItem* m_workspaceItem;
};

#endif // OCTOGENERALSETTINGS_H
