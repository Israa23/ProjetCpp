#ifndef AGENT_H
#define AGENT_H
#include <QSqlQueryModel>
#include <QSqlQuery>
class Agent
{
public:
    Agent();                                     //constructeur par défaut
    Agent(int,QString,QString,QString,QString,QString,int,QString,QString);    //constructeure parametré
int getid();
QString getnom();
QString getprenom();
QString getemail();
QString getmdp();
QString getdatee();
int getsalaire();
QString getcin();
QString getrole();


void setid(int);
void setnom(QString);
void setprenom(QString);
void setemail(QString);
void setmdp(QString);
void setdatee(QString);
void setsalaire(int);
void setcin(QString);
void setrole(QString);


bool ajouter();
QSqlQueryModel * afficher();
bool supprimer(int);
bool modifier();
QSqlQueryModel * trienom();
QSqlQueryModel * recherche(QString rech);
QSqlQueryModel * trierprenom();
QSqlQueryModel * trieid();
bool recherche_id(int);
private :
QString  nom ,prenom,email,mdp,datee,role,cin;

int salaire,id;
};


#endif // AGENT_H
