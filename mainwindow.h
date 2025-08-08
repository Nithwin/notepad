#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QScrollBar>
#include <QMenuBar>
#include <QAction>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QApplication>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots: 
    void newFile();
    void openFile();
    void saveFile();
    void exitApp();
    // void cutText();
    // void copyText();
    // void pasteText();
    void fullScreen();
private:
    QTextEdit *text;
    QAction *fullscreen;
};
#endif // MAINWINDOW_H
