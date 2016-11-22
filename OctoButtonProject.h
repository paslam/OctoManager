#ifndef OCTOBUTTONPROJECT_H
#define OCTOBUTTONPROJECT_H

#include "OctoButtonItem.h"

class OctoProject;
class OctoButtonProject : public OctoButtonItem
{
  Q_OBJECT
public:
  OctoButtonProject(OctoProject* project, QWidget* parent = 0);
  ~OctoButtonProject();

private slots:
  void onClick();

signals:
  void showFolder(const QString& path);

private:
  OctoProject* m_project;
};

#endif // OCTOBUTTONPROJECT_H
