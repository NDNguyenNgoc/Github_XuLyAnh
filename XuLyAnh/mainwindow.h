#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void DisplayImage(QImage &img, QString title);
    void Histogram_GrayImage(const QImage &img, const int &his_height);
    void Histogram_ColorImage(const QImage &img, const int &his_height);
    QImage SuaChuaHistogram(const QImage &imgin);
    QImage CanBangHistogram(const QImage &imgin);
    int Random(int n);
    QImage imNoise_Gray(QImage &image_in, float level);
    
private slots:
    void on_btn_filename_clicked();

    void on_btn_xlanhxam2_clicked();

    void on_btn_xlanhmau2_clicked();

    void on_btn_xlanhxam1_clicked();

    void on_btn_xlanhmau1_clicked();

    void on_btn_xlphannguon_clicked();

    void on_btn_vehistogram_clicked();

    void on_btn_vehistogram_2_clicked();

    void on_btn_xlanhxam3_clicked();

    void on_btn_xlanhmau3_clicked();

    void on_btn_bdtthistogram_clicked();

    void on_btn_canbanghistogram_clicked();

    void on_btn_LocTB_clicked();

    void on_btn_LocTV_clicked();

    void on_btn_ThemNhieuMT_clicked();

    void on_btn_Loc_Gradient_clicked();

    void on_btn_Loc_Robert_clicked();

    void on_btn_Loc_Sobel_clicked();

    void on_btn_Loc_Prewitt_clicked();

    void on_btn_Loc_Laplace_clicked();

    void on_btn_Gauss_Laplace_clicked();

    void on_btn_Gradient_AnhMau_clicked();

    void on_btn_Loc_Robert_AnhMau_clicked();

    void on_btn_Loc_Sobel_AnhMau_clicked();

    void on_btn_Loc_Prewitt_AnhMau_clicked();

    void on_btn_Loc_Laplace_AnhMau_clicked();

    void on_btn_G_L_AnhMau_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
