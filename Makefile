CC = xc8

CFLAGS = --chip=18F47Q10 --outdir=build

SOURCES = main.c
TARGET = demo

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $^

clean:
	del /s /q build\*

flash:
	copy build\main.hex D: