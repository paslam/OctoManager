#ifndef OCTOBUTTONPROJECT_H
#define OCTOBUTTONPROJECT_H

#include "OctoButtonItem.h"

class OctoProject;
class OctoButtonProject : public OctoButtonItem
{
  Q_OBJECT
public:
  OctoButtonProject(OctoProject* project);
  ~OctoButtonProject();

private slots:
  void onLeftClick();
  void onRightClick();

signals:
  void showFolder(const QString& path);
  void copyPath(const QString& path);

private:
  OctoProject* m_project;
};

#endif // OCTOBUTTONPROJECT_H
