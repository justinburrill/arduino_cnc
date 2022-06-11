from PIL import Image
# userinput = input("enter image name (eg: dog.png):")
filename = "Golden-Retriever.jpg"
userinput = "img/in/" + filename
img = Image.open(userinput)
pixels = img.load()
# n = 8

brightnesscount = 0 # find avg!!!!!!!
for x in range(img.size[0]):
    for y in range(img.size[1]):
        for rgbvalue in pixels[x, y]:
            brightnesscount += rgbvalue


for x in range(img.size[0]):
    for y in range(img.size[1]):
        a = 0
        # # threshold = n*100
        # threshold = 400
        for rgbvalue in pixels[x, y]:
            a += rgbvalue
        if a > threshold:
            pixels[x, y] = (255, 255, 255)
        else:
            pixels[x, y] = (0, 0, 0)
# pixels[1,1] = (255,255,255)
# img = img.save(str(n)+'out.png')
img = img.save('img/out/' + filename)
