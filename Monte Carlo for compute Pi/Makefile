se: SerialPi.c
	gcc -fopenmp SerialPi.c -o se -lm
      
pa: ParallelPi.c
	gcc -fopenmp ParallelPi.c -o pa -lm
      
run_se: se
	./se
run_pa: pa
	./pa
            
clean: 
	rm -f *.o se
	rm -f *.o pa
