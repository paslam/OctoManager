#ifndef OCTOTEXTITEM_H
#define OCTOTEXTITEM_H

#include <QGraphicsTextItem>

class OctoTextItem : public QGraphicsTextItem
{
public:
  OctoTextItem(const QString &text, QGraphicsItem *parent = Q_NULLPTR);
  void alignCentered(double width);

  QRectF boundingRect() const;
};

#endif // OCTOTEXTITEM_H
