#include "Disciplina.hpp"
#include "SalaAula.hpp"

#include<iostream>

using namespace ufpr;

Disciplina::Disciplina(std::string nome, SalaAula* sala)
	:nome{nome}, sala{nullptr} {
		this->setSalaAula(sala);
}

Disciplina::~Disciplina(){
	
	this->setSalaAula(nullptr);
	std::list<ConteudoMinistrado*>::iterator it;
	for(it=conteudos.begin(); it!=conteudos.end(); it++)
	delete *it;//liberando a memória de cada conteúdo
	
}

void Disciplina::adicionarAluno(Aluno* aluno){
	this->alunos.push_back(aluno);
}

void Disciplina::removerAluno(Aluno* aluno){
	this->alunos.remove(aluno);
}

void Disciplina::removerAluno(unsigned long cpf){
	std::list<Aluno*>::iterator it;

	for(it = this->alunos.begin(); it != this->alunos.end(); it++)
		if((*it)->getCpf() == cpf)
			break;
	delete *it;
	it = alunos.erase(it);
}

const std::list<Aluno*>& Disciplina::getAlunos() const{//retornamos uma referência para a lista, o que custa mais barato
	return alunos;
}

const std::string Disciplina::getNome() const{
	return this->nome;
}

void Disciplina::setNome(const std::string& nome){
	this->nome = nome;
}

const int Disciplina::getCargaHoraria() const{
	return this->cargaHoraria;
}

void Disciplina::setCargaHoraria(const unsigned int& cargaHoraria){
	this->cargaHoraria = cargaHoraria;
}

const Professor* Disciplina::getProfessor() const{
	return this->professor;
}

void Disciplina::setProfessor(Professor* professor){
	this->professor = professor;
}

void Disciplina::setSalaAula(SalaAula* sala){
	if(this->sala != nullptr)//se já existia uma sala, remover a disciplina dessa sala
		this->sala->removerDisciplina(this);
	this->sala = sala;
	if(this->sala != nullptr)
		this->sala->adicionarDisciplina(this);//adicionar a disciplina na nova sala
}

const SalaAula* Disciplina::getSalaAula() const{
	return this->sala;
}

void Disciplina::imprimeDados(std::string& cabecalho, unsigned int& cargaTotalCurso){
	double pctCurso = (double)cargaHoraria/cargaTotalCurso;
	pctCurso = pctCurso * 100;
	std::cout << cabecalho << std::endl;
	std::cout << "Disciplina: " << this->nome << std::endl;
	std::cout << "Carga: " << this->cargaHoraria << std::endl;
	std::cout << "Percentagem do curso: " << pctCurso << "%" << std::endl;
	std::cout << "Professor: " << this->professor->getNome() << std::endl;

}

void Disciplina::adicionarConteudoMinistrado(std::string conteudo, 
		unsigned short cargaHorariaConteudo){
	this->conteudos.push_back(new ConteudoMinistrado
			{conteudo, cargaHorariaConteudo});
}

void Disciplina::removerConteudoMinistrado(unsigned long id){
        std::list<ConteudoMinistrado*>::iterator it;

        for(it = this->conteudos.begin(); it != this->conteudos.end(); it++)
                if((*it)->getId() == id){
			break;
		}
	delete *it;
	it = conteudos.erase(it);
}

const std::list<ConteudoMinistrado*>& Disciplina::getConteudos() const{
	return conteudos;
}

void Disciplina::imprimirConteudosMinistrados(){
	std::list<ConteudoMinistrado*>::iterator it;
	for(it = conteudos.begin(); it!=conteudos.end(); it++){
		std::cout << "Id: " << (*it)->getId() << std::endl
		<< "Conteudo: " << (*it)->getDescricao() << std::endl
		<< "Carga: " << (*it)->getCargaHorariaConteudo() << 
			std::endl << std::endl;
	}
}

