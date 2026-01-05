BUILD_DIR:=build

CXX:=clang++
CXXFLAGS:=-Wall -Wextra -g -std=c++17 -MMD
LDFLAGS:=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_MAIN_FILES:=main.o player.o
SRC_EVENT_FILES:=eventDispatcher.o inputListener.o
SRC_COMPONENT_FILES:=button.o drawable.o component.o action.o window.o panel.o container.o
SRC_LAYOUT_FILES:=layoutManager.o orientedLayout.o borderLayout.o stackLayout.o

SRC_FILES:=$(addprefix $(BUILD_DIR)/, $(SRC_MAIN_FILES) $(SRC_EVENT_FILES) $(SRC_COMPONENT_FILES) $(SRC_LAYOUT_FILES))

TEST_SRC_FILES:=$(addprefix $(BUILD_DIR)/, observable.o)

TEST_FILES:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard test/*.cpp))))

DEPENDENCIES:=$(wildcard build/*.d)
VPATH=test src src/utils src/event src/component src/layout

all : run

test.run : $(TEST_FILES) $(TEST_SRC_FILES) | $(BUILD_DIR)
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