#include "CargaHorariaException.hpp"

using namespace ufpr;

CargaHorariaException::CargaHorariaException(const unsigned short cargaHoraria) : std::runtime_error{"A carga horária semanal deve ser entre 0 e 44 horas"}, 
	cargaHoraria{cargaHoraria}{
}
