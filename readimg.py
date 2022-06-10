from PIL import Image
# userinput = input("enter image name:")
userinput = "bw.png"
img = Image.open(userinput)
pixels = img.load()
for x in range(img.size[0]):
  for y in range(img.size[1]):
    a=0
    threshold = 350
    for t in pixels[x,y]:
      a+=t
    if a > threshold:
      pixels[x,y] = (255, 255, 255)
    else:
      pixels[x,y] = (0, 0, 0)
      

# pixels[1,1] = (255,255,255)
img = img.save('out.png')