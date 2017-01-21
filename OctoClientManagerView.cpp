#include "OctoClientManagerView.h"
#include "ui_OctoClientManagerView.h"
#include <QKeyEvent>
#include <QFocusEvent>
#include "OctoClient.h"
#include <QFileDialog>
#include <QPainter>

OctoClientManagerView::OctoClientManagerView(OctoClient* client, QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OctoClientManagerView),
  m_client(client)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

  move(
         parent->window()->frameGeometry().topLeft() +
         parent->window()->rect().center() - rect().center()
      );

  ui->editClientName->setText(client->name());
  ui->editClientName->setFocus(Qt::OtherFocusReason);

  loadAvatar();
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

void OctoClientManagerView::loadAvatar()
{
  if(m_client->hasAvatar())
  {
    ui->btnAvatar->setText("");
    ui->btnAvatar->setIcon(QIcon(m_client->avatarPath()));
  }
}

void OctoClientManagerView::on_btnAvatar_clicked()
{
  QString imageUrl = QFileDialog::getOpenFileName(this,
       tr("Select Avatar"), "", tr("Image Files (*.png *.jpg *.bmp)"));

  if(!imageUrl.isEmpty())
  {
    const int DIM = 100;
    QPixmap target(DIM, DIM); // the size may vary
    target.fill(Qt::transparent);
    QPixmap source(imageUrl);
    source = source.scaled(DIM, DIM, Qt::IgnoreAspectRatio,
                           Qt::SmoothTransformation);

    QPainter painter(&target);
    QRegion r(QRect(0, 0, DIM, DIM), QRegion::Ellipse);
    painter.setClipRegion(r);
    painter.drawPixmap(0, 0, source);

    target.save(m_client->avatarPath());

    loadAvatar();
  }
}
