main : fract.o main.o mat.o
	gcc -O3 -Wall -Wextra -o fractales main.o mat.o fract.o -L/Users/elliot/raylib/src -lraylib -lm -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -framework QuartzCore -lm

fract.o : ./src/fract.c ./include/fract.h ./include/mat.h
	gcc -c -O3 -Wall -Wextra -I/Users/elliot/raylib/src -o fract.o ./src/fract.c -lm

mat.o : ./src/mat.c ./include/mat.h ./include/fract.h
	gcc -c -O3 -Wall -Wextra -I/Users/elliot/raylib/src -o mat.o ./src/mat.c -lm

main.o : ./src/main.c ./include/mat.h ./include/fract.h
	gcc -c -O3 -Wall -Wextra -I/Users/elliot/raylib/src -o main.o ./src/main.c -lm

clean :
	rm -f *.o
	rm -f fractales