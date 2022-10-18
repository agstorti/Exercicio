#ifndef CONTEUDO_MINISTRADO_HPP
#define CONTEUDO_MINISTRADO_HPP

#include<string>

namespace ufpr{
class ConteudoMinistrado{
	public:
		ConteudoMinistrado(std::string descricao, unsigned short cargaHorariaConteudo);
		virtual ~ConteudoMinistrado() = default;
		const std::string& getDescricao() const;
		const unsigned short getCargaHorariaConteudo() const;
		const unsigned int getId() const;
	private:
		static unsigned int proxId;

		std::string descricao;
		unsigned short cargaHorariaConteudo;
		unsigned int id;
};
}
#endif
