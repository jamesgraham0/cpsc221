#include "block.h"
#include <cmath>
#include <iostream>

int Block::height() const {
  return data[0].size();
}

int Block::width() const {
  return data.size();
}


/**
   * Renders the given block onto img with its upper
   * left corner at (x, 0). Assumes block fits on the 
   * image.
   * 
   * block is the data with the 2 vectors
   * 
   * Draw the current block at position (x,0) in im.
   */
void Block::render(PNG &im, int x) const {
  for (int column = x; column < width() + x; column++) {
    for (int  y = 0; y < height(); y++) {
      HSLAPixel* imPixel = im.getPixel(column, y); 
      *imPixel = data[column - x][y];
    } 
  }
}

void Block::build(PNG &im, int x, int width) {
  unsigned height = im.height();
  vector<HSLAPixel> vector;

  for (int x_val = x; x_val <= x + width - 1; x_val++) {
    vector.clear();
  for (unsigned y = 0; y <= height - 1; y++) {
    vector.push_back(*(im.getPixel(x_val, y)));
    }
  data.push_back(vector);
  }
}

/** 
   * Creates a block that is width X img.height pixels in size
   * by copying the pixels from (x, 0) to (x+width-1, img.height-1)
   * in img. Assumes img is large enough to supply these pixels.
   */


/*
vector<vector<HSLAPixel>> data;
*/