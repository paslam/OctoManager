#ifndef OCTOMANAGERVIEW_H
#define OCTOMANAGERVIEW_H

#include <QDialog>

namespace Ui {
class OctoManagerView;
}

class OctoSettingsGeneral;
class OctoSettingsWorkspace;
class OctoManagerView : public QDialog
{
  Q_OBJECT

public:
  explicit OctoManagerView(QWidget *parent = 0);
  ~OctoManagerView();

  void updateActiveProject();
  void showSettings();
private slots:
  void updateWorkspace();

  void on_btnAddClient_clicked();
  void on_btnEditClient_clicked();
  void on_btnEditProject_clicked();
  void on_btnAddProject_clicked();
  void on_btnSettings_clicked();

  void on_cmbClients_currentIndexChanged(int index);

  void on_cmbProjects_currentIndexChanged(int index);

protected:
  void mouseMoveEvent(QMouseEvent* event);
  void mousePressEvent(QMouseEvent* event);
  void showEvent(QShowEvent *);

private:
  Ui::OctoManagerView *ui;
  QPoint m_lastMousePos;
  QPoint m_lastWindowPos;
};

#endif // OCTOMANAGERVIEW_H
