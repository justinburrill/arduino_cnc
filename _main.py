from imgtoblackandwhite import black_and_white
from imgtodata import make_data

filename = input("Enter image name (eg: dog.png):")
black_and_white(filename)
print("Image converted into black & white")
make_data(filename)
print("Pixel data file created")
