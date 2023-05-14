#pragma once

#include "ImageFactory.h"

class ImageValidator;
class ImageResize;
class ImageCrop;
class ImageBlur;
class ImageWatercolor;
class ImageCartoonize;

class PlugIn
{
public:
	virtual void operation(std::unique_ptr<ImageFactory> image) const = 0;
};

class ImageValidator : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class ImageResize : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class ImageCrop : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class ImageBlur : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class ImageWatercolor : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class ImageCartoonize : public PlugIn
{
public:
	void operation(std::unique_ptr<ImageFactory> image) const override;
};

class PlugInManager
{
public:
	std::vector<std::shared_ptr<PlugIn>> createPlugIns(std::string availablePlugIns);

private:
	std::vector<std::shared_ptr<PlugIn>> plugIns;
};