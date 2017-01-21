#include "OctoItem.h"
#include <QUuid>

OctoItem::OctoItem(OctoItem *parent) :
  m_parent(parent)
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

QString OctoItem::path() const
{
  return hasParent() ? (parent()->path() + "/" + name()) : name();
}

OctoItem *OctoItem::parent()
{
  return m_parent;
}

const OctoItem *OctoItem::parent() const
{
  return m_parent;
}

bool OctoItem::hasParent() const
{
  return m_parent;
}
