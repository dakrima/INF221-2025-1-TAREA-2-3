
compilador = clang++
flags      = -std=c++17 -stdlib=libc++ -O2 -Wall
archivo_main = dp_solver

archivos = dynamic_programming.cpp \
           algorithm/sequence_difference.cpp

objetos = $(archivos:.cpp=.o)

all: $(archivo_main)

$(archivo_main): $(objetos)
	$(compilador) $(flags) -o $@ $^

%.o: %.cpp
	$(compilador) $(flags) -c $< -o $@

clean:
	rm -f $(objetos) $(archivo_main)

run: $(archivo_main)
	./$(archivo_main)
