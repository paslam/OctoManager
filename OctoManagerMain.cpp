#include "OctoDashView.h"
#include <QApplication>
#include <QProxyStyle>
#include <QFile>

class StyleTweaks : public QProxyStyle
{
  public:
    void drawPrimitive(PrimitiveElement element, const QStyleOption *option,
                       QPainter *painter, const QWidget *widget) const
    {
      // do not draw focus rectangles - this permits modern styling
      if (element == QStyle::PE_FrameFocusRect)
          return;

      QProxyStyle::drawPrimitive(element, option, painter, widget);
    }
};


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  a.setOrganizationName("OctopodProd");
  a.setOrganizationDomain("http://octopodprod.com/");
  a.setApplicationName("OctoManager");
  a.setApplicationVersion("1.0");
  a.setStyle(new StyleTweaks);

  QFile file(":/OctoManagerStyle.css");
  file.open(QFile::ReadOnly);
  QString styleSheet = QLatin1String(file.readAll());
  a.setStyleSheet(styleSheet);

  OctoDashView dashScreen;
  dashScreen.show();

  return a.exec();
}

//2016/11/04 2h setup
//2016/11/18 3h prototypage
//2016/11/20 4h settings
//2016/01/21 3.5h interface
