#ifndef OCTOPROJECT_H
#define OCTOPROJECT_H

#include "OctoItem.h"

class OctoClient;
class OctoProject : public OctoItem
{
public:
  explicit OctoProject(OctoClient* client);
  virtual ~OctoProject();

  OctoClient* client() const;

private:
  OctoClient* m_client;
};

#endif // OCTOPROJECT_H
