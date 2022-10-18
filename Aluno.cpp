#include "Aluno.hpp"
#include "Disciplina.hpp"
#include <iostream>
#include <stdexcept>

using namespace ufpr;

Aluno::Aluno(const std::string& nome, const unsigned long cpf, const unsigned int numeroMatricula)
	: Pessoa(nome, cpf){
		this->setNumeroMatricula(numeroMatricula);
}

void Aluno::setNumeroMatricula(const unsigned int numeroMatricula){
	if (numeroMatricula < 0)
                throw std::invalid_argument{"Matricula menor que 0"};

	this->numeroMatricula = numeroMatricula;
}

unsigned int Aluno::getNumeroMatricula() const{
	return this->numeroMatricula;
}
void Aluno::adicionarDisciplina(Disciplina* disciplina){
	this->disciplinas.push_back(disciplina);
}

void Aluno::removerDisciplina(Disciplina* disciplina){
	this->disciplinas.remove(disciplina);
}

const std::list<Disciplina*>& Aluno::getDisciplina() const{
	return this->disciplinas;
}


void Aluno::imprimirDisciplinas(){
	std::list<Disciplina*>::iterator it;
	for(it = disciplinas.begin(); it!=disciplinas.end(); it++){
                std::cout << "Disciplina: " << (*it)->getNome() << std::endl;
	}
	delete *it;
}
