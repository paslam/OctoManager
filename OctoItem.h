#ifndef OCTOITEM_H
#define OCTOITEM_H

#include <QString>

class OctoItem
{
public:
  explicit OctoItem(OctoItem *parent = 0);
  virtual ~OctoItem();

  virtual const QString& name() const;
  virtual void setName(const QString &name);

  virtual QString uuid() const;
  virtual void setUuid(const QString &uuid);

  virtual QString path() const;

  virtual OctoItem* parent();
  virtual const OctoItem* parent() const;

  virtual bool hasParent() const;

private:
  QString m_uuid;
  QString m_name;
  OctoItem* m_parent;
};

#endif // OCTOITEM_H
