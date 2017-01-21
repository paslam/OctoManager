#include "OctoTextItem.h"
#include <QTextOption>
#include <QTextDocument>
#include <QGraphicsSceneHoverEvent>

OctoTextItem::OctoTextItem(const QString &text, QGraphicsItem *parent)
  : QGraphicsTextItem(text, parent)
{

}

void OctoTextItem::alignCentered(double width)
{
  setTextWidth(width);

  QTextOption option = document()->defaultTextOption();
  option.setAlignment(Qt::AlignCenter);
  document()->setDefaultTextOption(option);
}

QRectF OctoTextItem::boundingRect() const
{
  return QRectF();
}
