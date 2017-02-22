all : narray narrayomp
narray : main.cpp
	g++ -fopenmp main.cpp -o narray

narrayomp : mainomp.cpp
	g++ -fopenmp mainomp.cpp -o narrayomp

clean :
	rm -f narray narrayomp
