#ifndef OCTOBUTTONMANAGER_H
#define OCTOBUTTONMANAGER_H

#include "OctoButton.h"
class OctoButtonManager : public OctoButton
{
  Q_OBJECT
public:
  OctoButtonManager(QWidget* parent = 0);
  ~OctoButtonManager();

signals:
  void showManager();
};

#endif // OCTOBUTTONMANAGER_H
