#include "OctoButtonManager.h"

OctoButtonManager::OctoButtonManager(QWidget* parent)
  : OctoButton(parent)
{
  setText("OM");
  connect(this, SIGNAL(clicked()), SIGNAL(showManager()));
}

OctoButtonManager::~OctoButtonManager()
{

}

