from PIL import Image


def make_data(filename):
    filepath = "img/out/" + filename
    img = Image.open(filepath)
    pixels = img.load()
    data = []
    black = (0, 0, 0)
    for x in range(img.size[1]):
        for y in range(img.size[0]):
            if pixels[y, x] == black:
                data.append(1)
            else:
                data.append(0)
    with open("imginfo/" + filename + ".txt", 'w') as f:
        f.write(str(img.size[0]) + " " + str(img.size[1]))
        f.write('\n')
        for num in data:
            f.write(str(num))

