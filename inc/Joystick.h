#ifndef JOYSTICK_REPRESENTATION_H
#define JOYSTICK_REPRESENTATION_H

#include <qwidget.h>
#include <qpainter.h>
#include <qpainterpath.h>
#include <qbrush.h>
#include <qpen.h>
#include <qevent.h>

class Joystick : public QWidget
{
private:
  //member data
  double m_xVal; //current x value of the joystick. range [-1.0, 1.0]
  double m_yVal; //current y value of the joystick. range [-1.0, 1.0]
  double m_xDeadband; //x deadband, magnitude of x has to be greater than this to register
  double m_yDeadband; //y deadband, magnitude of y has to be greater than this ti register
  QColor m_dotColor; //color the dot representing where the joystick is is
  QColor m_circleColor; //color of the circle representing the whole joystick range
  QColor m_deadbandColor; //color of the circle representing the deadband area 

  //private functions
  void init(double xVal, double yVal, double xDeadband, double yDeadband, 
            const QColor& dotColor, const QColor& circleColor, 
            const QColor& deadbandColor);

protected:
  //event handlers
  void paintEvent(QPaintEvent* e) override;

public:
  //constructors
  Joystick(QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, QWidget* parent = nullptr);
  Joystick(const QColor& dotColor, QWidget* parent = nullptr);
  Joystick(const QColor& dotColor, const QColor& circleColor, QWidget* parent = nullptr);
  Joystick(const QColor& dotColor, const QColor& circleColor, const QColor& deadbandColor,
           QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, const QColor& dotColor, QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
           QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, const QColor& dotColor, const QColor& circleColor,
           const QColor& deadbandColor, QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
           QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
           const QColor& dotColor, 
           QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
           const QColor& dotColor,
           const QColor& circleColor,
           QWidget* parent = nullptr);
  Joystick(double xVal, double yVal, double xDeadband, double ydeadBand,
           const QColor& dotColor,
           const QColor& circleColor,
           const QColor& deadbandColor,
           QWidget* parent = nullptr);
  ~Joystick();

  //public functions

  //getters
  double xVal() const;
  double yVal() const;
  double xDeadband() const;
  double yDeadband() const;
  QColor dotColor() const;
  QColor circleColor() const;
  QColor deadbandColor() const;

  //setters
  /**
   * sets the value of the x-axis of the joystick
   * 
   * @param: newX: The new x value. range [-1.0, 1.0]
   */
  void setXVal(double newX);
  /**
   * 
   * @param: newY: The new y value. range [-1.0, 1.0]
   */
  void setYVal(double newY);
  void setXDeadband(double newXDeadband);
  void setyDeadband(double newYDeadband);
  void setDotColor(const QColor& newColor);
  void setDotColor(int r, int g, int b);
  void setCircleColor(const QColor& newColor);
  void setCircleColor(int r, int g, int b);
  void setDeadbandColor(const QColor& newColor);
  void setDeadbandColor(int r, int g, int b);

signals:
  //signals
  void xChanged(double oldX, double newX);
  void yChanged(double oldY, double newY);

public slots:
  //public slots
  void updateX(double newX);
  void updateY(double newY);

};

#endif