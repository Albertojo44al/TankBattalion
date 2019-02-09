//#include "stats.h"
//#include <iostream>
//#include <string>
//
//using namespace std;
//
//void datosStats::setPosicion(int pos) {
//	this->posicion = pos;
//}
//
//int datosStats::getPosicion() {
//	return this->posicion;
//}
//
//void datosStats::setNombre(string nom) {
//	this->nombre = nom;
//}
//
//string datosStats::getNombre() {
//	return this->nombre;
//}
//void datosStats::setScore(int sco) {
//	this->score = sco;
//}
//
//int datosStats::getScore() {
//	return this->score;
//}
//
//bool Stats::AgregarStats(string nombre, int score) {
//	for (int f = 0; f < 10; f++)
//	{
//		if(matriz[f][1].getNombre()==""){
//			matriz[f][0].setPosicion(f);
//			matriz[f][1].setNombre(nombre);
//			matriz[f][2].setScore(score);
//			return true;
//		}
//	}
//	return false;
//}
//
//void Stats::imprimirStats() {
//	for (int f = 0; f < 10; f++)
//	{
//		int posicion = matriz[f][0].getPosicion();
//		string nombre = matriz[f][1].getNombre();
//		int score = matriz[f][3].getScore();
//		cout<<posicion<< "         " << nombre<< "          " << score ;
//	}
//}