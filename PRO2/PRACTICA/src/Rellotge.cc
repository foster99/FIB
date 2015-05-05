/** @file Rellotge.cc
*  @brief Metodes de Rellotge

*  @brief Controla el pas del temps actualitzable per l'usuari. Aquest s'inicialitza a 20.04.15 00:00
*/
using namespace std;
#include <string>
#include "rellotge.hh"
// Constructora
Rellotge::Rellotge(){
  date = "15.04.20";
  hora = "00:00";
} // inicialitze at: 20.04.15 00:00 //note yy<->dd inverted
/** @brief CONSTRUCTORA RECOMANADA
    \pre Ha de rebre dos strings: "dd.mm.yy" y "hh:mm"
    \post crea un rellotge inicialitzat.  
*/
Rellotge::Rellotge(string date, string hora){
  this->date = rollBack(date);
  this->hora = hora;
}

// Destructora
//Rellotge::~Rellotge();

/** @override  
*/
 bool operator < (const Rellotge& r) {
  if(this.date != r.getDate()){ //comprobat dates
    if(this.date < r.getDate()) return true;
    return false;
  }else{ // mateixa data
    if(this.hora < r.getTime()) return true;
    return false;
  }
}

//Consultores

/** @brief Retorna un string del tipus yy.mm.dd
* \pre Cert
* \post Retorna la data completa en string "yy.mm.dd"
*/
string Rellotge::getDate() const{
  return date;
}

/** @brief Retorna una string del tipus hh:mm
* \pre Cert
* \post Retorna l'hora completa en string "hh:mm"
*/
string Rellotge::getTime() const{
  return hora;
}

/** @brief Retorna una string del tipus yy.mm.dd hh:mm
* \pre Cert
* \post Retorna la data completa en string "yy.mm.dd hh:mm"
*/
string Rellotge::getDateAndTime() const{
  return date + " " + hora;
}
/** @brief Escriu la data i hora en format desitjat per l'usuari
    \pre Cert
    \post Retorna la data completa en string "dd.mm.yy hh:mm"
*/
string Rellotge::printDateAndTime() const{
  return rollBack(date) + " " + hora;
}

/** @brief Escriu la data en format desijtat per l'usauri
    \pre Cert
    \post Retorna la data en format dd.mm.yy
*/
string Rellotge::printDate() const{
  return rollBack(date);
}


/** @brief actualitza la data del sistema amb l'obtinguda
* \pre el format de la data es correcte
* \post si dataIn >= dataActual el rellotge s'actualitza amb la nova data.
*/
void Rellotge::setDate(string date){
  Rellotge aux(date,"00:00");
  if(this < aux) this->date = aux.date;
  else cout << "No s'ha realitzat." << endl;
}

/** @brief actualitza la hora del sistema amb l'obtinguda
* \pre el formata de l'hora es correcte.
* \post si horaIN >= horaActual del rellotge s'actualitza amb la nova data.
*/
void Rellotge::setTime(string hora){
  Rellotge aux(this->date,hora);
  if(this < aux) this->hora = aux.hora;
  else cout << "No s'ha realitzat." << endl;
}

/** @brief Actualitza la data del sistema amb l'obtinguda
* \pre El format de la data completa es correcte.
* \post Si la data >= dataActual || data=dataActual && hora >= horaActual, l'actualiza amb la nova data completa
*/
void Rellotge::setTimeAndDate(string date, string hora){
  Rellotge aux(date,hora);
  if(aux < ) this->date = date , this->hora = hora;
  else cout << "No s'ha realitzat." << endl;  
}

/** @brief camiba yy <-> dd sobre el string.
    \pre El fotmat de data es: "dd.mm.yy" or "yy.mm.dd"
    \post retorna l'invers del dels pre dd <-> yy  el [.mm.] es mante estatic
*/
string Rellotge::rollBack(string date) const{
  return date[6]+date[7]+"."+date[3]+date[4]+"."+date[0]+date[1];
}