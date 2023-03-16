#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include "agent.h"
#include <QMessageBox>
#include <string>
#include <QDebug>
#include <QIntValidator>
#include <QPainter>
#include "connection.h"
#include "agent.h"
#include <QSqlQueryModel>
#include <QSqlQuery>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix("C:/Users/israaa/Pictures/propic/pic2.png");
            ui->logo->setPixmap(pix);
 ui->logo_2->setPixmap(pix);
 ui->logo_3->setPixmap(pix);
    Connection c;
   bool test=c.createconnect();
    if (test)
    {

        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Connetion successeful"), QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Failed to connect"), QMessageBox::Cancel);
    }
ui->tableView_2->setModel(Agent().afficher());
ui->cin_a->setValidator( new QIntValidator(00000000, 99999999, this));
ui->id_a->setValidator( new QIntValidator(00000000, 99999999, this));
ui->salaire_a->setValidator( new QIntValidator(00000, 10000, this));
ui->nom_a->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->prenom_a->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_6_clicked()
{
    int id=ui->id_a->text().toInt();
  QString nom=ui->nom_a->text();
   QString prenom=ui->prenom_a->text();
    QString email=ui->email_a->text();
     QString mdp=ui->mdp_a->text();
        QString datee=ui->date_a->text();
      int salaire=ui->salaire_a->text().toInt();
       QString cin=ui->cin_a->text();
   QString role=ui->role_a->text();

 Agent a(id,nom,prenom,email,mdp,datee,salaire,cin,role);

 bool test=a.ajouter();
 if (test)
         { //Actualiser
      ui->tableView_2->setModel(a.afficher());
         QMessageBox:: information(nullptr, QObject::tr("OK"),
                                            QObject::tr("Ajout effectué\n"
                                                        "click cancel to exit."),QMessageBox::Cancel);
         ui->comboBox->setModel(a.afficher());
         ui->tableView_2->setModel(a.afficher());
         }
     else
         QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n"
                                           "click Cancel to exit."),QMessageBox::Cancel);
 }

void MainWindow::on_pushButton_clicked()
    {


    Agent a;
    a.setid(ui->id_s->text().toInt());
    bool test=a.supprimer(a.getid());
    QMessageBox msgBox;
    if (test){
        msgBox.setText("Suppression avec succes.");
        ui->tableView_2->setModel(a.afficher());

    }
    else
        msgBox.setText("Echec de la suppression");
    msgBox.exec();

    }


void MainWindow::on_pushButton_2_clicked()
{  QString rech= ui->le_rech->text();
    ui->tableView_2->setModel(Agent().recherche(rech));

}

void MainWindow::on_pushButton_3_clicked()
{
      ui->tableView_2->setModel(Agent().trienom());
}

void MainWindow::on_pushButton_9_clicked()
{
      ui->tableView_2->setModel(Agent().trierprenom());
}

void MainWindow::on_pushButton_7_clicked()
{
     ui->tableView_2->setModel(Agent().trieid());
}





void MainWindow::on_modify_clicked()
{
    int id=ui->le_rech->text().toInt();
    bool test=Agent().recherche_id(id);
    QMessageBox msgBox;
    if (test){
        ui->tabWidget->setCurrentIndex(1);
        QSqlQuery query;

            query.prepare("SELECT * FROM agent where id= :id");
            query.bindValue(":id",id);
            if (query.exec())
            {
        while (query.next()) {
            ui->id_m->setText(query.value("id").toString());
            ui->nom_m->setText(query.value("nom").toString());
            ui->prenom_m->setText(query.value("prenom").toString());
            ui->email_m->setText(query.value("email").toString());
            ui->mdp_m->setText(query.value("mdp").toString());
            ui->date_m->setDate(query.value("datee").toDate());
            ui->salaire_m->setText(query.value("salaire").toString());
            ui->cin_m->setText(query.value("cin").toString());
            ui->role_m->setText(query.value("role").toString());
        }
    }
      else
    {   msgBox.setText("identifiant introuvable");
        msgBox.exec();
    }
}
}

void MainWindow::on_pushButton_5_clicked()
{
    int id=ui->id_m->text().toInt();
  QString nom=ui->nom_m->text();
   QString prenom=ui->prenom_m->text();
    QString email=ui->email_m->text();
     QString mdp=ui->mdp_m->text();
        QString datee=ui->date_m->text();
      int salaire=ui->salaire_m->text().toInt();
       QString cin=ui->cin_m->text();
   QString role=ui->role_m->text();

 Agent a(id,nom,prenom,email,mdp,datee,salaire,cin,role);

 bool test=a.modifier();

 QMessageBox msgBox;
 if(test)
 {
     ui->tableView_2->setModel(a.afficher());

      msgBox.setText("modification avec succes.");
      msgBox.exec();
      ui->tabWidget->setCurrentIndex(1);
 }
 else
    {
     msgBox.setText("Echec de modification");
     msgBox.exec();
 }

}

void MainWindow::on_anuuleraj_clicked()
{

      ui->id_a->clear();
      ui->nom_a->clear();
      ui->prenom_a->clear();
      ui->email_a->clear();
      ui->mdp_a->clear();
      ui->date_a->clear();
      ui->salaire_a->clear();
      ui->cin_a->clear();
      ui->role_a->clear();
    }




void MainWindow::on_pushButton_10_clicked()
{
    ui->id_m->clear();
    ui->nom_m->clear();
    ui->prenom_m->clear();
    ui->email_m->clear();
    ui->mdp_m->clear();
    ui->date_m->clear();
    ui->salaire_m->clear();
    ui->cin_m->clear();
    ui->role_m->clear();
    ui->tabWidget->setCurrentIndex(2);
}
