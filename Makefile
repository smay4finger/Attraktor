verify upload: Attraktor.ino
	arduino --$@ --board arduino:sam:due $<

.PHONY: upload verify
