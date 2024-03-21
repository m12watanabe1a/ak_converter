######################################
# target
######################################
CPP_INCLUDES =  \
	-Isrc

ifeq ($(MOTOR), AK60)
CPP_DEFS = -DAK60
else ifeq ($(MOTOR), AK70)
CPP_DEFS = -DAK70
else
CPP_DEFS = -DAK70
endif

CPPFLAGS += $(CPP_DEFS) $(CPP_INCLUDES) -Wall

#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

all: $(BUILD_DIR)/ak_pose $(BUILD_DIR)/ak_vel $(BUILD_DIR)/ak_torq $(BUILD_DIR)/ak_kp $(BUILD_DIR)/ak_kd

$(BUILD_DIR)/ak_pose: src/ak_pose.cpp $(BUILD_DIR)/ak.o
	g++ $^ $(CPPFLAGS) -o $@

$(BUILD_DIR)/ak_vel: src/ak_vel.cpp $(BUILD_DIR)/ak.o
	g++ $^ $(CPPFLAGS) -o $@

$(BUILD_DIR)/ak_torq: src/ak_torq.cpp $(BUILD_DIR)/ak.o
	g++ $^ $(CPPFLAGS) -o $@

$(BUILD_DIR)/ak_kp: src/ak_kp.cpp $(BUILD_DIR)/ak.o
	g++ $^ $(CPPFLAGS) -o $@

$(BUILD_DIR)/ak_kd: src/ak_kd.cpp $(BUILD_DIR)/ak.o
	g++ $^ $(CPPFLAGS) -o $@

$(BUILD_DIR)/ak.o: src/ak.cpp | $(BUILD_DIR)
	g++ -c -o $@ $^ $(CPPFLAGS)

$(BUILD_DIR):
	mkdir $@

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
