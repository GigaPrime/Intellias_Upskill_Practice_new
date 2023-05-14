#pragma once

#include <any>
#include <string>

class Operation
{
public:
	virtual void perform(std::string imagePath, std::any param, ...) const = 0;
};

// should operations keep operation settings as a state 
// or should they receive it from the outside as a param? 

// Validate is used to check if Task and Image is valid
class Validate : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};

class Resize : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};

class Crop : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};

class Blur : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};

class Watercolor : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};

class Cartoonize : public Operation
{
public:
	void perform(std::string imagePath, std::any param, ...) const override;

private:
	//internal logic here
};
