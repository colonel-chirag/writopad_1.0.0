#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>

QT_BEGIN_NAMESPACE
namespace Ui
//written by chirag_patel
{ class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionsave_triggered();
    void on_actionopen_triggered();
    void on_actionsave_as_triggered();
    void on_actionNew_triggered();
    void on_actionprint_triggered();
    void on_actionexit_triggered();
    void on_actionCopy_triggered();
    void on_actionPaste_triggered();
    void on_actionCut_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actiondev_triggered();
    void on_actionzoom_in_triggered();
    void on_actionZoom_Out_triggered();

private:
    Ui::MainWindow *ui;
    QString currentfile = "";

};
#endif // MAINWINDOW_H

