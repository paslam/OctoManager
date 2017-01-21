#ifndef OCTOBUTTONMANAGER_H
#define OCTOBUTTONMANAGER_H

#include "OctoButtonItem.h"
class OctoButtonManager : public OctoButtonItem
{
  Q_OBJECT
public:
  OctoButtonManager();
  ~OctoButtonManager();

signals:
  void showManager();
  void showFolder(const QString& path);
  void copyPath(const QString& path);

private:
  static OctoItem* s_itemManager;
};

#endif // OCTOBUTTONMANAGER_H
