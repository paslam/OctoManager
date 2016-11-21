#ifndef OCTOPROJECT_H
#define OCTOPROJECT_H

#include "OctoItem.h"

class OctoClient;
class OctoProject : public OctoItem
{
  Q_OBJECT
public:
  explicit OctoProject(OctoClient* client);
  ~OctoProject();

  OctoClient* client() const;

private:
  OctoClient* m_client;
};

#endif // OCTOPROJECT_H
