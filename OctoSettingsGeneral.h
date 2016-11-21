#ifndef OCTOGENERALSETTINGS_H
#define OCTOGENERALSETTINGS_H

#include <QSettings>

class OctoClient;
class OctoSettingsGeneral : protected QSettings
{
  Q_OBJECT
public:
  explicit OctoSettingsGeneral(QObject* parent);
  ~OctoSettingsGeneral();

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
};

#endif // OCTOGENERALSETTINGS_H
