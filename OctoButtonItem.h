#ifndef OCTOBUTTON_H
#define OCTOBUTTON_H

#include <QGraphicsEllipseItem>

class OctoItem;
class OctoButtonItem : public QObject, public QGraphicsEllipseItem
{
  Q_OBJECT
public:
  OctoButtonItem(OctoItem* item, int radius);
  ~OctoButtonItem();

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

  inline int radius() const { return m_radius; }

  void updateColor();

  bool isSelected() const;
  void setSelected(bool isSelected);

protected:
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
  void leftClick();
  void rightClick();

private:
  int m_radius;
  bool m_pointed;
  bool m_selected;
};

#endif // OCTOBUTTON_H
