#include "Image.h"

Image::Image() {
	this->width = -1;
	this->height = -1;
	this->imagePath = "";
	this->data = nullptr;
}

Image::Image(std::string imagePath) {
	this->width = -1;
	this->height = -1;
	this->imagePath = imagePath;
	this->data = nullptr;
}

Image::Image(Image * image) {
	this->width = image->getWidth();
	this->height = image->getHeight();
	this->imagePath = image->getPath();
	this->data = image->getData();
}

void Image::setWidth(const int width) {
	this->width = width;
}

void Image::setHeight(const int height) {
	this->height = height;
}

void Image::setPath(const std::string imagePath) {
	this->imagePath = imagePath;
}

void Image::setData(const char * data) {
	strcpy(this->data, data);
}

int Image::getWidth() {
	return this->width;
}

int Image::getHeight() {
	return this->height;
}

std::string Image::getPath() {
	return this->imagePath;
}

char * Image::getData() {
	return data;
}

bool Image::readImage() {
	// Open image file
	FILE *file;
	file = fopen(imagePath.c_str(), "rb");
	if (file) {
		std::cerr << "Error Opening File for Reading.";
		return false;
	}

	// create RGB channels
	std::vector<char> channelR(height*width);
	std::vector<char> channelG(height*width);
	std::vector<char> channelB(height*width);

	// load data
	for (int i = 0; i < height*width; i++)
		channelR[i] = fgetc(file);
	for (int i = 0; i < height*width; i++)
		channelG[i] = fgetc(file);
	for (int i = 0; i < height*width; i++)
		channelB[i] = fgetc(file);

	// allocate data
	data = new char[height*width * 4];
	for (int i = 0; i < height*width; i++) {
		data[4 * i] = channelR[i];
		data[4 * i + 1] = channelG[i];
		data[4 * i + 2] = channelB[i];
		data[4 * i + 3] = 255;
	}

	fclose(file);

	return true;
}