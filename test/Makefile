PROJECT_ROOT:=..
BUILD_DIR:=build

CXX:=clang++
CXXFLAGS:=-Wall -Wextra -g -std=c++17 
LDFLAGS:=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

CPP_FILES:=$(wildcard *.cpp)
OBJ_FILES:=$(CPP_FILES:%.cpp=%.o)

# all :
$(PROJECT_ROOT)/test.run : $(addprefix $(BUILD_DIR)/, $(OBJ_FILES))
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -lcppunit -o $@ $^

$(BUILD_DIR)/%.o : %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(BUILD_DIR) :
	mkdir -p $(BUILD_DIR)

clean :
	rm -vf $(BUILD_DIR)/*

.PHONY : clean