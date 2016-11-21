#include "OctoSettingsView.h"
#include "ui_OctoSettingsView.h"
#include <QKeyEvent>
#include "OctoSettings.h"
#include <QFileDialog>

OctoSettingsView::OctoSettingsView(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OctoSettingsView)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);

  move(
         parent->window()->frameGeometry().topLeft() +
         parent->window()->rect().center() - rect().center()
      );

  ui->editWorkspacePath->setText(settings()->general()->workspaceDir());
}

OctoSettingsView::~OctoSettingsView()
{
  delete ui;
}

void OctoSettingsView::keyPressEvent(QKeyEvent *e)
{
  QDialog::keyPressEvent(e);

  if(e->key() ==  Qt::Key_Return)
  {
    accept();
  }
}

void OctoSettingsView::on_OctoSettingsView_accepted()
{
  settings()->general()->setWorkspaceDir(ui->editWorkspacePath->text());
}

void OctoSettingsView::on_btnBrowseWorkspace_clicked()
{
  QString dir = QFileDialog::getExistingDirectory(this, "OctopodProd Workspace", ui->editWorkspacePath->text());
  if(!dir.isEmpty())
  {
    ui->editWorkspacePath->setText(dir);
  }
}
