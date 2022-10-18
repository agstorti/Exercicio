#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP

#include "Pessoa.hpp"

namespace ufpr{
class Professor : virtual public Pessoa{
	public:
		Professor(const std::string& nome, unsigned long cpf, const unsigned short int idade, const unsigned int salario, const unsigned short cargaHoraria);
		
		virtual ~Professor() = default;
		
		void setValorHora(const unsigned int& valorHora);
		unsigned int getValorHora() const;
		
		void setCargaHoraria(const unsigned short& cargaHoraria);
		unsigned short getCargaHoraria() const;
		virtual unsigned int getSalario() const;
	
	protected:
		unsigned int valorHora;
		unsigned short cargaHoraria;
};
}
#endif
