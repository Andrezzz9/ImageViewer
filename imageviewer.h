#ifndef IMAGEVIEWER_H
#define IMAGEVIEWER_H

#include <QMainWindow>
#include <QFileDialog>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class ImageViewer; }
QT_END_NAMESPACE

class ImageViewer : public QMainWindow
{
    Q_OBJECT

public:
    ImageViewer(QWidget *parent = nullptr);
    ~ImageViewer();

    void resizeEvent(QResizeEvent *event) override;

private slots:
    void on_pathButton_clicked();

    void on_imageButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::ImageViewer *ui;

    QString m_imagePath;

    QPixmap m_image;
};
#endif // IMAGEVIEWER_H
