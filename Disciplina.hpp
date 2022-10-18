#ifndef DISCIPLINA_HPP
#define DISCIPLINA_HPP

#include <string>
#include <list>

#include "Aluno.hpp"
#include "Professor.hpp"
#include "ConteudoMinistrado.hpp"
#include "Pessoa.hpp"

namespace ufpr{
class SalaAula;//forward declaration
class Disciplina{
	friend class SalaAula;
	public:
		Disciplina(std::string nome, SalaAula* sala);
		~Disciplina();

		const std::string getNome() const;
		void setNome(const std::string& nome);
		
		const int getCargaHoraria() const;
		void setCargaHoraria(const unsigned int& cargaHoraria);
		
		const Professor* getProfessor() const;
		void setProfessor(Professor* professor);

		void adicionarAluno(Aluno* aluno);
		void removerAluno(Aluno* aluno);
		void removerAluno(unsigned long cpf);
		const std::list<Aluno*>& getAlunos() const;

		void setSalaAulaSemAtualizarSala(SalaAula* sala);
		void setSalaAula(SalaAula* sala);
		const SalaAula* getSalaAula() const;

		void imprimeDados(std::string& cabecalho, 
				unsigned int& cargaTotalCurso);

		void adicionarConteudoMinistrado(std::string conteudo, 
				unsigned short cargaHorariaConteudo);
		void removerConteudoMinistrado(unsigned long id);
		const std::list<ConteudoMinistrado*>& getConteudos() const;
		

		void imprimirConteudosMinistrados();
	private:

		std::string nome;
		unsigned short int cargaHoraria;

		Professor* professor;
		SalaAula* sala;
		std::list<Aluno*> alunos;
		std::list<ConteudoMinistrado*> conteudos;
};
}
#endif
