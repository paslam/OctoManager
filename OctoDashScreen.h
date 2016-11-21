#ifndef OCTODASHBACK_H
#define OCTODASHBACK_H

#include <QMainWindow>

class OctoDash;
class OctoDashLogic;
class OctoDashScreen : public QMainWindow
{
  Q_OBJECT
public:
  explicit OctoDashScreen(QWidget *parent = 0);
  ~OctoDashScreen();
  inline OctoDash* dash() { return m_dash; }

protected:
  void paintEvent(QPaintEvent *);
  void mousePressEvent(QMouseEvent *);

private:
  OctoDash* m_dash;
  OctoDashLogic* m_dashLogic;
};

#endif // OCTODASHBACK_H
