#ifndef PROFESSOR_ADJUNTO_HPP
#define PROFESSOR_ADJUNTO_HPP
#include "Professor.hpp"

namespace ufpr{
class ProfessorAdjunto : public Professor{
	public:
		using Professor::Professor;

		virtual ~ProfessorAdjunto() = default;

		virtual unsigned int getSalario() const override;
};
}
#endif
