#ifndef OCTODASHBACK_H
#define OCTODASHBACK_H

#include <QGraphicsView>

class OctoButtonManager;
class OctoDashScene;
class QGraphicsScene;
class OctoDashView : public QGraphicsView
{
  Q_OBJECT
public:
  explicit OctoDashView(QWidget *parent = 0);
  ~OctoDashView();

protected:
  void mousePressEvent(QMouseEvent *);

  void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
  OctoDashScene* m_dashScene;
};

#endif // OCTODASHBACK_H
