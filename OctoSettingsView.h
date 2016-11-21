#ifndef OCTOSETTINGSVIEW_H
#define OCTOSETTINGSVIEW_H

#include <QDialog>

namespace Ui {
class OctoSettingsView;
}

class OctoSettingsView : public QDialog
{
  Q_OBJECT

public:
  explicit OctoSettingsView(QWidget *parent = 0);
  ~OctoSettingsView();

protected:
  void keyPressEvent(QKeyEvent *e);

private slots:
  void on_OctoSettingsView_accepted();

  void on_btnBrowseWorkspace_clicked();

private:
  Ui::OctoSettingsView *ui;
};

#endif // OCTOSETTINGSVIEW_H
