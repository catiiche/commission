#ifndef RASCHET_H
#define RASCHET_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Raschet; }
QT_END_NAMESPACE

class Raschet : public QMainWindow
{
    Q_OBJECT

public:
    Raschet(QWidget *parent = nullptr);
    ~Raschet();

private slots:
    void on_start_clicked();

private:
    Ui::Raschet *ui;
};
#endif // RASCHET_H
