#ifndef CANVAS_H
#define CANVAS_H

#include <QtWidgets/QWidget>

class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget* parent = nullptr);
    ~Canvas();

    void insertPainterPath(const QPainterPath& ppath);

protected:
    void paintEvent(QPaintEvent*) override;
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
    void mouseReleaseEvent(QMouseEvent*) override;
    void resizeEvent(QResizeEvent*) override;

private:
    void updateImage();
    QVector<QPointF> points_;
    QImage image_;
};

#endif // CANVAS_H
