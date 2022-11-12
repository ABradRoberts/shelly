from ctypes import *

shelly =  b""
shelly += b"\x48\xb8\x2f\x62\x69\x6e\x2f\x73\x68\x00\x99\x50"
shelly += b"\x54\x5f\x52\x5e\x6a\x3b\x58\x0f\x05"

wut = create_string_buffer(shelly, len(shelly))

shell = cast(wut, CFUNCTYPE(c_void_p))
shell()