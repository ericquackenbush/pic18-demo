CC = xc8

CFLAGS = --chip=18F47Q10 --outdir=build

SOURCES = main.c
TARGET = demo

$(TARGET) : $(SOURCES)
	$(CC) $(CFLAGS) $^

clean:
	rm -rf build/*

flash:
	cp build/main.hex D:\main.hex