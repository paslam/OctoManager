#include "OctoClientmanagerview.h"
#include "ui_octoclientmanagerview.h"
#include <QKeyEvent>
#include <QFocusEvent>
#include "OctoClient.h"

OctoClientManagerView::OctoClientManagerView(OctoClient* client, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OctoClientManagerView),
  m_client(client)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Popup);

  move(
         parent->window()->frameGeometry().topLeft() +
         parent->window()->rect().center() - rect().center()
      );

  ui->editClientName->setText(client->name());
  ui->editClientName->setFocus(Qt::OtherFocusReason);
}

OctoClientManagerView::~OctoClientManagerView()
{
  delete ui;
}

void OctoClientManagerView::keyPressEvent(QKeyEvent *e)
{
  QDialog::keyPressEvent(e);

  if(e->key() ==  Qt::Key_Return)
  {
    accept();
  }
}

void OctoClientManagerView::on_OctoClientManagerView_accepted()
{
  m_client->setName(ui->editClientName->text());
}
