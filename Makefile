PROJECT=MatOps

App: $(PROJECT).o main.o
	gcc $^ -o $@

main.o: main.c
	gcc -c $^ -o $@ -DDEBUG

$(PROJECT).o: $(PROJECT).c
	gcc -c $^ -o $@

exec: App
	./App

clean:
	rm *.o App
