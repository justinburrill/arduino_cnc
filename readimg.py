from imgtoblackandwhite import blackandwhite
from imgtodata import makedata

filename = input("Enter image name (eg: dog.png):")
blackandwhite(filename)
print("Image converted into black & white")
makedata(filename)
print("Pixel data file created")
