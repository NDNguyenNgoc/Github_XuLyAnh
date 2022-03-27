#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "QPixmap"
#include "QLabel"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Buoi 1
//Doc file anh
void MainWindow::on_btn_filename_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open File", "C:/CVIPtools/images", "*.* All Files;;*.bmp;;*.jpeg;;*.ppm;;*.png;;*.jpg");
    if(filename.isEmpty())
        return;
    ui->ln_filename->setText(filename);

    QPixmap pixmap(filename);
    QLabel *label = new QLabel();
    label->setPixmap(pixmap);
    label->setWindowTitle(QFileInfo(filename).fileName());
    label->show();
}

void MainWindow::DisplayImage(QImage &img, QString title){
    QLabel *label = new QLabel();
    label->setPixmap(QPixmap::fromImage(img));
    label->setWindowTitle(title);
    label->show();
}

//Thai doi muc sang anh xam
void MainWindow::on_btn_xlanhxam2_clicked()
{
    QString filename = ui->ln_filename->text();
    QImage image_in(filename);
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int c = ui->ln_mucsang->text().toInt();
    for (int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb color = image_in.pixel(x, y);
            int gray_in = qGray(color);
            int gray_out = gray_in + c;
            if(gray_out>255)
                gray_out=255;
            else if(gray_out<0)
                gray_out=0;
            QRgb color_out = qRgb(gray_out, gray_out, gray_out);
            image_out.setPixel(x,y, color_out);
        }
    DisplayImage(image_in, QFileInfo(filename).fileName());
    DisplayImage(image_out, QFileInfo(filename).fileName()+"_His_Slide");
}

//Thai doi muc sang anh mau
void MainWindow::on_btn_xlanhmau2_clicked()
{
    QString filename = ui->ln_filename->text();
    QImage image_in(filename);
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);
    int c = ui->ln_mucsang->text().toInt();
    for (int x=0; x<image_in.width(); x++)
        for(int y=0; y<image_in.height(); y++){
            QRgb rgb = image_in.pixel(x, y);
            QColor color_in(rgb);
            int h, s, v;
            color_in.getHsv(&h, &s, &v);
            int v_out = v+c;
            if (v_out>255)
                v_out=255;
            else if (v_out<0)
                v_out=0;
            QColor color_out = QColor::fromHsv(h, s, v_out);
            image_out.setPixel(x, y, color_out.rgb());
        }
    DisplayImage(image_in, QFileInfo(filename).fileName());
    DisplayImage(image_out, QFileInfo(filename).fileName()+"_His_Slide");
}

//Tao anh am ban anh xam
void MainWindow::on_btn_xlanhxam1_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    for(int i=0; i<image_in.width(); i++){
        for(int j=0; j<image_in.height(); j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i,j,color_in);
            int out = 255-gray;
            if(out>255)out = 255;
            else if(out<0)out = 0;

            QRgb color_out = qRgb(out, out, out);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

//Tao anh am ban anh mau
void MainWindow::on_btn_xlanhmau1_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    for(int i=0; i<image_in.width(); i++){
        for(int j=0; j<image_in.height(); j++){
            QRgb rgb = image_in.pixel(i,j);
            QColor color(rgb);
            int red = color.red();
            int green = color.green();
            int blue = color.blue();
            int n_red = 255-red;
            int n_blue = 255-blue;
            int n_green = 255-green;

            QRgb color_out = qRgb(n_red, n_green, n_blue);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

//Phan nguong anh xam
void MainWindow::on_btn_xlphannguon_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    int c = ui->ln_chonnguon->text().toInt();
    for(int i=0; i<image_in.width(); i++){
        for(int j=0; j<image_in.height(); j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray,gray,gray);
            image_in.setPixel(i,j,color_in);
            int out = gray;
            if(out>c) out = 255;
            else if(out<c) out = 0;

            QRgb color_out = qRgb(out,out,out);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out));
    label_out->show();
}

//Buoi 2
//Tao so do histogram cho anh xam
//Qua mainwindow.h tao truoc
void MainWindow::Histogram_GrayImage(const QImage &img, const int &his_height){
    int h[256];
    for (int i=0; i<256; i++)
        h[i]=0;
    QImage image_in(img);
    for (int x=0; x<img.width(); x++)
        for (int y=0; y<img.height(); y++){
            QRgb color = img.pixel(x,y);
            int gray = qGray(color);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(x,y,color_in);
            h[gray]++;
        }
    int max=0;
    for(int i=0; i<256; i++)
        if(h[i]>max) max=h[i];
    QImage img_his = QImage(256, his_height, QImage::Format_RGB888);
    img_his.fill(Qt::white);

    int lineHeight;
    for (int i=0; i<256; i++){
        lineHeight = his_height * h[i]/max;
        for(int j=his_height-1; j>=his_height-1-lineHeight; j--)
            img_his.setPixel(i,j,qRgb(0,0,0));
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(img_his));
    label_out->show();
}


//Ve
void MainWindow::on_btn_vehistogram_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_GrayImage(img,200);
}

//Tao so do histogram cho anh mau
//Qua mainwindow.h tao truoc
void MainWindow::Histogram_ColorImage(const QImage &img, const int &his_height){
    int hr[256];
    int hg[256];
    int hb[256];

    for(int i=0; i<256; i++){
        hr[i]=0;
        hg[i]=0;
        hb[i]=0;
    }

    QImage image_in(img);
    for(int x=0; x<img.width(); x++)
        for(int y=0; y<img.height(); y++){
            QRgb color = img.pixel(x,y);
            int green = qGreen(color);
            int red = qRed(color);
            int blue = qBlue(color);

            hr[red]++;
            hg[green]++;
            hb[blue]++;
        }
    int maxr = 0, maxg = 0, maxb = 0;
    for(int i=0; i<256; i++){
        if(hr[i]>maxr) maxr=hr[i];
        if(hg[i]>maxg) maxg=hg[i];
        if(hb[i]>maxb) maxb=hb[i];
    }

    QImage img_hisr = QImage(256, his_height, QImage::Format_RGB888);
    img_hisr.fill(Qt::white);

    QImage img_hisg = QImage(256, his_height, QImage::Format_RGB888);
    img_hisg.fill(Qt::white);

    QImage img_hisb = QImage(256, his_height, QImage::Format_RGB888);
    img_hisb.fill(Qt::white);

    int liner, lineg, lineb;
    for(int i=0; i<256; i++){
        liner = his_height*hr[i]/maxr;
        lineg = his_height*hg[i]/maxg;
        lineb = his_height*hb[i]/maxb;
        for(int j=his_height-1; j>=his_height-1-liner; j--)
            img_hisr.setPixel(i,j,qRgb(255,0,0));

        for(int j=his_height-1; j>=his_height-1-lineg; j--)
            img_hisg.setPixel(i,j,qRgb(0,255,0));

        for(int j=his_height-1; j>=his_height-1-lineb; j--)
            img_hisb.setPixel(i,j,qRgb(0,0,255));
    }

    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in));
    label_in->show();

    QLabel *label_out1 = new QLabel();
    label_out1->setPixmap(QPixmap::fromImage(img_hisr));
    label_out1->show();

    QLabel *label_out2 = new QLabel();
    label_out2->setPixmap(QPixmap::fromImage(img_hisg));
    label_out2->show();

    QLabel *label_out3 = new QLabel();
    label_out3->setPixmap(QPixmap::fromImage(img_hisb));
    label_out3->show();
}

//Ve
void MainWindow::on_btn_vehistogram_2_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_ColorImage(img,200);
}

//Thay doi do tuong phan(cang to chuc do) anh xam
void MainWindow::on_btn_xlanhxam3_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    float c = ui->ln_dotuongphan->text().toFloat();
    for(int i=0; i<image_in.width(); i++){
        for(int j=0; j<image_in.height(); j++){
            QRgb rgb = image_in.pixel(i,j);
            int gray = qGray(rgb);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(i,j,color_in);
            int out = gray*c;
            if(out>255) out=255;
            else if(out<0) out=0;

            QRgb color_out = qRgb(out,out,out);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640,480)));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640,480)));
    label_out->show();
}

//Thay doi do tuong phan(cang to chuc do) anh mau
void MainWindow::on_btn_xlanhmau3_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out(image_in.width(),image_in.height(),QImage::Format_ARGB32);

    float c = ui->ln_dotuongphan->text().toFloat();
    for(int i=0; i<image_in.width(); i++){
        for(int j=0; j<image_in.height(); j++){
            QRgb rgb = image_in.pixel(i,j);
            QColor color(rgb);

            float red = color.red();
            float green = color.green();
            float blue = color.blue();
            float n_red, n_green, n_blue;

            if(red*c<=255 && red*c>=0)
                n_red = red*c;
            else if(red*c>255)
                n_red = 255;
            else if(red*c<0)
                n_red = 0;

            if(green*c<=255 && green*c>=0)
                n_green = green*c;
            else if(green*c>255)
                n_green = 255;
            else if(green*c<0)
                n_green = 0;

            if(blue*c<=255 && blue*c>=0)
                n_blue = blue*c;
            else if(blue*c>255)
                n_blue = 255;
            else if(blue*c<0)
                n_blue = 0;

            QRgb color_out = qRgb(n_red, n_green, n_blue);
            image_out.setPixel(i,j,color_out);
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(640,480)));
    label_in->show();

    QLabel *label_out = new QLabel();
    label_out->setPixmap(QPixmap::fromImage(image_out.scaled(640,480)));
    label_out->show();
}

//Bien doi tuyen tinh to chuc do
QImage MainWindow::SuaChuaHistogram(const QImage &imgin){
    int max = 0;
    int min = 255;
    QImage image_in(imgin);
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);

    for (int x=0; x<imgin.width(); x++)
    {
        for (int y=0; y<imgin.height(); y++)
        {
            QRgb color = imgin.pixel(x,y);
            int gray = qGray(color);
            QRgb color_in = qRgb(gray, gray, gray);
            image_in.setPixel(x,y,color_in);
            if(gray>max)max = gray;
            if(gray<min)min = gray;
        }
    }
    for (int x=0; x<imgin.width(); x++)
    {
        for (int y=0; y<imgin.height(); y++)
        {
            int newgray = 0;
            QRgb color = imgin.pixel(x,y);
            int gray = qGray(color);
            newgray = (((gray-min)*255)/(max-min));
            QRgb color_out = qRgb(newgray,newgray,newgray);
            image_out.setPixel(x,y,color_out);
        }
    }
    return image_out;
}


void MainWindow::on_btn_bdtthistogram_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_GrayImage(img,200);

    QImage new_img = SuaChuaHistogram(img);
    Histogram_GrayImage(new_img,200);
}

//Can bang tu dong to chuc do
QImage MainWindow::CanBangHistogram(const QImage &imgin){
    double h[256];
    for(int i=0; i<256; i++)
        h[i]=0;

    QImage image_in(imgin);
    QImage image_out(image_in.width(), image_in.height(), QImage::Format_RGB32);
    for(int x=0; x<imgin.width();x++)
    {
        for(int y=0; y<imgin.height(); y++)
        {
            QRgb color = imgin.pixel(x,y);
            int gray = qGray(color);
            h[gray]++;
        }
    }

    double hn[256];
    int numpix = imgin.width() * imgin.height();
    for (int i=0; i<256; i++)
        hn[i] = h[i]/(numpix);

    double c[256];
    for (int i=0; i<256; i++)
        c[i]=0;

    for (int i=0; i<256; i++)
    {
        for (int j=0; j<i; j++)
        {
            c[i] = c[i]+hn[j];
        }
    }

    for (int x=0; x<imgin.width(); x++)
    {
        for (int y=0; y<imgin.height(); y++)
        {
            QRgb color = imgin.pixel(x,y);
            int gray = qGray(color);
            int newgray = (int)(c[gray]*255);
            QRgb color_out = qRgb(newgray, newgray, newgray);
            image_out.setPixel(x,y,color_out);
        }
    }
    return image_out;
}


void MainWindow::on_btn_canbanghistogram_clicked()
{
    QImage img(ui->ln_filename->text());
    Histogram_GrayImage(img, 200);

    QImage new_img = CanBangHistogram(img);
    Histogram_GrayImage(new_img, 200);
}

void MainWindow::on_btn_LocTB_clicked()
{
    QImage image_in(ui->ln_filename->text());
    //Khai bao cho mat na chap 3x3
    int size = ui->ln_KTMN->text().toInt();
    int margin = (size-1)/2;
    int cells = size*size;

    QImage image_out(image_in.width()-margin, image_in.height()-margin, QImage::Format_RGB32);
    int sumR, sumG, sumB;
    QColor color;
    for(int x=margin; x<image_in.width()-margin; x++)
        for(int y=margin; y<image_in.height()-margin; y++){
            sumR = sumG = sumB = 0;
            for(int i=-margin; i<=margin; i++)
                for(int j=-margin; j<=margin; j++){
                    color=image_in.pixel(x+i, y+j);
                    sumR += color.red();
                    sumG += color.green();
                    sumB += color.blue();
                }
            image_out.setPixel(x,y,qRgb(sumR/cells, sumG/cells, sumB/cells));
        }
    QLabel* label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage(image_in.scaled(1024,768)));
    label_in->setToolTip("Hinh Goc");
    label_in->show();

    QLabel* label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image_out.scaled(1024,768)));
    label->setToolTip("Hinh da xu ly");
    label->show();

    QString fname = QFileDialog::getSaveFileName();
    image_out.save(fname);
}

void MainWindow::on_btn_LocTV_clicked()
{
    QImage image_in(ui->ln_filename->text());
    // khai bao cho mat na chap
    int size = ui->ln_KTMN->text().toInt();
    int margin = (size -1)/2;
    int cells = size* size;

    QImage image_out (image_in.width() -margin, image_in.height()-margin, QImage::Format_RGB32);

    for (int x=margin; x<image_in.width()-margin; x++)
        for (int y=margin; y<image_in.height() -margin; y++) {
            int h[cells];
            int k=0;
            for (int i=-margin; i<=margin; i++)
                for (int j=-margin; j<=margin; j++) {
                    QRgb color = image_in.pixel (x+i, y+j);
                    int gray = qGray (color);
                    h[k] = gray;
                    k++;
                }
            qSort (h, h + cells);
            int meanV = h[(cells -1)/2];
            image_out.setPixel (x, y, qRgb (meanV, meanV, meanV));
        }
    QLabel* label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_in.scaled (1024,768)));
    label_in->setToolTip("Hinh Goc"); label_in->show();
    QLabel *label = new QLabel();
    label->setPixmap (QPixmap:: fromImage (image_out. scaled (1024, 768)));
    label->setToolTip("Hình da xu ly");
    label->show(); QString fname = QFileDialog::getSaveFileName();
    image_out. save (fname);
}

int MainWindow:: Random(int n){
    return rand()%n;
}


QImage MainWindow:: imNoise_Gray (QImage &image_in, float level){
    QImage image_out = image_in;
    int noisePoint = image_in.width() * image_in.height() * level;
    for (int i = 0; i< noisePoint;i++)
    {
        int x = Random(image_in.width());
        int y = Random(image_in.height());
        int a = Random (2);
        if (a == 0 )
            image_out.setPixel(x, y, qRgb(0,0,0));
        else
            image_out.setPixel (x, y, qRgb(255, 255, 255));
    }
    return image_out;
}


void MainWindow::on_btn_ThemNhieuMT_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_inGray (image_in.width(), image_in.height(), QImage::Format_RGB32);

    for(int i = 0; i < image_in.width(); i++){
        for(int j = 0; j < image_in.height(); j++){
            QRgb rgb = image_in.pixel(i, j);
            int gray = qGray (rgb);
            QRgb color_in = qRgb (gray, gray, gray);
            image_inGray.setPixel(i, j, color_in);
        }

    }

    float percentage = (ui->ln_TyLeNhieu->text().toInt())/100;

    QImage image_out = imNoise_Gray (image_inGray, percentage);

    QLabel* label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_inGray.scaled (1024,768)));
    label_in->setToolTip("Hinh Goc");
    label_in->show();

    QLabel *label = new QLabel();
    label->setPixmap (QPixmap:: fromImage (image_out.scaled (1024,768)));
    label->setToolTip("Hinh da xu ly");
    label->show();
    QString fname = QFileDialog::getSaveFileName();
    image_out.save(fname);
}

void MainWindow::on_btn_Loc_Gradient_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out_Gx(image_in.width()-1, image_in.height(), QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width(), image_in.height()-1, QImage::Format_RGB32);

    for (int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height(); j++)
        {
            QRgb color1 = image_in.pixel(i,j);
            int gray1 = qGray(color1);

            QRgb color_in = qRgb (gray1, gray1, gray1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i+1,j);
            int gray2 = qGray (color2);
            int newgray = abs (gray2 - gray1);
            image_out_Gx.setPixel(i, j, qRgb (newgray,newgray,newgray));
        }
    }
    for (int i = 0; i < image_in.width(); i++){
        for(int j = 0; j < image_in.height()-1; j++){
            QRgb color1 = image_in.pixel(i,j);
            int gray1 = qGray (color1);

            QRgb color_in = qRgb (gray1, gray1, gray1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i, j+1);
            int gray2 = qGray(color2);
            int newgray = abs (gray2 - gray1);
            image_out_Gy.setPixel(i, j, qRgb (newgray,newgray,newgray));
        }
    }
    QLabel* label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_in.scaled (1024,768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap:: fromImage (image_out_Gx.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap:: fromImage (image_out_Gy.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Robert_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out_Gx(image_in.width()-1, image_in.height()-1, QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width()-1, image_in.height()-1, QImage::Format_RGB32);

    for (int i = 0; i <image_in.width()-1; i++)
    {
        for (int j = 0; j<image_in.height()-1; j++)
        {
            QRgb color1 = image_in.pixel(i,j);
            int gray1 = qGray(color1);
            QRgb color2 = image_in.pixel (i+1, j);
            int gray2 = qGray (color2);
            QRgb color3 = image_in.pixel(i, j+1);
            int gray3 = qGray(color3);
            QRgb color4 = image_in.pixel (i+1, j+1);
            int gray4 = qGray (color4);

            int newgray_gx = abs(gray1 - gray4);

            int newgray_gy = abs(gray2 - gray3);

            image_out_Gx.setPixel(i,j,qRgb (newgray_gx, newgray_gx, newgray_gx));
            image_out_Gy.setPixel(i,j,qRgb (newgray_gy, newgray_gy, newgray_gy));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_in.scaled (1024,768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap:: fromImage (image_out_Gx.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap :: fromImage (image_out_Gy.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Sobel_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
        int margin = maskSize / 2;
        //int cells = maskSize * maskSize;
        int mask[maskSize][maskSize];
        mask [0][0] = -1; mask [0][1] = 0; mask [0][2] = 1;
        mask [1][0] = -2; mask [1][1] = 0; mask [1][2] = 2;
        mask [2][0] = -1; mask [2][1] = 0; mask [2][2] = 1;
        int mask2[maskSize][maskSize];
        mask2[0][0] = -1; mask2[0][1] = -2; mask2[0][2] = -1;
        mask2[1][0] = 0; mask2[1][1] = 0; mask2[1][2] = 0;
        mask2[2][0] = 1; mask2[2][1] = 2; mask2[2][2] = 1;

        QRgb color;
        int suml, sum2;
        for (int y = margin; y<image_in.height() - margin; y++)
        {
            for (int x = margin; x<image_in.width() - margin; x++){
                suml=sum2 = 0;
                for (int j= -margin; j <= margin; j++){
                    for (int i = -margin; i <= margin; i++){
                        color = image_in.pixel (x + i, y + j);
                        int gray = qGray (color);
                        suml += gray * mask[j+margin][i+margin];
                        sum2 += gray * mask2[j+margin] [i+margin];
                    }
                }
                image_out.setPixel (x, y, qRgb (abs (suml), abs (suml), abs (suml)));
                image_out2.setPixel (x, y, qRgb (abs (sum2), abs (sum2), abs (sum2)));
            }
        }
        QLabel *label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
        label_in->show();

        QLabel *label_Gx = new QLabel();
        label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
        label_Gx->show();

        QLabel *label_Gy = new QLabel();
        label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
        label_Gy->show();
}

void MainWindow::on_btn_Loc_Prewitt_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
        int margin = maskSize / 2;
        //int cells = maskSize * maskSize;
        int mask[maskSize][maskSize];
        mask [0][0] = -1; mask [0][1] = 0; mask [0][2] = 1;
        mask [1][0] = -1; mask [1][1] = 0; mask [1][2] = 1;
        mask [2][0] = -1; mask [2][1] = 0; mask [2][2] = 1;
        int mask2[maskSize][maskSize];
        mask2[0][0] = -1; mask2[0][1] = -1; mask2[0][2] = -1;
        mask2[1][0] = 0; mask2[1][1] = 0; mask2[1][2] = 0;
        mask2[2][0] = 1; mask2[2][1] = 1; mask2[2][2] = 1;

        QRgb color;
        int suml, sum2;
        for (int y = margin; y<image_in.height() - margin; y++)
        {
            for (int x = margin; x<image_in.width() - margin; x++){
                suml=sum2 = 0;
                for (int j= -margin; j <= margin; j++){
                    for (int i = -margin; i <= margin; i++){
                        color = image_in.pixel (x + i, y + j);
                        int gray = qGray (color);
                        suml += gray * mask[j+margin][i+margin];
                        sum2 += gray * mask2[j+margin] [i+margin];
                    }
                }
                image_out.setPixel (x, y, qRgb (abs (suml), abs (suml), abs (suml)));
                image_out2.setPixel (x, y, qRgb (abs (sum2), abs (sum2), abs (sum2)));
            }
        }
        QLabel *label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
        label_in->show();

        QLabel *label_Gx = new QLabel();
        label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
        label_Gx->show();

        QLabel *label_Gy = new QLabel();
        label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
        label_Gy->show();
}

void MainWindow::on_btn_Loc_Laplace_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
        int margin = maskSize / 2;
        //int cells = maskSize * maskSize;
        int mask[maskSize][maskSize];
        mask [0][0] = 0; mask [0][1] = 1; mask [0][2] = 0;
        mask [1][0] = 1; mask [1][1] = -4; mask [1][2] = 1;
        mask [2][0] = 0; mask [2][1] = 1; mask [2][2] = 0;
        int mask2[maskSize][maskSize];
        mask2[0][0] = 1; mask2[0][1] = 1; mask2[0][2] = 1;
        mask2[1][0] = 1; mask2[1][1] = -8; mask2[1][2] = 1;
        mask2[2][0] = 1; mask2[2][1] = 1; mask2[2][2] = 1;

        QRgb color;
        int suml, sum2;
        for (int y = margin; y<image_in.height() - margin; y++)
        {
            for (int x = margin; x<image_in.width() - margin; x++){
                suml=sum2 = 0;
                for (int j= -margin; j <= margin; j++){
                    for (int i = -margin; i <= margin; i++){
                        color = image_in.pixel (x + i, y + j);
                        int gray = qGray (color);
                        suml += gray * mask[j+margin][i+margin];
                        sum2 += gray * mask2[j+margin] [i+margin];
                    }
                }
                image_out.setPixel (x, y, qRgb (abs (suml), abs (suml), abs (suml)));
                image_out2.setPixel (x, y, qRgb (abs (sum2), abs (sum2), abs (sum2)));
            }
        }
        QLabel *label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
        label_in->show();

        QLabel *label_Gx = new QLabel();
        label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
        label_Gx->show();

        QLabel *label_Gy = new QLabel();
        label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
        label_Gy->show();
}

void MainWindow::on_btn_Gauss_Laplace_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);

    int maskSize = 5;
        int margin = maskSize / 2;
        //int cells = maskSize * maskSize;
        int mask[maskSize][maskSize];
        mask [0][0] = 0; mask [0][1] = 0; mask [0][2] = -1; mask [0][3] = 0; mask [0][4] = 0;
        mask [1][0] = 0; mask [1][1] = -1; mask [1][2] = -2; mask [1][3] = -1; mask [1][4] = 0;
        mask [2][0] = -1; mask [2][1] = -2; mask [2][2] = 16; mask [2][3] = -1; mask [2][4] = -1;
        mask [3][0] = 0; mask [3][1] = -1; mask [3][2] = -2; mask [3][3] = -1; mask [3][4] = 0;
        mask [4][0] = 0; mask [4][1] = 0; mask [4][2] = -1; mask [4][3] = 0; mask [4][4] = 0;

        QRgb color;
        int suml;
        for (int y = margin; y<image_in.height() - margin; y++)
        {
            for (int x = margin; x<image_in.width() - margin; x++){
                suml = 0;
                for (int j= -margin; j <= margin; j++){
                    for (int i = -margin; i <= margin; i++){
                        color = image_in.pixel (x + i, y + j);
                        int gray = qGray (color);
                        suml += gray * mask[j+margin][i+margin];
                    }
                }
                image_out.setPixel (x, y, qRgb (abs (suml), abs (suml), abs (suml)));
            }
        }
        QLabel *label_in = new QLabel();
        label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
        label_in->show();

        QLabel *label_Gx = new QLabel();
        label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
        label_Gx->show();
}

void MainWindow::on_btn_Gradient_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out_Gx(image_in.width()-1, image_in.height(), QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width(), image_in.height()-1, QImage::Format_RGB32);

    for (int i = 0; i < image_in.width() - 1; i++)
    {
        for(int j = 0; j < image_in.height(); j++)
        {
            QRgb color1 = image_in.pixel(i,j);
            int red1 = qRed(color1);
            int green1 = qGreen(color1);
            int blue1 = qBlue(color1);

            QRgb color_in = qRgb (red1, green1, blue1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i+1,j);
            int red2 = qRed (color2);
            int green2 = qGreen (color2);
            int blue2 = qBlue (color2);

            int nred = abs (red2 - red1);
            int ngreen = abs (green2 - green1);
            int nblue = abs (blue2 - blue1);
            image_out_Gx.setPixel(i, j, qRgb (nred,ngreen,nblue));
        }
    }
    for (int i = 0; i < image_in.width(); i++){
        for(int j = 0; j < image_in.height()-1; j++){
            QRgb color1 = image_in.pixel(i,j);
            int red1 = qRed(color1);
            int green1 = qGreen(color1);
            int blue1 = qBlue(color1);

            QRgb color_in = qRgb (red1, green1, blue1);
            image_in.setPixel(i, j, color_in);

            QRgb color2 = image_in.pixel(i,j+1);
            int red2 = qRed (color2);
            int green2 = qGreen (color2);
            int blue2 = qBlue (color2);

            int nred = abs (red2 - red1);
            int ngreen = abs (green2 - green1);
            int nblue = abs (blue2 - blue1);
            image_out_Gy.setPixel(i, j, qRgb (nred,ngreen,nblue));
        }
    }
    QLabel* label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_in.scaled (1024,768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap:: fromImage (image_out_Gx.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap:: fromImage (image_out_Gy.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Robert_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out_Gx(image_in.width()-1, image_in.height()-1, QImage::Format_RGB32);
    QImage image_out_Gy(image_in.width()-1, image_in.height()-1, QImage::Format_RGB32);

    for (int i = 0; i <image_in.width()-1; i++)
    {
        for (int j = 0; j<image_in.height()-1; j++)
        {
            QRgb color1 = image_in.pixel(i,j);
            int red1 = qRed(color1);
            int green1 = qGreen(color1);
            int blue1 = qBlue(color1);

            QRgb color2 = image_in.pixel (i+1, j);
            int red2 = qRed (color2);
            int green2 = qGreen(color2);
            int blue2 = qBlue(color2);

            QRgb color3 = image_in.pixel(i, j+1);
            int red3 = qRed(color3);
            int green3 = qGreen(color3);
            int blue3 = qBlue(color3);

            QRgb color4 = image_in.pixel (i+1, j+1);
            int red4 = qRed(color4);
            int green4 = qGreen(color4);
            int blue4 = qBlue(color4);

            int nred_gx = abs(red1 - red4);
            int nred_gy = abs(red2 - red3);

            int ngreen_gx = abs(green1 - green4);
            int ngreen_gy = abs(green2 - green3);

            int nblue_gx = abs(blue1 - blue4);
            int nblue_gy = abs(blue2 - blue3);

            image_out_Gx.setPixel(i,j,qRgb (nred_gx, ngreen_gx, nblue_gx));
            image_out_Gy.setPixel(i,j,qRgb (nred_gy, ngreen_gy, nblue_gy));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap (QPixmap:: fromImage (image_in.scaled (1024,768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap:: fromImage (image_out_Gx.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap :: fromImage (image_out_Gy.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Sobel_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
    int margin = maskSize / 2;
    //int cells = maskSize * maskSize;
    int mask[maskSize][maskSize];
    mask [0][0] = -1; mask [0][1] = 0; mask [0][2] = 1;
    mask [1][0] = -2; mask [1][1] = 0; mask [1][2] = 2;
    mask [2][0] = -1; mask [2][1] = 0; mask [2][2] = 1;
    int mask2[maskSize][maskSize];
    mask2[0][0] = -1; mask2[0][1] = -2; mask2[0][2] = -1;
    mask2[1][0] = 0; mask2[1][1] = 0; mask2[1][2] = 0;
    mask2[2][0] = 1; mask2[2][1] = 2; mask2[2][2] = 1;

    QRgb color;
    int sumRl, sumR2, sumGl, sumG2, sumBl, sumB2;
    for (int y = margin; y<image_in.height() - margin; y++)
    {
        for (int x = margin; x<image_in.width() - margin; x++){
            sumRl = sumR2 = sumGl = sumG2 = sumBl = sumB2 = 0;
            for (int j= -margin; j <= margin; j++){
                for (int i = -margin; i <= margin; i++){
                    color = image_in.pixel (x + i, y + j);
                    int red = qRed (color);
                    sumRl += red * mask[j+margin][i+margin];
                    sumR2 += red * mask2[j+margin] [i+margin];

                    int green = qGreen (color);
                    sumGl += green * mask[j+margin][i+margin];
                    sumG2 += green * mask2[j+margin] [i+margin];

                    int blue = qBlue (color);
                    sumBl += blue * mask[j+margin][i+margin];
                    sumB2 += blue * mask2[j+margin] [i+margin];
                }
            }
            image_out.setPixel (x, y, qRgb (abs (sumRl), abs (sumGl), abs (sumBl)));
            image_out2.setPixel (x, y, qRgb (abs (sumR2), abs (sumG2), abs (sumB2)));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Prewitt_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
    int margin = maskSize / 2;
    //int cells = maskSize * maskSize;
    int mask[maskSize][maskSize];
    mask [0][0] = -1; mask [0][1] = 0; mask [0][2] = 1;
    mask [1][0] = -1; mask [1][1] = 0; mask [1][2] = 1;
    mask [2][0] = -1; mask [2][1] = 0; mask [2][2] = 1;
    int mask2[maskSize][maskSize];
    mask2[0][0] = -1; mask2[0][1] = -1; mask2[0][2] = -1;
    mask2[1][0] = 0; mask2[1][1] = 0; mask2[1][2] = 0;
    mask2[2][0] = 1; mask2[2][1] = 1; mask2[2][2] = 1;

    QRgb color;
    int sumRl, sumR2, sumGl, sumG2, sumBl, sumB2;
    for (int y = margin; y<image_in.height() - margin; y++)
    {
        for (int x = margin; x<image_in.width() - margin; x++){
            sumRl = sumR2 = sumGl = sumG2 = sumBl = sumB2 = 0;
            for (int j= -margin; j <= margin; j++){
                for (int i = -margin; i <= margin; i++){
                    color = image_in.pixel (x + i, y + j);
                    int red = qRed (color);
                    sumRl += red * mask[j+margin][i+margin];
                    sumR2 += red * mask2[j+margin] [i+margin];

                    int green = qGreen (color);
                    sumGl += green * mask[j+margin][i+margin];
                    sumG2 += green * mask2[j+margin] [i+margin];

                    int blue = qBlue (color);
                    sumBl += blue * mask[j+margin][i+margin];
                    sumB2 += blue * mask2[j+margin] [i+margin];
                }
            }
            image_out.setPixel (x, y, qRgb (abs (sumRl), abs (sumGl), abs (sumBl)));
            image_out2.setPixel (x, y, qRgb (abs (sumR2), abs (sumG2), abs (sumB2)));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_Loc_Laplace_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);
    QImage image_out2 (image_in.width(), image_in.height(), QImage::Format_RGB32);
    int maskSize = 3;
    int margin = maskSize / 2;
    //int cells = maskSize * maskSize;
    int mask[maskSize][maskSize];
    mask [0][0] = 0; mask [0][1] = 1; mask [0][2] = 0;
    mask [1][0] = 1; mask [1][1] = -4; mask [1][2] = 1;
    mask [2][0] = 0; mask [2][1] = 1; mask [2][2] = 0;
    int mask2[maskSize][maskSize];
    mask2[0][0] = 1; mask2[0][1] = 1; mask2[0][2] = 1;
    mask2[1][0] = 1; mask2[1][1] = -8; mask2[1][2] = 1;
    mask2[2][0] = 1; mask2[2][1] = 1; mask2[2][2] = 1;

    QRgb color;
    int sumRl, sumR2, sumGl, sumG2, sumBl, sumB2;
    for (int y = margin; y<image_in.height() - margin; y++)
    {
        for (int x = margin; x<image_in.width() - margin; x++){
            sumRl = sumR2 = sumGl = sumG2 = sumBl = sumB2 = 0;
            for (int j= -margin; j <= margin; j++){
                for (int i = -margin; i <= margin; i++){
                    color = image_in.pixel (x + i, y + j);
                    int red = qRed (color);
                    sumRl += red * mask[j+margin][i+margin];
                    sumR2 += red * mask2[j+margin] [i+margin];

                    int green = qGreen (color);
                    sumGl += green * mask[j+margin][i+margin];
                    sumG2 += green * mask2[j+margin] [i+margin];

                    int blue = qBlue (color);
                    sumBl += blue * mask[j+margin][i+margin];
                    sumB2 += blue * mask2[j+margin] [i+margin];
                }
            }
            image_out.setPixel (x, y, qRgb (abs (sumRl), abs (sumGl), abs (sumBl)));
            image_out2.setPixel (x, y, qRgb (abs (sumR2), abs (sumG2), abs (sumB2)));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
    label_Gx->show();

    QLabel *label_Gy = new QLabel();
    label_Gy->setPixmap (QPixmap::fromImage (image_out2.scaled (1024,768)));
    label_Gy->show();
}

void MainWindow::on_btn_G_L_AnhMau_clicked()
{
    QImage image_in(ui->ln_filename->text());
    QImage image_out (image_in.width(), image_in.height(), QImage::Format_RGB32);

    int maskSize = 5;
    int margin = maskSize / 2;
    //int cells = maskSize * maskSize;
    int mask[maskSize][maskSize];
    mask [0][0] = 0; mask [0][1] = 0; mask [0][2] = -1; mask [0][3] = 0; mask [0][4] = 0;
    mask [1][0] = 0; mask [1][1] = -1; mask [1][2] = -2; mask [1][3] = -1; mask [1][4] = 0;
    mask [2][0] = -1; mask [2][1] = -2; mask [2][2] = 16; mask [2][3] = -1; mask [2][4] = -1;
    mask [3][0] = 0; mask [3][1] = -1; mask [3][2] = -2; mask [3][3] = -1; mask [3][4] = 0;
    mask [4][0] = 0; mask [4][1] = 0; mask [4][2] = -1; mask [4][3] = 0; mask [4][4] = 0;

    QRgb color;
    int sumRl, sumGl, sumBl;
    for (int y = margin; y<image_in.height() - margin; y++)
    {
        for (int x = margin; x<image_in.width() - margin; x++){
            sumRl = sumGl = sumBl = 0;
            for (int j= -margin; j <= margin; j++){
                for (int i = -margin; i <= margin; i++){
                    color = image_in.pixel (x + i, y + j);
                    int red = qRed (color);
                    sumRl += red * mask[j+margin][i+margin];

                    int green = qGreen (color);
                    sumGl += green * mask[j+margin][i+margin];

                    int blue = qBlue (color);
                    sumBl += blue * mask[j+margin][i+margin];
                }
            }
            image_out.setPixel (x, y, qRgb (abs (sumRl), abs (sumGl), abs (sumBl)));
        }
    }
    QLabel *label_in = new QLabel();
    label_in->setPixmap(QPixmap::fromImage (image_in.scaled (1024, 768)));
    label_in->show();

    QLabel *label_Gx = new QLabel();
    label_Gx->setPixmap (QPixmap::fromImage (image_out.scaled (1024,768)));
    label_Gx->show();
}
