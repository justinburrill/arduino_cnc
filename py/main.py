from py/imgtoblackandwhite import black_and_white
from py/imgtodata import make_data
//from py/downscale import downscale
from py/sendtoarduino import send

filename = input("Enter image name (eg: dog.png):")
black_and_white(filename)
//downscale(input("Enter resolution scale (1 for same res)"), filename)
print("Image converted into black & white")
make_data(filename)
print("Pixel data file created")
send()