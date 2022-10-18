#ifndef PESSOA_H
#define PESSOA_H

#include<string>

namespace ufpr{
class Pessoa{
	public:
		Pessoa();
		Pessoa(std::string nome);
		Pessoa(std::string nome, unsigned short int idade);
		Pessoa(std::string nome, unsigned long cpf, unsigned short int idade);

		virtual ~Pessoa() = default;
		const unsigned long getCpf() const;
		void setCpf(const unsigned long& cpf);

		const std::string getNome() const;
		void setNome(const std::string& nome);

		const unsigned short int getIdade() const;
		void setIdade(const unsigned short int& idade);

	private:
		bool validarCPF(unsigned long cpf);
	
	protected:
		std::string nome;
		unsigned long cpf;
		unsigned char idade;
};
}
#endif
