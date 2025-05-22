
compilador = clang++
flags      = -std=c++17 -stdlib=libc++ -O2 -Wall
archivo_main = brute_force

archivos = brute_force.cpp \
           algorithm/sequence_difference.cpp

ejecutables = $(archivos:.cpp=.o)

all: $(archivo_main)

$(archivo_main): $(ejecutables)
	$(compilador) $(flags) -o $@ $^

%.o: %.cpp
	$(compilador) $(flags) -c $< -o $@

clean:
	rm -f $(ejecutables) $(archivo_main)

run: $(archivo_main)
	./$(archivo_main)
