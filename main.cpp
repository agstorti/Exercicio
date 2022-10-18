#include <iostream>
#include "ProfessorEngenheiro.hpp"
#include "Disciplina.hpp"
#include "SalaAula.hpp"
#include <stdexcept>
using namespace ufpr;

int main(){
	ProfessorEngenheiro pe{"Maria", 11111111111, 60, 30, 40, 1234};
	SalaAula sala{"Lab info 1", 30};
	
	std::cout << "Sala: " << sala.getNome() << std::endl;
	std::cout << "Professor: " << pe.getNome() << std::endl;
	return 0;
};
