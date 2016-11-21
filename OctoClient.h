#ifndef OCTOCLIENT_H
#define OCTOCLIENT_H

#include "OctoItem.h"

class OctoClient : public OctoItem
{
  Q_OBJECT
public:
  explicit OctoClient(QObject *parent = 0);
  ~OctoClient();
};

#endif // OCTOCLIENT_H
