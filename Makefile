BUILD_DIR:=build

DEBUG_FLAGS=

CXX:=clang++
CXXFLAGS:=-Wall -Wextra -g -fno-omit-frame-pointer -std=c++17 -MMD $(DEBUG_FLAGS)
LDFLAGS:=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

SRC_APP_FILES:=$(wildcard src/app/*.cpp)
SRC_EVENT_FILES:=$(wildcard src/event/*.cpp)
SRC_COMPONENT_FILES:=$(wildcard src/component/*.cpp)
SRC_LAYOUT_FILES:=$(wildcard src/layout/*.cpp)
SRC_MODEL_FILES:=$(wildcard src/model/*.cpp)
SRC_RENDERERS_FILES:=$(wildcard src/renderers/*.cpp)

SRC_FILES:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(SRC_APP_FILES) $(SRC_EVENT_FILES) $(SRC_COMPONENT_FILES) $(SRC_LAYOUT_FILES) $(SRC_MODEL_FILES) $(SRC_RENDERERS_FILES))))

TEST_SRC_FILES:=$(addprefix $(BUILD_DIR)/, observable.o listener.o boundedRangeModel.o)

TEST_FILES:=$(addprefix $(BUILD_DIR)/, $(patsubst %.cpp, %.o, $(notdir $(wildcard test/*.cpp))))

DEPENDENCIES:=$(wildcard build/*.d)
VPATH=test src/app src/utils src/event src/component src/layout src/model src/renderers

all : run

test.run : $(TEST_FILES) $(TEST_SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS) -lcppunit

main.run : $(SRC_FILES) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

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

debug_makefile :
	@echo DEBUG :
	@echo $(BUILD_DIR)
	@echo $(DEBUG_FLAGS)
	@echo FILES :
	@echo $(SRC_APP_FILES)
	@echo $(SRC_EVENT_FILES)
	@echo $(SRC_COMPONENT_FILES)
	@echo $(SRC_LAYOUT_FILES)
	@echo $(SRC_MODEL_FILES)
	@echo $(SRC_FILES)
	@echo TEST FILES :
	@echo $(TEST_FILES)
	@echo $(TEST_SRC_FILES)
	@echo DEPENDENCIES :
	@echo $(DEPENDENCIES)

.PHONY : all test run clean clean_extra debug_makefile