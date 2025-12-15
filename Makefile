BUILD_DIR:=build

CXX:=clang++
CXXFLAGS:=-Wall -Wextra -g -std=c++17
LDFLAGS:=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

TEST_SRC_FILES:=$(addprefix $(BUILD_DIR)/, bag.o)
TEST_OBJ_FILES:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard test/*.cpp))))

VPATH=test src src/utils src/event

all : run

test.run : $(TEST_OBJ_FILES) $(TEST_SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit -o $@ $^

main.run : build/main.o $(TEST_SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR) :
	mkdir -p $@

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test : test.run
	./test.run

run : test main.run
	./main.run

clean :
	rm -vf build/*.o *.run

.PHONY : all test run clean