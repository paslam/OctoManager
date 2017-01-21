#ifndef OCTOBUTTON_H
#define OCTOBUTTON_H

#include <QGraphicsEllipseItem>
#include <QTextOption>
#include <QTextDocument>

class OctoItem;
class OctoButtonItem : public QObject, public QGraphicsEllipseItem
{
  Q_OBJECT
public:
  OctoButtonItem(OctoItem* item, int radius);
  ~OctoButtonItem();

  void setIconPath(const QString& iconPath);

  QSize minimumSizeHint() const;
  QSize sizeHint() const;

  inline int radius() const { return m_radius; }

  void updateSelection();

  bool isSelected() const;
  void setSelected(bool isSelected);

protected:
  void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
  void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
  void mousePressEvent(QGraphicsSceneMouseEvent* event);
  void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

signals:
  void clicked(Qt::MouseButton);
  void clickedLeft();
  void clickedRight();

private:
  int m_radius;
  bool m_pointed;
  bool m_selected;
  Qt::MouseButton m_pressedBtn;
};

#endif // OCTOBUTTON_H
