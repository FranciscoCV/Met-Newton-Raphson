#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>  //Bookstore for the use of text strings
#include <cmath>    //Library for use of mathematical functions
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Connections
    connect(ui->Calcular,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borra,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->salir,SIGNAL(clicked()),this,SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
    double MainWindow::funcion(double c){
    return  (exp(-c)-c); //returns the drag function
    }
    double MainWindow::funcion2(double c){
    return (-exp(-c)-1);  //return of the derived function
    }

void MainWindow::metodo(){
    QString temp, temp2, temp3, temp4; // //Temporary use text strings

            double xi=ui->Val_inicial->value();   //Retrieves the xi value of the spinbox
            double error=ui->Error_in->value();  //Retrieve the value of the spinbox error
            double xii=0.0;                       //variable to store the value of xi + 1
            int itera=ui->iteraciones->value();  //retrieves the value of the number of iterations that the user requires
            int it=0;   //variable to count the number of iterations
            double err=100.0;    //variable where the error value is saved
            while ((error<err)&&(it<itera)){  // the condition is evaluated either by error or by number of iterations
                xii=xi-(funcion(xi)/funcion2(xi));    //The method is done
                err=100*std::abs(xii-xi)/xii;         // the error is evaluated
                xi=xii;
                it=it+1;                                // Iterations increments
            }
            temp.append("Raiz=").append(temp2.setNum(xi)).append("\nError=").append(temp3.setNum(err)).append("\nIteraciones=").append(temp4.setNum(it));  //Se prepara el texto para ser presentado
            ui->texto->setText(temp);  //The text is presented
}
            void MainWindow::borrar(){
                ui->Val_inicial->setValue(0.0);  //Spinbox is deleted
                ui->Error_in->setValue(0.0);
                ui->texto->clear();     //Text is deleted
            }



