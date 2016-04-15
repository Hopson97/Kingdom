WARNINGS = -Wall
STD = -std=c++14
OPTIMIZE = -O3
INCLUDE = -ISource -ISource/Components -ISource/Entities -ISource/Light -ISource/Managers -ISource/States -ISource/Tiles -ISource/Util
INCLUDE += -ISource/Tiles/Util
LINKING = -D SFML_STATIC -lsfml-graphics -lsfml-window -lsfml-system -lGL

NAME = Kingdom

CPP_FILES = $(wildcard Source/*.cpp)
CPP_FILES +=$(wildcard Source/Components/*.cpp)
CPP_FILES +=$(wildcard Source/Components/AI/*.cpp)
CPP_FILES +=$(wildcard Source/Components/Bases/*.cpp)
CPP_FILES +=$(wildcard Source/Entities/*.cpp)
CPP_FILES +=$(wildcard Source/Entities/Bases/*.cpp)
CPP_FILES +=$(wildcard Source/Entities/Enemies/*.cpp)
CPP_FILES +=$(wildcard Source/Light/*.cpp)
CPP_FILES +=$(wildcard Source/Managers/*.cpp)
CPP_FILES +=$(wildcard Source/States/*.cpp)
CPP_FILES +=$(wildcard Source/Tiles/*.cpp)
CPP_FILES +=$(wildcard Source/Tiles/Base/*.cpp)
CPP_FILES +=$(wildcard Source/Tiles/Other/*.cpp)
CPP_FILES +=$(wildcard Source/Tiles/Util/*.cpp)
CPP_FILES +=$(wildcard Source/Util/*.cpp)

OBJ_FILES = $(addprefix bin/,$(notdir $(CPP_FILES:.cpp=.o)))

CXX=g++-5

all: mkbindir Kingdom

debug: OPTIMIZE = -Og -g 
debug: Kingdom

mkbindir:
	@mkdir -p bin/

Kingdom: $(OBJ_FILES)
	@echo Linking $@
	@$(CXX) $^ $(STD) -o $(NAME) $(LINKING) 

clean:
	rm -rf bin/
	rm -f Kingdom

bin/%.o: Source/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Components/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Components/AI/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Components/Bases/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Entities/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Entities/Bases/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Entities/Enemies/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Light/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Managers/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/States/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Tiles/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Tiles/Base/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Tiles/Other/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Tiles/Util/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<

bin/%.o: Source/Util/%.cpp
	@echo $(CXX) $<
	@$(CXX) $(STD) $(WARNINGS) $(INCLUDE) $(OPTIMIZE) $(DEFINES) -c -o $@ $<
