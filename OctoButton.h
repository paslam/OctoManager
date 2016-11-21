#ifndef OCTOBUTTON_H
#define OCTOBUTTON_H

#include <QPushButton>

class OctoButton : public QPushButton
{
  Q_OBJECT
public:
  OctoButton(QWidget* parent);
  ~OctoButton();
  void centerAt(QPoint pos);
};

#endif // OCTOBUTTON_H
