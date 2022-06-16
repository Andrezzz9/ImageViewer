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
    ui->pathField->setText(m_imagePath);
}


void ImageViewer::on_imageButton_clicked()
{

    if (m_imagePath.isNull()) {
        QMessageBox msgBox;

        msgBox.setText("Cant open the image\n"
                       "Please choose correct path");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);

        int ret = msgBox.exec();

        if (ret == QMessageBox::Ok) {
            msgBox.close();
        }
    }

    else {
        m_image.load(m_imagePath);
        ui->imageField->setPixmap(m_image.scaled(ui->scrollArea->width(),ui->scrollArea->height(),Qt::KeepAspectRatio));
    }
}


void ImageViewer::on_exitButton_clicked()
{
    QMainWindow::close();
}
