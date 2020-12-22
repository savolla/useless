import time

def display_progress_bar(texture, speed, bar_length):
    _texture = texture
    if ( bar_length == "normal" ):
        mod = 2
    elif ( bar_length == "short" ):
        mod = 3
    elif ( bar_length == "long" ):
        mod = 1

    for i in range(100):
        print("[",i,"%]",texture, end="\r")
        time.sleep(speed)
        if ( i % mod == 0 ):
            texture += _texture
    print("\n")


display_progress_bar("█", 0.125, "short")
