#ifndef OCTOBUTTONMANAGER_H
#define OCTOBUTTONMANAGER_H

#include "OctoButtonItem.h"
class OctoButtonManager : public OctoButtonItem
{
  Q_OBJECT
public:
  OctoButtonManager(QWidget* parent = 0);
  ~OctoButtonManager();

signals:
  void showManager();
};

#endif // OCTOBUTTONMANAGER_H
