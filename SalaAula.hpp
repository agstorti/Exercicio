#ifndef SALA_AULA_H
#define SALA_AULA_H
#include <string>
#include <list>
#include "Disciplina.hpp"

namespace ufpr{
class SalaAula{
	public:
		SalaAula(std::string nome, unsigned int capacidade);
		~SalaAula();

		const std::string getNome() const;
		void setNome(const std::string& nome);

		const unsigned int getCapacidade() const;
		void setCapcidade(const unsigned int& capacidade);

		void adicionarDisciplina(Disciplina* disciplina);
		void removerDisciplina(Disciplina* disciplina);
		const std::list<Disciplina*>& getDisciplinas() const;
	private:
		std::string nome;
		unsigned int capacidade;
		std::list<Disciplina*> disciplinasMinistradas;
};
}
#endif
