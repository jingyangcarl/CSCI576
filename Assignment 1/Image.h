#pragma once
#include <string>
#include <vector>
#include <iostream>

class Image {

private:
	int width;
	int height;
	std::string imagePath;
	char * data;

public:
	// Constructor
	Image();
	Image(std::string imagePath);
	Image(Image *image);

	//
	void setWidth(const int width);
	void setHeight(const int height);
	void setPath(const std::string imagePath);
	void setData(const char * data);
	int getWidth();
	int getHeight();
	std::string getPath();
	char * getData();

	// read and write
	bool readImage();
	bool writeImage();
};