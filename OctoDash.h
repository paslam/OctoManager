#ifndef OCTODASH_H
#define OCTODASH_H

#include <QWidget>

class OctoDash : public QWidget
{
  Q_OBJECT

public:
  OctoDash(QWidget *parent = 0);
  ~OctoDash();

signals:
  void showManager();
  void showFolder(const QString& folder);
};

#endif // OCTODASH_H
