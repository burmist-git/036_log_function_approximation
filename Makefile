CXX  = g++
CXXFLAGS  = -g -Wall -fPIC -Wno-deprecated -O3
CXXFLAGS += -std=c++14

main: main.c
	$(CXX) -o $@ $< $(CXXFLAGS)

log_table: log_table.c
	$(CXX) -o $@ $< $(CXXFLAGS)

log_approx.o: log_approx.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

log_table.o: log_table.c
	$(CXX) $(CXXFLAGS) -c $^ -o $@

liblog_approx.so: log_approx.o log_table.o
	$(CXX) -o $@ -shared $^

run_log_approx: run_log_approx.c
	$(CXX) $< -o $@ -L. -llog_approx

export_LD_LIBRARY_PATH:
	@echo export LD_LIBRARY_PATH=/home/burmist/home2/training/036_log_function_approximation:$(LD_LIBRARY_PATH)

print_LD_LIBRATY_PATH:
	@echo LD_LIBRARY_PATH = $(value LD_LIBRARY_PATH)

.PHONY : clean
clean:
	rm -f *~
	rm -f .*~
	rm -f *.o
	rm -f *.so
	rm -f main
	rm -f run_log_approx
	rm -f log_table
