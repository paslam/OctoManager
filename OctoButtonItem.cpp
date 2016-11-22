#include "OctoButtonItem.h"
#include <QPainter>

OctoButtonItem::OctoButtonItem(int radius, QWidget* parent)
  : QPushButton(parent),
    m_radius(radius)
{
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

OctoButtonItem::~OctoButtonItem()
{

}

QSize OctoButtonItem::minimumSizeHint() const
{
  return QSize(m_radius*2, m_radius*2);
}

QSize OctoButtonItem::sizeHint() const
{
  return QSize(minimumSizeHint().width()  + 10,
               minimumSizeHint().height() + 10);
}

void OctoButtonItem::paintEvent(QPaintEvent *)
{
  QPainter painter(this);
  painter.setRenderHint(QPainter::Antialiasing);
  painter.translate(width() / 2, height() /2);
  painter.setBrush(QBrush(QColor("#3f87fc")));
  painter.setPen(QPen(QColor(Qt::white)));
  painter.drawEllipse(QRect(-m_radius, -m_radius,
                            m_radius*2, m_radius*2));
}
