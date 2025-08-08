#include "mainwindow.h"
#include <QTextOption>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    
{
    text = new QTextEdit(this);
    text->setStyleSheet(
        "border:none;background-color:#2e2e2e; color:white;font-size:20px;"
        "selection-color:white; selection-background-color:#990ef6;");
    text->verticalScrollBar()->setStyleSheet(
        "QScrollBar:vertical {"
        "background:transparent;"
        "width:8px;"
        "margin:0px;"
        "border-radius:5px;"
        "padding:1px;"
        "}"
        "QScrollBar::handle:vertical {"
        "background:#949494;"
        "border-radius:3px;"
        "min-height:20px;"
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "background: transparent;"
        "height: 0px;"
        "}"
    );

    text->setLineWrapMode(QTextEdit::WidgetWidth);
    text->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    text->setWordWrapMode(QTextOption::WrapAnywhere);

    QMenuBar *menuBar = new QMenuBar(this);

    menuBar->setStyleSheet(
        "QMenuBar {"
    "background-color: #222;"
    "color: #fff;"
    "font-size: 15px;"
    "border: none;"
    "}"
    "QMenuBar::item {"
    "background-color: #222;"
    "padding: 8px"
    "}"
    "QMenuBar::item:selected {"
    "background: #444;"
    "color: #00f79c;"
    "border-radius: 6px;"
    "}"
    "QMenu {"
    "background-color: #222;"
    "border:none;"
    "border-radius:5px;"
    "padding:4px;"
    "font-size: 15px;"
    "margin:0px;"
    "}"
    "QMenu::item:selected {"
    "color: #00f79c;"
    "}"
    "QMenu::item{"
    "magin:0px;"
    "padding:5px 30px 5px 10px ;"
    "background: transparent;"
    "}"
    );

    // Creating File Menu
    QMenu *fileMenu = menuBar->addMenu("File");
    fileMenu->setWindowFlags(fileMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    // In the File Menu adding New Action
    QAction *newfile =  fileMenu->addAction("New");
    // Connecting the newfile with function to be triggered
    connect(newfile, &QAction::triggered, this, &MainWindow::newFile);

    //creating action to open a file
    QAction *openfile = fileMenu->addAction("Open");
    connect(openfile, &QAction::triggered, this, &MainWindow::openFile);

    //creating action to save the file
    QAction *savefile = fileMenu->addAction("Save");
    // connecting the savefile with function
    connect(savefile, &QAction::triggered, this, &MainWindow::saveFile);


    QAction *exitapp = fileMenu->addAction("Exit");
    connect(exitapp, &QAction::triggered, this, &MainWindow::exitApp);

    QMenu *editMenu = menuBar->addMenu("Edit");
    editMenu->setWindowFlags(fileMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    editMenu->addAction("Cut");
    editMenu->addAction("Copy");
    editMenu->addAction("Paste");

    QMenu *viewMenu = menuBar->addMenu("View");
    viewMenu->setWindowFlags(fileMenu->windowFlags() | Qt::NoDropShadowWindowHint);
    fullscreen = viewMenu->addAction("Fullscreen");
    connect(fullscreen, &QAction::triggered, this, &MainWindow::fullScreen);

    setCentralWidget(text);
    resize(400,400);
    setMenuBar(menuBar);
    setWindowTitle("Nithwin's Notepad");
}

MainWindow::~MainWindow()
{
    
}

void MainWindow::newFile(){
    text->clear();
}

void MainWindow::saveFile(){
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", "", "Text Files (*.txt)");
    if(fileName.isEmpty()) return;
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "Cannot save file: "+ file.errorString());
        return;
    }

    QTextStream out(&file);
    out << text->toPlainText();
    QMessageBox::information(this, "Saved", "File saved successfully!");
    file.close();
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, "Open File","","Text File (*.txt)");
    if(fileName.isEmpty()) return;

    QFile file(fileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::warning(this, "Error", "Cannot open file: "+ file.errorString());
    }
    QTextStream in(&file);
    text->setPlainText(in.readAll());
    file.close();
}

void MainWindow::exitApp(){
    int res = QMessageBox::question(this,"Exit", "Do you want to close this application?", QMessageBox::Yes | QMessageBox::No);
    if(res == QMessageBox::Yes) QApplication::quit();
}

void MainWindow::fullScreen(){
    if(isFullScreen()){
        showMaximized();
        fullscreen->setText("Fullscreen");
    }
    else {
        showFullScreen();
        fullscreen->setText("Exit Fullscreen");
    }
}