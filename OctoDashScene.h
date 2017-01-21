#ifndef OCTODASHLOGIC_H
#define OCTODASHLOGIC_H

#include <QGraphicsScene>

class OctoButtonManager;
class OctoManagerView;
class OctoDashScene : public QGraphicsScene
{
  Q_OBJECT
public:
  explicit OctoDashScene();
  ~OctoDashScene();

signals:
  void hideDashScreen();

public slots:
  void showManager();
  void showFolder(const QString& folder);
  void copyPath(const QString& path);

protected:
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

private:
  OctoManagerView* m_managerView;
};

#endif // OCTODASHLOGIC_H
