PROJECT_ROOT=..
BUILD_DIR=build

CXX=clang++
CXXFLAGS=-Wall -Wextra -g -std=c++17 
LDFLAGS=-lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all : main.run

main.run : $(BUILD_DIR)/main.o
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(PROJECT_ROOT)/$@ $^

$(BUILD_DIR)/%.o : %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $^

$(BUILD_DIR) :
	mkdir -p $(BUILD_DIR)

clean :
	rm -vf $(BUILD_DIR)/*