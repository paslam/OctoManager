#ifndef OCTOBUTTON_H
#define OCTOBUTTON_H

#include <QPushButton>

class OctoButtonItem : public QPushButton
{
  Q_OBJECT
public:
  OctoButtonItem(int radius, QWidget* parent);
  ~OctoButtonItem();

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

protected:
  void paintEvent(QPaintEvent *event);

private:
  int m_radius;
};

#endif // OCTOBUTTON_H
