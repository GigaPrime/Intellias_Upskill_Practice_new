#pragma once

#include <memory>
#include <string>
#include <variant>
#include <vector>

namespace Internal
{
	class Image
	{
	public:
		virtual const std::unique_ptr<Image> createFromPath(const std::string& imagePath) = 0;
		virtual const std::unique_ptr<Image> createFromBytes(const std::vector<uint8_t>& imageData) = 0;
		virtual const std::variant<std::vector<uint8_t>, std::string> getImageData() const = 0;
	};

	class ImageFromPath;
	class ImageFromBytes;

	class Proxy : public Image
	{
	public:
		const std::unique_ptr<Image> createFromPath(const std::string& imagePath) override;
		const std::unique_ptr<Image> createFromBytes(const std::vector<uint8_t>& imageData) override;
		const std::variant<std::vector<uint8_t>, std::string> getImageData() const override;

	private: 
		const bool isPathAndFileValid(const std::string& imagePath) const;
		const bool isImageDataValid(const std::vector<uint8_t>& imageData) const;
		std::unique_ptr<ImageFromPath> imageFromPath = nullptr;
		std::unique_ptr<ImageFromBytes> imageFromBytes = nullptr;
	};

	class ImageFromPath
	{
	public:
		ImageFromPath(const std::string& imagePath) : imagePath(imagePath) {};
		const std::string getImageData() const { return imagePath; };

	private:
		std::string imagePath;
	};

	class ImageFromBytes
	{
	public:
		ImageFromBytes(const std::vector<uint8_t>& imageBytes) : imageBytes(imageBytes) {};
		const std::vector<uint8_t> getImageData() const { return imageBytes; };

	private:
		// This type of vector could handle both JPG and PNG data format, 
		// however, for other image formats vectors of another (like float) 
		// types might be required
		std::vector<uint8_t> imageBytes;
	};
}
