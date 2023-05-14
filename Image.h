#pragma once

#include <memory>
#include <string>

//Add wrapper around imagePath as a proxy

namespace Internal
{
	class Image
	{
	public:
		virtual const std::unique_ptr<Image> createFromString(const std::string& imagePath) = 0;
	};

	// Should Proxy be 'unique' for each Image creation process 
	// (good for multiple images creation in threads)
	// or could it be a singletone?
	class Proxy : public Image
	{
	public:
		const std::unique_ptr<Image> createFromString(const std::string& imagePath) override;

	private: 
		const bool isImagePathValid(const std::string& imagePath) const;
		void parseImageType(const std::string& imagePath);
		const bool isImageAttributesValid(const std::string& imagePath) const;
		const std::unique_ptr<Image> createImageOfAppropriateType(const std::string& imagePath, const std::string& imageType) const;
	};

	class ImagePNG : public Image
	{
	public:
		const std::unique_ptr<Image> createFromString(const std::string& imagePath) override;
	private:
		void readImageData();

		std::vector<uint32_t> imageData;
	};

	class ImageJPG : public Image
	{
		const std::unique_ptr<Image> createFromString(const std::string& imagePath) override;
	private:
		void readImageData();

		std::vector<uint32_t> imageData;
	};
}
