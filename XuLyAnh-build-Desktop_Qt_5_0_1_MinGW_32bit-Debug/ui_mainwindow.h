/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *lb_filename;
    QLineEdit *ln_filename;
    QPushButton *btn_filename;
    QLabel *lb_anhamban;
    QPushButton *btn_xlanhxam1;
    QPushButton *btn_xlanhmau1;
    QLabel *lb_mucsang;
    QLineEdit *ln_mucsang;
    QLabel *lb_tanggiammucsang;
    QPushButton *btn_xlanhxam2;
    QPushButton *btn_xlanhmau2;
    QPushButton *btn_xlanhxam3;
    QPushButton *btn_xlanhmau3;
    QLineEdit *ln_dotuongphan;
    QLabel *lb_tanggiamdotuongphan;
    QLabel *lb_dotuongphan;
    QLineEdit *ln_chonnguon;
    QLabel *lb_chonnguon;
    QLabel *lb_tanggiamnguon;
    QPushButton *btn_xlphannguon;
    QPushButton *btn_gttuantu;
    QPushButton *btn_gtotsu;
    QPushButton *btn_vehistogram;
    QPushButton *btn_vehistogram_2;
    QPushButton *btn_bdtthistogram;
    QPushButton *btn_canbanghistogram;
    QLabel *lbKichThuocMN;
    QLineEdit *ln_KTMN;
    QLabel *lbKichThuocMN_2;
    QLineEdit *ln_TyLeNhieu;
    QPushButton *btn_LocTB;
    QPushButton *btn_LocTV;
    QPushButton *btn_ThemNhieuMT;
    QPushButton *btn_ThemNhieuAM;
    QPushButton *btn_Gauss_Laplace;
    QPushButton *btn_Loc_Gradient;
    QPushButton *btn_G_L_AnhMau;
    QPushButton *btn_Loc_Sobel;
    QPushButton *btn_Loc_Prewitt;
    QPushButton *btn_Loc_Robert;
    QPushButton *btn_Gradient_AnhMau;
    QPushButton *btn_Loc_Robert_AnhMau;
    QPushButton *btn_Loc_Laplace;
    QPushButton *btn_Loc_Prewitt_AnhMau;
    QPushButton *btn_Loc_Laplace_AnhMau;
    QPushButton *btn_Loc_Sobel_AnhMau;
    QLineEdit *ln_chonanh_1;
    QLabel *lb_Opacity_2;
    QLineEdit *ln_chonanh_2;
    QLabel *lb_Opacity_1;
    QPushButton *btn_cong_anh;
    QLineEdit *ln_Opacity_1;
    QPushButton *btn_chonanh_1;
    QLineEdit *ln_Opacity_2;
    QPushButton *btn_chonanh_2;
    QPushButton *btn_tru_anh;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1532, 666);
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lb_filename = new QLabel(centralWidget);
        lb_filename->setObjectName(QStringLiteral("lb_filename"));
        lb_filename->setGeometry(QRect(30, 20, 101, 21));
        ln_filename = new QLineEdit(centralWidget);
        ln_filename->setObjectName(QStringLiteral("ln_filename"));
        ln_filename->setGeometry(QRect(130, 20, 531, 20));
        btn_filename = new QPushButton(centralWidget);
        btn_filename->setObjectName(QStringLiteral("btn_filename"));
        btn_filename->setGeometry(QRect(680, 20, 91, 23));
        lb_anhamban = new QLabel(centralWidget);
        lb_anhamban->setObjectName(QStringLiteral("lb_anhamban"));
        lb_anhamban->setGeometry(QRect(30, 50, 101, 31));
        btn_xlanhxam1 = new QPushButton(centralWidget);
        btn_xlanhxam1->setObjectName(QStringLiteral("btn_xlanhxam1"));
        btn_xlanhxam1->setGeometry(QRect(500, 50, 131, 31));
        btn_xlanhmau1 = new QPushButton(centralWidget);
        btn_xlanhmau1->setObjectName(QStringLiteral("btn_xlanhmau1"));
        btn_xlanhmau1->setGeometry(QRect(640, 50, 131, 31));
        lb_mucsang = new QLabel(centralWidget);
        lb_mucsang->setObjectName(QStringLiteral("lb_mucsang"));
        lb_mucsang->setGeometry(QRect(30, 100, 81, 21));
        ln_mucsang = new QLineEdit(centralWidget);
        ln_mucsang->setObjectName(QStringLiteral("ln_mucsang"));
        ln_mucsang->setGeometry(QRect(160, 100, 113, 20));
        lb_tanggiammucsang = new QLabel(centralWidget);
        lb_tanggiammucsang->setObjectName(QStringLiteral("lb_tanggiammucsang"));
        lb_tanggiammucsang->setGeometry(QRect(300, 100, 141, 21));
        btn_xlanhxam2 = new QPushButton(centralWidget);
        btn_xlanhxam2->setObjectName(QStringLiteral("btn_xlanhxam2"));
        btn_xlanhxam2->setGeometry(QRect(500, 100, 131, 31));
        btn_xlanhmau2 = new QPushButton(centralWidget);
        btn_xlanhmau2->setObjectName(QStringLiteral("btn_xlanhmau2"));
        btn_xlanhmau2->setGeometry(QRect(640, 100, 131, 31));
        btn_xlanhxam3 = new QPushButton(centralWidget);
        btn_xlanhxam3->setObjectName(QStringLiteral("btn_xlanhxam3"));
        btn_xlanhxam3->setGeometry(QRect(500, 150, 131, 31));
        btn_xlanhmau3 = new QPushButton(centralWidget);
        btn_xlanhmau3->setObjectName(QStringLiteral("btn_xlanhmau3"));
        btn_xlanhmau3->setGeometry(QRect(640, 150, 131, 31));
        ln_dotuongphan = new QLineEdit(centralWidget);
        ln_dotuongphan->setObjectName(QStringLiteral("ln_dotuongphan"));
        ln_dotuongphan->setGeometry(QRect(160, 150, 113, 20));
        lb_tanggiamdotuongphan = new QLabel(centralWidget);
        lb_tanggiamdotuongphan->setObjectName(QStringLiteral("lb_tanggiamdotuongphan"));
        lb_tanggiamdotuongphan->setGeometry(QRect(300, 150, 171, 21));
        lb_dotuongphan = new QLabel(centralWidget);
        lb_dotuongphan->setObjectName(QStringLiteral("lb_dotuongphan"));
        lb_dotuongphan->setGeometry(QRect(30, 150, 121, 21));
        ln_chonnguon = new QLineEdit(centralWidget);
        ln_chonnguon->setObjectName(QStringLiteral("ln_chonnguon"));
        ln_chonnguon->setGeometry(QRect(160, 220, 113, 20));
        lb_chonnguon = new QLabel(centralWidget);
        lb_chonnguon->setObjectName(QStringLiteral("lb_chonnguon"));
        lb_chonnguon->setGeometry(QRect(30, 220, 121, 21));
        lb_tanggiamnguon = new QLabel(centralWidget);
        lb_tanggiamnguon->setObjectName(QStringLiteral("lb_tanggiamnguon"));
        lb_tanggiamnguon->setGeometry(QRect(300, 220, 131, 21));
        btn_xlphannguon = new QPushButton(centralWidget);
        btn_xlphannguon->setObjectName(QStringLiteral("btn_xlphannguon"));
        btn_xlphannguon->setGeometry(QRect(450, 220, 161, 31));
        btn_gttuantu = new QPushButton(centralWidget);
        btn_gttuantu->setObjectName(QStringLiteral("btn_gttuantu"));
        btn_gttuantu->setGeometry(QRect(620, 190, 151, 31));
        btn_gtotsu = new QPushButton(centralWidget);
        btn_gtotsu->setObjectName(QStringLiteral("btn_gtotsu"));
        btn_gtotsu->setGeometry(QRect(620, 250, 151, 31));
        btn_vehistogram = new QPushButton(centralWidget);
        btn_vehistogram->setObjectName(QStringLiteral("btn_vehistogram"));
        btn_vehistogram->setGeometry(QRect(160, 300, 191, 31));
        btn_vehistogram_2 = new QPushButton(centralWidget);
        btn_vehistogram_2->setObjectName(QStringLiteral("btn_vehistogram_2"));
        btn_vehistogram_2->setGeometry(QRect(380, 300, 191, 31));
        btn_bdtthistogram = new QPushButton(centralWidget);
        btn_bdtthistogram->setObjectName(QStringLiteral("btn_bdtthistogram"));
        btn_bdtthistogram->setGeometry(QRect(110, 350, 241, 31));
        btn_canbanghistogram = new QPushButton(centralWidget);
        btn_canbanghistogram->setObjectName(QStringLiteral("btn_canbanghistogram"));
        btn_canbanghistogram->setGeometry(QRect(380, 350, 241, 31));
        lbKichThuocMN = new QLabel(centralWidget);
        lbKichThuocMN->setObjectName(QStringLiteral("lbKichThuocMN"));
        lbKichThuocMN->setGeometry(QRect(30, 410, 151, 21));
        ln_KTMN = new QLineEdit(centralWidget);
        ln_KTMN->setObjectName(QStringLiteral("ln_KTMN"));
        ln_KTMN->setGeometry(QRect(190, 410, 113, 20));
        lbKichThuocMN_2 = new QLabel(centralWidget);
        lbKichThuocMN_2->setObjectName(QStringLiteral("lbKichThuocMN_2"));
        lbKichThuocMN_2->setGeometry(QRect(30, 460, 151, 21));
        ln_TyLeNhieu = new QLineEdit(centralWidget);
        ln_TyLeNhieu->setObjectName(QStringLiteral("ln_TyLeNhieu"));
        ln_TyLeNhieu->setGeometry(QRect(190, 460, 113, 20));
        btn_LocTB = new QPushButton(centralWidget);
        btn_LocTB->setObjectName(QStringLiteral("btn_LocTB"));
        btn_LocTB->setGeometry(QRect(330, 410, 191, 31));
        btn_LocTV = new QPushButton(centralWidget);
        btn_LocTV->setObjectName(QStringLiteral("btn_LocTV"));
        btn_LocTV->setGeometry(QRect(580, 410, 191, 31));
        btn_ThemNhieuMT = new QPushButton(centralWidget);
        btn_ThemNhieuMT->setObjectName(QStringLiteral("btn_ThemNhieuMT"));
        btn_ThemNhieuMT->setGeometry(QRect(330, 460, 191, 31));
        btn_ThemNhieuAM = new QPushButton(centralWidget);
        btn_ThemNhieuAM->setObjectName(QStringLiteral("btn_ThemNhieuAM"));
        btn_ThemNhieuAM->setGeometry(QRect(580, 460, 191, 31));
        btn_Gauss_Laplace = new QPushButton(centralWidget);
        btn_Gauss_Laplace->setObjectName(QStringLiteral("btn_Gauss_Laplace"));
        btn_Gauss_Laplace->setGeometry(QRect(30, 510, 191, 31));
        btn_Loc_Gradient = new QPushButton(centralWidget);
        btn_Loc_Gradient->setObjectName(QStringLiteral("btn_Loc_Gradient"));
        btn_Loc_Gradient->setGeometry(QRect(300, 510, 191, 31));
        btn_G_L_AnhMau = new QPushButton(centralWidget);
        btn_G_L_AnhMau->setObjectName(QStringLiteral("btn_G_L_AnhMau"));
        btn_G_L_AnhMau->setGeometry(QRect(30, 630, 191, 31));
        btn_Loc_Sobel = new QPushButton(centralWidget);
        btn_Loc_Sobel->setObjectName(QStringLiteral("btn_Loc_Sobel"));
        btn_Loc_Sobel->setGeometry(QRect(30, 570, 191, 31));
        btn_Loc_Prewitt = new QPushButton(centralWidget);
        btn_Loc_Prewitt->setObjectName(QStringLiteral("btn_Loc_Prewitt"));
        btn_Loc_Prewitt->setGeometry(QRect(300, 570, 191, 31));
        btn_Loc_Robert = new QPushButton(centralWidget);
        btn_Loc_Robert->setObjectName(QStringLiteral("btn_Loc_Robert"));
        btn_Loc_Robert->setGeometry(QRect(580, 510, 191, 31));
        btn_Gradient_AnhMau = new QPushButton(centralWidget);
        btn_Gradient_AnhMau->setObjectName(QStringLiteral("btn_Gradient_AnhMau"));
        btn_Gradient_AnhMau->setGeometry(QRect(300, 630, 191, 31));
        btn_Loc_Robert_AnhMau = new QPushButton(centralWidget);
        btn_Loc_Robert_AnhMau->setObjectName(QStringLiteral("btn_Loc_Robert_AnhMau"));
        btn_Loc_Robert_AnhMau->setGeometry(QRect(580, 630, 191, 31));
        btn_Loc_Laplace = new QPushButton(centralWidget);
        btn_Loc_Laplace->setObjectName(QStringLiteral("btn_Loc_Laplace"));
        btn_Loc_Laplace->setGeometry(QRect(580, 570, 191, 31));
        btn_Loc_Prewitt_AnhMau = new QPushButton(centralWidget);
        btn_Loc_Prewitt_AnhMau->setObjectName(QStringLiteral("btn_Loc_Prewitt_AnhMau"));
        btn_Loc_Prewitt_AnhMau->setGeometry(QRect(300, 690, 191, 31));
        btn_Loc_Laplace_AnhMau = new QPushButton(centralWidget);
        btn_Loc_Laplace_AnhMau->setObjectName(QStringLiteral("btn_Loc_Laplace_AnhMau"));
        btn_Loc_Laplace_AnhMau->setGeometry(QRect(580, 690, 191, 31));
        btn_Loc_Sobel_AnhMau = new QPushButton(centralWidget);
        btn_Loc_Sobel_AnhMau->setObjectName(QStringLiteral("btn_Loc_Sobel_AnhMau"));
        btn_Loc_Sobel_AnhMau->setGeometry(QRect(30, 690, 191, 31));
        ln_chonanh_1 = new QLineEdit(centralWidget);
        ln_chonanh_1->setObjectName(QStringLiteral("ln_chonanh_1"));
        ln_chonanh_1->setGeometry(QRect(830, 50, 471, 20));
        lb_Opacity_2 = new QLabel(centralWidget);
        lb_Opacity_2->setObjectName(QStringLiteral("lb_Opacity_2"));
        lb_Opacity_2->setGeometry(QRect(830, 190, 121, 21));
        ln_chonanh_2 = new QLineEdit(centralWidget);
        ln_chonanh_2->setObjectName(QStringLiteral("ln_chonanh_2"));
        ln_chonanh_2->setGeometry(QRect(830, 100, 471, 20));
        lb_Opacity_1 = new QLabel(centralWidget);
        lb_Opacity_1->setObjectName(QStringLiteral("lb_Opacity_1"));
        lb_Opacity_1->setGeometry(QRect(830, 150, 121, 21));
        btn_cong_anh = new QPushButton(centralWidget);
        btn_cong_anh->setObjectName(QStringLiteral("btn_cong_anh"));
        btn_cong_anh->setGeometry(QRect(1190, 140, 161, 31));
        ln_Opacity_1 = new QLineEdit(centralWidget);
        ln_Opacity_1->setObjectName(QStringLiteral("ln_Opacity_1"));
        ln_Opacity_1->setGeometry(QRect(960, 150, 191, 20));
        btn_chonanh_1 = new QPushButton(centralWidget);
        btn_chonanh_1->setObjectName(QStringLiteral("btn_chonanh_1"));
        btn_chonanh_1->setGeometry(QRect(1340, 40, 161, 31));
        ln_Opacity_2 = new QLineEdit(centralWidget);
        ln_Opacity_2->setObjectName(QStringLiteral("ln_Opacity_2"));
        ln_Opacity_2->setGeometry(QRect(960, 190, 191, 20));
        btn_chonanh_2 = new QPushButton(centralWidget);
        btn_chonanh_2->setObjectName(QStringLiteral("btn_chonanh_2"));
        btn_chonanh_2->setGeometry(QRect(1340, 90, 161, 31));
        btn_tru_anh = new QPushButton(centralWidget);
        btn_tru_anh->setObjectName(QStringLiteral("btn_tru_anh"));
        btn_tru_anh->setGeometry(QRect(1190, 190, 161, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1532, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        lb_filename->setText(QApplication::translate("MainWindow", "T\303\252n file \341\272\243nh", 0));
        btn_filename->setText(QApplication::translate("MainWindow", "Ch\341\273\215n", 0));
        lb_anhamban->setText(QApplication::translate("MainWindow", "\341\272\242nh \303\242m b\341\272\243n", 0));
        btn_xlanhxam1->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_xlanhmau1->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        lb_mucsang->setText(QApplication::translate("MainWindow", "M\341\273\251c s\303\241ng", 0));
        lb_tanggiammucsang->setText(QApplication::translate("MainWindow", ">0 t\304\203ng, <0 gi\341\272\243m", 0));
        btn_xlanhxam2->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_xlanhmau2->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        btn_xlanhxam3->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh x\303\241m", 0));
        btn_xlanhmau3->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 \341\272\243nh m\303\240u", 0));
        lb_tanggiamdotuongphan->setText(QApplication::translate("MainWindow", ">1 t\304\203ng, 0<c<1 gi\341\272\243m", 0));
        lb_dotuongphan->setText(QApplication::translate("MainWindow", "\304\220\341\273\231 t\306\260\306\241ng ph\341\272\243n", 0));
        lb_chonnguon->setText(QApplication::translate("MainWindow", "Ch\341\273\215n ng\306\260\341\273\241n", 0));
        lb_tanggiamnguon->setText(QApplication::translate("MainWindow", ">n tr\341\272\257ng, n< \304\221en", 0));
        btn_xlphannguon->setText(QApplication::translate("MainWindow", "X\341\273\255 l\303\275 ph\303\242n ng\306\260\341\273\241ng", 0));
        btn_gttuantu->setText(QApplication::translate("MainWindow", "Gi\341\272\243i thu\341\272\255t tu\341\272\247n t\341\273\261", 0));
        btn_gtotsu->setText(QApplication::translate("MainWindow", "Gi\341\272\243i thu\341\272\255t Otsu", 0));
        btn_vehistogram->setText(QApplication::translate("MainWindow", "V\341\272\275 histogram \341\272\243nh x\303\241m", 0));
        btn_vehistogram_2->setText(QApplication::translate("MainWindow", "V\341\272\275 histogram \341\272\243nh m\303\240u", 0));
        btn_bdtthistogram->setText(QApplication::translate("MainWindow", "Bi\341\272\277n \304\221\341\273\225i tuy\341\272\277n t\303\255nh histogram", 0));
        btn_canbanghistogram->setText(QApplication::translate("MainWindow", "C\303\242n b\341\272\261ng histogram", 0));
        lbKichThuocMN->setText(QApplication::translate("MainWindow", "K\303\255ch th\306\260\341\273\233c m\341\272\267t n\341\272\241", 0));
        lbKichThuocMN_2->setText(QApplication::translate("MainWindow", "T\341\273\267 l\341\273\207 nhi\341\273\205u (%)", 0));
        btn_LocTB->setText(QApplication::translate("MainWindow", "L\341\273\215c trung b\303\254nh", 0));
        btn_LocTV->setText(QApplication::translate("MainWindow", "L\341\273\215c trung v\341\273\213", 0));
        btn_ThemNhieuMT->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u mu\341\273\221i ti\303\252u", 0));
        btn_ThemNhieuAM->setText(QApplication::translate("MainWindow", "Th\303\252m nhi\341\273\205u \341\272\243nh m\303\240u", 0));
        btn_Gauss_Laplace->setText(QApplication::translate("MainWindow", "Gauss + Laplace", 0));
        btn_Loc_Gradient->setText(QApplication::translate("MainWindow", "L\341\273\215c Gradient", 0));
        btn_G_L_AnhMau->setText(QApplication::translate("MainWindow", "G + L \341\272\242nh m\303\240u", 0));
        btn_Loc_Sobel->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel", 0));
        btn_Loc_Prewitt->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt", 0));
        btn_Loc_Robert->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert", 0));
        btn_Gradient_AnhMau->setText(QApplication::translate("MainWindow", "Gradient \341\272\243nh m\303\240u", 0));
        btn_Loc_Robert_AnhMau->setText(QApplication::translate("MainWindow", "L\341\273\215c Robert \341\272\243nh m\303\240u", 0));
        btn_Loc_Laplace->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace", 0));
        btn_Loc_Prewitt_AnhMau->setText(QApplication::translate("MainWindow", "L\341\273\215c Prewitt \341\272\243nh m\303\240u", 0));
        btn_Loc_Laplace_AnhMau->setText(QApplication::translate("MainWindow", "L\341\273\215c Laplace \341\272\243nh m\303\240u", 0));
        btn_Loc_Sobel_AnhMau->setText(QApplication::translate("MainWindow", "L\341\273\215c Sobel \341\272\243nh m\303\240u", 0));
        lb_Opacity_2->setText(QApplication::translate("MainWindow", "Opacity \341\272\243nh 2", 0));
        lb_Opacity_1->setText(QApplication::translate("MainWindow", "Opacity \341\272\243nh 1", 0));
        btn_cong_anh->setText(QApplication::translate("MainWindow", "C\341\273\231ng 2 \341\272\243nh", 0));
        btn_chonanh_1->setText(QApplication::translate("MainWindow", "Chon \341\272\243nh 1", 0));
        btn_chonanh_2->setText(QApplication::translate("MainWindow", "Chon \341\272\243nh 2", 0));
        btn_tru_anh->setText(QApplication::translate("MainWindow", "Tr\341\273\253 2 \341\272\243nh", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
