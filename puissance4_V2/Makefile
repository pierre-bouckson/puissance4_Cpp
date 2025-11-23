# ==== Projet : station_meteo ====

CXX       := g++
CXXFLAGS  := -std=c++17 -Wall -Wextra -O2 -Iinclude

SRC_DIR   := src
BUILD_DIR := build
TARGET    := $(BUILD_DIR)/puissance_4

# Liste automatique des .cpp et .o
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# ---- Règle principale ----
all: $(TARGET)
	@echo "Compilation terminée. Exécutable : $(TARGET)"

# ---- Lien final ----
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@echo "Édition de liens -> $@"
	@$(CXX) $(OBJS) -o $@

# ---- Compilation ----
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@echo "  Compilation de $<"
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# ---- Nettoyage ----
clean:
	@echo " Suppression du dossier build/"
	@rm -rf $(BUILD_DIR)

.PHONY: all clean

