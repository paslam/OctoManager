#include "OctoProjectManagerView.h"
#include "ui_OctoProjectManagerView.h"
#include <QKeyEvent>
#include "OctoProject.h"

OctoProjectManagerView::OctoProjectManagerView(OctoProject* project,
                                               QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OctoProjectManagerView),
  m_project(project)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Popup);

  move(
         parent->window()->frameGeometry().topLeft() +
         parent->window()->rect().center() - rect().center()
      );

  ui->editProjectName->setText(project->name());
  ui->editProjectName->setFocus(Qt::OtherFocusReason);
}

OctoProjectManagerView::~OctoProjectManagerView()
{
  delete ui;
}

void OctoProjectManagerView::keyPressEvent(QKeyEvent *e)
{
  QDialog::keyPressEvent(e);

  if(e->key() ==  Qt::Key_Return)
  {
    accept();
  }
}

void OctoProjectManagerView::on_OctoProjectManagerView_accepted()
{
  m_project->setName(ui->editProjectName->text());
}
