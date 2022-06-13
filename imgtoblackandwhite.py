from PIL import Image


def blackandwhite(filename, invert=False):
    # filename = "caterpillar.jpg"
    filepath = "img/in/" + filename
    img = Image.open(filepath)
    pixels = img.load()

    # find average pixel brightness in the image
    brightnesscount = 0
    for x in range(img.size[0]):
        for y in range(img.size[1]):
            pixelval = 0
            for rgbvalue in pixels[x, y]:
                pixelval += rgbvalue
            brightnesscount += pixelval/3

    threshold = brightnesscount / (img.size[0]*img.size[1])

    # convert pixels to either black or white depending if they are
    for x in range(img.size[0]):
        for y in range(img.size[1]):
            rgbavg = 0
            for rgbvalue in pixels[x, y]:
                rgbavg += rgbvalue
            rgbavg = rgbavg/3
            if rgbavg > threshold:
                num = 255 * (not invert)
                pixels[x, y] = (num, num, num)
            else:
                num = 255 * (invert)
                pixels[x, y] = (num, num, num)
    # pixels[1,1] = (255,255,255)
    # img = img.save(str(n)+'out.png')
    img = img.save('img/out/' + filename)
