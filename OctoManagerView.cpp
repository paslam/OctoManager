#include "OctoManagerView.h"
#include "ui_OctoManagerView.h"
#include "OctoProjectManagerView.h"
#include "OctoClientManagerView.h"
#include "OctoSettingsView.h"
#include "OctoSettings.h"
#include "OctoClient.h"
#include "OctoProject.h"
#include <QMouseEvent>

OctoManagerView::OctoManagerView(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::OctoManagerView)
{
  ui->setupUi(this);
  setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
  setFixedSize(size());

  ui->cmbClients->blockSignals(true);
  const QList<OctoClient*> clients = settings()->general()->clients();
  for(int i = 0; i < clients.size(); ++i)
  {
    OctoClient* client = clients[i];
    ui->cmbClients->addItem(client->name(), client->uuid());
  }
  ui->btnEditClient->setEnabled(!clients.isEmpty());
  ui->cmbClients->blockSignals(false);

  updateWorkspace();
  connect(settings(), SIGNAL(workspaceChanged()), SLOT(updateWorkspace()));

  OctoProject* activeProject = settings()->workspace()->activeProject();
  if(activeProject)
  {
    ui->cmbClients->setCurrentIndex(ui->cmbClients->findData(activeProject->client()->uuid()));
    ui->cmbProjects->setCurrentIndex(ui->cmbProjects->findData(activeProject->uuid()));
  }
}

OctoManagerView::~OctoManagerView()
{
  delete ui;
}

void OctoManagerView::updateWorkspace()
{
  ui->cmbProjects->blockSignals(true);
  ui->cmbProjects->clear();
  const QList<OctoProject*> projects = settings()->workspace()->projects();
  for(int i = 0; i < projects.size(); ++i)
  {
    OctoProject* project = projects[i];
    if(project->client()->uuid() == ui->cmbClients->currentData().toString())
    {
      ui->cmbProjects->addItem(project->name(), project->uuid());
    }
  }
  bool settingsValid = !settings()->general()->workspaceDir().isEmpty();
  ui->cmbProjects->setEnabled(settingsValid);
  ui->btnAddProject->setEnabled(settingsValid);
  ui->btnEditProject->setEnabled(settingsValid && !projects.isEmpty());
  ui->cmbProjects->blockSignals(false);
}

void OctoManagerView::on_btnAddClient_clicked()
{
  OctoClient* client = new OctoClient;
  OctoClientManagerView addClientView(client, this);
  if(addClientView.exec() == QDialog::Accepted)
  {
    settings()->general()->saveClient(client);
    ui->cmbClients->addItem(client->name(), client->uuid());
    ui->cmbClients->setCurrentIndex(ui->cmbClients->count()-1);
  }
}

void OctoManagerView::on_btnEditClient_clicked()
{
  OctoClient* client = settings()->general()->client(ui->cmbClients->currentData().toString());
  OctoClientManagerView editClientView(client, this);
  if(editClientView.exec() == QDialog::Accepted)
  {
    settings()->general()->saveClient(client);
    ui->cmbClients->setItemText(ui->cmbClients->currentIndex(), client->name());
  }
}

void OctoManagerView::on_btnAddProject_clicked()
{
  OctoClient* client = settings()->general()->client(ui->cmbClients->currentData().toString());
  OctoProject* project = new OctoProject(client);
  OctoProjectManagerView addProjectView(project, this);
  if(addProjectView.exec() == QDialog::Accepted)
  {
    settings()->workspace()->saveProject(project);
    ui->cmbProjects->addItem(project->name(), project->uuid());
    ui->cmbProjects->setCurrentIndex(ui->cmbProjects->count()-1);
  }
}

void OctoManagerView::on_btnEditProject_clicked()
{
  OctoProject* project = settings()->workspace()->project(ui->cmbProjects->currentData().toString());
  OctoProjectManagerView editProjectView(project, this);
  if(editProjectView.exec() == QDialog::Accepted)
  {
    settings()->workspace()->saveProject(project);
    ui->cmbProjects->setItemText(ui->cmbProjects->currentIndex(), project->name());
  }
}

void OctoManagerView::showSettings()
{
  OctoSettingsView settingsView(this);
  settingsView.exec();
}

void OctoManagerView::on_btnSettings_clicked()
{
  showSettings();
}

void OctoManagerView::mousePressEvent(QMouseEvent* event)
{
  if(event->button() == Qt::LeftButton)
  {
    m_lastMousePos = event->globalPos();
    m_lastWindowPos = pos();
  }
}

void OctoManagerView::showEvent(QShowEvent *)
{
  bool settingsValid = !settings()->general()->workspaceDir().isEmpty();
  if(!settingsValid)
  {
    showSettings();
  }
}

void OctoManagerView::mouseMoveEvent(QMouseEvent* event)
{
  if(event->buttons() & Qt::LeftButton)
  {
    move(m_lastWindowPos + (event->globalPos() - m_lastMousePos));
  }
}

void OctoManagerView::on_cmbClients_currentIndexChanged(int)
{
  updateWorkspace();
  updateActiveProject();
}

void OctoManagerView::updateActiveProject()
{
  OctoProject* activeProject = settings()->workspace()->project(
        ui->cmbProjects->currentData().toString());
  if(activeProject)
  {
    settings()->workspace()->setActiveProject(activeProject);
  }
}

void OctoManagerView::on_cmbProjects_currentIndexChanged(int)
{
  updateActiveProject();
}
