#ifndef OCTOPROJECTMANAGERVIEW_H
#define OCTOPROJECTMANAGERVIEW_H

#include <QDialog>

namespace Ui {
class OctoProjectManagerView;
}

class OctoProject;
class OctoProjectManagerView : public QDialog
{
  Q_OBJECT

public:
  explicit OctoProjectManagerView(OctoProject* project, QWidget *parent = 0);
  ~OctoProjectManagerView();

protected:
  virtual void keyPressEvent(QKeyEvent *e);

private slots:
  void on_OctoProjectManagerView_accepted();

private:
  Ui::OctoProjectManagerView *ui;
  OctoProject* m_project;
};

#endif // OCTOPROJECTMANAGERVIEW_H
