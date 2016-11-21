#ifndef OCTODASHLOGIC_H
#define OCTODASHLOGIC_H

#include <QObject>

class OctoDash;
class OctoManagerView;
class OctoDashLogic : public QObject
{
  Q_OBJECT
public:
  explicit OctoDashLogic(OctoDash* dash);
  ~OctoDashLogic();

signals:
  void hideDashScreen();

public slots:
  void showManager();
  void showFolder(const QString& folder);

private:
  OctoManagerView* m_managerView;
};

#endif // OCTODASHLOGIC_H
