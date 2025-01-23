CC = g++
STD = c++11
SRC_DIR = src
BUILD_DIR = build

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
    @mkdir -p $(BUILD_DIR)
    @$(CC) -MM -MT $@ $< > $(BUILD_DIR)/$*.d
    $(CC) -c -o $@ $< -std=$(STD)

$(BUILD_DIR)/test_bigints: $(BUILD_DIR)/test_bigints.o $(BUILD_DIR)/BigInt.o
    $(CC) -o $@ $^ -std=$(STD)

-include $(BUILD_DIR)/*.d

.PHONY: test all clean

test: $(BUILD_DIR)/test_bigints
    ./$(BUILD_DIR)/test_bigints

clean:
    rm -rf $(BUILD_DIR)