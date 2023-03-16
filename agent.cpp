#include "agent.h"
#include <QDebug>
#include <qdebug.h>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlQuery>
#include <QDateTime>
    Agent::Agent()
{
   id=0;
  nom="";
   prenom="";
  email="";
   mdp="";
  datee="";
   salaire=0;
    cin="";
    role="";
};
 Agent::Agent(int id,QString nom,QString prenom,QString email,QString mdp,QString datee,int salaire,QString cin,QString role){

        this->id=id;
        this->nom=nom;
        this->prenom=prenom;
        this->email=email;
        this->mdp=mdp;
        this->datee=datee;
        this->salaire=salaire;
        this->cin=cin;
        this->role=role;


    };
int Agent::getid() {return id;}
QString Agent::getnom(){return nom ;}
QString Agent::getprenom(){return nom;}
QString Agent::getemail(){return email;}
QString Agent::getmdp(){return mdp;}
QString Agent::getdatee() {return datee;}
int Agent::getsalaire() {return salaire;}
QString Agent::getcin() {return cin;}
QString Agent::getrole() {return role;}
void Agent::setid(int id){this->id=id;}
void Agent::setnom(QString nom){this->nom=nom;}
void Agent::setprenom(QString prenom){this->prenom=prenom;}
void Agent::setemail(QString email){this->email=email;}
void Agent::setmdp(QString mdp){this->mdp=mdp;}
void Agent::setdatee(QString datee){this->datee=datee;}
void Agent::setsalaire(int salaire){this->salaire=salaire;}
void Agent::setcin(QString cin){this->cin=cin;}
void Agent::setrole(QString role){this->role=role;}


bool Agent::ajouter()
{//bool test=false;
    QSqlQuery query;


    query.prepare("insert into agent (id,nom,prenom,email,mdp,datee,salaire,cin,role)"
              "  values (:id,:nom,:prenom,:email,:mdp,to_date(:datee,'dd/mm/yyyy'),:salaire,:cin,:role)");
   query.bindValue(":id",id);
    query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
      query.bindValue(":email",email);
       query.bindValue(":mdp",mdp);
        query.bindValue(":datee",datee);
         query.bindValue(":salaire",salaire);
          query.bindValue(":cin",cin);
           query.bindValue(":role",role);

          return query.exec();   //execution de requette
};
QSqlQueryModel * Agent::afficher(){

    QSqlQueryModel  * mod=new QSqlQueryModel();
    mod->setQuery("SELECT * from agent");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot de passe"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_naissance"));
     mod->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN"));
    mod->setHeaderData(8,Qt::Horizontal,QObject::tr("role"));

    return mod ;
}



bool Agent::supprimer(int id)
{
    QSqlQuery query ;
    query.prepare("DELETE from Agent where id =:id") ;
    query.bindValue(":id",id);
    return query.exec();
}
bool Agent::recherche_id(int id)
{
    QSqlQuery query;

    query.prepare("SELECT * FROM agent where id= :id");
    query.bindValue(":id",id);
    if (query.exec() && query.next())
    {
    return true;
    }
    else
    {
        return false;
    }
}
bool Agent::modifier()
{
    QSqlQuery query;
 QString id_string= QString::number(id);
 QString salaire_string= QString::number(salaire);
query.prepare("UPDATE  Agent SET id='"+id_string+"',nom='"+nom+"',prenom='"+prenom+"',email='"+email+"',mdp='"+mdp+"',datee='"+datee+"',salaire='"+salaire_string+"',cin='"+cin+"',role='"+role+"' where id='"+id_string+"'");
            query.bindValue(0, id);
            query.bindValue(1,nom);
            query.bindValue(2,prenom);
            query.bindValue(3, email);
            query.bindValue(4,mdp);
           query.bindValue(5, datee);
            query.bindValue(6, salaire);
            query.bindValue(7,cin);
            query.bindValue(8,role);

            return query.exec();   //execution de requette

}

QSqlQueryModel * Agent::recherche(QString rech)
{
    QSqlQueryModel *mod=new QSqlQueryModel();
    mod->setQuery("select * from agent where id like '%"+rech+"%' or nom like '%"+rech+"%' or prenom like '%"+rech+"%' ;");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot de passe"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_naissance"));
     mod->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN"));
    mod->setHeaderData(8,Qt::Horizontal,QObject::tr("role"));

    return mod;
}

QSqlQueryModel * Agent::trienom(){
    QSqlQueryModel * mod = new QSqlQueryModel();
    mod->setQuery("select * from Agent ORDER BY nom");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot de passe"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_naissance"));
     mod->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN"));
    mod->setHeaderData(8,Qt::Horizontal,QObject::tr("role"));

    return mod;
}


QSqlQueryModel * Agent::trierprenom(){
    QSqlQueryModel * mod = new QSqlQueryModel();
    mod->setQuery("select * from agent ORDER BY prenom");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot de passe"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_naissance"));
     mod->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN"));
    mod->setHeaderData(8,Qt::Horizontal,QObject::tr("role"));

    return mod;
}

QSqlQueryModel * Agent::trieid(){
    QSqlQueryModel * mod = new QSqlQueryModel();
    mod->setQuery("select * from agent ORDER BY id");
    mod->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    mod->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    mod->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));
    mod->setHeaderData(3,Qt::Horizontal,QObject::tr("Email"));
    mod->setHeaderData(4,Qt::Horizontal,QObject::tr("Mot de passe"));
    mod->setHeaderData(5,Qt::Horizontal,QObject::tr("Date_naissance"));
     mod->setHeaderData(6,Qt::Horizontal,QObject::tr("Salaire"));
    mod->setHeaderData(7,Qt::Horizontal,QObject::tr("CIN"));
    mod->setHeaderData(8,Qt::Horizontal,QObject::tr("role"));

    return mod;
}
