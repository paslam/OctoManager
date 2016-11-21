#ifndef OCTOITEM_H
#define OCTOITEM_H

#include <QObject>

class OctoItem : public QObject
{
  Q_OBJECT
public:
  explicit OctoItem(QObject *parent = 0);
  ~OctoItem();

  virtual const QString& name() const;
  virtual void setName(const QString &name);

  virtual QString uuid() const;
  virtual void setUuid(const QString &uuid);

private:
  QString m_uuid;
  QString m_name;
};

#endif // OCTOITEM_H
