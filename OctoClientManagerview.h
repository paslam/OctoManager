#ifndef OCTOCLIENTMANAGERVIEW_H
#define OCTOCLIENTMANAGERVIEW_H

#include <QDialog>

namespace Ui {
class OctoClientManagerView;
}

class OctoClient;
class OctoClientManagerView : public QDialog
{
  Q_OBJECT

public:
  explicit OctoClientManagerView(OctoClient* client, QWidget *parent = 0);
  ~OctoClientManagerView();

protected:
  virtual void keyPressEvent(QKeyEvent *e);

private slots:
  void on_OctoClientManagerView_accepted();

private:
  Ui::OctoClientManagerView *ui;
  OctoClient* m_client;
};

#endif // OCTOCLIENTMANAGERVIEW_H
