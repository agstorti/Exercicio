parametrosCompilacao=-Wall #-Wshadow
nomePrograma=aula

all: $(nomePrograma)

$(nomePrograma): main.o Aluno.o Pessoa.o Disciplina.o SalaAula.o ConteudoMinistrado.o Console.o Professor.o ProfessorAdjunto.o Engenheiro.o ProfessorEngenheiro.o CPFInvalidoException.o CargaHorariaException.o
	g++ -o $(nomePrograma) main.o Aluno.o Pessoa.o Disciplina.o SalaAula.o ConteudoMinistrado.o Console.o Professor.o ProfessorAdjunto.o Engenheiro.o ProfessorEngenheiro.o CPFInvalidoException.o CargaHorariaException.o $(parametrosCompilacao)

main.o: main.cpp
	g++ -c main.cpp $(parametrosCompilacao)

Aluno.o: Aluno.hpp Aluno.cpp
	g++ -c Aluno.cpp $(parametrosCompilacao)


Pessoa.o: Pessoa.hpp Pessoa.cpp
	g++ -c Pessoa.cpp $(parametrosCompilacao)

Disciplina.o: Disciplina.hpp Disciplina.cpp
	g++ -c Disciplina.cpp $(parametrosCompilacao)

SalaAula.o: SalaAula.hpp SalaAula.cpp
	g++ -c SalaAula.cpp $(parametrosCompilacao)

ConteudoMinistrado.o: ConteudoMinistrado.hpp ConteudoMinistrado.cpp
	g++ -c ConteudoMinistrado.cpp $(parametrosCompilacao)

Console.o: Console.hpp Console.cpp
	g++ -c Console.cpp $(parametrosCompilacao)

Professor.o: Professor.hpp Professor.cpp
	g++ -c Professor.cpp $(parametrosCompilacao)

ProfessorAdjunto.o: ProfessorAdjunto.hpp ProfessorAdjunto.cpp
	g++ -c ProfessorAdjunto.cpp $(parametrosCompilacao)

Engenheiro.o: Engenheiro.hpp Engenheiro.cpp
	g++ -c Engenheiro.cpp $(parametrosCompilacao)

ProfessorEngenheiro.o: ProfessorEngenheiro.hpp ProfessorEngenheiro.cpp
	g++ -c ProfessorEngenheiro.cpp $(parametrosCompilacao)

CPFInvalidoException.o: CPFInvalidoException.hpp CPFInvalidoException.cpp
	g++ -c CPFInvalidoException.cpp $(parametrosCompilacao)

CargaHorariaException.o: CargaHorariaException.hpp CargaHorariaException.cpp
	g++ -c CargaHorariaException.cpp $(parametrosCompilacao)

clean:
	rm -f *.o *.gch $(nomePrograma)
