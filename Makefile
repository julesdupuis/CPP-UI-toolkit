BUILD_DIR:=build

CXX:=clang++
CXXFLAGS:=-Wall -Wextra -g -std=c++17 -MMD
LDFLAGS:=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_FILES:=$(addprefix $(BUILD_DIR)/, main.o game.o eventDispatcher.o player.o inputListener.o)
TEST_SRC_FILES:=$(addprefix $(BUILD_DIR)/, bag.o observable.o)
TEST_OBJ_FILES:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard test/*.cpp))))

DEPENDENCIES:=$(wildcard build/*.d)
VPATH=test src src/utils src/event

all : run

test.run : $(TEST_OBJ_FILES) $(TEST_SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit -o $@ $^

main.run : $(SRC_FILES) $(TEST_SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

$(BUILD_DIR) :
	mkdir -p $@

-include $(DEPENDENCIES)

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

test : test.run
	./test.run

run : test main.run
	./main.run

clean :
	rm -vf $(BUILD_DIR)/*.o *.run

clean_extra :
	rm -vf $(BUILD_DIR)/*.d

.PHONY : all test run clean clean_extra