#include "Professor.hpp"
#include "CargaHorariaException.hpp"
#include <stdexcept>
#include<iostream>

using namespace ufpr;

Professor::Professor(const std::string& nome, const unsigned long cpf, const unsigned short int idade, const unsigned int valorHora, const unsigned short cargaHoraria) 
	: Pessoa{nome, cpf, idade}{
		this->setValorHora(valorHora);
		this->setCargaHoraria(cargaHoraria);
}

void Professor::setValorHora(const unsigned int& valorHora){
	if((valorHora < 0)&&(valorHora > 150))
		throw std::invalid_argument{"Valor invalido."};	
	this->valorHora = valorHora;
}

unsigned int Professor::getValorHora() const{
	return this->valorHora;
}

void Professor::setCargaHoraria(const unsigned short& cargaHoraria){
	if((cargaHoraria < 0)&&(cargaHoraria > 44))
		throw CargaHorariaException(cargaHoraria);

	this->cargaHoraria = cargaHoraria;
}

unsigned short Professor::getCargaHoraria() const{
	return this->cargaHoraria;
}
unsigned int Professor::getSalario() const{
	//assumindo que um mês tem aprox 4.5 semanas
	return valorHora * cargaHoraria * 4.5;
}
