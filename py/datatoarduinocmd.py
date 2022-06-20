paper_width = 10
paper_height = 10

img_width = 5
img_height = 5

def get_coords(desired_x, desired_y):
  pixel_size = paper_width / img_width
  if desired_x > img_width - 1 or desired_y > img_height - 1 or desired_x < 0 or desired_y < 0:
    return "out of bounds"
  xpos = str(pixel_size * desired_x) + " to " + str(pixel_size * desired_x+pixel_size)
  ypos = str(pixel_size * desired_y) + " to " + str(pixel_size * desired_y+pixel_size)
  return xpos, ypos

print(get_coords(int(input("x: ")), int(input("y: "))))