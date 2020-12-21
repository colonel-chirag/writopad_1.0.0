 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionsave_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save");
        QFile file(fileName);
        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }
        currentfile = fileName;
        setWindowTitle(fileName);
        QTextStream out(&file);
        QString text = ui->plainTextEdit->toPlainText();
        out << text;
        file.close();

}

void MainWindow::on_actionopen_triggered()
{

        QString fileName = QFileDialog::getOpenFileName(this, "Open the file");


        QFile file(fileName);


        currentfile = fileName;


        if (!file.open(QIODevice::ReadOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot open file: " + file.errorString());
            return;

}
        setWindowTitle(fileName);


        QTextStream in(&file);


        QString text = in.readAll();


        ui->plainTextEdit->setPlainText(text);


        file.close();
    }



void MainWindow::on_actionsave_as_triggered()
{

        QString fileName = QFileDialog::getSaveFileName(this, "Save as");


        QFile file(fileName);


        if (!file.open(QFile::WriteOnly | QFile::Text)) {
            QMessageBox::warning(this, "Warning", "Cannot save file: " + file.errorString());
            return;
        }


        currentfile = fileName;


        setWindowTitle(fileName);


        QTextStream out(&file);


        QString text = ui->plainTextEdit->toPlainText();


        out << text;


        file.close();
}

void MainWindow::on_actionNew_triggered()
{

       currentfile.clear();


       ui->plainTextEdit->setPlainText(QString());
}

void MainWindow::on_actionprint_triggered()
{

        QPrinter printer;


        printer.setPrinterName("Printer Name");


        QPrintDialog pDialog(&printer, this);

        if(pDialog.exec() == QDialog::Rejected){
            QMessageBox::warning(this, "Warning", "Cannot Access Printer");
            return;
        }


        ui->plainTextEdit->print(&printer);
}

void MainWindow::on_actionexit_triggered()
{
     QApplication::quit();
}

void MainWindow::on_actionCopy_triggered()
{
     ui->plainTextEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
     ui->plainTextEdit->paste();
}

void MainWindow::on_actionCut_triggered()
{

    ui->plainTextEdit->cut();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->plainTextEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
     ui->plainTextEdit->redo();
}



void MainWindow::on_actionzoom_in_triggered()
{
    ui->plainTextEdit->zoomIn();
}

void MainWindow::on_actionZoom_Out_triggered()
{
    ui->plainTextEdit->zoomOut();
}
void MainWindow::on_actiondev_triggered()
{
    QMessageBox::about(this, "About WritoPad", "WRITOPAD 1.0.0\n \n Built On 11 September 2020 \n \n Developed By Chirag Patel");
}

//CREATED BY CHIRAG PATEL
