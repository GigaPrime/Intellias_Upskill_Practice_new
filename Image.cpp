#include <algorithm>
#include <filesystem>
#include <exception>

#include "Image.h"

const std::unique_ptr<Internal::Image> Internal::Proxy::createFromPath(const std::string& imagePath)
{
	if (!isPathAndFileValid(imagePath))
	{
		return nullptr;
	}

	imageFromPath = std::make_unique<Internal::ImageFromPath>(imagePath);
	return std::make_unique<Image>(this);
}

const std::unique_ptr<Internal::Image> Internal::Proxy::createFromBytes(const std::vector<uint8_t>& imageData)
{
	if (!isImageDataValid(imageData))
	{
		return nullptr;
	}

	imageFromBytes = std::make_unique<Internal::ImageFromBytes>(imageData);
	return std::make_unique<Image>(this);
}

const std::variant<std::vector<uint8_t>, std::string> Internal::Proxy::getImageData() const
{
	if (imageFromPath != nullptr)
	{
		return imageFromPath.get()->getImageData();
	}

	if (imageFromBytes != nullptr)
	{
		return imageFromBytes.get()->getImageData();
	}
}

const bool Internal::Proxy::isPathAndFileValid(const std::string& imagePath) const
{
	if (!std::filesystem::exists(imagePath))
	{
		throw std::runtime_error(std::string("Image path " + imagePath + " is not valid"));
		return false;
	}

	const std::filesystem::path imageFilePath{ imagePath };
	if (!std::filesystem::file_size(imageFilePath) > 0)
	{
		throw std::runtime_error(std::string("Image file " + imagePath + " is empty"));
		return false;
	}

	std::string imageFileExtenesion = imageFilePath.extension().string();
	std::transform(imageFileExtenesion.begin(), imageFileExtenesion.end(), imageFileExtenesion.begin(), tolower(*imageFileExtenesion.begin()));
	if (imageFileExtenesion.empty() || imageFileExtenesion != "jpg" || imageFileExtenesion != "png")
	{
		throw std::runtime_error(std::string("Type of image " + imageFileExtenesion + "is not supported of file is not of an image type"));
		return false;
	}

	return true;
}

const bool Internal::Proxy::isImageDataValid(const std::vector<uint8_t>& imageData) const
{
	if (!imageData.size() > 0)
	{
		throw std::runtime_error(std::string("Image data is empty"));
		return false;
	}

	if (imageData.size() % 3 != 0 || imageData.size() % 4 != 0)
	{
		throw std::runtime_error(std::string("Image is corrupted. Image size should be multiple of 3 or 4 bytes"));
		return false;
	}

	return true;
}

