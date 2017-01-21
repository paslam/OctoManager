#include "OctoButtonItem.h"
#include <QPainter>
#include <QMouseEvent>
#include <cmath>
#include <QDebug>
#include "OctoItem.h"
#include "OctoTextItem.h"
#include <QGraphicsSceneMouseEvent>

#define BACK_COLOR "#3f87fc"

OctoButtonItem::OctoButtonItem(OctoItem* item, int radius)
  : QGraphicsEllipseItem(-radius, -radius, radius*2, radius*2),
    m_radius(radius),
    m_pointed(false),
    m_selected(false)
{
  updateSelection();
  setAcceptHoverEvents(true);

  OctoTextItem* itemText = new OctoTextItem(item->name(), this);
  itemText->alignCentered(radius*2);
  itemText->moveBy(-radius, radius);

  setBrush(QBrush(QColor(BACK_COLOR)));
}

void OctoButtonItem::updateSelection()
{
  setPen(QPen(QBrush(m_pointed ? Qt::black : QColor("#1f47dc")), 5));
}

void OctoButtonItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
  QGraphicsEllipseItem::hoverEnterEvent(event);

  m_pointed = true;
  updateSelection();
}

void OctoButtonItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
  QGraphicsEllipseItem::hoverLeaveEvent(event);

  m_pointed = false;
  updateSelection();
}

void OctoButtonItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsEllipseItem::mousePressEvent(event);
  setSelected(true);
  event->accept();
  m_pressedBtn = event->button();
}

void OctoButtonItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
  QGraphicsEllipseItem::mouseReleaseEvent(event);
  setSelected(false);
  if(m_pressedBtn == event->button())
  {
    emit clicked(m_pressedBtn);
    if(m_pressedBtn == Qt::LeftButton)
    {
      emit clickedLeft();
    }
    else if(m_pressedBtn == Qt::RightButton)
    {
      emit clickedRight();
    }
  }
}

bool OctoButtonItem::isSelected() const
{
  return m_selected;
}

void OctoButtonItem::setSelected(bool selected)
{
  m_selected = selected;
  updateSelection();
}


OctoButtonItem::~OctoButtonItem()
{

}

void OctoButtonItem::setIconPath(const QString &iconPath)
{
  const int DIM = m_radius*2;
  QPixmap source(iconPath);
  source = source.scaled(DIM, DIM, Qt::IgnoreAspectRatio,
                         Qt::SmoothTransformation);
  QPixmap target(DIM, DIM); // the size may vary
  target.fill(QColor(BACK_COLOR));

  QPainter painter(&target);
  painter.drawPixmap(0, 0, source);

  QBrush brush(target);
  QTransform transform;
  transform.translate(m_radius, m_radius);
  brush.setTransform(transform);
  setBrush(brush);
}


