#include "imageviewer.h"
#include "./ui_imageviewer.h"

ImageViewer::ImageViewer(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ImageViewer)
{
    ui->setupUi(this);
}

ImageViewer::~ImageViewer()
{
    delete ui;
}

void ImageViewer::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    ui->imageField->setPixmap(m_image.scaled(ui->scrollArea->width(),ui->scrollArea->height(),Qt::KeepAspectRatio));
}


void ImageViewer::on_pathButton_clicked()
{
    m_imagePath = QFileDialog::getOpenFileName(this, "Choose path to your image", "../ImageViewer",
                                             "JPEG Image (*.jpg);; PNG Image (*.png);");
}


void ImageViewer::on_imageButton_clicked()
{
    m_image.load(m_imagePath);
    ui->imageField->setPixmap(m_image.scaled(ui->scrollArea->width(),ui->scrollArea->height(),Qt::KeepAspectRatio));
}


void ImageViewer::on_exitButton_clicked()
{
    QMainWindow::close();
}
