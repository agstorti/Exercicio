#ifndef CARGA_HORARIA_EXCEPTION
#define CARGA_HORARIA_EXCEPTION
#include <stdexcept>

namespace ufpr{
class CargaHorariaException : public std::runtime_error{
	public:
		const unsigned short cargaHoraria;

		CargaHorariaException(const unsigned short cargaHoraria);
		virtual ~CargaHorariaException() = default;
};
}
#endif
