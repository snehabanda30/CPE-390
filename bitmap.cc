#include <fstream>
#include "bitmap.hh"
#include <webp/decode.h>
#include <webp/encode.h>
#include <random>

using namespace std;
/*

	AUTHOR: Sneha Banda 
	CITE: cite any sources you used other than the ones given
	PLEDGE
*/

/*
	In order to compile you will need to install libwebp, a new graphics
	standard from google. Most image programs won't yet work with webp,
	which is better compression than jpeg in general.

	In order to install under msys2: 
	https://packages.msys2.org/package/mingw-w64-x86_64-libwebp

	In order to access a particular element of this bitmap (x,y) use the
	following equation point(x,y) does this

	y*w + x

	this works because the first point is 0*w+0 = 0, the second would be 0*w+1

	one row down would be 1*w + 0
 */


bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h), rgb(new uint32_t[w*h]) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

void bitmap::clear(uint32_t color) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
	//TODO: implement this
	
	for (uint32_t i = x1 ; i <= x2 ; i++) 
	{
		rgb[y * w + i] = color;
	}
	
	
}



void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
	//TODO: implement this

for (uint32_t i = y1 ; i <= y2 ; i++) 
	{
		rgb[i * w + x] = color;
	}

	
}
	


void bitmap::fill_rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this
	
	for (uint32_t i = x0 ; i <= x0+rw ; i++) 
	{
		for (uint32_t j = y0 ; j <= y0+rh ; j++) 
		{
			rgb[j * w + i] = color;
		}
	}
	
	
	
}
void bitmap::rect(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t color) {
	//TODO: implement this 
	
	for(uint32_t i=x0; i<=x0+rw; i+=rw) 
	{
		for (uint32_t j=y0; j<=y0+rh; j++) 
		{
			rgb[j * w + i] = color;
		}
	}
	for(uint32_t i=y0; i<=y0+rh; i+=rh) 
	{
		for (uint32_t j=x0; j<=x0+rw; j++) 
		{
			rgb[i * w + j] = color;
		}
	}
}

void bitmap::grid(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh, uint32_t divx, uint32_t divy, uint32_t color) 
{
	//TODO: implement this
	for(uint32_t i=x0; i<=x0+rw; i+=divx) 
	{
		for (uint32_t j=y0; j<=y0+rh; j++) 
		{
			rgb[j * w + i] = color;
		}
	}
	for(uint32_t i=y0; i<=y0+rh; i+=divy) 
	{
		for (uint32_t j=x0; j<=x0+rw; j++) 
		{
			rgb[i * w + j] = color;
		}
	} 
	
}


std::default_random_engine gen;

//https://stackoverflow.com/questions/22853349/how-to-generate-random-32bit-integers-in-c
void bitmap::random(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh) {
	//TODO: implement this
	for (uint32_t i = x0 ; i <= x0+rw ; i++) 
	{
		for (uint32_t j = y0 ; j <= y0+rh ; j++) 
		{
			auto val = gen();
			rgb[j * w + i] = val;
		}
	}	
	
}


void bitmap::circle(uint32_t x, uint32_t y, uint32_t d, uint32_t color) {
	//TODO: implement this 

	double testcal = 0;
    uint32_t r = d/2;
    double r_out = (r + 0.5) * (r + 0.5);
    double r_in = (r - 0.5) * (r - 0.5);
    for (int i = x - d; i <= x + d; i++) {
        for (int j = y - d; j <= y + d; j++) {
            testcal = ((i - x) * (i - x)) + ((j - y)* (j - y));
            if (testcal <r_out && testcal > r_in) {
                rgb[j * w + i] = color;
            }
        }
    }

    
	
}

//https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
void bitmap::fill_circle(uint32_t x0, uint32_t y0, uint32_t d, uint32_t color) {
	//TODO: implement this  
	double testcal = 0;
    uint32_t r = d/2;
    double r_out = (r + 0.5) * (r + 0.5);
    double r_in = (r - 0.5) * (r - 0.5);
    for (int i = x0 - d; i <= x0 + d; i++) {
        for (int j = y0 - d; j <= y0 + d; j++) {
            testcal = ((i - x0) * (i - x0)) + ((j - y0)* (j - y0));
            if (testcal <r_out) {
                rgb[j * w + i] = color;
            }
        }
    }
}


void bitmap::save(const char filename[]) {
	uint8_t*out;
	size_t s = WebPEncodeRGBA((uint8_t*)rgb, w, h, 4*w, 100, &out);
	ofstream f(filename, ios::binary);
	f.write((char*)out, s);
	WebPFree(out);
}

