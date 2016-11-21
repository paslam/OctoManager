#include "OctoProject.h"
#include <QUuid>
#include "OctoClient.h"

OctoProject::OctoProject(OctoClient* client) :
  OctoItem(client),
  m_client(client)
{
}

OctoProject::~OctoProject()
{

}

OctoClient *OctoProject::client() const
{
  return m_client;
}



