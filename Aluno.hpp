#ifndef ALUNO_HPP
#define ALUNO_HPP
#include "Pessoa.hpp"


#include <string>
#include <list>

namespace ufpr{
class Disciplina;//forward declaration
class Aluno: virtual public Pessoa{
	public:
		Aluno(const std::string& nome, const unsigned long cpf, const unsigned int numeroMatricula);
		
		virtual ~Aluno() = default;
		
		void setNumeroMatricula(const unsigned int numeroMatricula);
		unsigned int getNumeroMatricula() const;
		

		void adicionarDisciplina(Disciplina* disciplina);
		void removerDisciplina(Disciplina* disciplina);
		const std::list<Disciplina*>& getDisciplina() const;
		void imprimirDisciplinas();
	
	private:

		std::list<Disciplina*> disciplinas;
		unsigned int numeroMatricula;
};
}
#endif
