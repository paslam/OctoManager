#include "OctoClient.h"
#include <QFileInfo>

OctoClient::OctoClient(OctoItem *parent) : OctoItem(parent)
{

}

OctoClient::~OctoClient()
{

}

QString OctoClient::avatarPath() const
{
  return path() + "/" + "avatar.png";
}

bool OctoClient::hasAvatar() const
{
  return QFileInfo(avatarPath()).exists();
}
