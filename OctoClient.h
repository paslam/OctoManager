#ifndef OCTOCLIENT_H
#define OCTOCLIENT_H

#include "OctoItem.h"

class OctoClient : public OctoItem
{
public:
  explicit OctoClient(OctoItem *parent = 0);
  virtual ~OctoClient();

  virtual QString avatarPath() const;
  virtual bool hasAvatar() const;
};

#endif // OCTOCLIENT_H
