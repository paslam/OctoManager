#include "OctoButton.h"

OctoButton::OctoButton(QWidget* parent) : QPushButton(parent)
{
  setObjectName("OctoButton");
  centerAt(QPoint());
}

OctoButton::~OctoButton()
{

}

void OctoButton::centerAt(QPoint pos)
{
  QWidget* parentBtn = dynamic_cast<QWidget*>(parent());
  move(-rect().center()/2 + parentBtn->rect().center() + pos);
}
