#include "ProfessorEngenheiro.hpp"
#include <iostream>

using namespace ufpr;

ProfessorEngenheiro::ProfessorEngenheiro(const std::string& nome, 
	const unsigned long cpf, unsigned short int idade, 
	const unsigned int valorHora, 
	const unsigned short cargaHoraria, const unsigned int numeroCrea) 
	:Pessoa(nome, cpf, idade), 
	Professor(nome, cpf, idade, valorHora, cargaHoraria), 
	Engenheiro(nome, cpf, numeroCrea){
}

unsigned int ProfessorEngenheiro::getSalario() const{
        return Professor::getSalario() + Engenheiro::getSalario();
}

ProfessorEngenheiro::~ProfessorEngenheiro(){}
