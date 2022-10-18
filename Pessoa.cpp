#include "Pessoa.hpp"
#include <iostream>
#include <stdexcept>
#include "CPFInvalidoException.hpp"

using namespace ufpr;

Pessoa::Pessoa(){
}

Pessoa::Pessoa(std::string nome)
		:nome{nome}{
}

Pessoa::Pessoa(std::string nome,  unsigned short int idade)
		:nome{nome}{
			this->setIdade((unsigned char)idade);
}

Pessoa::Pessoa(std::string nome, unsigned long cpf, unsigned short int idade)
	:Pessoa{nome, idade}{
		this->setCpf(cpf);
}
const unsigned long Pessoa::getCpf() const{
	return this->cpf;
}

void Pessoa::setCpf(const unsigned long& cpf){
	if(!validarCPF(cpf))
		throw CPFInvalidoException{cpf};
	this->cpf = cpf;
		
}

const std::string Pessoa::getNome() const{
	return this->nome;
}

void Pessoa::setNome(const std::string& nome){
	this->nome = nome;
}

const unsigned short int Pessoa::getIdade() const{
	return (unsigned short int)idade;
}

void Pessoa::setIdade(const unsigned short int& idade){
	if(idade > 150)
		throw std::invalid_argument{"Idade Invalida."};
	
	this->idade = (unsigned char)idade;
}


bool Pessoa::validarCPF(unsigned long cpfTeste){
	int somatorioValidaUltimo;
	int modulo;
	int somatorioValidaPenultimo = 0;
	int ultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	int penultimo = cpfTeste%10;
	cpfTeste = cpfTeste/10;
	
	somatorioValidaUltimo = penultimo*2;
	for(int i=2; i <= 11; i++){
		modulo = cpfTeste%10;
		cpfTeste = cpfTeste/10;
		somatorioValidaPenultimo += modulo*i;
		somatorioValidaUltimo += modulo*(i+1);
	}
	modulo = somatorioValidaPenultimo%11;
	if(modulo < 2){
		if(!penultimo)
			return false;//cpf invalido
	}else{
		if(penultimo != 11 - modulo)
			return false;//cpf invalido
	}
	modulo = somatorioValidaUltimo%11;
	if(modulo < 2){
		if(!ultimo)
			return false;//cpf invalido
	}else{
		if(ultimo != 11-modulo)
			return false;//cpf invalido
	}
	return true;//cpf valido
}
