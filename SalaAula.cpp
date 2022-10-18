#include "SalaAula.hpp"
#include "Disciplina.hpp"
#include <iostream>

using namespace ufpr;

SalaAula::SalaAula(std::string nome, unsigned int capacidade)
	:nome{nome}, capacidade{capacidade}{
}

SalaAula::~SalaAula(){
        std::list<Disciplina*>::iterator it;
        for(it=disciplinasMinistradas.begin(); it!=disciplinasMinistradas.end(); it++){
		(*it)->sala = (nullptr);
	}
	this->disciplinasMinistradas.clear();
}

const std::string SalaAula::getNome() const{
	return nome;
}

void SalaAula::setNome(const std::string& nome){
	this->nome = nome;
}

const unsigned int SalaAula::getCapacidade() const{
	return capacidade;
}

void SalaAula::setCapcidade(const unsigned int& capacidade){
	this->capacidade = capacidade;
}

void SalaAula::adicionarDisciplina(Disciplina* disciplina){
	disciplinasMinistradas.push_back(disciplina);
}

void SalaAula::removerDisciplina(Disciplina* disciplina){
	disciplinasMinistradas.remove(disciplina);
}

const std::list<Disciplina*>& SalaAula::getDisciplinas() const{
	return disciplinasMinistradas;
}
