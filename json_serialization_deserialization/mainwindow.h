#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
  private slots:
    void write_json();
    void read_json();
    
  private:
    QString filename_;
};
#endif  // MAINWINDOW_H
