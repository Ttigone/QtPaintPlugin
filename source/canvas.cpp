#include "canvas.h"

#include <QMouseEvent>
#include <QPainter>

#include <QtWidgets/qstyleoption.h>

Canvas::Canvas(QWidget* parent) : QWidget(parent)
{
}

Canvas::~Canvas()
{
}

void Canvas::insertPainterPath(const QPainterPath& ppath)
{
    QPainter painter(&image_);
    painter.drawPath(ppath);
    this->update();
}

void Canvas::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);

    QStyleOption opt;
    opt.initFrom(this);
    this->style()->drawPrimitive(QStyle::PE_Widget, &opt, &painter, this);

    // painter.setPen(QColor(Qt::black));
    // painter.setRenderHint(QPainter::Antialiasing);
    // painter.drawPolyline(points_.data(), points_.count());
    painter.drawImage(e->rect().topLeft(), image_);
}

void Canvas::mousePressEvent(QMouseEvent* e)
{
    points_.clear();
    points_.append(e->position());
    // this->update();
    updateImage();
}

void Canvas::mouseMoveEvent(QMouseEvent* e)
{
    points_.append(e->position());
    // this->update();
    updateImage();
}

void Canvas::mouseReleaseEvent(QMouseEvent* e)
{
    points_.append(e->position());
    // this->update();
    updateImage();
}

void Canvas::resizeEvent(QResizeEvent* e)
{
    QImage newImage(e->size(), QImage::Format_RGB32);
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(0, 0, image_);
    image_ = newImage;
    QWidget::resizeEvent(e);
}

void Canvas::updateImage()
{
    QPainter painter(&image_);
    painter.setPen(QColor(Qt::black));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawPolyline(points_.data(), points_.count());
    this->update();
}
