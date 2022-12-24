def say_thing(blob):
    bin_blob_segs = [blob[i:i+8] for i in range(0,len(blob),8)]
    return "".join([chr(int(byte, 2)) for byte in bin_blob_segs])

print(say_thing("010000010100001001000011"))
