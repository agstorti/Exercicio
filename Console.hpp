#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "Disciplina.hpp"

namespace ufpr{
class Console{
	public:
		static const void imprimirDadosDisciplina(Disciplina& disciplina);
		virtual ~Console() = default;	
};
}
#endif
