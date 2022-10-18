#include "ConteudoMinistrado.hpp"
#include <iostream>

using namespace ufpr;

unsigned int ConteudoMinistrado::proxId{0};

ConteudoMinistrado::ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo)
	:descricao(descricao), cargaHorariaConteudo(cargaHorariaConteudo), id{ConteudoMinistrado::proxId}{
	ConteudoMinistrado::proxId++;
}

const std::string& ConteudoMinistrado::getDescricao() const{
	return descricao;
}

const unsigned short ConteudoMinistrado::getCargaHorariaConteudo() const{
	return cargaHorariaConteudo;
}

const unsigned int ConteudoMinistrado::getId() const{
	return id;
}
