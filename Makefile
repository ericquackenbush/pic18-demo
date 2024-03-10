CC = xc8
CHIP = 18F47Q10
BUILD = build/
TARGET = demo
CURIOSITY_NANO = D:

CFLAGS = --chip=$(CHIP) --outdir=$(BUILD)

$(TARGET): $(BUILD)*.p1
	$(CC) $(CFLAGS) -O$@.hex $^ 

$(BUILD)*.p1: *.c
	$(CC) $(CFLAGS) --PASS1 $^ 

clean:
	rm -f $(BUILD)/*

flash:
	cp $(BUILD)/$(TARGET).hex $(CURIOSITY_NANO)