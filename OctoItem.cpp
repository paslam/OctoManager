#include "OctoItem.h"
#include <QUuid>

OctoItem::OctoItem(QObject *parent) :
  QObject(parent)
{
  m_uuid = QUuid::createUuid().toString();
}

OctoItem::~OctoItem()
{

}

const QString& OctoItem::name() const
{
  return m_name;
}

void OctoItem::setName(const QString &name)
{
  m_name = name;
}

QString OctoItem::uuid() const
{
  return m_uuid;
}

void OctoItem::setUuid(const QString &uuid)
{
  m_uuid = uuid;
}
