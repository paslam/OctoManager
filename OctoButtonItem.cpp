#include "OctoButtonItem.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include <QDebug>
#include "OctoItem.h"
#include <QTextOption>
#include <QTextDocument>

OctoButtonItem::OctoButtonItem(OctoItem* item, int radius)
  : QGraphicsEllipseItem(-radius, -radius, radius*2, radius*2),
    m_radius(radius),
    m_pointed(false),
    m_selected(false)
{
  updateColor();
  setAcceptHoverEvents(true);
  setAcceptTouchEvents(true);

  QGraphicsTextItem* itemText = new QGraphicsTextItem(item->name(), this);
  itemText->setTextWidth(radius*2);

  QTextOption option = itemText->document()->defaultTextOption();
  option.setAlignment(Qt::AlignCenter);
  itemText->document()->setDefaultTextOption(option);

  itemText->moveBy(-radius, radius);
}

void OctoButtonItem::updateColor()
{
  setBrush(QBrush(QColor(m_pointed ? "#68a1fd": "#3f87fc")));
  setPen(QPen(QBrush(m_selected ? Qt::yellow : Qt::white), 5));
}

void OctoButtonItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  QGraphicsEllipseItem::hoverEnterEvent(event);

  m_pointed = true;
  updateColor();
}

void OctoButtonItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  QGraphicsEllipseItem::hoverLeaveEvent(event);

  m_pointed = false;
  updateColor();
}
bool OctoButtonItem::isSelected() const
{
  return m_selected;
}

void OctoButtonItem::setSelected(bool selected)
{
  m_selected = selected;
  updateColor();
}


OctoButtonItem::~OctoButtonItem()
{

}


