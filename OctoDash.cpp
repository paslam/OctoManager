#include "OctoDash.h"
#include "OctoButtonManager.h"
#include "OctoSettings.h"
#define _USE_MATH_DEFINES
#include <math.h>

OctoDash::OctoDash(QWidget *parent)
  : QWidget(parent)
{
  setFixedSize(800, 800);

  OctoButtonManager* managerBtn = new OctoButtonManager(this);
  connect(managerBtn, SIGNAL(showManager()), SIGNAL(showManager()));
}

OctoDash::~OctoDash()
{

}
