#pragma once

#include <string>
#include <fstream>
#include <iostream>
#include <list>

/*
===========
ShaderIncludeRecursive
===========
INTRODUCTION
The sole purpose of this class is to load a file and extract the text that is in it.
In theory, this class could be used for a variety of text-processing purposes, but
it was initially designed to be used to load shader source code.
USING THIS CLASS
Since the entire class is a static class, you only have to add this single line of
code to your project:
--------------------------------------------------------------------------------------
std::string shaderSource = ShaderIncludeRecursive::load("./path/to/shader.extension");
--------------------------------------------------------------------------------------
This will (recursively) extract the source code from the first shader file.
Now, you might be wondering, what is the point of using your code for something
so trivial as to loading a file and calling the "std::getline()" function on it?
Well, besides loading the shader source code from a single file, the loader also
supports custom keywords that allow you to include external files inside your
shader source code!
PARAMETERS OF THE LOAD FUNCTION
- std::string	path				path to the "main" shader file
- std::string	includeIdentifier		keyword to look for when scanning for files
MISCELLANEOUS
- Author	:	Tahar Meijs
- Date		:	10th - 12th of April 2018
- Language	:	C++ (can easily be converted into other languages)
*/
class ShaderIncludeRecursive {
public:
	// Return the source code of the complete shader
	static std::string load(std::string path, std::string includeIndentifier = "#include") {
		std::list<std::string> fileList;
		// add original path into list to avoid reuse
		fileList.push_back(path);
		return load2(path, includeIndentifier + ' ', fileList);
	}

private:
	static std::string load2(std::string path, std::string includeIndentifier, std::list<std::string> &fileList) {
		static bool isRecursiveCall = false;
		std::string fullSourceCode = "";
		std::ifstream file(path);
		if (!file.is_open()) {
			std::cerr << "ERROR: could not open the shader at: " << path << "\n" << std::endl;
			return fullSourceCode;
		}
		std::string lineBuffer;
		while (std::getline(file, lineBuffer)) {
			// Look for the new shader include identifier
			if (lineBuffer.find(includeIndentifier) != lineBuffer.npos) {
				// Remove the include identifier, this will cause the path to remain
				lineBuffer.erase(0, includeIndentifier.size());
				// The include path is relative to the current shader file path
				std::string pathOfThisFile;
				getFilePath(path, pathOfThisFile);
				lineBuffer.insert(0, pathOfThisFile);
				// By using recursion, the new include file can be extracted
				// and inserted at this location in the shader source code
				auto it = std::find(fileList.begin(), fileList.end(), lineBuffer);
				// path not in list
				if (fileList.end() == it) {
					isRecursiveCall = true;
					//add path to list
					fileList.push_back(lineBuffer);
					//std::cout << "New file: " << lineBuffer << std::endl;
					fullSourceCode += "\r\n"+load2(lineBuffer, includeIndentifier, fileList)+"\r\n";
				}
				else {
					//std::cout << "!File already included: " << lineBuffer << std::endl;
					// file already included, no need to include it again
				}
				// Do not add this line to the shader source code, as the include
				// path would generate a compilation issue in the final source code
				continue;
			}
			fullSourceCode += lineBuffer + "\r\n";
		}
		// Only add the null terminator at the end of the complete file,
		// essentially skipping recursive function calls this way
		if (!isRecursiveCall)
			fullSourceCode += "\0";
		file.close();
		return fullSourceCode;
	}
	static void getFilePath(const std::string& fullPath, std::string& pathWithoutFileName) {
		// Remove the file name and store the path to this folder
		size_t found = fullPath.find_last_of("/\\");
		pathWithoutFileName = fullPath.substr(0, found + 1);
	}
};